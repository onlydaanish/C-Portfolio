#pragma once
#include <Windows.h>
#include "Global.h"
#include <ImageHlp.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#pragma comment (lib, "ImageHlp.lib")
using namespace std;
static bool GetDLLFunctions(string sADllName, vector<string>& slListOfDllFunctions);


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

static bool GetDLLFunctions(string sADllName, vector<string>& slListOfDllFunctions, string Find, UINT Mesg)
{
	ofstream VectorFile;
	CConverter *stringConverter = new CConverter();
    DWORD *dNameRVAs(0);
    _IMAGE_EXPORT_DIRECTORY *ImageExportDirectory;
    unsigned long cDirSize, Old, dOld;
    _LOADED_IMAGE LoadedImage;
    string sName;
    slListOfDllFunctions.clear();
    if (MapAndLoad(sADllName.c_str(), NULL, &LoadedImage, TRUE, TRUE))
    {
        ImageExportDirectory = (_IMAGE_EXPORT_DIRECTORY*) ImageDirectoryEntryToData(LoadedImage.MappedAddress, false, IMAGE_DIRECTORY_ENTRY_EXPORT, &cDirSize);
        if (ImageExportDirectory != NULL)
        {
			VirtualProtect((LPVOID)(LoadedImage.MappedAddress), LoadedImage.SizeOfImage, PAGE_EXECUTE_READWRITE, &Old);
            dNameRVAs = (DWORD *)ImageRvaToVa(LoadedImage.FileHeader, LoadedImage.MappedAddress, ImageExportDirectory->AddressOfNames, NULL);
			if (dNameRVAs != NULL)
			{
				for(size_t i = 0; i < ImageExportDirectory->NumberOfNames; i++)
				{
					sName = (char *)ImageRvaToVa(LoadedImage.FileHeader, LoadedImage.MappedAddress, dNameRVAs[i], NULL);
					slListOfDllFunctions.push_back(sName);

					//if (wcsstr(stringConverter->strToWchart(sName), stringConverter->strToWchart(Find)) != NULL)
					//	return true;
				}
			}
        }
		VirtualProtect((LPVOID)(LoadedImage.MappedAddress), LoadedImage.SizeOfImage, Old, &dOld);
        UnMapAndLoad(&LoadedImage);
		return false;
		ofstream file("D:\\VectorText.txt");
		for(unsigned int i=0; i<slListOfDllFunctions.size(); i++)
			file << slListOfDllFunctions[i] << endl;
		file.close();
    }
	else
	{
		Msg(Mesg);
		return false;
	}
	return false;
}