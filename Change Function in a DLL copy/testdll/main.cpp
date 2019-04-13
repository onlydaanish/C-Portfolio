#include "main.h"
extern "C" __declspec(dllexport) int __stdcall Daanish();

#pragma once
#include <Windows.h>
#include <ImageHlp.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>


#pragma comment (lib, "ImageHlp.lib")
using namespace std;
static void GetDLLFunctions(string sADllName, vector<string>& slListOfDllFunctions);
vector<string> ExportNames;
typedef BOOL (WINAPI *fIntersectRect)(LPRECT lprcDst, const RECT *lprcscr1, const RECT *lprcSrc2);
fIntersectRect IntersectAddress = NULL;
fIntersectRect IntersectTrampoline = NULL;

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
    unsigned long cDirSize;
	int NewSize;
    _LOADED_IMAGE LoadedImage;
    string sName;
    slListOfDllFunctions.clear();
        ImageExportDirectory = (_IMAGE_EXPORT_DIRECTORY*)
            ImageDirectoryEntryToData(LoadedImage.MappedAddress,
            false, IMAGE_DIRECTORY_ENTRY_EXPORT, &cDirSize);
        if (ImageExportDirectory != NULL)
        {
            dNameRVAs = (DWORD *)ImageRvaToVa(LoadedImage.FileHeader, 
                LoadedImage.MappedAddress,
            ImageExportDirectory->AddressOfNames, NULL);
			if (ImageExportDirectory->NumberOfFunctions != 0)
			{	
			
				if (dNameRVAs != NULL)
				{
					for(size_t i = 0; i < ImageExportDirectory->NumberOfNames; i++)
					{
						sName = (char *)ImageRvaToVa(LoadedImage.FileHeader, 
								LoadedImage.MappedAddress,
							   dNameRVAs[i], NULL);
					 slListOfDllFunctions.push_back(sName);
					 slListOfDllFunctions.push_back((LPCSTR)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(dNameRVAs[i].ToString()));
					}
				}
			}
			else
			{
				::MessageBox(0, "NULL", "None", MB_OK);
			}
        }
        UnMapAndLoad(&LoadedImage);
		ofstream file("D:\\VectorText.txt");
		if (!slListOfDllFunctions.empty())
		{
		for(unsigned int i=0; i<slListOfDllFunctions.size(); i++)
			file << slListOfDllFunctions[i] << endl;
		file.close();
		}
		else
		{
			::MessageBox(0, "Empty", "Here", MB_OK);
		}
		//VectorFile.open("VectorText.txt",std::ios::out | std::ios::binary);
		//VectorFile.write((char*)&slListOfDllFunctions[0], slListOfDllFunctions.size() * sizeof(float));
}
BOOL WINAPI ZSIntersectRect()
{
	return 0;
}
void CrippleHackShield()
{
	//LoadLibrary("d3d9.dll");
	GetDLLFunctions("Canvas.dll", ExportNames);
	//IntersectAddress = (fIntersectRect) GetProcAddress(GetModuleHandle("User32.dll"), "IntersectRect");
	//IntersectTrampoline = (fIntersectRect) DetourFunction((PBYTE)IntersectAddress, (PBYTE)ZSIntersectRect);
}
#pragma unmanaged
bool __stdcall DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpvReserved) 
{
	switch (dwReason)
	{
		case DLL_PROCESS_ATTACH:
			DisableThreadLibraryCalls(hModule);
				//hsaes_relink();
				CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE) CrippleHackShield, NULL, NULL, NULL);

				//Environment::ReadVersionHeaders(L"hshield\\3n.mhe", L"\\hshield\\hshield.dat");
				//Environment::ReadInfoFromLog(L"\\hshield\\hshield.log");
		break;

		case DLL_THREAD_ATTACH:
		break;
		
		case DLL_THREAD_DETACH:
		break;
		
		case DLL_PROCESS_DETACH:
		break;
	}
	return true;
}

int __stdcall Daanish(){
return 2;}