#include "Hidden.h"
#include "Global.h"

using namespace ZS;
using namespace System;
using namespace System::IO;
using namespace std;
using namespace System::Runtime::InteropServices;
LPCSTR SToLPCSTR (System::String ^X);
System::String^ LToString (LPCSTR X);

[STAThread]
int Begin()  
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Hidden);
	return 0;
}

LPCSTR SToLPCSTR (System::String ^X)
{
	return (LPCSTR)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(X);
}

System::String^ LToString (LPCSTR X)
{
	return (System::String^)System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)(void*)X);
}

void Hidden::WndProc(System::Windows::Forms::Message %m)
{
	switch (m.Msg)
	{
		case _UpdateLogoSkip:
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&UpdateLogo, 0, 0, NULL);
		break;
		case _UpdateAddys:
			{

				char Loc[MAX_PATH];
				GetPrivateProfileString("Main", "Path", "", Loc, sizeof(Loc), SToLPCSTR(Directory::GetCurrentDirectory() + "\\Path.ZS"));
				System::String ^ FoundDir = gcnew String(Loc) + "\\Info.ZS";

				if (File::Exists(FoundDir))
				{
					CurrentDir = sToLPCSTR(FoundDir);
				}
				else
				{
					::MessageBox(0, "Error Finding Path.ZS", Title, MB_OK);
					ExitProcess(0);
				}

				CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&UpdateAddys, 0, 0, NULL);
			}
		break;
		case _GetFunction:
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&GetDetourInfo, 0, 0, NULL);
		break;

		case _PIC:
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&tPIC, 0, 0, NULL);
		break;

		case _GodMode:
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&tGodMode, 0, 0, NULL);
		break;

		case _Kami:
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&tKami, 0, 0, NULL);
		break;

		case _Filter:
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&tFilter, 0, 0, NULL);
		break;
		
		case _LogoSkip:
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&tLogoSkip, 0, 0, NULL);
		break;
		case _TEST:
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&TestThread, 0, 0, NULL);
		break;
	}
	System::Windows::Forms::Form::WndProc(m);
}

void Hidden::Hidden_Load(System::Object^  sender, System::EventArgs^  e)
{
	hHidden = (HWND)this->Handle.ToPointer();
}