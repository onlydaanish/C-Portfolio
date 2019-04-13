#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include "Global.h"
#include <msclr\marshal.h>

using namespace std;
using namespace System;
using namespace msclr::interop;


#pragma once

static void Press(LPCTSTR keys)
{
	if (!Embeded)
	{
		ShowWindow(MapleHWND, SW_SHOWNORMAL);
		Sk.AppActivate(MapleHWND);
	}
	else
	{
		Sk.AppActivate(eMapleHWND);
	}
	Sk.SendKeys(keys);
}

static Image^ GetMiniMap(int iMapID)
{
	String^ MapId = iMapID.ToString();
	
	System::Net::HttpWebRequest^ wReq = dynamic_cast<System::Net::HttpWebRequest^>(System::Net::WebRequest::Create("http://www.forgottenpassage.org/xmls/Map.wz/Map/Map"+MapId[0]+"/"+MapId+".img/miniMap/canvas.png"));
	System::Net::HttpWebResponse^ wRes = dynamic_cast<System::Net::HttpWebResponse^>(wReq->GetResponse());
	
	if (wRes->ResponseUri->ToString() != "http://www.forgottenpassage.org/images2/noicon.png")
		return Image::FromStream(wRes->GetResponseStream());
	else
		return nullptr;
}

static bool WaitForResponse()
{
	while (Result == NULL && MapleHWND != NULL) //Make sure someone isnt going in a portal causing mapid to be 0
	{
		Result = SendMessageTimeout(MapleHWND, WM_NULL, 0, 0, SMTO_ABORTIFHUNG, 500, &Respond);
		Sleep(100);
	}
	if (MapleHWND != NULL)
	{
		Result = NULL; // Set Result to Null Again
		return true;
	}
	return false;
}

static LPARAM GetL(UINT Key)
{
	return ((MapVirtualKeyA((UINT)Key, 0) << 16) + 1);
}

static void SendKey(UINT Key)
{
	if (MapleOpen)
	{
		if (Embeded)
		{
			PostMessage(eMapleHWND, WM_KEYDOWN, Key, GetL(Key));
			PostMessage(eMapleHWND, WM_KEYUP, Key, GetL(Key));
		}
		else
		{
			PostMessage(MapleHWND, WM_KEYDOWN, Key, GetL(Key));
			PostMessage(MapleHWND, WM_KEYUP, Key, GetL(Key));
		}
	}
}

static void Msg(UINT MESSAGE)
{
	SendMessage(MsgWnd, MESSAGE, 0,0);
}

static bool Wait(__in  DWORD dwMilliseconds)
{
	Sleep(dwMilliseconds);
	return true;
}

static bool InjectDLL(DWORD dwProcessID, char * dllPath)
{
	HANDLE hProcess, hThread;
	LPVOID AllocedMem, LLAAddress;

	SIZE_T pathLength = strlen(dllPath) + 1;

	if ((hProcess = OpenProcess(0x1F0FFF, TRUE, dwProcessID)))

		if (AllocedMem = VirtualAllocEx(hProcess, NULL, pathLength,MEM_COMMIT, PAGE_READWRITE))

			if (WriteProcessMemory(hProcess, AllocedMem, dllPath, pathLength, NULL))
				if (LLAAddress = GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA"))
					if (hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)LLAAddress,AllocedMem, 0, NULL))
					{
						WaitForSingleObject(hThread, INFINITE);
						CloseHandle(hThread);
						VirtualFreeEx(hProcess, LLAAddress, pathLength, MEM_RELEASE);
						return true;
					}
	return false;
}

static HANDLE GetProcessHandle(LPSTR szExeName)
{
  PROCESSENTRY32 Pc = { sizeof(PROCESSENTRY32) };
  HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
  if(Process32First(hSnapshot, &Pc)){
    do{
      if(!strcmp(Pc.szExeFile, szExeName)) {
        return OpenProcess(PROCESS_ALL_ACCESS, TRUE, Pc.th32ProcessID);
      }
    }while(Process32Next(hSnapshot, &Pc));
  }
  return NULL;
}

static DWORD WaitForProcess(char * strProcess)
{
	char buffer[50];
	DWORD pIDs[300], dwNeeded;
	HANDLE hProcess = NULL;
	while (TRUE)
	{
		ZeroMemory(buffer, 50);
		EnumProcesses(pIDs, sizeof(pIDs), &dwNeeded);

		for ( unsigned i = 0; i < dwNeeded / sizeof(DWORD); i++)
		{
			if (GetProcessHandle("MapleStory.exe") != NULL)
			{
				if (pIDs[i] != 0)
				{
					HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, 0, pIDs[i]);
					GetModuleBaseName(hProcess, 0, buffer, 50);
					CloseHandle(hProcess);
					if (strcmp(buffer, strProcess) == 0)
						return pIDs[i];
				}
			}
			else
			{
				return NULL;
			}
		}
		Sleep (200);
	}
}

static bool isProcessRunning(HANDLE process)
{
    return WaitForSingleObject( process, 0 ) == WAIT_TIMEOUT;
}

static int Talk(LPCWSTR x)
{
	ISpVoice * pVoice = NULL;
    HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
	__try
	{
	if( SUCCEEDED( hr ) )
		{		
        hr = pVoice->Speak(x, SPF_IS_XML, NULL);
        pVoice->Release();
		pVoice = NULL;
		return true;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER){} 
	return false;
}

static LPCSTR StringToLPCSTR (System::String ^X)
{
	return (LPCSTR)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(X);
}

static System::String^ LPCSTRToString (LPCSTR X)
{
	return (System::String^)System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)(void*)X);
}

static int numDigits(int number)
{
    int digits = 0;
    if (number < 0)
		digits = 1; // remove this line if '-' counts as a digit
    while (number) 
	{
        number /= 10;
        digits++;
    }
    return digits;
}

static void SetMSSize(int x, int y, int xx, int yy)
{
	if (!Embeded)
		SetWindowPos(MapleHWND, HWND_TOP, x, y, xx, yy, SWP_FRAMECHANGED);
	else
		SetWindowPos(eMapleHWND, HWND_TOP, x, y, xx, yy, SWP_FRAMECHANGED);
}

static void GetMapleSize()
{
	if (!Embeded)
		GetClientRect(MapleHWND, &MapleRect);
	else
		GetClientRect(eMapleHWND, &MapleRect);
}


static void hToggle(System::Windows::Forms::CheckBox^ Box, bool &OnOff, UINT Message, bool &MapleStory)
{
	if (Box->Checked)
	{
		if (!OnOff && MapleStory)
		{
			Msg(Message);
		}
		OnOff = true;
	}
	else
	{
		if (OnOff && MapleStory)
		{
			Msg(Message);
		}
		OnOff = false;
	}
}

static bool is_digits(const std::string &str)
{
	return str.find_first_not_of("0123456789") == std::string::npos;
}