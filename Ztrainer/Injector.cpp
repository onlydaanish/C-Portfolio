#include "Injector.h"
#include "Functions.h"
using namespace ZSTrainer;
using namespace System::IO;

void Injector::InjectButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (File::Exists(textBox1->Text))	
		InjectDLL(MaplePID, (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(textBox1->Text));
}
void Injector::BrowseButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (BrowseDLL->ShowDialog() == ::DialogResult::OK)
		textBox1->Text = BrowseDLL->FileName;
}