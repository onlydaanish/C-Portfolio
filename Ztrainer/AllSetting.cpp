#include "AllSetting.h"
#include "Functions.h"
#include "Global.h"

using namespace ZSTrainer;
using namespace System;
using namespace System::IO;
[STAThread]

void AllSetting::AllSetting_Load(System::Object^  sender, System::EventArgs^  e)
{
	if (MapleDir.length() > 0)
		FilePath->Text = gcnew System::String(MapleDir.c_str());

	IDBox->Text = LPCSTRToString(ID);
	PWBox->Text = LPCSTRToString(PW);
	PICBox->Text = LPCSTRToString(PIC);
	serverbox->Text = LPCSTRToString(cServer);
	wNeeded = serverbox->SelectedIndex;
	channelbox->Text = sChannel.ToString();
	charbox->Text = sChar.ToString();

	ProfileTB->Text = gcnew System::String(ProfName);
	DelayTB->Value = WaitTime;
	WaitTimeLabel->Text = WaitTime.ToString();

	if (typePIC)
		PicCB->Checked = true;

	if (LogoSkipOn)
		LogoCB->Checked = true;

	//Check Hacks
	if (!fPic)
	{
		PicCB->Checked = false;
		PicCB->Enabled = false;
	}
	else if (typePIC)
	{
		PicCB->Checked = true;
	}

	if (!fLogoSkip)
	{
		LogoCB->Checked = false;
		LogoCB->Enabled = false;
	}
	else if (LogoSkipOn)
	{
		LogoCB->Checked = true;
	}
}

void AllSetting::AllSetting_Closing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	
}

void AllSetting::IDBox_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	ID = StringToLPCSTR(IDBox->Text);
	if (RegOpenKey(HKEY_LOCAL_MACHINE, "Software\\Wizet\\MapleStory", &key) == ERROR_SUCCESS || RegOpenKey(HKEY_LOCAL_MACHINE, "Software\\Wow6432Node\\MapleStory", &key) == ERROR_SUCCESS)
	{
		RegSetValueEx(key, "LMA", 0, REG_SZ,(unsigned char*)ID, (IDBox->TextLength)); //Sets Current Login ID
		RegCloseKey(key);
	}
}

void AllSetting::PWBox_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	PW = StringToLPCSTR(PWBox->Text);
}

void AllSetting::PICBox_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	PIC = StringToLPCSTR(PICBox->Text);
}

void AllSetting::Browse_Click(System::Object^  sender, System::EventArgs^  e)
{
	//TODO(SheerIce): Set BrowseMaple's default open path as one acquired from system registry... (or just use system registry...)
	if (BrowseMaple->ShowDialog() == System::Windows::Forms::DialogResult::OK) 
	{
		FilePath->Text = BrowseMaple->FileName; // Set File Path to TextBox
		MapleDir = StringToLPCSTR(BrowseMaple->FileName); //Set File Path to MapleDir Variable
	}
}

void AllSetting::DelayTB_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	WaitTimeLabel->Text = DelayTB->Value.ToString();
	WaitTime = DelayTB->Value;
}

void AllSetting::ProfileTB_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	ProfName = StringToLPCSTR(ProfileTB->Text);
}

// Check Boxes //

void AllSetting::FilePath_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	MapleDir = StringToLPCSTR(FilePath->Text);
}

void AllSetting::serverbox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	cServer = StringToLPCSTR(serverbox->Text);
	wNeeded = serverbox->SelectedIndex;
	
}

void AllSetting::channelbox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	sChannel = Convert::ToInt32(channelbox->Text);
}

void AllSetting::charbox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	sChar = Convert::ToInt32(charbox->Text);
}

void AllSetting::PicCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	hToggle(PicCB, typePIC, _PIC, MapleOpen);
}

void AllSetting::LogoCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	hToggle(LogoCB, LogoSkipOn, _LogoSkip, MapleOpen);
}

#pragma unmanaged