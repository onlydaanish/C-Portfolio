#include <Windows.h>
#include <ImageHlp.h>
#pragma comment(lib, "ImageHlp")
#include <strsafe.h>
#include <TlHelp32.h>
HWND hWnd;
bool HSService = false, HSInitialize = false;

#pragma once
class CAPIHook {
public:
// Hook a function in all modules
CAPIHook(PSTR pszCalleeModName, PSTR pszFuncName, PROC pfnHook);
// Unhook a function from all modules
//~CAPIHook();
// Returns the original address of the hooked function
operator PROC() { return(m_pfnOrig); }
// Hook module w/CAPIHook implementation?
// I have to make it static because I need to use it
// in ReplaceIATEntryInAllMods
static BOOL ExcludeAPIHookMod;
public:
	// Calls the real GetProcAddress
static FARPROC WINAPI GetProcAddressRaw(HMODULE hmod, PCSTR pszProcName);
public:
static PVOID sm_pvMaxAppAddr; // Maximum private memory address
static CAPIHook* sm_pHead; // Address of first object
CAPIHook* m_pNext; // Address of next object
PCSTR m_pszCalleeModName; // Module containing the function (ANSI)
PCSTR m_pszFuncName; // Function name in callee (ANSI)
PROC m_pfnOrig; // Original function address in callee
PROC m_pfnHook; // Hook function address
public:
// Replaces a symbol's address in a module's import section
static void WINAPI ReplaceIATEntryInAllMods(PCSTR pszCalleeModName, PROC pfnOrig, PROC pfnHook);
// Replaces a symbol's address in all modules' import sections
static bool WINAPI ReplaceIATEntryInOneMod(PCSTR pszCalleeModName, PROC pfnOrig, PROC pfnHook, HMODULE hmodCaller);
// Replaces a symbol's address in a module's export sections
static bool ReplaceEATEntryInOneMod(HMODULE hmod, PCSTR pszFunctionName,
PROC pfnNew);
public:
// Used when a DLL is newly loaded after hooking a function
static void WINAPI FixupNewlyLoadedModule(HMODULE hmod, DWORD dwFlags);
// Used to trap when DLLs are newly loaded
static HMODULE WINAPI LoadLibraryA(PCSTR pszModulePath);
static HMODULE WINAPI LoadLibraryW(PCWSTR pszModulePath);
static HMODULE WINAPI LoadLibraryExA(PCSTR pszModulePath,
HANDLE hFile, DWORD dwFlags);
static HMODULE WINAPI LoadLibraryExW(PCWSTR pszModulePath,
HANDLE hFile, DWORD dwFlags);
// Returns address of replacement function if hooked function is requested
static FARPROC WINAPI GetProcAddress(HMODULE hmod, PCSTR pszProcName);
private:
// Instantiates hooks on these functions
static CAPIHook sm_LoadLibraryA;
static CAPIHook sm_LoadLibraryW;
static CAPIHook sm_LoadLibraryExA;
static CAPIHook sm_LoadLibraryExW;
static CAPIHook sm_GetProcAddress;
}; 
/////////////////////////////////////////////////////////////////////////////////////
CAPIHook* CAPIHook::sm_pHead = NULL; 
FARPROC CAPIHook::GetProcAddressRaw(HMODULE hmod, PCSTR pszProcName) {
return(::GetProcAddress(hmod, pszProcName));
}
// Handle unexpected exceptions if the module is unloaded
LONG WINAPI InvalidReadExceptionFilter(PEXCEPTION_POINTERS pep) {
// handle all unexpected exceptions because we simply don't update
// any module in that case
LONG lDisposition = EXCEPTION_EXECUTE_HANDLER;
// Note: pep->ExceptionRecord->ExceptionCode has 0xc0000005 as a value
return(lDisposition);
}

