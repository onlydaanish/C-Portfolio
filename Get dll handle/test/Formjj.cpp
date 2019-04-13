#include "Formjj.h"
#include <Windows.h>
#include <Tlhelp32.h>
#include <sstream>
#include <string>
#include <OAIdl.h>
using namespace test;
using namespace System::Runtime::InteropServices;
int Val;
HWND hwWindow;
DWORD Result = NULL;
LRESULT Return = NULL;
[STAThread]
int Main()  {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Formjj);
	return 0;
}
#pragma unmanaged
__inline ULONG_PTR ReadPointer(ULONG_PTR* ulBase, INT nOffset)
{
	if ( !IsBadReadPtr((VOID*)ulBase, sizeof(ULONG_PTR)) )
		if ( !IsBadReadPtr((VOID*)((*(ULONG_PTR*)ulBase)+nOffset), sizeof(ULONG_PTR)) )
			return *(ULONG_PTR*)((*(ULONG_PTR*)ulBase)+nOffset);
	return 0;
}

HMODULE GetModuleHandleExtern( char *szModuleName, DWORD dwProcessId )
{
   if( !szModuleName || !dwProcessId ) { return NULL; } // invalid input
   HANDLE hSnap = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE, dwProcessId );
   if( hSnap == INVALID_HANDLE_VALUE ) { return NULL; }
   MODULEENTRY32 me;
   me.dwSize = sizeof( MODULEENTRY32 );
   if( Module32First( hSnap, &me ) ) // we go now
   {
      while( Module32Next( hSnap, &me ) ) // through all modules in the target process
      {
         if( !strcmp( me.szModule, szModuleName ) ) // is this the model we are looking for?
         {
            CloseHandle( hSnap );
            return me.hModule; // this is our module, return it.
         }
      }
   }
   CloseHandle( hSnap );
   return NULL; // counldn't find module
}
int Tester()
{
	unsigned long ulProcID = 0;
	HWND hwWindow = FindWindow("MapleStoryClass", "MapleStory");
	if (hwWindow)
	{
	if (GetWindowThreadProcessId(hwWindow, &ulProcID))
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ulProcID);
	}
	else
	{
		::MessageBoxA(0, "No Window", "None", MB_OK);
	}
	DWORD Handle = (DWORD)GetModuleHandleExtern("ntdll.dll", ulProcID);
	DWORD Addy = Handle+0xD77C8;
	for(;;)
	{
	Val = ReadPointer((ULONG_PTR*)Addy, 0x14);
	Sleep(100);
	}
	return 0;
}
#pragma managed
void Formjj::timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{
	HWND hwWindow = FindWindow("MapleStoryClass", "MapleStory");
	if (hwWindow == NULL)
	{
		label1->Text = "No Window";
	}
	else
	{
		label1->Text = "Window";

	}
}
