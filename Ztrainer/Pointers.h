#include <Windows.h>
#pragma once


namespace Character //8100
{
	static DWORD Base;					// A1 ? ? ? ? 85 C0 75 ? 5F C3 8D 48 04
	

	namespace Offset 
	{
		static DWORD
			X,							// 89 8E ?? ?? ?? ?? 8B 50 ?? 8B 06 89 96 ?? ?? ?? ?? 8B 50
			Y,							// X + 4
			Teleport,					// OUTDATD 83 BE ? ? 00 00 00 89 44 ? ? 0F 84
			TeleportX,					// 8B 8E ? ? 00 00 51 6A 00 ? ? FF D2 8B ? ? ? 00 00 8D BE ? ? ? ? 8D ? ? 50 8B
			TeleportY,					// TeleportX + 4
			Breath,						// 83 B8 ?? ?? ?? ?? 00 7E ?? 6A 00 6A 00 6A 00 6A 00
			Attack;						// 89 ?? ?? ?? ?? 00 C7 ?? ?? ?? ?? 00 ?? ?? ?? 00 8D ?? ?? ?? ?? 00 C6		
	};

	namespace AOB 
	{
		static char
			Base[15] = "\xA1\x00\x00\x00\x00\x85\xC0\x75\x00\x5F\xC3\x8D\x48\x04",
			X[20] = "\x89\x8E\x00\x00\x00\x00\x8B\x50\x00\x8B\x06\x89\x96\x00\x00\x00\x00\x8B\x50",
			Teleport[31] = "\x83\xBE\x00\x00\x00\x00\x00\x89\x44\x00\x00\x0F\x84",
			TeleportX[31] = "\x8B\x8E\x00\x00\x00\x00\x51\x6A\x00\x00\x00\xFF\xD2\x8B\x00\x00\x00\x00\x00\x8D\xBE\x00\x00\x00\x00\x8D\x00\x00\x50\x8B",
			TeleportY, // TeleX+4
			Breath[18] = "\x83\xB8\x00\x00\x00\x00\x00\x7E\x00\x6A\x00\x6A\x00\x6A\x00\x6A\x00",
			Attack[24] = "\x89\x00\x00\x00\x00\x00\xC7\x00\x00\x00\x00\x00\x00\x00\x00\x00\x8D\x00\x00\x00\x00\x00\xC6";
		};

		namespace Mask
		{
			static char* Base = "x????xxx?xxxxx";
			static char* X = "xx????xx?xxxx????xx";
			static char* Teleport = "xx??xxxxx??xx";
			static char* TeleportX = "xx??xxxxx??xxx???xxxx????x??xx";
			static char* Breath = "xx????xx?xxxxxxxx";
			static char* Attack = "x????xx????x???xx????xx";
		};
};

namespace Server
{
	static DWORD Base; //8B 2D ?? ?? ?? ?? A1 ?? ?? ?? ?? 8D ?? 24 ?? ?? 8B

	namespace Offset
	{
		static DWORD
			Server, // 8B 8F ?? ?? 00 00 8B ?? 51 50 6A ?? 8B ?? C7 ?? 24 ?? 01
			Channel; // Server + 8
	};

	namespace AOB
	{
		static char
			Base[18] = "\x8B\x2D\x00\x00\x00\x00\xA1\x00\x00\x00\x00\x8D\x00\x24\x00\x00\x8B",
			Server[20] = "\x8B\x8F\x00\x00\x00\x00\x8B\x00\x51\x50\x6A\x00\x8B\x00\xC7\x00\x24\x00\x01";
	};

	namespace Mask
	{
		static char* Base = "xx????x????x?x??x";
		static char* Server = "xx??xxx?xxx?x?x?x?x";
	};
};

namespace Mouse
{
	static DWORD Base; //8B 0D ?? ?? ?? ?? 74 12 83 B9 ?? ?? ?? ?? ?? 74 09 6A ?? 6A ?? E8

	namespace Offset
	{
		static DWORD
			BaseOff, //8B ?? ?? ?? ?? ?? 85 ?? 75 ?? 68 ?? ?? ?? ?? E8 ?? ?? ?? 00 8B ?? 24 ?? 8B ?? 8B ?? ?? ?? ?? ?? F7
			Animation, // 89 8f ? ? ? ? 8b 8f ? ? ? ? 83 bc 8f
			X, // 8B 88 ? ? ? ? 6A FF 57 83 C5 FE 55
			Y; // 8D 88 ? ? ? ? 3B F1 75 ? 8B 0D ? ? ? ? E8
	};

	namespace AOB
	{
		static char
			Base[23] = "\x8B\x0D\x00\x00\x00\x00\x74\x12\x83\xB9\x00\x00\x00\x00\x00\x74\x09\x6A\x00\x6A\x00\xE8",
			BaseOff[34]= "\x8B\x00\x00\x00\x00\x00\x85\x00\x75\x00\x68\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\x00\x24\x00\x8B\x00\x8B\x00\x00\x00\x00\x00\xF7",
			Animation[16] = "\x89\x8F\x00\x00\x00\x00\x8B\x8F\x00\x00\x00\x00\x83\xBC\x8F",
			X[14] = "\x8B\x88\x00\x00\x00\x00\x6A\xFF\x57\x83\xC5\xFE\x55",
			Y[18] = "\x8D\x88\x00\x00\x00\x00\x3B\xF1\x75\x00\x8B\x0D\x00\x00\x00\x00\xE8";
	};

