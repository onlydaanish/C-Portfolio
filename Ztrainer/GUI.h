#pragma once

namespace ZSTrainer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		static GUI^ Zuko;
		GUI(void)
		{
			InitializeComponent();
			Zuko = this;
		}

	public:
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^  SettingsButton;
	public: System::Windows::Forms::PictureBox^  LoadButton;
	public: System::Windows::Forms::PictureBox^  SaveButton;
	public: System::Windows::Forms::Label^  explabel;
	public: System::Windows::Forms::Label^  mplabel;
	public: System::Windows::Forms::Label^  hplabel;
	public: System::Windows::Forms::PictureBox^  StartButton;
	public: System::Windows::Forms::Label^  mouselabel;
	public: System::Windows::Forms::Label^  worldlabel;
	public: System::Windows::Forms::Label^  channellabel;
	public: System::Windows::Forms::Label^  breathlabel;
	public: System::Windows::Forms::Label^  attacklabel;
	public: System::Windows::Forms::Panel^  CharInfoPanel;
	public: System::Windows::Forms::Panel^  ServerInfoPanel;
	public: System::Windows::Forms::TextBox^  Log;
	public: System::Windows::Forms::Label^  Status;
	public: System::Windows::Forms::Panel^  HackPanel;
	public: System::Windows::Forms::PictureBox^  VacButton;
	public: System::Windows::Forms::PictureBox^  FilterButton;
	public: System::Windows::Forms::PictureBox^  HackButton;
	public: System::Windows::Forms::ProgressBar^  ProgressBar;
	public: System::Windows::Forms::PictureBox^  UpdateButton;
	public: System::Windows::Forms::PictureBox^  InjectButton;
	public: System::Windows::Forms::CheckBox^  ChangeCB;
	public: System::Windows::Forms::PictureBox^  CCButton;
	public: System::Windows::Forms::CheckBox^  LoginCB;
	public: System::Windows::Forms::PictureBox^  ALButton;
	public: System::Windows::Forms::CheckBox^  BotCB;
	public: System::Windows::Forms::PictureBox^  BotButton;
	public: System::Windows::Forms::CheckBox^  FilterCB;
	public: System::Windows::Forms::CheckBox^  VacCB;
	public: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::CheckBox^  EmbedCB;
	public: System::Windows::Forms::CheckBox^  HideCB;
	public: System::Windows::Forms::OpenFileDialog^  BrowseProfile;
	public: System::Windows::Forms::SaveFileDialog^  SaveProfile;
	public: System::Windows::Forms::Label^  topnamelabel;
	public: System::Windows::Forms::Label^  islandlabel;
	public: System::Windows::Forms::Label^  npclabel;
	public: System::Windows::Forms::Label^  moblabel;
	public: System::Windows::Forms::Label^  itemlabel;
	public: System::Windows::Forms::Label^  peoplelabel;
	public: System::Windows::Forms::Label^  maplabel;
	public: System::Windows::Forms::Label^  locationlabel;
	public: System::Windows::Forms::PictureBox^  MiniMap;
	public: System::Windows::Forms::PictureBox^  HpBar;
	public: System::Windows::Forms::PictureBox^  MpBar;
	public: System::Windows::Forms::PictureBox^  ExpBar;
	public: System::Windows::Forms::PictureBox^  pictureBox1;
	public: System::Windows::Forms::PictureBox^  pictureBox2;
	public: System::Windows::Forms::PictureBox^  pictureBox3;
	public: System::ComponentModel::IContainer^  components;
	public:

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GUI::typeid));
			this->SettingsButton = (gcnew System::Windows::Forms::PictureBox());
			this->LoadButton = (gcnew System::Windows::Forms::PictureBox());
			this->SaveButton = (gcnew System::Windows::Forms::PictureBox());
			this->explabel = (gcnew System::Windows::Forms::Label());
			this->mplabel = (gcnew System::Windows::Forms::Label());
			this->hplabel = (gcnew System::Windows::Forms::Label());
			this->StartButton = (gcnew System::Windows::Forms::PictureBox());
			this->mouselabel = (gcnew System::Windows::Forms::Label());
			this->worldlabel = (gcnew System::Windows::Forms::Label());
			this->channellabel = (gcnew System::Windows::Forms::Label());
			this->breathlabel = (gcnew System::Windows::Forms::Label());
			this->attacklabel = (gcnew System::Windows::Forms::Label());
			this->CharInfoPanel = (gcnew System::Windows::Forms::Panel());
			this->ServerInfoPanel = (gcnew System::Windows::Forms::Panel());
			this->Log = (gcnew System::Windows::Forms::TextBox());
			this->Status = (gcnew System::Windows::Forms::Label());
			this->UpdateButton = (gcnew System::Windows::Forms::PictureBox());
			this->ProgressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->HackPanel = (gcnew System::Windows::Forms::Panel());
			this->ChangeCB = (gcnew System::Windows::Forms::CheckBox());
			this->CCButton = (gcnew System::Windows::Forms::PictureBox());
			this->LoginCB = (gcnew System::Windows::Forms::CheckBox());
			this->ALButton = (gcnew System::Windows::Forms::PictureBox());
			this->BotCB = (gcnew System::Windows::Forms::CheckBox());
			this->BotButton = (gcnew System::Windows::Forms::PictureBox());
			this->FilterCB = (gcnew System::Windows::Forms::CheckBox());
			this->VacCB = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->VacButton = (gcnew System::Windows::Forms::PictureBox());
			this->FilterButton = (gcnew System::Windows::Forms::PictureBox());
			this->HackButton = (gcnew System::Windows::Forms::PictureBox());
			this->InjectButton = (gcnew System::Windows::Forms::PictureBox());
			this->EmbedCB = (gcnew System::Windows::Forms::CheckBox());
			this->HideCB = (gcnew System::Windows::Forms::CheckBox());
			this->BrowseProfile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SaveProfile = (gcnew System::Windows::Forms::SaveFileDialog());
			this->topnamelabel = (gcnew System::Windows::Forms::Label());
			this->islandlabel = (gcnew System::Windows::Forms::Label());
			this->npclabel = (gcnew System::Windows::Forms::Label());
			this->moblabel = (gcnew System::Windows::Forms::Label());
			this->itemlabel = (gcnew System::Windows::Forms::Label());
			this->peoplelabel = (gcnew System::Windows::Forms::Label());
			this->maplabel = (gcnew System::Windows::Forms::Label());
			this->locationlabel = (gcnew System::Windows::Forms::Label());
			this->MiniMap = (gcnew System::Windows::Forms::PictureBox());
			this->HpBar = (gcnew System::Windows::Forms::PictureBox());
			this->MpBar = (gcnew System::Windows::Forms::PictureBox());
			this->ExpBar = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SettingsButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LoadButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SaveButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StartButton))->BeginInit();
			this->CharInfoPanel->SuspendLayout();
			this->ServerInfoPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UpdateButton))->BeginInit();
			this->HackPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CCButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ALButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BotButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VacButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FilterButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->HackButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InjectButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MiniMap))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->HpBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MpBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ExpBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// SettingsButton
			// 
			this->SettingsButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SettingsButton.Image")));
			this->SettingsButton->Location = System::Drawing::Point(389, 55);
			this->SettingsButton->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->SettingsButton->Name = L"SettingsButton";
			this->SettingsButton->Size = System::Drawing::Size(43, 39);
			this->SettingsButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->SettingsButton->TabIndex = 1;
			this->SettingsButton->TabStop = false;
			this->SettingsButton->Tag = L"Settings";
			this->SettingsButton->Click += gcnew System::EventHandler(this, &GUI::SettingsButton_Click);
			// 
			// LoadButton
			// 
			this->LoadButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LoadButton.Image")));
			this->LoadButton->Location = System::Drawing::Point(80, 52);
			this->LoadButton->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->LoadButton->Name = L"LoadButton";
			this->LoadButton->Size = System::Drawing::Size(43, 43);
			this->LoadButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->LoadButton->TabIndex = 2;
			this->LoadButton->TabStop = false;
			this->LoadButton->Tag = L"Load Profile";
			this->LoadButton->Click += gcnew System::EventHandler(this, &GUI::LoadButton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SaveButton.Image")));
			this->SaveButton->Location = System::Drawing::Point(131, 57);
			this->SaveButton->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(37, 34);
			this->SaveButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->SaveButton->TabIndex = 3;
			this->SaveButton->TabStop = false;
			this->SaveButton->Tag = L"Save Profile";
			this->SaveButton->Click += gcnew System::EventHandler(this, &GUI::SaveButton_Click);
			// 
			// explabel
			// 
			this->explabel->AutoSize = true;
			this->explabel->ForeColor = System::Drawing::Color::Gold;
			this->explabel->Location = System::Drawing::Point(293, 7);
			this->explabel->Margin = System::Windows::Forms::Padding(0);
			this->explabel->Name = L"explabel";
			this->explabel->Size = System::Drawing::Size(43, 17);
			this->explabel->TabIndex = 25;
			this->explabel->Text = L"EXP :";
			// 
			// mplabel
			// 
			this->mplabel->AutoSize = true;
			this->mplabel->BackColor = System::Drawing::Color::Transparent;
			this->mplabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mplabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->mplabel->Location = System::Drawing::Point(163, 7);
			this->mplabel->Margin = System::Windows::Forms::Padding(0);
			this->mplabel->Name = L"mplabel";
			this->mplabel->Size = System::Drawing::Size(32, 17);
			this->mplabel->TabIndex = 24;
			this->mplabel->Text = L"MP:";
			// 
			// hplabel
			// 
			this->hplabel->AutoSize = true;
			this->hplabel->BackColor = System::Drawing::Color::Transparent;
			this->hplabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hplabel->ForeColor = System::Drawing::Color::Red;
			this->hplabel->Location = System::Drawing::Point(25, 7);
			this->hplabel->Margin = System::Windows::Forms::Padding(0);
			this->hplabel->Name = L"hplabel";
			this->hplabel->Size = System::Drawing::Size(31, 17);
			this->hplabel->TabIndex = 23;
			this->hplabel->Text = L"HP:";
			// 
			// StartButton
			// 
			this->StartButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"StartButton.Image")));
			this->StartButton->Location = System::Drawing::Point(29, 53);
			this->StartButton->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->StartButton->Name = L"StartButton";
			this->StartButton->Size = System::Drawing::Size(41, 42);
			this->StartButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->StartButton->TabIndex = 34;
			this->StartButton->TabStop = false;
			this->StartButton->Tag = L"Start MapleStory";
			this->StartButton->Click += gcnew System::EventHandler(this, &GUI::StartButton_Click);
			// 
			// mouselabel
			// 
			this->mouselabel->AutoSize = true;
			this->mouselabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mouselabel->ForeColor = System::Drawing::Color::Azure;
			this->mouselabel->Location = System::Drawing::Point(1, 0);
			this->mouselabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->mouselabel->Name = L"mouselabel";
			this->mouselabel->Size = System::Drawing::Size(53, 17);
			this->mouselabel->TabIndex = 37;
			this->mouselabel->Text = L"Mouse:";
			// 
			// worldlabel
			// 
			this->worldlabel->AutoSize = true;
			this->worldlabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->worldlabel->ForeColor = System::Drawing::Color::Azure;
			this->worldlabel->Location = System::Drawing::Point(0, 17);
			this->worldlabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->worldlabel->Name = L"worldlabel";
			this->worldlabel->Size = System::Drawing::Size(50, 17);
			this->worldlabel->TabIndex = 36;
			this->worldlabel->Text = L"World:";
			// 
			// channellabel
			// 
			this->channellabel->AutoSize = true;
			this->channellabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->channellabel->ForeColor = System::Drawing::Color::Azure;
			this->channellabel->Location = System::Drawing::Point(0, 33);
			this->channellabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->channellabel->Name = L"channellabel";
			this->channellabel->Size = System::Drawing::Size(65, 17);
			this->channellabel->TabIndex = 35;
			this->channellabel->Text = L"Channel:";
			// 
			// breathlabel
			// 
			this->breathlabel->AutoSize = true;
			this->breathlabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->breathlabel->ForeColor = System::Drawing::Color::Azure;
			this->breathlabel->Location = System::Drawing::Point(0, 65);
			this->breathlabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->breathlabel->Name = L"breathlabel";
			this->breathlabel->Size = System::Drawing::Size(55, 17);
			this->breathlabel->TabIndex = 42;
			this->breathlabel->Text = L"Breath:";
			// 
			// attacklabel
			// 
			this->attacklabel->AutoSize = true;
			this->attacklabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->attacklabel->ForeColor = System::Drawing::Color::Azure;
			this->attacklabel->Location = System::Drawing::Point(0, 49);
			this->attacklabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->attacklabel->Name = L"attacklabel";
			this->attacklabel->Size = System::Drawing::Size(61, 17);
			this->attacklabel->TabIndex = 38;
			this->attacklabel->Text = L"Attacks:";
			// 
			// CharInfoPanel
			// 
			this->CharInfoPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CharInfoPanel->Controls->Add(this->breathlabel);
			this->CharInfoPanel->Controls->Add(this->attacklabel);
			this->CharInfoPanel->Location = System::Drawing::Point(29, 293);
			this->CharInfoPanel->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->CharInfoPanel->Name = L"CharInfoPanel";
			this->CharInfoPanel->Size = System::Drawing::Size(109, 86);
			this->CharInfoPanel->TabIndex = 43;
			// 
			// ServerInfoPanel
			// 
			this->ServerInfoPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ServerInfoPanel->Controls->Add(this->mouselabel);
			this->ServerInfoPanel->Controls->Add(this->worldlabel);
			this->ServerInfoPanel->Controls->Add(this->channellabel);
			this->ServerInfoPanel->Location = System::Drawing::Point(29, 386);
			this->ServerInfoPanel->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->ServerInfoPanel->Name = L"ServerInfoPanel";
			this->ServerInfoPanel->Size = System::Drawing::Size(109, 54);
			this->ServerInfoPanel->TabIndex = 44;
			// 
			// Log
			// 
			this->Log->BackColor = System::Drawing::Color::Black;
			this->Log->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Log->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Log->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Log->ForeColor = System::Drawing::Color::Lime;
			this->Log->Location = System::Drawing::Point(31, 448);
			this->Log->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->Log->MaxLength = 999999999;
			this->Log->Multiline = true;
			this->Log->Name = L"Log";
			this->Log->ReadOnly = true;
			this->Log->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->Log->Size = System::Drawing::Size(399, 232);
			this->Log->TabIndex = 45;
			this->Log->TabStop = false;
			this->Log->Text = L"           :: ZSTrainer Log :: \r\n\r\n";
			// 
			// Status
			// 
			this->Status->AutoSize = true;
			this->Status->ForeColor = System::Drawing::Color::Red;
			this->Status->Location = System::Drawing::Point(5, 686);
			this->Status->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->Status->Name = L"Status";
			this->Status->Size = System::Drawing::Size(106, 17);
			this->Status->TabIndex = 46;
			this->Status->Text = L"Not Connected ";
			// 
			// UpdateButton
			// 
			this->UpdateButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"UpdateButton.Image")));
			this->UpdateButton->Location = System::Drawing::Point(347, 57);
			this->UpdateButton->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->UpdateButton->Name = L"UpdateButton";
			this->UpdateButton->Size = System::Drawing::Size(37, 37);
			this->UpdateButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->UpdateButton->TabIndex = 48;
			this->UpdateButton->TabStop = false;
			// 
			// ProgressBar
			// 
			this->ProgressBar->Location = System::Drawing::Point(323, 686);
			this->ProgressBar->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->ProgressBar->Name = L"ProgressBar";
			this->ProgressBar->Size = System::Drawing::Size(129, 16);
			this->ProgressBar->TabIndex = 49;
			// 
			// HackPanel
			// 
			this->HackPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->HackPanel->Controls->Add(this->ChangeCB);
			this->HackPanel->Controls->Add(this->CCButton);
			this->HackPanel->Controls->Add(this->LoginCB);
			this->HackPanel->Controls->Add(this->ALButton);
			this->HackPanel->Controls->Add(this->BotCB);
			this->HackPanel->Controls->Add(this->BotButton);
			this->HackPanel->Controls->Add(this->FilterCB);
			this->HackPanel->Controls->Add(this->VacCB);
			this->HackPanel->Controls->Add(this->label1);
			this->HackPanel->Controls->Add(this->VacButton);
			this->HackPanel->Controls->Add(this->FilterButton);
			this->HackPanel->Controls->Add(this->HackButton);
			this->HackPanel->Location = System::Drawing::Point(147, 293);
			this->HackPanel->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->HackPanel->Name = L"HackPanel";
			this->HackPanel->Size = System::Drawing::Size(282, 147);
			this->HackPanel->TabIndex = 50;
			// 
			// ChangeCB
			// 
			this->ChangeCB->AutoSize = true;
			this->ChangeCB->ForeColor = System::Drawing::Color::Azure;
			this->ChangeCB->Location = System::Drawing::Point(197, 126);
			this->ChangeCB->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->ChangeCB->Name = L"ChangeCB";
			this->ChangeCB->Size = System::Drawing::Size(70, 21);
			this->ChangeCB->TabIndex = 11;
			this->ChangeCB->Text = L"CC/CS";
			this->ChangeCB->UseVisualStyleBackColor = true;
			// 
			// CCButton
			// 
			this->CCButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CCButton.Image")));
			this->CCButton->Location = System::Drawing::Point(216, 84);
			this->CCButton->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->CCButton->Name = L"CCButton";
			this->CCButton->Size = System::Drawing::Size(43, 39);
			this->CCButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->CCButton->TabIndex = 10;
			this->CCButton->TabStop = false;
			// 
			// LoginCB
			// 
			this->LoginCB->AutoSize = true;
			this->LoginCB->ForeColor = System::Drawing::Color::Azure;
			this->LoginCB->Location = System::Drawing::Point(87, 126);
			this->LoginCB->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->LoginCB->Name = L"LoginCB";
			this->LoginCB->Size = System::Drawing::Size(98, 21);
			this->LoginCB->TabIndex = 9;
			this->LoginCB->Text = L"Auto Login";
			this->LoginCB->UseVisualStyleBackColor = true;
			this->LoginCB->CheckedChanged += gcnew System::EventHandler(this, &GUI::LoginCB_CheckedChanged);
			// 
			// ALButton
			// 
			this->ALButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ALButton.Image")));
			this->ALButton->Location = System::Drawing::Point(115, 84);
			this->ALButton->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->ALButton->Name = L"ALButton";
			this->ALButton->Size = System::Drawing::Size(43, 39);
			this->ALButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->ALButton->TabIndex = 8;
			this->ALButton->TabStop = false;
			// 
			// BotCB
			// 
			this->BotCB->AutoSize = true;
			this->BotCB->ForeColor = System::Drawing::Color::Azure;
			this->BotCB->Location = System::Drawing::Point(3, 126);
			this->BotCB->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->BotCB->Name = L"BotCB";
			this->BotCB->Size = System::Drawing::Size(51, 21);
			this->BotCB->TabIndex = 7;
			this->BotCB->Text = L"Bot";
			this->BotCB->UseVisualStyleBackColor = true;
			// 
			// BotButton
			// 
			this->BotButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BotButton.Image")));
			this->BotButton->Location = System::Drawing::Point(15, 84);
			this->BotButton->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->BotButton->Name = L"BotButton";
			this->BotButton->Size = System::Drawing::Size(47, 39);
			this->BotButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->BotButton->TabIndex = 6;
			this->BotButton->TabStop = false;
			// 
			// FilterCB
			// 
			this->FilterCB->AutoSize = true;
			this->FilterCB->ForeColor = System::Drawing::Color::Azure;
			this->FilterCB->Location = System::Drawing::Point(197, 48);
			this->FilterCB->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->FilterCB->Name = L"FilterCB";
			this->FilterCB->Size = System::Drawing::Size(61, 21);
			this->FilterCB->TabIndex = 5;
			this->FilterCB->Text = L"Filter";
			this->FilterCB->UseVisualStyleBackColor = true;
			this->FilterCB->CheckedChanged += gcnew System::EventHandler(this, &GUI::FilterCB_CheckedChanged);
			// 
			// VacCB
			// 
			this->VacCB->AutoSize = true;
			this->VacCB->ForeColor = System::Drawing::Color::Azure;
			this->VacCB->Location = System::Drawing::Point(99, 48);
			this->VacCB->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->VacCB->Name = L"VacCB";
			this->VacCB->Size = System::Drawing::Size(54, 21);
			this->VacCB->TabIndex = 4;
			this->VacCB->Text = L"Vac";
			this->VacCB->UseVisualStyleBackColor = true;
			this->VacCB->CheckedChanged += gcnew System::EventHandler(this, &GUI::VacCB_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->ForeColor = System::Drawing::Color::Azure;
			this->label1->Location = System::Drawing::Point(15, 49);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Hacks";
			// 
			// VacButton
			// 
			this->VacButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"VacButton.Image")));
			this->VacButton->Location = System::Drawing::Point(115, 4);
			this->VacButton->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->VacButton->Name = L"VacButton";
			this->VacButton->Size = System::Drawing::Size(43, 39);
			this->VacButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->VacButton->TabIndex = 2;
			this->VacButton->TabStop = false;
			// 
			// FilterButton
			// 
			this->FilterButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FilterButton.Image")));
			this->FilterButton->Location = System::Drawing::Point(216, 4);
			this->FilterButton->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->FilterButton->Name = L"FilterButton";
			this->FilterButton->Size = System::Drawing::Size(43, 39);
			this->FilterButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->FilterButton->TabIndex = 1;
			this->FilterButton->TabStop = false;
			this->FilterButton->Click += gcnew System::EventHandler(this, &GUI::FilterButton_Click);
			// 
			// HackButton
			// 
			this->HackButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"HackButton.Image")));
			this->HackButton->Location = System::Drawing::Point(19, 3);
			this->HackButton->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->HackButton->Name = L"HackButton";
			this->HackButton->Size = System::Drawing::Size(43, 39);
			this->HackButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->HackButton->TabIndex = 0;
			this->HackButton->TabStop = false;
			// 
			// InjectButton
			// 
			this->InjectButton->AccessibleDescription = L"";
			this->InjectButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"InjectButton.Image")));
			this->InjectButton->Location = System::Drawing::Point(296, 55);
			this->InjectButton->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->InjectButton->Name = L"InjectButton";
			this->InjectButton->Size = System::Drawing::Size(43, 39);
			this->InjectButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->InjectButton->TabIndex = 4;
			this->InjectButton->TabStop = false;
			this->InjectButton->Tag = L"DLL Injector";
			this->InjectButton->Click += gcnew System::EventHandler(this, &GUI::InjectButton_Click);
			// 
			// EmbedCB
			// 
			this->EmbedCB->AutoSize = true;
			this->EmbedCB->Location = System::Drawing::Point(435, 663);
			this->EmbedCB->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->EmbedCB->Name = L"EmbedCB";
			this->EmbedCB->Size = System::Drawing::Size(18, 17);
			this->EmbedCB->TabIndex = 51;
			this->EmbedCB->UseVisualStyleBackColor = true;
			this->EmbedCB->CheckedChanged += gcnew System::EventHandler(this, &GUI::EmbedCB_CheckedChanged);
			// 
			// HideCB
			// 
			this->HideCB->AutoSize = true;
			this->HideCB->Location = System::Drawing::Point(8, 665);
			this->HideCB->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->HideCB->Name = L"HideCB";
			this->HideCB->Size = System::Drawing::Size(18, 17);
			this->HideCB->TabIndex = 52;
			this->HideCB->UseVisualStyleBackColor = true;
			this->HideCB->CheckedChanged += gcnew System::EventHandler(this, &GUI::HideCB_CheckedChanged);
			// 
			// BrowseProfile
			// 
			this->BrowseProfile->Filter = L"ZS Profile (*zs)|*zs";
			// 
			// SaveProfile
			// 
			this->SaveProfile->DefaultExt = L"ini";
			this->SaveProfile->Filter = L"ZS Profile (*zs)|*zs";
			// 
			// topnamelabel
			// 
			this->topnamelabel->AutoSize = true;
			this->topnamelabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->topnamelabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->topnamelabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->topnamelabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->topnamelabel->Location = System::Drawing::Point(37, 119);
			this->topnamelabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->topnamelabel->Name = L"topnamelabel";
			this->topnamelabel->Size = System::Drawing::Size(76, 17);
			this->topnamelabel->TabIndex = 73;
			this->topnamelabel->Text = L"                 ";
			// 
			// islandlabel
			// 
			this->islandlabel->AutoSize = true;
			this->islandlabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->islandlabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->islandlabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->islandlabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->islandlabel->Location = System::Drawing::Point(37, 103);
			this->islandlabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->islandlabel->Name = L"islandlabel";
			this->islandlabel->Size = System::Drawing::Size(72, 17);
			this->islandlabel->TabIndex = 72;
			this->islandlabel->Text = L"                ";
			// 
			// npclabel
			// 
			this->npclabel->AutoSize = true;
			this->npclabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->npclabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->npclabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->npclabel->Location = System::Drawing::Point(35, 252);
			this->npclabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->npclabel->Name = L"npclabel";
			this->npclabel->Size = System::Drawing::Size(50, 17);
			this->npclabel->TabIndex = 71;
			this->npclabel->Text = L"NPC\'s:";
			// 
			// moblabel
			// 
			this->moblabel->AutoSize = true;
			this->moblabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->moblabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->moblabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->moblabel->Location = System::Drawing::Point(353, 252);
			this->moblabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->moblabel->Name = L"moblabel";
			this->moblabel->Size = System::Drawing::Size(45, 17);
			this->moblabel->TabIndex = 70;
			this->moblabel->Text = L"Mobs:";
			// 
			// itemlabel
			// 
			this->itemlabel->AutoSize = true;
			this->itemlabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->itemlabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->itemlabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->itemlabel->Location = System::Drawing::Point(353, 268);
			this->itemlabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->itemlabel->Name = L"itemlabel";
			this->itemlabel->Size = System::Drawing::Size(49, 17);
			this->itemlabel->TabIndex = 69;
			this->itemlabel->Text = L"Items:";
			// 
			// peoplelabel
			// 
			this->peoplelabel->AutoSize = true;
			this->peoplelabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->peoplelabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->peoplelabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->peoplelabel->Location = System::Drawing::Point(37, 268);
			this->peoplelabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->peoplelabel->Name = L"peoplelabel";
			this->peoplelabel->Size = System::Drawing::Size(53, 17);
			this->peoplelabel->TabIndex = 68;
			this->peoplelabel->Text = L"People:";
			// 
			// maplabel
			// 
			this->maplabel->AutoSize = true;
			this->maplabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->maplabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->maplabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->maplabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->maplabel->Location = System::Drawing::Point(37, 135);
			this->maplabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->maplabel->Name = L"maplabel";
			this->maplabel->Size = System::Drawing::Size(76, 17);
			this->maplabel->TabIndex = 66;
			this->maplabel->Text = L"                 ";
			// 
			// locationlabel
			// 
			this->locationlabel->AutoSize = true;
			this->locationlabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(1)));
			this->locationlabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->locationlabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->locationlabel->Location = System::Drawing::Point(37, 236);
			this->locationlabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->locationlabel->Name = L"locationlabel";
			this->locationlabel->Size = System::Drawing::Size(66, 17);
			this->locationlabel->TabIndex = 67;
			this->locationlabel->Text = L"Location:";
			// 
			// MiniMap
			// 
			this->MiniMap->BackColor = System::Drawing::Color::Transparent;
			this->MiniMap->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MiniMap.BackgroundImage")));
			this->MiniMap->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->MiniMap->Location = System::Drawing::Point(29, 102);
			this->MiniMap->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->MiniMap->Name = L"MiniMap";
			this->MiniMap->Size = System::Drawing::Size(399, 184);
			this->MiniMap->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->MiniMap->TabIndex = 65;
			this->MiniMap->TabStop = false;
			// 
			// HpBar
			// 
			this->HpBar->BackColor = System::Drawing::Color::Firebrick;
			this->HpBar->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->HpBar->Location = System::Drawing::Point(27, 27);
			this->HpBar->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->HpBar->Name = L"HpBar";
			this->HpBar->Size = System::Drawing::Size(0, 17);
			this->HpBar->TabIndex = 74;
			this->HpBar->TabStop = false;
			// 
			// MpBar
			// 
			this->MpBar->BackColor = System::Drawing::Color::MediumBlue;
			this->MpBar->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->MpBar->Location = System::Drawing::Point(163, 27);
			this->MpBar->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->MpBar->Name = L"MpBar";
			this->MpBar->Size = System::Drawing::Size(0, 17);
			this->MpBar->TabIndex = 75;
			this->MpBar->TabStop = false;
			// 
			// ExpBar
			// 
			this->ExpBar->BackColor = System::Drawing::Color::Gold;
			this->ExpBar->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ExpBar->Location = System::Drawing::Point(297, 27);
			this->ExpBar->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->ExpBar->Name = L"ExpBar";
			this->ExpBar->Size = System::Drawing::Size(0, 17);
			this->ExpBar->TabIndex = 76;
			this->ExpBar->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(27, 27);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(133, 17);
			this->pictureBox1->TabIndex = 77;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Location = System::Drawing::Point(163, 27);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(133, 17);
			this->pictureBox2->TabIndex = 78;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox3->Location = System::Drawing::Point(297, 27);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(133, 17);
			this->pictureBox3->TabIndex = 79;
			this->pictureBox3->TabStop = false;
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(457, 704);
			this->Controls->Add(this->explabel);
			this->Controls->Add(this->ExpBar);
			this->Controls->Add(this->hplabel);
			this->Controls->Add(this->mplabel);
			this->Controls->Add(this->MpBar);
			this->Controls->Add(this->HpBar);
			this->Controls->Add(this->topnamelabel);
			this->Controls->Add(this->islandlabel);
			this->Controls->Add(this->npclabel);
			this->Controls->Add(this->moblabel);
			this->Controls->Add(this->itemlabel);
			this->Controls->Add(this->peoplelabel);
			this->Controls->Add(this->maplabel);
			this->Controls->Add(this->locationlabel);
			this->Controls->Add(this->MiniMap);
			this->Controls->Add(this->Log);
			this->Controls->Add(this->HideCB);
			this->Controls->Add(this->EmbedCB);
			this->Controls->Add(this->InjectButton);
			this->Controls->Add(this->HackPanel);
			this->Controls->Add(this->ProgressBar);
			this->Controls->Add(this->UpdateButton);
			this->Controls->Add(this->Status);
			this->Controls->Add(this->ServerInfoPanel);
			this->Controls->Add(this->CharInfoPanel);
			this->Controls->Add(this->StartButton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->LoadButton);
			this->Controls->Add(this->SettingsButton);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox3);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->MaximizeBox = false;
			this->Name = L"GUI";
			this->Opacity = 0.85;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"::ZSTrainer::";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &GUI::GUI_Closing);
			this->Load += gcnew System::EventHandler(this, &GUI::GUI_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SettingsButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LoadButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SaveButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StartButton))->EndInit();
			this->CharInfoPanel->ResumeLayout(false);
			this->CharInfoPanel->PerformLayout();
			this->ServerInfoPanel->ResumeLayout(false);
			this->ServerInfoPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UpdateButton))->EndInit();
			this->HackPanel->ResumeLayout(false);
			this->HackPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CCButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ALButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BotButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VacButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FilterButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->HackButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InjectButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MiniMap))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->HpBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MpBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ExpBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public:	
	System::Void GUI_Closing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e );
	System::Void EmbedCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void StartButton_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void GUI_Load(System::Object^  sender, System::EventArgs^  e);
	System::Void SettingsButton_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void LoadButton_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void HideCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e);
	virtual void WndProc(System::Windows::Forms::Message %m) override;
	System::Void LoginCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void InjectButton_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void FilterButton_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void VacCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	System::Void FilterCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
};
}