bool CAPIHook::ReplaceIATEntryInOneMod(PCSTR pszCalleeModName,
PROC pfnCurrent, PROC pfnNew, HMODULE hmodCaller) 
{
// Get the address of the module's import section
ULONG ulSize;
// An exception was triggered by Explorer (when browsing the content of
// a folder) into imagehlp.dll. It looks like one module was unloaded...
// Maybe some threading problem: the list of modules from Toolhelp might
// not be accurate if FreeLibrary is called during the enumeration.
PIMAGE_IMPORT_DESCRIPTOR pImportDesc = NULL;
	__try 
	{
	pImportDesc = (PIMAGE_IMPORT_DESCRIPTOR) ImageDirectoryEntryToData(
	hmodCaller, TRUE, IMAGE_DIRECTORY_ENTRY_IMPORT, &ulSize);
	}
__except (InvalidReadExceptionFilter(GetExceptionInformation())) {}
if (pImportDesc == NULL)
return false; // This module has no import section or is no longer loaded
// Find the import descriptor containing references to callee's functions
for (; pImportDesc->Name; pImportDesc++) 
{
	PSTR pszModName = (PSTR) ((PBYTE) hmodCaller + pImportDesc->Name);
	if (lstrcmpiA(pszModName, pszCalleeModName) == 0) 
	{
		// Get caller's import address table (IAT) for the callee's functions
		PIMAGE_THUNK_DATA pThunk = (PIMAGE_THUNK_DATA)
		((PBYTE) hmodCaller + pImportDesc->FirstThunk);
		// Replace current function address with new function address
		for (; pThunk->u1.Function; pThunk++) 
		{
			// Get the address of the function address
			PROC* ppfn = (PROC*) &pThunk->u1.Function;
			// Is this the function we're looking for?
			BOOL bFound = (*ppfn == pfnCurrent);
		if (bFound) 
		{
		if (!WriteProcessMemory(GetCurrentProcess(), ppfn, &pfnNew,sizeof(pfnNew), NULL) && (ERROR_NOACCESS == GetLastError())) 
		{
			DWORD dwOldProtect;
			if (VirtualProtect(ppfn, sizeof(pfnNew), PAGE_WRITECOPY,&dwOldProtect)) 
			{
				WriteProcessMemory(GetCurrentProcess(), ppfn, &pfnNew,
				sizeof(pfnNew), NULL);
				VirtualProtect(ppfn, sizeof(pfnNew), dwOldProtect,
				&dwOldProtect);
			}
		}
		return true; // We did it, get out
		}
}
} // Each import section is parsed until the right entry is found and patched
}
}

FARPROC WINAPI CAPIHook::GetProcAddress(HMODULE hmod, PCSTR pszProcName) 
{
	// Get the true address of the function
	FARPROC pfn = GetProcAddressRaw(hmod, pszProcName);
	// Is it one of the functions that we want hooked?
	CAPIHook* p = sm_pHead;
	for (; (pfn != NULL) && (p != NULL); p = p->m_pNext) 
	{
		if (pfn == p->m_pfnOrig) 
		{
			// The address to return matches an address we want to hook
			// Return the hook function address instead
			pfn = p->m_pfnHook;
			break;
		}
	}
	return(pfn);
}

void WINAPI CAPIHook::ReplaceIATEntryInAllMods(PCSTR pszModuleName, PROC pfnCurrent, PROC pfnNew) 
{
    HANDLE hModuleSnap = CreateToolhelp32Snapshot(
        TH32CS_SNAPMODULE, GetCurrentProcessId());
    if(hModuleSnap == INVALID_HANDLE_VALUE)
        return;

    MODULEENTRY32 me;
    me.dwSize = sizeof(me);
    BOOL bModuleResult = Module32First(hModuleSnap, &me);

    while(bModuleResult) {        
        CAPIHook::ReplaceIATEntryInOneMod(pszModuleName, pfnCurrent, pfnNew, me.hModule);
        bModuleResult = Module32Next(hModuleSnap, &me);
    }
    CloseHandle(hModuleSnap);
}

CAPIHook::CAPIHook(PSTR pszCalleeModName, PSTR pszFuncName, PROC pfnHook) {
m_pNext = sm_pHead; // The next node was at the head
sm_pHead = this; // This node is now at the head
// Save information about this hooked function
m_pszCalleeModName = pszCalleeModName;
m_pszFuncName = pszFuncName;
m_pfnHook = pfnHook;
m_pfnOrig =
GetProcAddressRaw(GetModuleHandleA(pszCalleeModName), m_pszFuncName);
// If function does not exit,... bye bye
// This happens when the module is not already loaded
if (m_pfnOrig == NULL)
{
wchar_t szPathname[MAX_PATH];
GetModuleFileNameW(NULL, szPathname, _countof(szPathname));
wchar_t sz[1024];
StringCchPrintfW(sz, _countof(sz), STRSAFE_LPCWSTR("[%4u - %s] impossible to find %S\r\n"), GetCurrentProcessId(), szPathname, pszFuncName);
OutputDebugString(LPCSTR(sz));
return;
}
// Hook this function in all currently loaded modules
ReplaceIATEntryInAllMods(m_pszCalleeModName, m_pfnOrig, m_pfnHook);
}
