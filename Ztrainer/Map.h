#pragma once

namespace ZS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Map
	/// </summary>
	public ref class Map : public System::Windows::Forms::Form
	{
	public:
		static Map^ MiniMap;
		Map(void)
		{
			InitializeComponent();
			MiniMap = this;
		}

	public:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Map()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^  Picture;
	public: System::Windows::Forms::PictureBox^  Character;
	public: System::Windows::Forms::Label^  label1;
	public: 
	public: System::Windows::Forms::Label^  label2;
	public: 

	public: 

	public: 

	public: 

	public:
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Map::typeid));
			this->Picture = (gcnew System::Windows::Forms::PictureBox());
			this->Character = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Picture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Character))->BeginInit();
			this->SuspendLayout();
			// 
			// Picture
			// 
			this->Picture->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Picture->Location = System::Drawing::Point(0, 0);
			this->Picture->Name = L"Picture";
			this->Picture->Size = System::Drawing::Size(81, 197);
			this->Picture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->Picture->TabIndex = 0;
			this->Picture->TabStop = false;
			// 
			// Character
			// 
			this->Character->BackColor = System::Drawing::Color::Yellow;
			this->Character->Location = System::Drawing::Point(12, 12);
			this->Character->Name = L"Character";
			this->Character->Size = System::Drawing::Size(6, 6);
			this->Character->TabIndex = 1;
			this->Character->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(146, 110);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(146, 123);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"label2";
			// 
			// Map
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(286, 277);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Character);
			this->Controls->Add(this->Picture);
			this->DoubleBuffered = true;
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Map";
			this->Opacity = 0.7;
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L":: ZS Trainer ::";
			this->TopMost = true;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Map::Map_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Map::Map_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Picture))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Character))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		 System::Void Map_Load(System::Object^  sender, System::EventArgs^  e);
		 System::Void Map_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	};
}
