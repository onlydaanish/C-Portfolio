#include "Global.h"
#include "Functions.h"
#include "Pointers.h"

int MaxHpp = 0, MaxMpp = 0;

bool UpdateAddys()
{
	
	//***************************************************//
	//					  Pointers						//
	//**************************************************//	

	//Mini Map // Its Crucial This is Found before to Have a Backup for X,Y Coords
	/*MiniMap::Base = Search(_MiniMapBase, MiniMap::AOB::Base, MiniMap::Mask::Base, 1, true);
	MiniMap::Offset::X = Search(_MiniMapX, MiniMap::AOB::X, MiniMap::Mask::X, 2, true);
	if (MiniMap::Offset::X != Bad)
	MiniMap::Offset::Y = MiniMap::Offset::X + 4;*/

	//Character Addys
	Character::Base = Search(_CharacterBase, Character::AOB::Base, Character::Mask::Base, 1, true);
	cBase = Character::Base;

	Character::Offset::Breath = Search(_BreathOffset, Character::AOB::Breath, Character::Mask::Breath, 2, true);

	Character::Offset::Attack = Search(_AttackOffset, Character::AOB::Attack, Character::Mask::Attack, 2, true);
	Character::Mask::Attack -= 10;

	// Mouse Addys
	Mouse::Base = Search(_MouseBase, Mouse::AOB::Base, Mouse::Mask::Base, 2, true);
	//Mouse::Offset::BaseOff = Search(_MouseOff, Mouse::AOB::BaseOff, Mouse::Mask::BaseOff, 2, true);
	Mouse::Offset::Animation = *(DWORD*)(Mouse::Base + 8); 
	//Search(_AnimationOffset, Mouse::AOB::Animation, Mouse::Mask::Animation, 2, true);
	Mouse::Offset::X = Search(_mXOffset, Mouse::AOB::X, Mouse::Mask::X, 2, true);
	Mouse::Offset::Y = Mouse::Offset::X + 4;

	//Server Addys
	Server::Base = Search(_ServerBase, Server::AOB::Base, Server::Mask::Base, 2, true);
	Server::Offset::Server = Search(_ServerOffset, Server::AOB::Server, Server::Mask::Server, 2, true);
	if (Server::Offset::Server != Bad)
	Server::Offset::Channel = Server::Offset::Server + 8;

	//Info Addys
	Info::Base = Search(_InfoBase, Info::AOB::Base, Info::Mask::Base, 2, true);
	Info::Offset::HPAlert = 0x58;
	if (Info::Offset::HPAlert != Bad)
	Info::Offset::MPAlert = Info::Offset::HPAlert + 4;

	//Stat Addys
	Stat::Base = Search(_StatBase, Stat::AOB::Base, Stat::Mask::Base, 2, true);
	Stat::Offset::HP = Search(_HPOffset, Stat::AOB::HP, Stat::Mask::HP, 2, true);
	if (Stat::Offset::HP != Bad)
	Stat::Offset::MP = Stat::Offset::HP + 4;
	Stat::Offset::EXP = Search(_EXPOffset, Stat::AOB::EXP, Stat::Mask::EXP, 2, true);
	
	//Map
	Map::Base = Search(_MapBase, Map::AOB::Base, Map::Mask::Base, 1, true);
	if (Map::Base != Bad)
	{
		Map::Offset::ID = Search(_MapOffset, Map::AOB::ID, Map::Mask::ID, 2, true);
		Map::Offset::CharX = Search(_MapOffset, Map::AOB::CharX, Map::Mask::CharX,2,true);
		Map::Offset::NPC = Map::Offset::CharX + 38;
	}

	//People
	People::Base = Search(_PeopleBase, People::AOB::Base, People::Mask::Base, 2, true);
	//People::Offset::Count = Search(_PeopleOffset, People::AOB::Count, People::Mask::Count, 2, true);
	
	//Item
	Item::Base = Search(_ItemBase, Item::AOB::Base, Item::Mask::Base, 1, true);
	//Item::Hook = Search(_ItemHook, Item::AOB::Hook, Item::Mask::Hook, 0, true);
	if (Item::Hook != Bad)
	Item::HookRet = GetPointedAddress((ULONG_PTR*)ReadPointer((ULONG_PTR*)Item::Hook, 2), 0);

	//Wall
	Wall::Base = Search(_WallBase, Wall::AOB::Base, Wall::Mask::Base, 2, true);
	Wall::Offset::Left = 0xC;//Search(_WallLeft, Wall::AOB::Left, Wall::Mask::Left, 3, true);
	Wall::Offset::Right = Wall::Offset::Left + 4;//Search(_WallRight, Wall::AOB::Right, Wall::Mask::Right, 3, true);
	Wall::Offset::Top = Wall::Offset::Left + 8;//Search(_WallTop, Wall::AOB::Top, Wall::Mask::Top, 3, true);
	Wall::Offset::Bottom = Wall::Offset::Left + 12;//Search(_WallBottom, Wall::AOB::Bottom, Wall::Mask::Bottom, 3, true);

	if ( CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ReadPointers, 0, 0, NULL) == NULL)
	Msg(_ReadPointer);

	if ( CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)UpdateHacks, 0, 0, NULL) == NULL)
	Msg(_UpdateHacks);

	if (CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)UpdateMobStruct, 0, 0, NULL) == NULL)
	Msg(_UpdateHacks);


	return true;
}

