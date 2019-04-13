#include "Export.h"
#include "ApiHook.h"

vector<string> ExportNames;
//typedef BOOL (WINAPI *fIntersectRect)(LPRECT lprcDst, const RECT *lprcscr1, const RECT *lprcSrc2);
//fIntersectRect IntersectAddress = NULL;
//fIntersectRect IntersectTrampoline = NULL;

BOOL WINAPI ZSIntersectRect(LPRECT lprcDst, const RECT *lprcscr1, const RECT *lprcSrc2)
{
	::MessageBox(0, "Hooked YEAH!", "hi", MB_OK);
	return 0;
}


bool GetDetourInfo()
{
	// EXTRA INFO FOR HOOKING

	/*DetourTransactionBegin();
	8etourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)fIntersectRect, ZSIntersectRect);
	DetourTransactionCommit();*/
	/*

	HOOKAPI IntRectHook[2];
	IntRectHook[0].szFunc = "IntersectRect";
	IntRectHook[0].pNewProc = (PROC)ZSIntersectRect;
	HookAPIByName(GetModuleHandle("MapleStory.exe"), "User32.dll", &IntRectHook[0]);*/

	//CAPIHook::CAPIHook("User32.dll", "IntersectRect", (PROC)ZSIntersectRect);

	//IntersectAddress = (fIntersectRect) GetProcAddress(GetModuleHandle("User32.dll"), "IntersectRect");
	//IntersectTrampoline = (fIntersectRect) DetourFunction((PBYTE)IntersectAddress, (PBYTE)ZSIntersectRect);
	Msg(_GetFunction);
	return true;
}
