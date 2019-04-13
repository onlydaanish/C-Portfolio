#pragma once

namespace testhack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ghsd
	/// </summary>
	public ref class ghsd : public System::Windows::Forms::Form
	{
	public:
		static ghsd ^Gui;
		ghsd(void)
		{
			
			InitializeComponent();
			//
			Gui = this;
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ghsd()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Timer^  timer1;
	public: System::Windows::Forms::Label^  label1;
	private: System::ComponentModel::IContainer^  components;
	public: 
	protected: 


	public:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &ghsd::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(74, 100);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// ghsd
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->label1);
			this->Name = L"ghsd";
			this->Text = L"ghsd";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ghsd_Load(System::Object^  sender, System::EventArgs^  e);
				
	};
}