	namespace Mask
	{
		static char* Base = "xx????xxxx?????xxx?x?x";
		static char* BaseOff="x?????x?x?x????x???xx?x?x?x?????x";
		static char* Animation = "xx????xx????xxx";
		static char* X = "xx????xxxxxxx";
		static char* Y = "xx????xxx?xx????x";
	};
};

namespace Info
{
	static DWORD Base; //8B 15 ?? ?? ?? ?? 8B 4A ?? 8D 0C 89

	namespace Offset
	{
		static DWORD 
			HPAlert, // 8b ? ? 8d ? ? 85 c9 ? ? 8b 7d 
			MPAlert; //HP Alert + 4
	};

	namespace AOB
	{
		static char
			Base[13] = "\x8B\x15\x00\x00\x00\x00\x8B\x4A\x00\x8D\x0C\x89",
			HPAlert[13] = "\x8B\x00\x00\x8D\x00\x00\x85\xC9\x00\x00\x8B\x7D";
	};

	namespace Mask
	{
		static char* Base = "xx????xx?xxx";
		static char* HPAlert = "x??x??xx??xx";
	};
};

namespace Stat
{
	static DWORD Base; //8B ?? ?? ?? ?? ?? 56 E8 ?? ?? ?? ?? C7 ?? ?? ?? FF FF FF FF 3B ?? 74 ?? 83 ?? ?? 56 E8

	namespace Offset
	{
		static DWORD
			HP, // 89 8E ?? ?? 00 00 80 BE ?? ?? 00 00 00 75 
			MP,
			EXP; //DD 9E ?? ?? ?? ?? 66 89 ?? 24 ?? 89 ?? 24
	};

	namespace AOB
	{
		static char
			Base[31] = "\x8B\x00\x00\x00\x00\x00\x56\xE8\x00\x00\x00\x00\xC7\x00\x00\x00\xFF\xFF\xFF\xFF\x3B\x00\x74\x00\x83\x00\x00\x56\xE8",
			HP[16] = "\x89\x8E\x00\x00\x00\x00\x80\xBE\x00\x00\x00\x00\x00\x75",
			MP,
			EXP[16] = "\xDD\x9E\x00\x00\x00\x00\x66\x89\x00\x24\x00\x89\x00\x24";
	};

	namespace Mask
	{
		static char* Base = "x?????xx????x???xxxxx?x?x??xx";
		static char* HP = "xx??xxxx??xxxx";
		static char* MP = "";
		static char* EXP = "xx????xx?x?x?x";
	};
};

namespace Map
{
	static DWORD Base;
	 //A1 ? ? ? ? 85 C0 74 ? 8B ? ? ? 00 00 8B ? 89


	namespace Offset
	{
		static DWORD ID;
	// 80 ? ? ? 00 00 00 0F 84 ? ? ? ? 8B ? 24 ? 8B
		static DWORD CharX,NPC;
		// 8B 8F ?? ?? 00 00 ?? E8 ?? ?? FF FF ?? ?? ?? C2
	};

	namespace AOB
	{
		static char
			Base[19] = "\xA1\x00\x00\x00\x00\x85\xC0\x74\x00\x8B\x00\x00\x00\x00\x00\x8B\x00\x89",
			ID[19] = "\x80\x00\x00\x00\x00\x00\x00\x0F\x84\x00\x00\x00\x00\x8B\x00\x24\x00\x8B",
			CharX[17] = "\x8B\x8F\x00\x00\x00\x00\x00\xE8\x00\x00\xFF\xFF\x00\x00\x00\xC2",
		//Back AOB
			bBase[31] = "\x8B\x00\x00\x00\x00\x00\x50\x51\x8B\x0D\x00\x00\x00\x00\x8D\x00\x00\x00\x52\xC6\x84\x00\x00\x00\x00\x00\x03\xE8\x00\x00";
	};

	namespace Mask
	{
		static char* Base = "x????xxx?x???xxx?x";
		static char* ID = "x???xxxxx????x?x?x";
		static char* CharX = "xx??xx?x??xx???x";

		//Back Mask
		static char* bBase = "x?????xxxx????x???xxx?????xx??";
	};
};

namespace People
{
	static DWORD Base; //8B ? ? ? ? ? 50 E8 ? ? ? ? ? ? ? ? 0F 84 ? ? ? ? 39 ? ? ? ? ? 0F 85
	
	namespace Offset
	{
		static DWORD Count = 0x18; //8B 76 ? 85 F6 7C ? 83 FE 03 7D ? 8B
	};