bool ReadPointers()
{
	for (;;)
	{
		if (Character::Base != Bad)
		{
			if (Character::Offset::Breath != Bad)
			{
				Breath = ReadPointer((ULONG_PTR*)Character::Base, Character::Offset::Breath);
				WritePrivateProfileString("Char", "Breath", sToLPCSTR(Breath.ToString()), CurrentDir);
			}
			if (Character::Offset::Attack != Bad)
			{
				Attacks = ReadPointer((ULONG_PTR*)Character::Base, Character::Offset::Attack);
				WritePrivateProfileString("Char", "Attack", sToLPCSTR(Attacks.ToString()), CurrentDir);
			}

		}

		if (Mouse::Base != Bad)
		{
			if (Mouse::Offset::X != Bad)
			{
				MouseX = ReadPointer((ULONG_PTR*)Mouse::Base, Mouse::Offset::X);
				WritePrivateProfileString("Mouse", "X", sToLPCSTR(MouseX.ToString()), CurrentDir);
			}

			if (Mouse::Offset::X != Bad)
			{
				MouseY = ReadPointer((ULONG_PTR*)Mouse::Base, Mouse::Offset::Y);
				WritePrivateProfileString("Mouse", "Y", sToLPCSTR(MouseY.ToString()), CurrentDir);
			
			}
		}

		if (Server::Base != Bad)
		{
			if (Server::Offset::Server != Bad)
			{
				World = ReadPointer((ULONG_PTR*)Server::Base, Server::Offset::Server);
				WritePrivateProfileString("Server", "World", sToLPCSTR(World.ToString()), CurrentDir);

				Channel = ReadPointer((ULONG_PTR*)Server::Base, Server::Offset::Channel);
				WritePrivateProfileString("Server", "Channel", sToLPCSTR(Channel.ToString()), CurrentDir);
			}
		}

		if (Stat::Base != Bad && !StatHooked)
		{
			if (Stat::Offset::HP != Bad)
			{
				HP = ReadPointer((ULONG_PTR*)Stat::Base , Stat::Offset::HP);

				WritePrivateProfileString("Char", "Hp", sToLPCSTR(HP.ToString()), CurrentDir);

				if (HP > MaxHP && (HP < 999999))
				{
					MaxHP = HP;
					WritePrivateProfileString("Char", "MaxHp", sToLPCSTR(MaxHP.ToString()), CurrentDir);
				}
			}
			if (Stat::Offset::MP != Bad)
			{
				MP = ReadPointer((ULONG_PTR*)Stat::Base , Stat::Offset::MP);

				WritePrivateProfileString("Char", "Mp", sToLPCSTR(MP.ToString()), CurrentDir);

				if ((MP > MaxMP) && (MP < 999999))
				{
					MaxMP = MP;
					WritePrivateProfileString("Char", "MaxMp", sToLPCSTR(MaxMP.ToString()), CurrentDir);
				}
			}
			if (Stat::Offset::EXP != Bad)
			{
				EXP = ReadDouble((ULONG_PTR*)Stat::Base , Stat::Offset::EXP);
				WritePrivateProfileString("Char", "Exp", sToLPCSTR(EXP.ToString("f2")), CurrentDir);
			}
		}

		if (Map::Base != Bad && Map::Offset::ID != Bad)
		{
			MapID = ReadPointer((ULONG_PTR*)Map::Base, Map::Offset::ID);
			WritePrivateProfileString("Map", "ID", sToLPCSTR(MapID.ToString()), CurrentDir);
		}
		if (Map::Base != Bad && Map::Offset::CharX != Bad)
		{
			NPC = ReadPointer((ULONG_PTR*)Map::Base, Map::Offset::NPC);
			WritePrivateProfileString("Map", "NPC", sToLPCSTR(NPC.ToString()), CurrentDir);
		}

		if (Map::Base != Bad && Map::Offset::CharX != Bad)
		{
			CharX = ReadPointer((ULONG_PTR*)Map::Base, Map::Offset::CharX);
			CharY = ReadPointer((ULONG_PTR*)Map::Base, (Map::Offset::CharX + 4));

			WritePrivateProfileString("Char", "X", sToLPCSTR(CharX.ToString()), CurrentDir);
			WritePrivateProfileString("Char", "Y", sToLPCSTR(CharY.ToString()), CurrentDir);
		}

		if (Info::Base != Bad && Info::Offset::HPAlert != Bad)
		{
			HPAlert = ReadPointer((ULONG_PTR*)Info::Base, Info::Offset::HPAlert);
			WritePrivateProfileString("Alert", "HP", sToLPCSTR(HPAlert.ToString()), CurrentDir);
		}

		if (People::Base != Bad && People::Offset::Count != Bad)
		{
			PeopleCount = ReadPointer((ULONG_PTR*)People::Base, People::Offset::Count);
			WritePrivateProfileString("People", "Count", sToLPCSTR(PeopleCount.ToString()), CurrentDir);
		}

		if (Item::Base != Bad)
		{
			Items = ReadPointer((ULONG_PTR*)Item::Base, Item::Offset::Count);
			WritePrivateProfileString("Item", "Count", sToLPCSTR(Items.ToString()), CurrentDir);
		}

		if (Wall::Base != Bad)
		{
			if (Wall::Offset::Left != Bad)
			{
				WallLeft = ReadPointer((ULONG_PTR*)Wall::Base, Wall::Offset::Left);

				WallRight = ReadPointer((ULONG_PTR*)Wall::Base, Wall::Offset::Right);

				WallTop = ReadPointer((ULONG_PTR*)Wall::Base, Wall::Offset::Top);

				WallBottom = ReadPointer((ULONG_PTR*)Wall::Base, Wall::Offset::Bottom);

				MapX = WallRight + (WallLeft * (-1));
				MapY = WallBottom + (WallTop * (-1));
			}
			if (Wall::Offset::Left != Bad && Wall::Offset::Right != Bad)
			MapX = WallRight + (WallLeft * (-1));

			if (Wall::Offset::Top != Bad && Wall::Offset::Bottom != Bad)
			MapY = WallBottom + (WallTop * (-1));
		}
		//End
		Sleep(50);
	}
	return true;
}