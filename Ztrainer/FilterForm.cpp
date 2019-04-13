#include "FilterForm.h"
#include "Functions.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

using namespace ZSTrainer;
using namespace std;
using namespace System::IO;
using namespace msclr::interop;


void FilterForm::SearchButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	ifstream Query;
	string line;
	int position = 0;

	System::String ^Dir = Directory::GetCurrentDirectory();
	Dir = Dir + "\\Items.ZS";

	SearchList->Items->Clear();

	Query.open(StringToLPCSTR(Dir));

	if (Query.is_open())
	{

		while (!Query.eof())
		{

			getline(Query, line);

			if ((position = line.find(StringToLPCSTR(ItemText->Text), 0)) != string::npos)
				SearchList->Items->Add(LPCSTRToString(line.c_str()));
		}
		Query.close();
	}
	else
	{
		::MessageBox(0, "Cannot Open Items.ZS", Title, MB_OK);
	}

}

void FilterForm::AddButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	ifstream Query;
	string line; 
	int position; 

	if (is_digits(StringToLPCSTR(ItemText->Text)))
	{
		System::String ^ILDir = Directory::GetCurrentDirectory();
		ILDir = ILDir + "\\Items.ZS";

		System::String ^IFDir = Directory::GetCurrentDirectory();
		IFDir = IFDir + "\\Filter.ZS";

		if (SearchList->SelectedIndex < 0)
		{
			if (SearchList->Items->Count < 1)
			{
				SearchList->Items->Add("");
			}
			SearchList->SelectedIndex = 0;
		}

		string AI = StringToLPCSTR(SearchList->SelectedItem->ToString());
		if (StringToLPCSTR(ItemText->Text->ToString()) != AI.substr(0,7))
		{
			Query.open(StringToLPCSTR(IFDir));
			while (!Query.eof())
			{
				getline(Query, line);
				if ((position = line.find(StringToLPCSTR(ItemText->Text->ToString()), 0)) != string::npos)
				{
					string T = line.substr(0,7);
					if (find(iFilter.begin(), iFilter.end(), atoi(T.c_str())) == iFilter.end())
					{
						::MessageBox(0, "1", Title, MB_OK);
						AcceptedList->Items->Add(LPCSTRToString(line.c_str())); // Add found item to Accpeted List
						FilterMem.push_back(line); // Add Whole item Name for Load of Form
						line = line.substr(0, 7); // Get only numbers from item name
						iFilter.push_back(atoi(line.c_str())); // Add To Vector

						StreamWriter^ sw = gcnew StreamWriter(IFDir); // Open Filter File for DLL
						sw->WriteLine(line.c_str()); // Write Item Numbers

						sw->Close();
						Query.close();
					}
				}
			}
		}
		
		else
		{
			AcceptedList->Items->Add(SearchList->SelectedItem); // Add found item to accepted list
			FilterMem.push_back(StringToLPCSTR(SearchList->SelectedItem->ToString())); // Add whole item name for form load
			string Line = StringToLPCSTR(SearchList->SelectedItem->ToString());
			Line = Line.substr(0, 7); // Get numebers from item name
			iFilter.push_back(atoi(Line.c_str())); // Add to Filter
			
			StreamWriter^ sw = gcnew StreamWriter(IFDir); // Open Filter File for DLL
			const char* b = Line.c_str();
			sw->Write(b);
			sw->Close();
		}
	}

	/*
	int found = 0;
	string aI;
	string Item = StringToLPCSTR(ItemText->Text->ToString());
	


	if (find(iFilter.begin(), iFilter.end(), atoi(Item.c_str())) == iFilter.end())
	{
		if (SearchList->SelectedIndex > -1)
		{
			aI = StringToLPCSTR(SearchList->SelectedItem->ToString());
			aI.substr(0, 7);
		}
		if (StringToLPCSTR(ItemText->Text->ToString()) != aI && SearchList->SelectedIndex > -1)
		{

			ifstream Query;
			string line;
			int position = 0;

			System::String ^ILDir = Directory::GetCurrentDirectory();
			ILDir = ILDir + "\\Items.ZS";

			Query.open(StringToLPCSTR(ILDir));

			while (!Query.eof())
			{

				getline(Query, line);

				if ((position = line.find(StringToLPCSTR(ItemText->Text), 0)) != string::npos)
				{
					found++;
					SearchList->Items->Add(LPCSTRToString(line.c_str()));
					Query.close();
				}

			}

			if (found == 0)
			{
				::MessageBox(Gui, "Item Does Not Exist! Please Add it to Item.ZS", Title, MB_OK);
			}
			else
			{
				Item = line;
				Item = Item.substr(0, 7);
				iFilter.push_back(atoi(Item.c_str()));
				FilterMem.push_back(line);
				AcceptedList->Items->Add(LPCSTRToString(line.c_str()));

				StreamWriter^ sw = gcnew StreamWriter(IFDir);
				sw->WriteLine(LPCSTRToString(Item.c_str()));
				sw->Close();
			}
		}
		else
		{
			Item = StringToLPCSTR(SearchList->SelectedItem->ToString());
			Item = Item.substr(0, 7);

			iFilter.push_back(atoi(Item.c_str()));
			AcceptedList->Items->Add(SearchList->SelectedItem);
			FilterMem.push_back(Item);

			StreamWriter^ sw = gcnew StreamWriter(IFDir);
			sw->WriteLine(LPCSTRToString(Item.c_str()));
			sw->Close();
		}
	}*/
}

void FilterForm::RemoveButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (AcceptedList->SelectedIndex > -1)
	{
		string Item = StringToLPCSTR(SearchList->SelectedItem->ToString());
		Item = Item.substr(0, 7);

		iFilter.erase(iFilter.begin() + AcceptedList->SelectedIndex); //Get Index Number And Remove From ListBox
		FilterMem.erase(FilterMem.begin() + AcceptedList->SelectedIndex);
		AcceptedList->Items->Remove(AcceptedList->SelectedItem);
		AcceptedList->TopIndex = AcceptedList->Items->Count - 1;
	}
}

void FilterForm::MesoBox_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	MesoAmount = Convert::ToInt32(MesoBox->Text->ToString());
}

void FilterForm::SearchList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{

	string Item = StringToLPCSTR(SearchList->SelectedItem->ToString());
	Item = Item.substr(0, 7);

	ItemText->Text = LPCSTRToString(Item.c_str());
}

void FilterForm::AcceptedList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{

}

void FilterForm::FilterForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	for (int i = 0; i < FilterMem.size(); i++)
	{
		AcceptedList->Items->Add(marshal_as<String^>(FilterMem[i]));
	}
	MesoBox->Text = MesoAmount.ToString();
}