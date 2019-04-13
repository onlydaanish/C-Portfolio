#pragma once

namespace ZSTrainer {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AllSetting : public System::Windows::Forms::Form
	{
		static AllSetting^ sGUI;
	public:
		AllSetting(void) 
		{
			InitializeComponent();
			sGUI = this;
		}

	public:
		~AllSetting() {
			if (components)
				delete components;
		}
	public: System::Windows::Forms::Panel^  DirPanel;
	public: 
	public: System::Windows::Forms::Button^  Browse;
	public: System::Windows::Forms::TextBox^  FilePath;



	public: System::Windows::Forms::OpenFileDialog^  BrowseMaple;
	public: System::Windows::Forms::Panel^  panel1;
	public: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::CheckBox^  BreathCB;

	public: System::Windows::Forms::CheckBox^  LogoCB;


	public: System::Windows::Forms::CheckBox^  PicCB;
	public: System::Windows::Forms::Panel^  panel2;
	public: System::Windows::Forms::Label^  label3;
	public: System::Windows::Forms::TextBox^  ProfileTB;
	public: System::Windows::Forms::Label^  label5;
	public: System::Windows::Forms::Label^  WaitTimeLabel;
	public: System::Windows::Forms::TrackBar^  DelayTB;
	public: System::Windows::Forms::Label^  label2;
	public: System::Windows::Forms::Panel^  panel3;
	public: System::Windows::Forms::TextBox^  PICBox;
	public: System::Windows::Forms::TextBox^  PWBox;
	public: System::Windows::Forms::TextBox^  IDBox;
	public: System::Windows::Forms::Label^  label7;
	public: System::Windows::Forms::Label^  label6;
	public: System::Windows::Forms::Label^  label4;
	public: System::Windows::Forms::ComboBox^  serverbox;
	public: System::Windows::Forms::Label^  label8;
	public: System::Windows::Forms::ComboBox^  channelbox;

	private: System::Windows::Forms::Label^  label9;
	public: System::Windows::Forms::ComboBox^  charbox;
	private: 

	private: 
	private: System::Windows::Forms::Label^  label10;
	public: 
	public: 

	public: 


