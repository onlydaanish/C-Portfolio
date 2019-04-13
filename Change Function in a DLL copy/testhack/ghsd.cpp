#include "ghsd.h"

#include "global.h"
	
using namespace testhack;
using namespace System;

[STAThread]
int Begin()  
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew ghsd);
	return 0;
}


int WINAPI FDaanish()
{
	return 0; 
}

#pragma managed

void ghsd::timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{
	while (!j)
			{
				ghsd::Gui->label1->Text = "0";
	}
	ghsd::Gui->label1->Text = "1";
}

void ghsd::ghsd_Load(System::Object^  sender, System::EventArgs^  e)
{

}