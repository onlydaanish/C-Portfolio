#include <Windows.h>
#pragma unmanaged
int Main();
int Tester();
bool __stdcall DllMain (HMODULE hModule, DWORD dwReason, LPVOID lpvReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
			DisableThreadLibraryCalls(hModule);
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&Main, hModule, 0, 0);
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Tester, hModule, 0, 0);
		break;
		case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return true;
}