	public:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AllSetting::typeid));
			this->DirPanel = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->WaitTimeLabel = (gcnew System::Windows::Forms::Label());
			this->DelayTB = (gcnew System::Windows::Forms::TrackBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Browse = (gcnew System::Windows::Forms::Button());
			this->FilePath = (gcnew System::Windows::Forms::TextBox());
			this->BrowseMaple = (gcnew System::Windows::Forms::OpenFileDialog());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->LogoCB = (gcnew System::Windows::Forms::CheckBox());
			this->PicCB = (gcnew System::Windows::Forms::CheckBox());
			this->BreathCB = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->ProfileTB = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->charbox = (gcnew System::Windows::Forms::ComboBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->channelbox = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->serverbox = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->PICBox = (gcnew System::Windows::Forms::TextBox());
			this->PWBox = (gcnew System::Windows::Forms::TextBox());
			this->IDBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->DirPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DelayTB))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// DirPanel
			// 
			this->DirPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->DirPanel->Controls->Add(this->label5);
			this->DirPanel->Controls->Add(this->WaitTimeLabel);
			this->DirPanel->Controls->Add(this->DelayTB);
			this->DirPanel->Controls->Add(this->label2);
			this->DirPanel->Controls->Add(this->Browse);
			this->DirPanel->Controls->Add(this->FilePath);
			this->DirPanel->Location = System::Drawing::Point(7, 142);
			this->DirPanel->Margin = System::Windows::Forms::Padding(4);
			this->DirPanel->Name = L"DirPanel";
			this->DirPanel->Size = System::Drawing::Size(366, 70);
			this->DirPanel->TabIndex = 0;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(327, 48);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(32, 17);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Sec";
			// 
			// WaitTimeLabel
			// 
			this->WaitTimeLabel->AutoSize = true;
			this->WaitTimeLabel->Location = System::Drawing::Point(332, 32);
			this->WaitTimeLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->WaitTimeLabel->Name = L"WaitTimeLabel";
			this->WaitTimeLabel->Size = System::Drawing::Size(24, 17);
			this->WaitTimeLabel->TabIndex = 4;
			this->WaitTimeLabel->Text = L"15";
			// 
			// DelayTB
			// 
			this->DelayTB->Location = System::Drawing::Point(183, 31);
			this->DelayTB->Margin = System::Windows::Forms::Padding(4);
			this->DelayTB->Maximum = 60;
			this->DelayTB->Minimum = 15;
			this->DelayTB->Name = L"DelayTB";
			this->DelayTB->Size = System::Drawing::Size(155, 56);
			this->DelayTB->TabIndex = 4;
			this->DelayTB->Value = 15;
			this->DelayTB->Scroll += gcnew System::EventHandler(this, &AllSetting::DelayTB_Scroll);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(4, 39);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(157, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Wait For Login Screen: ";
			// 
			// Browse
			// 
			this->Browse->ForeColor = System::Drawing::Color::Black;
			this->Browse->Location = System::Drawing::Point(316, 4);
			this->Browse->Margin = System::Windows::Forms::Padding(4);
			this->Browse->Name = L"Browse";
			this->Browse->Size = System::Drawing::Size(44, 25);
			this->Browse->TabIndex = 1;
			this->Browse->Text = L"...";
			this->Browse->UseVisualStyleBackColor = true;
			this->Browse->Click += gcnew System::EventHandler(this, &AllSetting::Browse_Click);
			// 
			// FilePath
			// 
			this->FilePath->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->FilePath->Location = System::Drawing::Point(4, 4);
			this->FilePath->Margin = System::Windows::Forms::Padding(4);
			this->FilePath->Name = L"FilePath";
			this->FilePath->Size = System::Drawing::Size(310, 22);
			this->FilePath->TabIndex = 0;
			this->FilePath->TextChanged += gcnew System::EventHandler(this, &AllSetting::FilePath_TextChanged);
			// 
			// BrowseMaple
			// 
			this->BrowseMaple->FileName = L"GameLauncher.exe";
			this->BrowseMaple->Filter = L"GameLauncher.exe (*GameLauncher.exe) | GameLauncher.exe";
			// 
			// panel1
			// 
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->LogoCB);
			this->panel1->Controls->Add(this->PicCB);
			this->panel1->Controls->Add(this->BreathCB);
			this->panel1->Location = System::Drawing::Point(7, 220);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(366, 44);
			this->panel1->TabIndex = 1;
			// 
			// LogoCB
			// 
			this->LogoCB->AutoSize = true;
			this->LogoCB->Location = System::Drawing::Point(261, 16);
			this->LogoCB->Margin = System::Windows::Forms::Padding(4);
			this->LogoCB->Name = L"LogoCB";
			this->LogoCB->Size = System::Drawing::Size(93, 21);
			this->LogoCB->TabIndex = 5;
			this->LogoCB->Text = L"Skip Logo";
			this->LogoCB->UseVisualStyleBackColor = true;
			this->LogoCB->CheckedChanged += gcnew System::EventHandler(this, &AllSetting::LogoCB_CheckedChanged);
			// 
			// PicCB
			// 
			this->PicCB->AutoSize = true;
			this->PicCB->Location = System::Drawing::Point(133, 16);
			this->PicCB->Margin = System::Windows::Forms::Padding(4);
			this->PicCB->Name = L"PicCB";
			this->PicCB->Size = System::Drawing::Size(100, 21);
			this->PicCB->TabIndex = 2;
			this->PicCB->Text = L"P.I.C Typer";
			this->PicCB->UseVisualStyleBackColor = true;
			this->PicCB->CheckedChanged += gcnew System::EventHandler(this, &AllSetting::PicCB_CheckedChanged);
			// 
			// BreathCB
			// 
			this->BreathCB->AutoSize = true;
			this->BreathCB->Location = System::Drawing::Point(4, 16);
			this->BreathCB->Margin = System::Windows::Forms::Padding(4);
			this->BreathCB->Name = L"BreathCB";
			this->BreathCB->Size = System::Drawing::Size(94, 21);
			this->BreathCB->TabIndex = 1;
			this->BreathCB->Text = L"No Breath";
			this->BreathCB->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(137, 215);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Startup Hacks";
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->ProfileTB);
			this->panel2->Location = System::Drawing::Point(7, 6);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(366, 33);
			this->panel2->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(20, 7);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 17);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Profile Name:";
			// 
			// ProfileTB
			// 
			this->ProfileTB->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ProfileTB->Location = System::Drawing::Point(164, 4);
			this->ProfileTB->Margin = System::Windows::Forms::Padding(4);
			this->ProfileTB->Name = L"ProfileTB";
			this->ProfileTB->Size = System::Drawing::Size(190, 22);
			this->ProfileTB->TabIndex = 0;
			this->ProfileTB->TextChanged += gcnew System::EventHandler(this, &AllSetting::ProfileTB_TextChanged);
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->charbox);
			this->panel3->Controls->Add(this->label10);
			this->panel3->Controls->Add(this->channelbox);
			this->panel3->Controls->Add(this->label9);
			this->panel3->Controls->Add(this->serverbox);
			this->panel3->Controls->Add(this->label8);
			this->panel3->Controls->Add(this->PICBox);
			this->panel3->Controls->Add(this->PWBox);
			this->panel3->Controls->Add(this->IDBox);
			this->panel3->Controls->Add(this->label7);
			this->panel3->Controls->Add(this->label6);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Location = System::Drawing::Point(7, 43);
			this->panel3->Margin = System::Windows::Forms::Padding(4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(366, 94);
			this->panel3->TabIndex = 4;
			// 
			// charbox
			// 
			this->charbox->FormattingEnabled = true;
			this->charbox->Items->AddRange(gcnew cli::array< System::Object^  >(16) {
				L"", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10", L"11", L"12", L"13", L"14", L"15"
			});
			this->charbox->Location = System::Drawing::Point(252, 62);
			this->charbox->Margin = System::Windows::Forms::Padding(4);
			this->charbox->Name = L"charbox";
			this->charbox->Size = System::Drawing::Size(107, 24);
			this->charbox->TabIndex = 15;
			this->charbox->SelectedIndexChanged += gcnew System::EventHandler(this, &AllSetting::charbox_SelectedIndexChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(201, 65);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(42, 17);
			this->label10->TabIndex = 14;
			this->label10->Text = L"Char:";
			// 
			// channelbox
			// 
			this->channelbox->FormattingEnabled = true;
			this->channelbox->Items->AddRange(gcnew cli::array< System::Object^  >(21) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7",
					L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20"
			});
			this->channelbox->Location = System::Drawing::Point(77, 62);
			this->channelbox->Margin = System::Windows::Forms::Padding(4);
			this->channelbox->Name = L"channelbox";
			this->channelbox->Size = System::Drawing::Size(115, 24);
			this->channelbox->TabIndex = 13;
			this->channelbox->SelectedIndexChanged += gcnew System::EventHandler(this, &AllSetting::channelbox_SelectedIndexChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(4, 65);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(64, 17);
			this->label9->TabIndex = 12;
			this->label9->Text = L"Channel:";
			// 
			// serverbox
			// 
			this->serverbox->FormattingEnabled = true;
			this->serverbox->Items->AddRange(gcnew cli::array< System::Object^  >(17) {
				L"Scania", L"Bera", L"Broa", L"Windia", L"Khaini",
					L"Bellocan", L"Mardia", L"Kradia", L"Yellonde", L"Demethos", L"Galicia", L"ElNido", L"Zenith", L"Arcania", L"Chaos", L"Nova",
					L"Renegades"
			});
			this->serverbox->Location = System::Drawing::Point(253, 31);
			this->serverbox->Margin = System::Windows::Forms::Padding(4);
			this->serverbox->Name = L"serverbox";
			this->serverbox->Size = System::Drawing::Size(105, 24);
			this->serverbox->TabIndex = 11;
			this->serverbox->SelectedIndexChanged += gcnew System::EventHandler(this, &AllSetting::serverbox_SelectedIndexChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(201, 34);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(54, 17);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Server:";
			// 
			// PICBox
			// 
			this->PICBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PICBox->Location = System::Drawing::Point(252, 4);
			this->PICBox->Margin = System::Windows::Forms::Padding(4);
			this->PICBox->Name = L"PICBox";
			this->PICBox->Size = System::Drawing::Size(107, 22);
			this->PICBox->TabIndex = 9;
			this->PICBox->TextChanged += gcnew System::EventHandler(this, &AllSetting::PICBox_TextChanged);
			// 
			// PWBox
			// 
			this->PWBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PWBox->Location = System::Drawing::Point(79, 32);
			this->PWBox->Margin = System::Windows::Forms::Padding(4);
			this->PWBox->Name = L"PWBox";
			this->PWBox->Size = System::Drawing::Size(114, 22);
			this->PWBox->TabIndex = 8;
			this->PWBox->TextChanged += gcnew System::EventHandler(this, &AllSetting::PWBox_TextChanged);
			// 
			// IDBox
			// 
			this->IDBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->IDBox->Location = System::Drawing::Point(79, 4);
			this->IDBox->Margin = System::Windows::Forms::Padding(4);
			this->IDBox->Name = L"IDBox";
			this->IDBox->Size = System::Drawing::Size(114, 22);
			this->IDBox->TabIndex = 7;
			this->IDBox->TextChanged += gcnew System::EventHandler(this, &AllSetting::IDBox_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(201, 6);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(41, 17);
			this->label7->TabIndex = 6;
			this->label7->Text = L"P.I.C:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(4, 34);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(73, 17);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Password:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(4, 6);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 17);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Login ID:";
			// 
			// AllSetting
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(379, 269);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->DirPanel);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"AllSetting";
			this->Opacity = 0.85;
			this->Text = L"Settings";
			this->TopMost = true;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &AllSetting::AllSetting_Closing);
			this->Load += gcnew System::EventHandler(this, &AllSetting::AllSetting_Load);
			this->DirPanel->ResumeLayout(false);
			this->DirPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DelayTB))->EndInit();
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

	System::Void AllSetting_Load(System::Object^  sender, System::EventArgs^  e);
	System::Void Browse_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void AllSetting_Closing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e );
	System::Void DelayTB_Scroll(System::Object^  sender, System::EventArgs^  e);
	System::Void ProfileTB_TextChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void FilePath_TextChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void PWBox_TextChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void IDBox_TextChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void PICBox_TextChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void serverbox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void channelbox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e); 
	System::Void charbox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void PicCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void LogoCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
};
}
