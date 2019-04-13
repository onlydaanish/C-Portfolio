#include <Windows.h>
#include <string>
#include <WinInet.h>
#include <Messages.h>
#include <Character.h>
#include <vector>
#include <string>
#include <xstring>
#include <OAIdl.h>
#include <iostream>
#include <stdio.h>
#include <psapi.h>
#include <tchar.h>
#include <sapi53.h>
#include <Tlhelp32.h>
#include "sKey.h"

#pragma once

#pragma comment(lib, "psapi.lib")
#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "MsHackLib.lib")
#define SERVER_CHECK //Automatically check if servers are online/offline (See GUI.cpp-ServerCheck().)
#define DLL_CHECK
//#define BYPASS
//#define HSBypass
//#define _LOGIN

using namespace System::Drawing;

static CSendKeys Sk;
static HKEY key, skey;
static RECT MapleRect;

/* Identifiers */
bool StartMaple();
bool LoadProfile(LPCTSTR Profile);
bool CreateDefault(LPCSTR Name);
bool EmbedMaple(bool x);
void HideMaple();
void ShowMaple();
void MSCheck();
bool Login();
void ReadPointers();
void zLog(System::String^ msg);
bool CheckLogin();
void Reset();
bool StartupHacks();

//***************************************************//
//					 HackShield						//
//**************************************************//
extern bool fHSAddy1, fHSAddy2;

/*Handles*/
extern HWND Gui;
extern DWORD MaplePID; // Maple PID
extern DWORD HackShieldPID;
extern char dllPath[MAX_PATH];
extern HANDLE MapleHandle; // Maple Process Handle
extern HANDLE HSHandle; //HS Process Handle
extern HWND MapleHWND; //MapleStory Handle
extern HWND eMapleHWND; // Maple Embedded Handle
extern HWND hParent; //Handle To the Previous Parent (Desktop)
extern HMODULE hMaple;
extern DWORD Respond;
extern LRESULT Result;
extern HWND MsgWnd;
extern HANDLE StartThread;
extern HANDLE Checker;
extern HANDLE LoginChecker;
extern HANDLE MiniMapHandle;

/*Server Check*/
namespace MapleServer 
{
static CHAR buffer [500];
static DWORD dwRead;
static HWND hwnd;
static HINTERNET hOpen, hFile;
static bool Online = NULL;
};

/*Number of worlds*/
extern int TotalWorlds;

/* Embedding MapleStory Variable's */
extern bool Embeded;
extern bool MapleHidden;

/*Embeding Buffers*/
extern char EmbededBuffer[5];
extern std::string sEmbeded;

/*Hiding Buffers*/
extern char HiddenBuffer[5];
extern std::string sHidden;

/*MapleStory Class*/
static const char *MSClass = "MapleStoryClass";

/*Directories*/
extern std::string MapleDir;
extern char MapleDirBuf[50];
extern LPCSTR sPath;
extern LPCTSTR CurrentDir;

/*Wait*/
extern char WaitTimeBuf[10];
extern int WaitTime;
extern int MSWaitTime;

// Profile Name //
extern char Name[50];
extern LPCSTR ProfName;
extern bool ProfileLoaded;

//Crash //
extern bool Crashed;
extern bool MapleOpen;
extern bool LoggedIn;
extern bool Starting;

//Message Bools // 
extern bool CipherBypassed;
extern bool CRCBypassed;
extern bool HSBypassed;
extern bool Updated;
extern bool FunctionFound;
//Map Info//
extern int CurMap, CurMap2;

