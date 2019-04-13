#include <windows.h>
#include "environment.h"
#include "hs_aes.h"
#include "heartbeat.h"
#include "log.h"
#include "maple.h"
#include "blackcipher.h"

// main dispatch function called by the game client to do various things incl generating heartbeat
bool __stdcall ServiceDispatch(unsigned int service, void **param, unsigned int *errorCode)
{
	if (service == 13)	// heartbeat request
	{
		Log(L"Heartbeat....\n");
		Heartbeat beat;
		beat.Beat((unsigned char *)param[0], (int)param[1], (unsigned char *)param[2]);
	}

	*errorCode = 0;
	return true;
}

BOOL MemoryEdit(VOID *lpMem,VOID *lpSrc,DWORD len)
{
    DWORD lpflOldProtect, flNewProtect = PAGE_READWRITE;
    unsigned char * pDst = (unsigned char *)lpMem,
    *pSrc = (unsigned char *)lpSrc;
    if (VirtualProtect(lpMem,len,flNewProtect,&lpflOldProtect))
    {
        while(len-- > 0) *pDst++ = *pSrc++;
        return(0);
    } 
    return(1);
}

DWORD WINAPI CrippleHackShield()
{
	DWORD dwEhSvc = 0;
	do 
	{
		dwEhSvc = (DWORD) GetModuleHandleA("EhSvc.dll");
		Sleep(1000);
	} 
	while(!dwEhSvc);

    MemoryEdit((void *)(dwEhSvc + 0x09FA8), (void *)"\x74\x15", 2);             // HS_Call_Back_2
    MemoryEdit((void *)(dwEhSvc + 0x7A387), (void *)"\xC3", 1);                 // HS_Call_Back_1
    MemoryEdit((void *)(dwEhSvc + 0x98510), (void *)"\x03\xD2", 2);             // HS_Nano_Scan_1
    MemoryEdit((void *)(dwEhSvc + 0x95F5F), (void *)"\xB8\x00\x00\x00\x00", 5); // HS_Nano_Scan_2
    MemoryEdit((void *)(dwEhSvc + 0x09F10), (void *)"\xC2\x04\x00", 3);         // HS_Detection
    MemoryEdit((void *)(dwEhSvc + 0x2BBC1), (void *)"\x90\x90", 2);             // HS_Assembly
    MemoryEdit((void *)(dwEhSvc + 0x3C52E), (void *)"\x90\x90", 2);             // HS_Anti_Crash
	return 0;
}

// implement maplestory-only stuff (currently only has support for EMS, check in maple.cpp to update the crc)
void DoMaplestory()
{
	Log(L"Identified process as Maplestory\n");

	Maplestory::DisableCrc();
	Maplestory::DisableInternalHackdetection();
	Maplestory::EnableMultiMS();
	//Maplestory::DisableExceptionOnClose();
}

BOOL WINAPI DllMain(HINSTANCE, DWORD r, LPVOID)
{
	if (r == DLL_PROCESS_ATTACH)
	{
		AllocConsole();	// comment this line to remove the console from showing
		hsaes_relink();	// initialize the ripped code from ehsvc.dll originally

		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE) CrippleHackShield, NULL, NULL, NULL);
		HookBlackcipherAPIs();

		// get the current working directory to determine what the app might be
		wchar_t cwd[MAX_PATH + 1];
		GetCurrentDirectory(MAX_PATH + 1, cwd);
		Log(L"cwd: %s\n", cwd);

		if (wcsstr(_wcslwr(cwd), L"maplestory") != 0)
			DoMaplestory();

		// read the data needed to generate heartbeat from hshield files
		Environment::ReadVersionHeaders(L"hshield\\3n.mhe", L"hshield\\hshield.dat");
		Environment::ReadInfoFromLog(L"hshield\\hshield.log");
	} else if (r == DLL_PROCESS_DETACH)
	{
		FreeConsole();
	}

	return TRUE;
}