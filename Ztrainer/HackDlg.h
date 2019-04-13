#pragma once

namespace ZSTrainer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for HackDlg
	/// </summary>
	public ref class HackDlg : public System::Windows::Forms::Form
	{
	public:
		HackDlg(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HackDlg()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^  gmodeCB;
	private: System::Windows::Forms::CheckBox^  AggroCB;
	private: System::Windows::Forms::CheckBox^  SlideCB;
	private: System::Windows::Forms::CheckBox^  KBCB;
	private: System::Windows::Forms::CheckBox^  TubiCB;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  label3;
	protected:

	protected:



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(HackDlg::typeid));
			this->gmodeCB = (gcnew System::Windows::Forms::CheckBox());
			this->AggroCB = (gcnew System::Windows::Forms::CheckBox());
			this->SlideCB = (gcnew System::Windows::Forms::CheckBox());
			this->KBCB = (gcnew System::Windows::Forms::CheckBox());
			this->TubiCB = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// gmodeCB
			// 
			this->gmodeCB->AutoSize = true;
			this->gmodeCB->Location = System::Drawing::Point(6, 14);
			this->gmodeCB->Name = L"gmodeCB";
			this->gmodeCB->Size = System::Drawing::Size(140, 21);
			this->gmodeCB->TabIndex = 0;
			this->gmodeCB->Text = L"58 Sec Godmode";
			this->gmodeCB->UseVisualStyleBackColor = true;
			// 
			// AggroCB
			// 
			this->AggroCB->AutoSize = true;
			this->AggroCB->Location = System::Drawing::Point(134, 19);
			this->AggroCB->Name = L"AggroCB";
			this->AggroCB->Size = System::Drawing::Size(101, 21);
			this->AggroCB->TabIndex = 1;
			this->AggroCB->Text = L"Auto Aggro";
			this->AggroCB->UseVisualStyleBackColor = true;
			// 
			// SlideCB
			// 
			this->SlideCB->AutoSize = true;
			this->SlideCB->Location = System::Drawing::Point(6, 41);
			this->SlideCB->Name = L"SlideCB";
			this->SlideCB->Size = System::Drawing::Size(104, 21);
			this->SlideCB->TabIndex = 2;
			this->SlideCB->Text = L"Slide Attack";
			this->SlideCB->UseVisualStyleBackColor = true;
			// 
			// KBCB
			// 
			this->KBCB->AutoSize = true;
			this->KBCB->Location = System::Drawing::Point(161, 14);
			this->KBCB->Name = L"KBCB";
			this->KBCB->Size = System::Drawing::Size(74, 21);
			this->KBCB->TabIndex = 3;
			this->KBCB->Text = L"No K/B";
			this->KBCB->UseVisualStyleBackColor = true;
			// 
			// TubiCB
			// 
			this->TubiCB->AutoSize = true;
			this->TubiCB->Location = System::Drawing::Point(144, 15);
			this->TubiCB->Name = L"TubiCB";
			this->TubiCB->Size = System::Drawing::Size(91, 21);
			this->TubiCB->TabIndex = 4;
			this->TubiCB->Text = L"Safe Tubi";
			this->TubiCB->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(274, 15);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(92, 21);
			this->checkBox3->TabIndex = 5;
			this->checkBox3->Text = L"Semi iVac";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(6, 15);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(82, 21);
			this->checkBox1->TabIndex = 6;
			this->checkBox1->Text = L"Pet iVac";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(251, 14);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(131, 21);
			this->checkBox2->TabIndex = 7;
			this->checkBox2->Text = L"Unlimited Attack";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(6, 19);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(105, 21);
			this->checkBox4->TabIndex = 8;
			this->checkBox4->Text = L"Mob Disarm";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->gmodeCB);
			this->panel1->Controls->Add(this->KBCB);
			this->panel1->Controls->Add(this->checkBox2);
			this->panel1->Controls->Add(this->SlideCB);
			this->panel1->Location = System::Drawing::Point(7, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(384, 68);
			this->panel1->TabIndex = 9;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &HackDlg::panel1_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(140, 3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 17);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Character Hacks";
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->checkBox1);
			this->panel2->Controls->Add(this->TubiCB);
			this->panel2->Controls->Add(this->checkBox3);
			this->panel2->Location = System::Drawing::Point(7, 98);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(383, 45);
			this->panel2->TabIndex = 11;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(160, 88);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 17);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Item Hacks";
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->checkBox4);
			this->panel3->Controls->Add(this->AggroCB);
			this->panel3->Location = System::Drawing::Point(7, 162);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(383, 49);
			this->panel3->TabIndex = 13;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(158, 158);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 17);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Mob Hacks";
			// 
			// HackDlg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(396, 333);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"HackDlg";
			this->Text = L"Hacks";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
};
}
