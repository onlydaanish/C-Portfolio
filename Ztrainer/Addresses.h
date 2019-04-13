#include <Windows.h>
#pragma once
#define PhsyGmode 0x0072DC16 //85 ? ? ? 8D ? ? ? C7 ? ? ? ? ? ? ? E8 ? ? ? ? 33 ? 39

// Intersect Rect Info
namespace GodMode
{
	static DWORD Addy = NULL;
	static DWORD Return = NULL;
	static bool Status = false;
	static BYTE Disable[5] = {0x8B, 0xFF, 0x55, 0x8B, 0xEC};
};
//
namespace CLI_SetNumberValue
{
	static DWORD Addy = NULL; //8B ? ? 8B ? 8B ? ? ? ? ? ? ? ? ? 8B ? ? 8B ? ? ? ? ? ? ? 74
	static DWORD Return = NULL;
	static char AOB[28] = "\x8B\x00\x00\x8B\x00\x8B\x00\x00\x00\x00\x00\x00\x00\x00\x00\x8B\x00\x00\x8B\x00\x00\x00\x00\x00\x00\x00\x74";
	static char* Mask = "x??x?x?????????x??x???????x";
};

//9100
namespace Pic
{
	static DWORD Addyf = NULL; //56 8B F1 83 ? ? ? 00 00 00 57 8B ? 24 ? 74 ? 57 E8 ? ? ? ? 83 ? ? 85 C0 75
	static DWORD Addyfs = NULL; ////53 55 56 8B F1 57 8D ? ? E8 ? ? ? ? 8D ? ? 8B CD E8 ? ? ? ? 8B ? 24 ? 85 FF
	static DWORD Addys = NULL; // 74 ? 8B ? 24 ? C7 ? 24 ? FF FF FF FF 3B ? 74 ? 83 ? ? 50 EB ? 8B ? 24 ? 3B
	static DWORD Return = NULL;
	static char AOBf[30] = "\x56\x8B\xF1\x83\x00\x00\x00\x00\x00\x00\x57\x8B\x00\x24\x00\x74\x00\x57\xE8\x00\x00\x00\x00\x83\x00\x00\x85\xC0\x75";
	static char AOBfx[31] = "\x53\x55\x56\x8B\xF1\x57\x8D\x00\x00\xE8\x00\x00\x00\x00\x8D\x00\x00\x8B\xCD\xE8\x00\x00\x00\x00\x8B\x00\x24\x00\x85\xFF";
	static char AOBs[30] = "\x74\x00\x8B\x00\x24\x00\xC7\x00\x24\x00\xFF\xFF\xFF\xFF\x3B\x00\x74\x00\x83\x00\x00\x50\xEB\x00\x8B\x00\x24\x00\x3B";
	static char* Mask = "xxxx???xxxxx?x?x?xx????x??xxx";
	static char* Maskfs = "xxxxxxx??x????x??xxx????x?x?xx";
	static char* Masks ="x?x?x?x?x?xxxxx?x?x??xx?x?x?x";
	static BYTE Disables[1] = {0x74}, Enables[1] = {0xEB};
	static BYTE Disablef[20];
	static bool status = false;
};

namespace LogoSkip
{
	static DWORD Addy = NULL; //74 19 2B F8 81 FF DC 05 00 00 0F 86 ?? ?? 00 00 5F 88 5E ?? C6 46 ?? 00 5E 5B C3  
	static char AOB[28] = "\x74\x19\x2B\xF8\x81\xFF\xDC\x05\x00\x00\x0F\x86\x00\x00\x00\x00\x5F\x88\x5E\x00\xC6\x46\x00\x00\x5E\x5B\xC3";
	static char* Mask = "xxxxxxxxxxxx??xxxxx?xx?xxxx";
	static BYTE Enable[1] = { 0x75 };
	static BYTE Disable[1] = { 0x74 };
	static bool Status = false;
};

//9200
namespace Kami
{
	static DWORD Addy; //8B ? ? ? 00 00 85 C0 74 ? 83 ? ? 74 ? 83 ? ? C3 33 C0 C3 CC CC CC CC CC CC CC CC CC CC 8B ? 24 ? 56 50 8B ? E8
	static DWORD TeleAddy; //8B ? ? ? 8B ? ? 8B ? ? 56 8D ? ? 8B ? ? ? 51 52 56 FF ? 85 ? 7D ? 68 ? ? ? ? 56 50 E8 ? ? ? ? 5E C2 [1st Result]
	static char AddyAOB[42] = "\x8B\x00\x00\x00\x00\x00\x85\xC0\x74\x00\x83\x00\x00\x74\x00\x83\x00\x00\xC3\x33\xC0\xC3\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\x8B\x00\x24\x00\x56\x50\x8B\x00\xE8";
	static char TeleAddyAob[42] = "\x8B\x00\x00\x00\x8B\x00\x00\x8B\x00\x00\x56\x8D\x00\x00\x8B\x00\x00\x00\x51\x52\x56\xFF\x00\x85\x00\x7D\x00\x68\x00\x00\x00\x00\x56\x50\xE8\x00\x00\x00\x00\x5E\xC2";
	static char* addyMask = "x???xxxxx?x??x?x??xxxxxxxxxxxxxxx?x?xxx?x";
	static char* TeleMask = "x???x??x??xx??x???xxxx?x?x?x????xxx????xx";
	static bool Status = false;
	static BYTE CleanKami[25];
}

namespace ItemFilter
{
	static DWORD Addy, FilterReturn; //8B ? 89 ? ? E8 ? ? ? ? 8B ? 89 ? ? E8 ? ? ? ? 0F ? ? 89 ? ? 8B ? E8 ? ? ? ? 0F
	static char FilterAOB[35] = "\x8B\x00\x89\x00\x00\xE8\x00\x00\x00\x00\x8B\x00\x89\x00\x00\xE8\x00\x00\x00\x00\x0F\x00\x00\x89\x00\x00\x8B\x00\xE8\x00\x00\x00\x00\x0F";
	static char* FilterMask = "x?x??x????x?x??x????x??x??x?x????x";
	static bool Status = false;
	static BYTE CleanFilter[25];
}