#include "Functions.h"

void __stdcall GetMobCount();
void __stdcall GetMobAddys();
void __stdcall GetMobPool();
void __stdcall MobPoolEven();
void __stdcall MobPoolOdd();

void Teleport(int X, int Y);

namespace MobStruct
{
	static DWORD Base; //8B 0D ? ? ? ? ? E8 ? ? ? ? 8B ? 85 ? 74 ? 8B ? ? 8B ? ? 8D
	static DWORD Start = Bad, LastMobAddy;
	static DWORD XAddy[200], YAddy[200], DeathAddy[200];

	namespace Offset
	{
		static DWORD
			Count = 0x10,
			Main, //89 7E ?? 89 7E ?? ?? ?? ?? ?? ?? 89 46
			Next, //89 7B ? 89 5C 24 ? E8 ? ? ? ? C7 ? ? ? FF FF FF FF 85 FF 74 ? 6A 00 8D ? ? ?
			Second, //83 BE ?? ?? ?? ?? ?? 0F 84 ?? ?? ?? ?? 83 CF ?? 39 BD ?? ?? ?? ?? 0F 8E
			Third = 0x20, // 89 5C ? ? C7 01 ? ? ? ? 89 ? ? 89 ? ? 89 ? ? E8 ? ? ? ? 89 9E ? ? ? ? 89
			X, // 89 ?? ?? 8D ?? ?? 89 ?? 8D ?? ?? 89 ?? 8D
			Y, // X+4
			Death; //89 86 ? ? ? ? 89 86 ? ? ? ? 33 C0 89 86
	};

	namespace AOB
	{
		static char
			Base[26] = "\x8B\x0D\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\x00\x85\x00\x74\x00\x8B\x00\x00\x8B\x00\x00\x8D",
			Main[14] = "\x89\x7E\x00\x89\x7E\x00\x00\x00\x00\x00\x00\x89\x46",
			Next[31] = "\x89\x7B\x00\x89\x00\x24\x00\x0F\x00\xD6",
			Second[25] = "\x83\xBE\x00\x00\x00\x00\x00\x0F\x84\x00\x00\x00\x00\x83\xCF\x00\x39\xBD\x00\x00\x00\x00\x0F\x8E",
			X[15] = "\x89\x00\x00\x8D\x00\x00\x89\x00\x8D\x00\x00\x89\x00\x8D",
			Death[17] = "\x89\x86\x00\x00\x00\x00\x89\x86\x00\x00\x00\x00\x33\xC0\x89\x86";
	};

	namespace Mask
	{
		static char* Base = "xx?????x????x?x?x?x??x??x";
		static char* Main = "xx?xx??????xx";
		static char* Next = "xx?x?x?x?x";
		static char* Second = "xx?????xx????xx?xx????xx";
		static char* Third = "xx?????xx????xx?xx????xx";
		static char* X ="8x??x??x?x??x?x";
		static char* Death = "xx????xx????xxxx";
	};
};

struct MobStruct_Info
{
	int MaxMobs;
	HANDLE MobCountThread, MobAddyThread, MobPoolThread, OddThread, EvenThread;
	bool ChoordsFound;

} Mob_Info;

class Monster
{
	private:
			int X,Y,Death; //add other things like health, etc...
	public:
		Monster() {}
		~Monster() {}

		// The Functions to retrieve SPECIFIC Mobs X,Y
		void GetMobChoords(int MobNumber)
		{
			X = ReadVal(MobStruct::XAddy[MobNumber]);
			Y = ReadVal(MobStruct::YAddy[MobNumber]);
			Death = ReadVal(MobStruct::DeathAddy[MobNumber]);
		}

		//Functions to return values, to keep Members private
		int ReturnX()
		{
			return X;
		}

		int ReturnY()
		{
			return Y;
		}

		int ReturnDeath()
		{
			return Death;
		}
};

vector<Monster> MobPool;

RECT GetWalls()
{
	RECT r;

	r.left = WallLeft;
	r.top = WallTop;
	r.right = WallRight;
	r.bottom = WallBottom;

	return r;
}

void Teleport(POINT coord)
{
	RECT walls = GetWalls();
	if (PtInRect(&walls, coord))
	{
		auto GetCVecCtrlUser = reinterpret_cast<void*(__thiscall*)(void*)>(Kami::Addy);
		auto CVecCtrlUser_OnTeleport = reinterpret_cast<void(__thiscall*)(void* lpvEcx, bool bToggle, long x, long y)>(Kami::TeleAddy);

		CVecCtrlUser_OnTeleport(GetCVecCtrlUser(PVOID(*reinterpret_cast<DWORD*>(cBase)+4)), TRUE, coord.x, coord.y);
	}
}

void Teleport(int X, int Y)
{
	POINT p;
	p.x = X;
	p.y = Y;

	Teleport(p);
}