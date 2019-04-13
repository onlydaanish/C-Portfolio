#include <Windows.h>
#include "global.h"
#include "Functions.h"
#pragma once
#include <Windows.h>
#include <ImageHlp.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#include <winnt.h>
#include <stdio.h>
#include <assert.h>
#pragma comment (lib, "ImageHlp.lib")
using namespace std;
#pragma unmanaged
static PROC IntOrig = NULL;
typedef int (__stdcall *fDaanish)();
void CrippleHackShield();
void functwo();
fDaanish DaanishOrg = NULL;
#define Addy 0x0072DC16
DWORD returnhere_intersectrect;

BOOL WINAPI FakeDaanish(LPRECT lprcDst, const RECT *lprcscr1, const RECT *lprcSrc2)
{
	::MessageBox(0, "Title", "None", MB_OK);
	return 0;
}

HANDLE WINAPI fCreateMutex(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCTSTR lpName)
{
	return GetCurrentProcess();
}

void __declspec(naked) _stdcall ASM()
{
	_asm
	{
		cmp [esp],Addy
		je ret_false
		mov edi,edi
		push ebp
		mov ebp,esp
		jmp returnhere_intersectrect

		ret_false:
		mov eax,0
		ret 0x0C
	}
}
bool Testt()
{
	
			/*while (GetModuleHandle("EhSvc.dll") == NULL)
			{
				Sleep(200);
			}

			while (CAPIHook::GetProcAddress(GetModuleHandle("EhSvc.dll"), "_AhnHS_Initialize"))
			{
				IntOrig = CAPIHook::GetProcAddress(GetModuleHandle("EhSvc.dll"), "_AhnHS_Initialize");
				Sleep(200);
			}
			::MessageBox(NULL, "None", "None", MB_OK);
			//HMODULE hmodCaller = GetModuleHandle("MapleStory.exe");
			//HSService = CAPIHook::ReplaceIATEntryInOneMod("testdll.dll", IntOrig, FakeDaanish, hmodCaller);*/
			returnhere_intersectrect = (DWORD)GetProcAddress(GetModuleHandle("Kernel32.dll"), "CreateMutex") + 5;
			CAPIHook::CAPIHook("Kernel32.dll", "CreateMutex", (PROC)ASM);
			/*CAPIHook::ReplaceIATEntryInAllMods("notepad.exe", GetProcAddress(GetModuleHandle("User32.dll"), "MessageBoxW"), FakeDaanish);
			return true;
			Sleep(100);
			
			::MessageBox(NULL, "0", "None", MB_OK);
			while (GetModuleHandle("testdll.dll") == NULL)
			{
				Sleep(100);
			}
			::MessageBox(NULL, "1", "None", MB_OK);
			DaanishOrg = (fDaanish)(GetProcAddress(GetModuleHandle("testdll.dll"), "_Daanish@0"));
			PROC IntOrg = CAPIHook::GetProcAddress(GetModuleHandle("testdll.dll"), "Daanish");
			if (DaanishOrg == NULL)
				::MessageBox(NULL, "Fail", "None", MB_OK);
			return true;
			//HOOKAPI IntRectHook[2];
			//IntRectHook[0].szFunc = "MessageBoxW";
			//IntRectHook[0].pNewProc = (PROC)FakeDaanish;
			//HookAPIByName(GetModuleHandle("notepad.exe"), "User32.dll", &IntRectHook[0]);*/
			return 0;
}

static void GetDLLFunctions(string sADllName, vector<string>& slListOfDllFunctions);
vector<string> ExportNames;

class CConverter {
   
   public:
   
      CConverter();
      ~CConverter();

      const wchar_t* strToWchart(std::string sInput);
      const std::string wchartToStr(const wchar_t* wInput);
   
      wchar_t *m_wCharBuffer;
      
};

CConverter::CConverter() {

   m_wCharBuffer = new wchar_t[1023];

}

CConverter::~CConverter()  {

   delete[] m_wCharBuffer;

}

const wchar_t* CConverter::strToWchart(std::string sInput) {

   size_t* sizeOut = new size_t;
   size_t sizeInWords = 256;
   
   const char* cStr;
   cStr = sInput.c_str();
   //mbstowcs_s( sizeOut, m_wCharBuffer, sizeInWords, cStr, strlen(cStr)+1);
   mbstowcs(m_wCharBuffer, cStr, sizeInWords);
   
   delete sizeOut;
   return m_wCharBuffer;

}

