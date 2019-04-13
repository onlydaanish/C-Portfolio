#include "Global.h"
//Why do we have this file as a .cpp file?

//***************************************************//
//					 HackShield						//
//**************************************************//
extern bool fHSAddy1 = true, fHSAddy2 = true;

/*Handles*/
extern HWND Gui = NULL;
extern DWORD MaplePID = NULL;
extern DWORD HackShieldPID = NULL;
extern char dllPath[MAX_PATH] = {'\0'};
extern HANDLE MapleHandle = NULL;
extern HANDLE HSHandle = NULL;
extern HWND hParent = NULL;
extern HWND MapleHWND = NULL;
extern HWND eMapleHWND = NULL;
extern HMODULE hMaple = NULL;
extern DWORD Respond = NULL;
extern LRESULT Result = NULL;
extern HWND MsgWnd = NULL;
extern HANDLE StartThread = NULL;
extern HANDLE Checker = NULL;
extern HANDLE LoginChecker = NULL;
extern HANDLE MiniMapHandle = NULL;

/*Number of Worlds*/
extern int TotalWorlds = 16;

/*Directories*/
extern std::string MapleDir = "";
extern char MapleDirBuf[50] = {0};
extern LPCSTR sPath = "";
extern LPCTSTR CurrentDir = "";

/*Wait*/
extern char WaitTimeBuf[10] = {0};
extern int WaitTime = 60;
extern int MSWaitTime = 0;

/*Embeding*/
extern char EmbededBuffer[5] = {0};
extern std::string sEmbeded = "";
extern bool Embeded = false;
extern bool MapleHidden = false;

/*Hiding Buffers*/
extern char HiddenBuffer[5] = {0};
extern std::string sHidden = "";

// Profile //
extern char Name[50] = "";
extern LPCSTR ProfName = "";
extern bool ProfileLoaded = false;

// Crash //
extern bool Crashed = false;
extern bool MapleOpen = false;
extern bool LoggedIn = false;
extern bool Starting = false;

// Message Bools // 
extern bool CipherBypassed = true; 
extern bool CRCBypassed = true;
extern bool HSBypassed = true;
extern bool Updated = false;
extern bool FunctionFound = false;

//Map Info//
extern int CurMap = NULL, CurMap2 = NULL;
