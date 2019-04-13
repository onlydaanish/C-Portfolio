#pragma once

namespace ZSTrainer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FilterForm
	/// </summary>
	public ref class FilterForm : public System::Windows::Forms::Form
	{
	public:
		static FilterForm^ Filterf;
		FilterForm(void)
		{
			InitializeComponent();
			//
			Filterf = this;
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FilterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  SearchList;
	private: System::Windows::Forms::TextBox^  ItemText;
	private: System::Windows::Forms::Button^  SearchButton;
	private: System::Windows::Forms::ListBox^  AcceptedList;

	protected:



	private: System::Windows::Forms::Button^  AddButton;
	private: System::Windows::Forms::Button^  RemoveButton;


	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::TextBox^  MesoBox;

	private: System::Windows::Forms::Label^  label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SearchList = (gcnew System::Windows::Forms::ListBox());
			this->ItemText = (gcnew System::Windows::Forms::TextBox());
			this->SearchButton = (gcnew System::Windows::Forms::Button());
			this->AcceptedList = (gcnew System::Windows::Forms::ListBox());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->RemoveButton = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->MesoBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// SearchList
			// 
			this->SearchList->BackColor = System::Drawing::Color::Black;
			this->SearchList->ForeColor = System::Drawing::Color::White;
			this->SearchList->FormattingEnabled = true;
			this->SearchList->ItemHeight = 16;
			this->SearchList->Location = System::Drawing::Point(2, 2);
			this->SearchList->Name = L"SearchList";
			this->SearchList->Size = System::Drawing::Size(376, 116);
			this->SearchList->TabIndex = 0;
			this->SearchList->SelectedIndexChanged += gcnew System::EventHandler(this, &FilterForm::SearchList_SelectedIndexChanged);
			// 
			// ItemText
			// 
			this->ItemText->Location = System::Drawing::Point(2, 124);
			this->ItemText->Name = L"ItemText";
			this->ItemText->Size = System::Drawing::Size(214, 22);
			this->ItemText->TabIndex = 1;
			// 
			// SearchButton
			// 
			this->SearchButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SearchButton->Location = System::Drawing::Point(222, 121);
			this->SearchButton->Name = L"SearchButton";
			this->SearchButton->Size = System::Drawing::Size(75, 28);
			this->SearchButton->TabIndex = 2;
			this->SearchButton->Text = L"Search";
			this->SearchButton->UseVisualStyleBackColor = true;
			this->SearchButton->Click += gcnew System::EventHandler(this, &FilterForm::SearchButton_Click);
			// 
			// AcceptedList
			// 
			this->AcceptedList->BackColor = System::Drawing::Color::Black;
			this->AcceptedList->ForeColor = System::Drawing::Color::White;
			this->AcceptedList->FormattingEnabled = true;
			this->AcceptedList->ItemHeight = 16;
			this->AcceptedList->Location = System::Drawing::Point(2, 152);
			this->AcceptedList->Name = L"AcceptedList";
			this->AcceptedList->Size = System::Drawing::Size(376, 116);
			this->AcceptedList->TabIndex = 3;
			this->AcceptedList->SelectedIndexChanged += gcnew System::EventHandler(this, &FilterForm::AcceptedList_SelectedIndexChanged);
			// 
			// AddButton
			// 
			this->AddButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->AddButton->Location = System::Drawing::Point(303, 121);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(75, 28);
			this->AddButton->TabIndex = 4;
			this->AddButton->Text = L"Add";
			this->AddButton->UseVisualStyleBackColor = true;
			this->AddButton->Click += gcnew System::EventHandler(this, &FilterForm::AddButton_Click);
			// 
			// RemoveButton
			// 
			this->RemoveButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->RemoveButton->Location = System::Drawing::Point(303, 274);
			this->RemoveButton->Name = L"RemoveButton";
			this->RemoveButton->Size = System::Drawing::Size(75, 28);
			this->RemoveButton->TabIndex = 5;
			this->RemoveButton->Text = L"Remove";
			this->RemoveButton->UseVisualStyleBackColor = true;
			this->RemoveButton->Click += gcnew System::EventHandler(this, &FilterForm::RemoveButton_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Enabled = false;
			this->checkBox1->Location = System::Drawing::Point(225, 279);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(73, 21);
			this->checkBox1->TabIndex = 6;
			this->checkBox1->Text = L"Accept";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// MesoBox
			// 
			this->MesoBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->MesoBox->Location = System::Drawing::Point(148, 277);
			this->MesoBox->Name = L"MesoBox";
			this->MesoBox->Size = System::Drawing::Size(68, 22);
			this->MesoBox->TabIndex = 7;
			this->MesoBox->Text = L"1";
			this->MesoBox->TextChanged += gcnew System::EventHandler(this, &FilterForm::MesoBox_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(-1, 280);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(143, 17);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Mesos Greater Than:";
			// 
			// FilterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(380, 308);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->MesoBox);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->RemoveButton);
			this->Controls->Add(this->AddButton);
			this->Controls->Add(this->AcceptedList);
			this->Controls->Add(this->SearchButton);
			this->Controls->Add(this->ItemText);
			this->Controls->Add(this->SearchList);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"FilterForm";
			this->Text = L"Item Filter";
			this->Load += gcnew System::EventHandler(this, &FilterForm::FilterForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void SearchButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void AddButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void RemoveButton_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void MesoBox_TextChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void SearchList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void AcceptedList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void FilterForm_Load(System::Object^  sender, System::EventArgs^  e);
};
}
