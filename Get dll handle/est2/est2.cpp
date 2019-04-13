// est2.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include <Windows.h>

using namespace est2;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}

void Form1::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	HWND MS = FindWindow("MapleStoryClass", "MapleStory");
	HANDLE hData;//For the data to send to the clipboard
    char szData[] = "Hello World (from the clipboard!!)",//phrase
         *ptrData = NULL;//pointer to allow char copying
    int nStrLen = strlen(szData);//length of phrase
 
    hData = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE,
        nStrLen + 1);//get handle to memory to hold phrase
     
    ptrData = (char*)GlobalLock(hData);//get pointer from handle
 
    memcpy(ptrData,szData,nStrLen + 1);//copy over the phrase
 
    GlobalUnlock(hData);//free the handle
 
    ::OpenClipboard(NULL);//allow you to work with clipboard
 
    EmptyClipboard();//clear previous contents
 
    SetClipboardData(CF_TEXT,hData);//set our data
 
    CloseClipboard();//finished!!
}