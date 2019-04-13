#pragma once

namespace ZSTrainer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Injector
	/// </summary>
	public ref class Injector : public System::Windows::Forms::Form
	{
		static Injector^ iGui;
	public:
		Injector(void)
		{
			InitializeComponent();
			//
			iGui = this;
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Injector()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  InjectButton;
	protected:

	private: System::Windows::Forms::Button^  BrowseButton;

	private: System::Windows::Forms::OpenFileDialog^  BrowseDLL;


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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->InjectButton = (gcnew System::Windows::Forms::Button());
			this->BrowseButton = (gcnew System::Windows::Forms::Button());
			this->BrowseDLL = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(346, 22);
			this->textBox1->TabIndex = 0;
			// 
			// InjectButton
			// 
			this->InjectButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->InjectButton->ForeColor = System::Drawing::Color::White;
			this->InjectButton->Location = System::Drawing::Point(12, 40);
			this->InjectButton->Name = L"InjectButton";
			this->InjectButton->Size = System::Drawing::Size(376, 27);
			this->InjectButton->TabIndex = 1;
			this->InjectButton->Text = L"Inject";
			this->InjectButton->UseVisualStyleBackColor = true;
			this->InjectButton->Click += gcnew System::EventHandler(this, &Injector::InjectButton_Click);
			// 
			// BrowseButton
			// 
			this->BrowseButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->BrowseButton->Location = System::Drawing::Point(364, 12);
			this->BrowseButton->Name = L"BrowseButton";
			this->BrowseButton->Size = System::Drawing::Size(24, 22);
			this->BrowseButton->TabIndex = 2;
			this->BrowseButton->Text = L",,,";
			this->BrowseButton->UseVisualStyleBackColor = true;
			this->BrowseButton->Click += gcnew System::EventHandler(this, &Injector::BrowseButton_Click);
			// 
			// BrowseDLL
			// 
			this->BrowseDLL->Filter = L"Dynamic Link Library | .dll";
			// 
			// Injector
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(400, 79);
			this->Controls->Add(this->BrowseButton);
			this->Controls->Add(this->InjectButton);
			this->Controls->Add(this->textBox1);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Injector";
			this->Text = L"                              Dll Injector";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void InjectButton_Click(System::Object^  sender, System::EventArgs^  e);
	public: System::Void BrowseButton_Click(System::Object^  sender, System::EventArgs^  e);
};
}
