#include <Windows.h>

typedef struct tag_HOOKAPI
{
LPCSTR szFunc; // HOOK API functions by name.
PROC pNewProc; // replace function addresses.
PROC pOldProc; // address of original API functions.
} HOOKAPI, * LPHOOKAPI;



extern "C" __declspec (dllexport) PIMAGE_IMPORT_DESCRIPTOR
LocationIAT (HMODULE hModule, LPCSTR szImportMod)

{

PIMAGE_DOS_HEADER pDOSHeader = (PIMAGE_DOS_HEADER) hModule;
if (pDOSHeader-> e_magic != IMAGE_DOS_SIGNATURE) return NULL;

PIMAGE_NT_HEADERS pNTHeader = (PIMAGE_NT_HEADERS) ((DWORD) pDOSHeader + (DWORD) (pDOSHeader-> e_lfanew));
if (pNTHeader-> Signature != IMAGE_NT_SIGNATURE) return NULL;

if (pNTHeader-> OptionalHeader.DataDirectory [IMAGE_DIRECTORY_ENTRY_IMPORT]. VirtualAddress == 0) return NULL;

PIMAGE_IMPORT_DESCRIPTOR pImportDesc = (PIMAGE_IMPORT_DESCRIPTOR) ((DWORD) pDOSHeader + (DWORD) (pNTHeader-> OptionalHeader.DataDirectory [IMAGE_DIRECTORY_ENTRY_IMPORT]. VirtualAddress));
while (pImportDesc-> Name)
{
PSTR szCurrMod = (PSTR) ((DWORD) pDOSHeader + (DWORD) (pImportDesc-> Name));
if (_stricmp (szCurrMod, szImportMod) == 0) break;
pImportDesc++;
}
if (pImportDesc-> Name == NULL) return NULL;
return pImportDesc;
}


FARPROC WINAPI HookAPIByName (HMODULE hModule, LPCSTR szImportMod, LPHOOKAPI pHookApi)
{
PIMAGE_IMPORT_DESCRIPTOR pImportDesc = LocationIAT (hModule, szImportMod);
if (pImportDesc == NULL) return FALSE;
PIMAGE_THUNK_DATA pOrigThunk = (PIMAGE_THUNK_DATA) ((DWORD) hModule + (DWORD) (pImportDesc-> OriginalFirstThunk));
PIMAGE_THUNK_DATA pRealThunk = (PIMAGE_THUNK_DATA) ((DWORD) hModule + (DWORD) (pImportDesc-> FirstThunk));
while (pOrigThunk-> u1.Function)
{
if ((pOrigThunk-> u1.Ordinal & IMAGE_ORDINAL_FLAG) != IMAGE_ORDINAL_FLAG)
{
PIMAGE_IMPORT_BY_NAME pByName = (PIMAGE_IMPORT_BY_NAME) ((DWORD) hModule + (DWORD) (pOrigThunk-> u1.AddressOfData));
if (pByName-> Name [0] == '\ 0') 
	return FALSE;
if (_strcmpi (pHookApi-> szFunc, (char *) pByName-> Name) == 0)
{
MEMORY_BASIC_INFORMATION mbi_thunk;
VirtualQuery (pRealThunk, & mbi_thunk, sizeof (MEMORY_BASIC_INFORMATION));
VirtualProtect (mbi_thunk.BaseAddress, mbi_thunk.RegionSize, PAGE_READWRITE, & mbi_thunk.Protect);
if (pHookApi-> pOldProc == NULL)
pHookApi-> pOldProc = (PROC) pRealThunk-> u1.Function;
pRealThunk-> u1.Function = (DWORD) pHookApi-> pNewProc;
DWORD dwOldProtect;
VirtualProtect (mbi_thunk.BaseAddress, mbi_thunk.RegionSize, mbi_thunk.Protect, & dwOldProtect);
}
}
pOrigThunk++;
pRealThunk++;
}
SetLastError (ERROR_SUCCESS); 
}

static int WINAPI MessageBoxA1()
{
	::MessageBoxA(NULL, "Hooked", "T", MB_OK);
	return 0;
}


BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpvReserved) { 
    switch (dwReason){
		case DLL_PROCESS_ATTACH: 
			DisableThreadLibraryCalls( hModule );
			HOOKAPI api [2];
			api [0].szFunc = "MessageBoxA"; // set the name of the function is blocked section.
			api [0].pNewProc = (PROC)MessageBoxA1; // set to replace the function of the address.
			HookAPIByName (GetModuleHandle("notepad.exe"), "User32.dll", &api[0]);
		break;
	}
    return TRUE;
}