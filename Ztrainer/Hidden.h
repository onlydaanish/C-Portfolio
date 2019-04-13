#pragma once

namespace ZS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Hidden
	/// </summary>
	public ref class Hidden : public System::Windows::Forms::Form
	{
	public:
		static Hidden^ Gui;
		Hidden(void)
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
		~Hidden()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->SuspendLayout();
			// 
			// Hidden
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(88, 21);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MinimizeBox = false;
			this->Name = L"Hidden";
			this->Opacity = 0;
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"Hidden";
			this->Load += gcnew System::EventHandler(this, &Hidden::Hidden_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		virtual void WndProc(System::Windows::Forms::Message %m) override;
		private: System::Void Hidden_Load(System::Object^  sender, System::EventArgs^  e);
	};
}
