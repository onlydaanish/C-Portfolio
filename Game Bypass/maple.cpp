#include "maple.h"
#include "util.h"
#include <winternl.h>

namespace Maplestory
{
	unsigned char *memoryBackup;
	unsigned int imgStart, imgEnd;

	const unsigned int crcMain = 0x00D53C64; // 8A 11 80 C2 01 //8A ? 80 C2 ? 8B
	const unsigned int crcMainRet = crcMain + 5;
	const unsigned int crcSecondary = 0x012B8336; //? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 8B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 59 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? E9 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? E9
	const unsigned int crcSecondaryRet = crcSecondary + 5;
	const unsigned int crcTertiary = 0x011D9185; //? ? E9 ? ? ? ? ? ? E9 ? ? ? ? ? ? ? ? ? ? ? ? ? ? 8B ? ? ? ? ? ? ? ? ? ? ? E9
	const unsigned int crcTertiaryRet = 0x011C5D9F; // Skip 3 bytes from Trietary Addy
	const unsigned int crcC1 = crcMain - 6;
	const unsigned int crcC2 = crcMain + 5;
	const unsigned int crcC3 = crcSecondary - 4;
	const unsigned int crcC4 = crcSecondary + 8;

	const unsigned int sendStart = 0;	// add these in yourself
	const unsigned int sendEnd = 0;		// because i'm really can't be bothered


	struct SYSTEM_HANDLE_INFORMATION 
	{
		DWORD pid;
		BYTE type;
		BYTE flags;
		WORD handle;
		DWORD object;
		DWORD access;
	};

	typedef struct _OBJECT_NAME_INFORMATION {
		UNICODE_STRING Name;
	} OBJECT_NAME_INFORMATION, *POBJECT_NAME_INFORMATION;

	typedef NTSTATUS (NTAPI *NtQuerySystemInformation_t) (SYSTEM_INFORMATION_CLASS SystemInformationClass, PVOID SystemInformation, ULONG SystemInformationLength, PULONG ReturnLength);
	typedef NTSTATUS (NTAPI *NtQueryObject_t) (HANDLE Handle, OBJECT_INFORMATION_CLASS ObjectInformationClass, PVOID ObjectInformation, ULONG ObjectInformationLength, PULONG ReturnLength);

	LONG WINAPI ExceptionHandler(EXCEPTION_POINTERS *info)
	{
		if (info->ExceptionRecord->ExceptionCode == 0xc0000005)
		{
			TerminateProcess(GetCurrentProcess(), 0);
		}
		return EXCEPTION_CONTINUE_EXECUTION;
	}

	void DisableExceptionOnClose()
	{
		//c0000005
		AddVectoredExceptionHandler(1, &ExceptionHandler);
	}

	bool EnableMultiMS()
	{
		int handleCount = 1024;

		HMODULE ntdll = GetModuleHandle(L"ntdll");
		if (ntdll == NULL)
		{
			Log(L"Couldn't get ntdll handle\n");
			return false;
		}

		NtQueryObject_t ntQO = (NtQueryObject_t)GetProcAddress(ntdll, "NtQueryObject");
		NtQuerySystemInformation_t ntQSI = (NtQuerySystemInformation_t)GetProcAddress(ntdll, "NtQuerySystemInformation");
		if (ntQO == NULL || ntQSI == NULL)
		{
			Log(L"Couldn't find procedures for MultiMS (%x / %x)\n", ntQO, ntQSI);
			return false;
		}

		struct HandleInfoSet
		{
			unsigned int count;
			SYSTEM_HANDLE_INFORMATION handles[1];
		};

		HandleInfoSet *infoSet = (HandleInfoSet *)malloc(4 + sizeof(SYSTEM_HANDLE_INFORMATION) * handleCount);
		DWORD length;

		NTSTATUS status = ntQSI((SYSTEM_INFORMATION_CLASS)16, infoSet, 4 + sizeof(SYSTEM_HANDLE_INFORMATION) * handleCount, &length);

		Log(L"alloc with %i // %i\n", handleCount, handleCount * sizeof(SYSTEM_HANDLE_INFORMATION) + 4);

		while (status == 0xc0000004 /*STATUS_INFO_LENGTH_MISMATCH*/)
		{
			free(infoSet);

			handleCount *= 2;

			Log(L"alloc with %i // %i\n", handleCount, handleCount * sizeof(SYSTEM_HANDLE_INFORMATION) + 4);
			infoSet = (HandleInfoSet *)malloc(4 + sizeof(SYSTEM_HANDLE_INFORMATION) * handleCount);
			status = ntQSI((SYSTEM_INFORMATION_CLASS)16, infoSet, 4 + sizeof(SYSTEM_HANDLE_INFORMATION) * handleCount, &length);
		}

		if (status != 0 /*STATUS_SUCCESS*/)
		{
			Log(L"Failed to enumerate handles open by this process (errorcode %x)\n", status);
			free(infoSet);
			return false;
		}

		for (unsigned int i = 0; i < infoSet->count; i++)
		{
			wchar_t nameBuffer[1024];
			if (infoSet->handles[i].handle == 0x0012019F) continue;	// some buggy thing we need to skip
			status = ntQO((HANDLE)infoSet->handles[i].handle, (OBJECT_INFORMATION_CLASS)1, nameBuffer, 1024, &length);
			if (status != 0 /*STATUS_SUCCESS*/)
				continue;

			if (wcsstr(nameBuffer + 4, L"WvsClientMtx") != NULL)
			{
				HANDLE handle;
				DuplicateHandle(GetCurrentProcess(), (HANDLE)infoSet->handles[i].handle, 0, &handle, 0, FALSE, DUPLICATE_CLOSE_SOURCE);
				CloseHandle(handle);
				Log(L"Mutex closed, MultiMS is ok\n");
				break;
			}
		}

		free(infoSet);
		return true;
	}
	
