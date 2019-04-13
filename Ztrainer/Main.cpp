#pragma once
#include <Windows.h>
#include "Global.h"
using namespace System;
using namespace System::IO;
using namespace std;
using namespace System::Runtime::InteropServices;
#pragma unmanaged

bool __stdcall Checker()
{
	for (;;)
	{
		if (FindWindow(NULL, GuiTitle) == NULL)
			ExitProcess(0);

	Sleep(1000);
	}
}

bool __stdcall DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpvReserved) 
{
	switch (dwReason)
	{
		case DLL_PROCESS_ATTACH:
			DisableThreadLibraryCalls(hModule);

			if (FindWindow(NULL, GuiTitle))
			{
				GuiHWND = FindWindow(NULL, GuiTitle);
				CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Checker, hModule, 0, NULL);
				CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Begin, hModule, 0, NULL);
				//CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)StartMap, hModule, 0, NULL);
			}
			else
			{
				::MessageBox(NULL, "ZSTrainer is Not Open!", "Error", MB_OK);
			}
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