	namespace AOB
	{
		static char
			Base[31] = "\x8B\x00\x00\x00\x00\x00\x50\xE8\x00\x00\x00\x00\x00\x00\x00\x00\x0F\x84\x00\x00\x00\x00\x39\x00\x00\x00\x00\x00\x0F\x85",
			Count[14] = "\x8B\x76\x00\x85\xF6\x7C\x00\x83\xFE\x03\x7D\x00\x8B";
	};

	namespace Mask
	{
		static char* Base = "x?????xx????????xx????x?????xx";
		static char* Count = "xx?xxx?xxxx?x";
	};
};

namespace MiniMap
{
	static DWORD Base; //a1 ? ? ? ? 85 ? 74 ? 8b 53 ? 8b

	namespace Offset
	{
		static DWORD 
			X, //89 86 ? ? ? ? 8b ? 8b 52 ? 8d
			Y; // X+4
	};

	namespace AOB
	{
		static char
			Base[14] = "\xA1\x00\x00\x00\x00\x85\x00\x74\x00\x8B\x53\x00\x8B",
			X[13] = "\x89\x86\x00\x00\x00\x00\x8B\x00\x8B\x52\x00\x8D";
	};

	namespace Mask
	{
		static char* Base = "x????x?x?xx?x";
		static char* X = "xx????x?xx?x";
	};
};

namespace Item
{
	static DWORD Base; //89 3D ? ? ? ? 8D 4E ? C7
	static DWORD Hook; //85 C0 75 4E 8D 4C ? ? C7 44 24 44 ? ? ? ? E8 // 85 C0 75 4E 8D 4C 24 24 C7 44 24 44 FF FF FF FF
	static DWORD HookRet;

	namespace Offset
	{
		static DWORD
			Count = 0x14;
	};

	namespace AOB
	{
		static char 
			Base[11] = "\x89\x3D\x00\x00\x00\x00\x8D\x4E\x00\xC7",
			Hook[18] = "\x85\xC0\x75\x4E\x8D\x4C\x00\x00\xC7\x44\x24\x44\x00\x00\x00\x00\xE8";
	};

	namespace Mask
	{
		static char* Base = "xx????xx?x";
		static char* Hook = "xxxxxx??xxxx????x";
	};
};

namespace Wall
{
	static DWORD Base; //8B ? ? ? ? ? 8B ? ? 8B ? ? ? ? ? 85 C0 74 ? 8B ? ? 48 ? ? 76 ? 6A ? ?
	
	namespace Offset
	{
		static DWORD
			Left = 0x1C, //8B ? ? ? 50 E8 ? ? ? ? ? ? 75 ? 8B 44 ? ? C7 40 ? 00 00 00 00 ? ? ? 0F 82
			Top = Left + 4, //8B ? ? ? 89 44 ? ? ? ? 72 ? 89 ? ? ? 8B ? ? ? ? ? ? 8B ? 8B 50 ? 8D ?
			Right = Left + 8, //8B ? ? ? 89 84 ? ? ? ? ? 0F 85 ? ? ? ? ? ? 0F 85 ? ? ? ? 33 C0 E9 ? ?
			Bottom = Left + 12; //8B ? ? ? 8B 94 ? ? ? ? ? 50 83 ? ? 51 6A ? 51 8B ? 89 ? 8B 84 ? ? ? ? ?
	};

	namespace AOB
	{
		static char
			Base[31] = "\x8B\x00\x00\x00\x00\x00\x8B\x00\x00\x8B\x00\x00\x00\x00\x00\x85\xC0\x74\x00\x8B\x00\x00\x48\x00\x00\x76\x00\x6A\x00\x00",
			Left[31] = "\x8B\x00\x00\x00\x50\xE8\x00\x00\x00\x00\x00\x00\x75\x00\x8B\x44\x00\x00\xC7\x40\x00\x00\x00\x00\x00\x00\x00\x00\x0F\x82",
			Right[31] = "\x8B\x00\x00\x00\x89\x44\x00\x00\x00\x00\x72\x00\x89\x00\x00\x00\x8B\x00\x00\x00\x00\x00\x00\x8B\x00\x8B\x50\x00\x8D\x00",
			Top[31] = "\x8B\x00\x00\x00\x89\x84\x00\x00\x00\x00\x00\x0F\x85\x00\x00\x00\x00\x00\x00\x0F\x85\x00\x00\x00\x00\x33\xC0\xE9\x00\x00",
			Bottom[31] = "\x8B\x00\x00\x00\x8B\x94\x00\x00\x00\x00\x00\x50\x83\x00\x00\x51\x6A\x00\x51\x8B\x00\x89\x00\x8B\x84\x00\x00\x00\x00\x00";
	};

	namespace Mask
	{
		static char* Base = "x?????x??x?????xxx?x??x??x?x??";
		static char* Left = "x???xx??????x?xx??xx?xxxx???xx";
		static char* Right = "x???xx????x?x???x??????x?xx?x?";
		static char* Top = "x???xx?????xx??????xx????xxx??";
		static char* Bottom = "x???xx?????xx??xx?xx?x?xx?????";
	};
};