	void __declspec(naked) crcMainHook()
	{
		_asm
		{
			cmp		ecx, [imgStart]
			jl		nobypass
			cmp		ecx, [imgEnd]
			jg		nobypass
			sub		ecx, imgStart
			add		ecx, memoryBackup

  nobypass:
			mov		dl,	[ecx]
			add		dl, 1
			jmp		crcMainRet
		}
	}

	void __declspec(naked) crcSecondaryHook()
	{
		_asm
        {
            cmp		ebx, [imgStart]
            jl      nobypass
            cmp     ebx, [imgEnd]
            jg      nobypass
            sub     ebx, imgStart
            add     ebx, memoryBackup

  nobypass:
            add		al,[ebx]
            pop     ebx
            push    ecx
            mov     cl,0xDE
            jmp     crcSecondaryRet
        }
	}

	void __declspec(naked) crcTertiaryHook()
	{
		_asm
		{
			cmp		edx, crcC1
			jl		nobypass1
			cmp		edx, crcC2
			jg		nobypass1
			jmp		bypass

			nobypass1:
			cmp		edx, crcC3
			jl		nobypass2
			cmp		edx, crcC4
			jg		nobypass2
			jmp		bypass

			nobypass2:
			cmp		sendStart, 0
			jz		nobypass
			cmp		edx, sendStart
			jl		nobypass
			cmp		edx, sendEnd
			jg		nobypass

			bypass:
			sub		edx, imgStart
			add		edx, memoryBackup

			nobypass:
			push	[edx]
			jmp		crcTertiaryRet
		}
	}
	
	bool DisableInternalHackdetection()
	{
		DWORD old;
		unsigned char scanPattern[] = {0x85, 0xc0, 0x0f, 0x84, 0xf9, 0xf9, 0x00, 0x00, 0x8b, 0x4e, 0xf9, 0x8b, 0xc1};	// msea, ems
		unsigned char scanPattern2[] = {0x3d, 0x01, 0x05, 0x01, 0x00, 0x7f};	// gms
		unsigned int position = FindAoB(imgStart, imgEnd, scanPattern, _countof(scanPattern));
		if (position == 0)
		{
			position = FindAoB(imgStart, imgEnd, scanPattern2, _countof(scanPattern2));
			if (position == 0)
			{
				Log(L"AoB scan failed for CSecurityClient::Update\n");
				return false;
			}
			position -= 6;
		} 
		else
		{
			position -= 14;
		}

		VirtualProtect((void *)position, 1, PAGE_EXECUTE_READWRITE, &old);
		*(unsigned char *)position = 0xc3;	// retn
		
		Log(L"Internal hack detection patched @ %x\n", position);
		return true;
	}

	bool DisableCrc()
	{
		HMODULE mod = GetModuleHandle(L"MapleStory.exe");
		IMAGE_NT_HEADERS *nth = (IMAGE_NT_HEADERS *)((unsigned int)mod + PIMAGE_DOS_HEADER(mod)->e_lfanew);
		DWORD old; 

		imgStart = (unsigned int)mod;
		imgEnd = imgStart + nth->OptionalHeader.SizeOfImage;

		memoryBackup = (unsigned char *)malloc(nth->OptionalHeader.SizeOfImage);
		Log(L"Backing up %x - %x (%x) to %x\n", imgStart, imgEnd, nth->OptionalHeader.SizeOfImage, memoryBackup);
		memcpy(memoryBackup, mod, nth->OptionalHeader.SizeOfImage);


		VirtualProtect((void *)crcMain, 16, PAGE_EXECUTE_READWRITE, &old);
		*(unsigned char *)crcMain = 0xe9;
		*(unsigned int *)(crcMain + 1) = (int)crcMainHook - crcMain - 5;

		VirtualProtect((void *)crcSecondary, 16, PAGE_EXECUTE_READWRITE, &old);
		*(unsigned char *)crcSecondary = 0xe9;
		*(unsigned int *)(crcSecondary + 1) = (int)crcSecondaryHook - crcSecondary - 5;
		*(unsigned char *)(crcSecondary + 5) = 0x90;

		VirtualProtect((void *)crcTertiary, 16, PAGE_EXECUTE_READWRITE, &old);
		*(unsigned char *)crcTertiary = 0xe9;
		*(unsigned int *)(crcTertiary + 1) = (int)crcTertiaryHook - crcTertiary - 5;
		*(unsigned char *)(crcTertiary + 5) = 0x90;

		return true;
	}
}