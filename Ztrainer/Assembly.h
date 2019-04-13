#include "Addresses.h"
#pragma once
#pragma unmanaged

static void __declspec(naked) _stdcall CLI_SetNumberValue_ASM()
{
	_asm
	{
		/*
		push eax
		mov eax,[ebp+0x08]
		mov [HP],eax
			mov eax,[ebp+0x0C]
		mov [MaxHP],eax
			mov eax,[ebp+0x10]
		mov [MP],eax
			mov eax,[ebp+0x14]
		mov [MaxMP],eax
			mov eax,[ebp+0x18]
		mov [EXP],eax
			mov eax,[ebp+0x1C]
		mov [MaxEXP],eax
			pop eax
			lea ecx,[eax+eax*4]
		test ecx,ecx
			jmp dword ptr [CLI_SetNumberValue::Return]*/
	}
}

static void __declspec(naked) _stdcall IntersectRectASM()
{
	_asm
	{
		cmp [esp],PhsyGmode
		je ret_false
		mov edi,edi
		push ebp
		mov ebp,esp
		jmp GodMode::Return

		ret_false:
		mov eax,0
		ret 0x0C
	}
}

static void _declspec(naked) _stdcall IntersectRectDisable()
{
	_asm
	{
		mov edi,edi
		push ebp
		mov ebp,esp
	}
}

static void _declspec(naked) _stdcall PicASM()
{
	_asm
	{
		jmp [Pic::Addyfs]
	}
}


static void _declspec(naked) _stdcall FilterASM()
{
	_asm
	{
			push edx
			mov edx,MesoAmount
			cmp eax, edx
			jle FilterMesos
			mov edx,iFilter
			jmp	RejectOrAccept


			RejectOrAccept :
			cmp byte ptr[FilterMode], 0x0
			je AcceptFilter
			cmp byte ptr[FilterMode], 0x1
			je RejectFilter

			FilterMesos :
			mov[esi+0x40],0x0
			jmp End

			AcceptFilter :
			cmp eax,[edx]
			je End
			cmp dword ptr[edx],0x0
			je Ignore
			add edx, 0x4
			jmp AcceptFilter

			RejectFilter :
			cmp eax, [edx]
			je Ignore
			cmp dword ptr[edx], 0
			je End
			add edx, 0x4
			jmp RejectFilter


			Ignore:
			cmp eax,RANDDEF // added this code otherwise mesos is dropped but not shown in accept mode
			jle End
			mov eax,0x0

			End:
			pop edx
			mov ecx, ebx  // org code
			mov[esi+0x44], eax // org code
			jmp dword ptr [ItemFilter::FilterReturn]
	}
}

#pragma managed