const std::string CConverter::wchartToStr(const wchar_t* wInput) {
   
   std::string sOutput = "";
   size_t* nbOfChar = new size_t;
   char* cOut = new char[1023];
   size_t sizeInBytes = 1023;
   
   //wcstombs_s( nbOfChar, cOut, sizeInBytes, wInput, 1023);
   wcstombs(cOut,wInput,sizeInBytes);
   sOutput += cOut;
   
   delete nbOfChar;
   delete[] cOut;
   return sOutput;
   
}

static void GetDLLFunctions(string sADllName, vector<string>& slListOfDllFunctions)
{
	ofstream VectorFile;
	CConverter *stringConverter = new CConverter();
    DWORD *dNameRVAs(0);
    _IMAGE_EXPORT_DIRECTORY *ImageExportDirectory;
	unsigned long Old, dOld;
    unsigned long cDirSize;
	int NewSize;
    _LOADED_IMAGE LoadedImage;
    string sName;
    slListOfDllFunctions.clear();
    if (MapAndLoad(sADllName.c_str(), NULL, &LoadedImage, TRUE, TRUE))
    {
        ImageExportDirectory = (_IMAGE_EXPORT_DIRECTORY*)
            ImageDirectoryEntryToData(LoadedImage.MappedAddress,
            false, IMAGE_DIRECTORY_ENTRY_EXPORT, &cDirSize);
        if (ImageExportDirectory != NULL)
        {
			VirtualProtect((LPVOID)(LoadedImage.MappedAddress), LoadedImage.SizeOfImage, PAGE_EXECUTE_READWRITE, &Old);
            dNameRVAs = (DWORD *)ImageRvaToVa(LoadedImage.FileHeader, 
                LoadedImage.MappedAddress,
            ImageExportDirectory->AddressOfNames, NULL);
            for(size_t i = 0; i < ImageExportDirectory->NumberOfNames; i++)
            {
                sName = (char *)ImageRvaToVa(LoadedImage.FileHeader, 
                        LoadedImage.MappedAddress,
                       dNameRVAs[i], NULL);
             slListOfDllFunctions.push_back(sName);
            }
        }
		VirtualProtect((LPVOID)(LoadedImage.MappedAddress), LoadedImage.SizeOfImage, Old, &dOld);
        UnMapAndLoad(&LoadedImage);
		ofstream file("VectorText.txt");

		for(unsigned int i=0; i<slListOfDllFunctions.size(); i++)
			file << slListOfDllFunctions[i] << endl;
		file.close();

		//VectorFile.open("VectorText.txt",std::ios::out | std::ios::binary);
		//VectorFile.write((char*)&slListOfDllFunctions[0], slListOfDllFunctions.size() * sizeof(float));
    }
	else
	{
		::MessageBox(0, "Failed to Load DLL", "Fail", MB_OK);
	}
}

static void functwo()
{
	ofstream file("VectorText.txt");
	HMODULE lib = LoadLibraryEx("Canvas.dll", NULL, DONT_RESOLVE_DLL_REFERENCES);
	assert(((PIMAGE_DOS_HEADER)lib)->e_magic == IMAGE_DOS_SIGNATURE);
	PIMAGE_NT_HEADERS header = (PIMAGE_NT_HEADERS)lib + ((PIMAGE_DOS_HEADER)lib)->e_lfanew;
	assert(header->Signature == IMAGE_NT_SIGNATURE);
	assert(header->OptionalHeader.NumberOfRvaAndSizes > 0);
	PIMAGE_EXPORT_DIRECTORY exports = (PIMAGE_EXPORT_DIRECTORY)lib + header->
		OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
	PVOID names = (PIMAGE_EXPORT_DIRECTORY)lib + exports->AddressOfNames;
	::MessageBox(0, "here", "here", MB_OK);
	for (int i = 0; i < exports->NumberOfNames; i++)
		file << ((DWORD *)names)[i] << endl;
	
}

void CrippleHackShield()
{
	//functwo();
	GetDLLFunctions("KERNEL32.dll", ExportNames);
}

BOOL __stdcall DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpvReserved) { 
    switch ( dwReason ) 
	{ 
        case DLL_PROCESS_ATTACH: 
            DisableThreadLibraryCalls(hModule);
			//CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE) CrippleHackShield, NULL, NULL, NULL);
			//CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&Begin, 0, 0, NULL);
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Testt, 0, 0, NULL);
			break; 

		case DLL_THREAD_ATTACH:
		break;
		
		case DLL_THREAD_DETACH:
		break;
		
		case DLL_PROCESS_DETACH:
		break;
    }
    return TRUE; 
}