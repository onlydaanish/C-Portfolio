#ifdef DEBUG

//#include <Map.h>
#include <Character.h>

#pragma once

namespace ZSTrainer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DevScreen
	/// </summary>
	public ref class DevScreen : public System::Windows::Forms::Form
	{
	public:
		DevScreen(void)
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
		~DevScreen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  CharacterGroupBox;
	private: System::Windows::Forms::Label^  CharacterHPLabel;
	private: System::Windows::Forms::GroupBox^  MapGroupBox;
	private: System::Windows::Forms::Label^  MapOffsetRightLabel;
	private: System::Windows::Forms::Label^  MapOffsetLeftLabel;
	private: System::Windows::Forms::Label^  MapOffsetBottomLabel;
	private: System::Windows::Forms::Label^  MapOffsetTopLabel;
	private: System::Windows::Forms::Label^  MapHeightLabel;
	private: System::Windows::Forms::Label^  MapWidthLabel;
	private: System::Windows::Forms::Label^  MapYPosLabel;
	private: System::Windows::Forms::Label^  MapXPosLabel;
	private: System::Windows::Forms::Label^  MapYRatioLabel;
	private: System::Windows::Forms::Label^  MapXRatioLabel;
	private: System::Windows::Forms::Label^  MapMiniHeightLabel;
	private: System::Windows::Forms::Label^  MapMiniWidthLabel;
	private: System::Windows::Forms::Label^  MapNPCsLabel;
	private: System::Windows::Forms::Label^  MapPortalsLabel;
	private: System::Windows::Forms::Timer^  DevUpdateTimer;
	private: System::ComponentModel::IContainer^  components;

	private:

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->CharacterGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->CharacterHPLabel = (gcnew System::Windows::Forms::Label());
			this->MapGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->MapNPCsLabel = (gcnew System::Windows::Forms::Label());
			this->MapPortalsLabel = (gcnew System::Windows::Forms::Label());
			this->MapYPosLabel = (gcnew System::Windows::Forms::Label());
			this->MapXPosLabel = (gcnew System::Windows::Forms::Label());
			this->MapYRatioLabel = (gcnew System::Windows::Forms::Label());
			this->MapXRatioLabel = (gcnew System::Windows::Forms::Label());
			this->MapMiniHeightLabel = (gcnew System::Windows::Forms::Label());
			this->MapMiniWidthLabel = (gcnew System::Windows::Forms::Label());
			this->MapOffsetRightLabel = (gcnew System::Windows::Forms::Label());
			this->MapOffsetLeftLabel = (gcnew System::Windows::Forms::Label());
			this->MapOffsetBottomLabel = (gcnew System::Windows::Forms::Label());
			this->MapOffsetTopLabel = (gcnew System::Windows::Forms::Label());
			this->MapHeightLabel = (gcnew System::Windows::Forms::Label());
			this->MapWidthLabel = (gcnew System::Windows::Forms::Label());
			this->DevUpdateTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->CharacterGroupBox->SuspendLayout();
			this->MapGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// CharacterGroupBox
			// 
			this->CharacterGroupBox->Controls->Add(this->CharacterHPLabel);
			this->CharacterGroupBox->Location = System::Drawing::Point(24, 28);
			this->CharacterGroupBox->Name = L"CharacterGroupBox";
			this->CharacterGroupBox->Size = System::Drawing::Size(200, 49);
			this->CharacterGroupBox->TabIndex = 0;
			this->CharacterGroupBox->TabStop = false;
			this->CharacterGroupBox->Text = L"Character";
			// 
			// CharacterHPLabel
			// 
			this->CharacterHPLabel->AutoSize = true;
			this->CharacterHPLabel->Location = System::Drawing::Point(6, 16);
			this->CharacterHPLabel->Name = L"CharacterHPLabel";
			this->CharacterHPLabel->Size = System::Drawing::Size(25, 13);
			this->CharacterHPLabel->TabIndex = 1;
			this->CharacterHPLabel->Text = L"HP:";
			// 
			// MapGroupBox
			// 
			this->MapGroupBox->Controls->Add(this->MapNPCsLabel);
			this->MapGroupBox->Controls->Add(this->MapPortalsLabel);
			this->MapGroupBox->Controls->Add(this->MapYPosLabel);
			this->MapGroupBox->Controls->Add(this->MapXPosLabel);
			this->MapGroupBox->Controls->Add(this->MapYRatioLabel);
			this->MapGroupBox->Controls->Add(this->MapXRatioLabel);
			this->MapGroupBox->Controls->Add(this->MapMiniHeightLabel);
			this->MapGroupBox->Controls->Add(this->MapMiniWidthLabel);
			this->MapGroupBox->Controls->Add(this->MapOffsetRightLabel);
			this->MapGroupBox->Controls->Add(this->MapOffsetLeftLabel);
			this->MapGroupBox->Controls->Add(this->MapOffsetBottomLabel);
			this->MapGroupBox->Controls->Add(this->MapOffsetTopLabel);
			this->MapGroupBox->Controls->Add(this->MapHeightLabel);
			this->MapGroupBox->Controls->Add(this->MapWidthLabel);
			this->MapGroupBox->Location = System::Drawing::Point(24, 97);
			this->MapGroupBox->Name = L"MapGroupBox";
			this->MapGroupBox->Size = System::Drawing::Size(234, 174);
			this->MapGroupBox->TabIndex = 2;
			this->MapGroupBox->TabStop = false;
			this->MapGroupBox->Text = L"Map ID:";
			// 
			// MapNPCsLabel
			// 
			this->MapNPCsLabel->AutoSize = true;
			this->MapNPCsLabel->Location = System::Drawing::Point(14, 29);
			this->MapNPCsLabel->Name = L"MapNPCsLabel";
			this->MapNPCsLabel->Size = System::Drawing::Size(37, 13);
			this->MapNPCsLabel->TabIndex = 14;
			this->MapNPCsLabel->Text = L"NPCs:";
			// 
			// MapPortalsLabel
			// 
			this->MapPortalsLabel->AutoSize = true;
			this->MapPortalsLabel->Location = System::Drawing::Point(9, 16);
			this->MapPortalsLabel->Name = L"MapPortalsLabel";
			this->MapPortalsLabel->Size = System::Drawing::Size(42, 13);
			this->MapPortalsLabel->TabIndex = 13;
			this->MapPortalsLabel->Text = L"Portals:";
			// 
			// MapYPosLabel
			// 
			this->MapYPosLabel->AutoSize = true;
			this->MapYPosLabel->Location = System::Drawing::Point(123, 154);
			this->MapYPosLabel->Name = L"MapYPosLabel";
			this->MapYPosLabel->Size = System::Drawing::Size(38, 13);
			this->MapYPosLabel->TabIndex = 12;
			this->MapYPosLabel->Text = L"Y Pos:";
			// 
			// MapXPosLabel
			// 
			this->MapXPosLabel->AutoSize = true;
			this->MapXPosLabel->Location = System::Drawing::Point(123, 141);
			this->MapXPosLabel->Name = L"MapXPosLabel";
			this->MapXPosLabel->Size = System::Drawing::Size(38, 13);
			this->MapXPosLabel->TabIndex = 11;
			this->MapXPosLabel->Text = L"X Pos:";
			// 
			// MapYRatioLabel
			// 
			this->MapYRatioLabel->AutoSize = true;
			this->MapYRatioLabel->Location = System::Drawing::Point(45, 154);
			this->MapYRatioLabel->Name = L"MapYRatioLabel";
			this->MapYRatioLabel->Size = System::Drawing::Size(45, 13);
			this->MapYRatioLabel->TabIndex = 10;
			this->MapYRatioLabel->Text = L"Y Ratio:";
			// 
			// MapXRatioLabel
			// 
			this->MapXRatioLabel->AutoSize = true;
			this->MapXRatioLabel->Location = System::Drawing::Point(45, 141);
			this->MapXRatioLabel->Name = L"MapXRatioLabel";
			this->MapXRatioLabel->Size = System::Drawing::Size(45, 13);
			this->MapXRatioLabel->TabIndex = 9;
			this->MapXRatioLabel->Text = L"X Ratio:";
			// 
			// MapMiniHeightLabel
			// 
			this->MapMiniHeightLabel->AutoSize = true;
			this->MapMiniHeightLabel->Location = System::Drawing::Point(3, 125);
			this->MapMiniHeightLabel->Name = L"MapMiniHeightLabel";
			this->MapMiniHeightLabel->Size = System::Drawing::Size(87, 13);
			this->MapMiniHeightLabel->TabIndex = 8;
			this->MapMiniHeightLabel->Text = L"Mini Map Height:";
			// 
			// MapMiniWidthLabel
			// 
			this->MapMiniWidthLabel->AutoSize = true;
			this->MapMiniWidthLabel->Location = System::Drawing::Point(6, 112);
			this->MapMiniWidthLabel->Name = L"MapMiniWidthLabel";
			this->MapMiniWidthLabel->Size = System::Drawing::Size(84, 13);
			this->MapMiniWidthLabel->TabIndex = 7;
			this->MapMiniWidthLabel->Text = L"Mini Map Width:";
			// 
			// MapOffsetRightLabel
			// 
			this->MapOffsetRightLabel->AutoSize = true;
			this->MapOffsetRightLabel->Location = System::Drawing::Point(91, 98);
			this->MapOffsetRightLabel->Name = L"MapOffsetRightLabel";
			this->MapOffsetRightLabel->Size = System::Drawing::Size(66, 13);
			this->MapOffsetRightLabel->TabIndex = 6;
			this->MapOffsetRightLabel->Text = L"Offset Right:";
			// 
			// MapOffsetLeftLabel
			// 
			this->MapOffsetLeftLabel->AutoSize = true;
			this->MapOffsetLeftLabel->Location = System::Drawing::Point(98, 85);
			this->MapOffsetLeftLabel->Name = L"MapOffsetLeftLabel";
			this->MapOffsetLeftLabel->Size = System::Drawing::Size(59, 13);
			this->MapOffsetLeftLabel->TabIndex = 5;
			this->MapOffsetLeftLabel->Text = L"Offset Left:";
			// 
			// MapOffsetBottomLabel
			// 
			this->MapOffsetBottomLabel->AutoSize = true;
			this->MapOffsetBottomLabel->Location = System::Drawing::Point(83, 72);
			this->MapOffsetBottomLabel->Name = L"MapOffsetBottomLabel";
			this->MapOffsetBottomLabel->Size = System::Drawing::Size(74, 13);
			this->MapOffsetBottomLabel->TabIndex = 4;
			this->MapOffsetBottomLabel->Text = L"Offset Bottom:";
			// 
			// MapOffsetTopLabel
			// 
			this->MapOffsetTopLabel->AutoSize = true;
			this->MapOffsetTopLabel->Location = System::Drawing::Point(97, 59);
			this->MapOffsetTopLabel->Name = L"MapOffsetTopLabel";
			this->MapOffsetTopLabel->Size = System::Drawing::Size(60, 13);
			this->MapOffsetTopLabel->TabIndex = 3;
			this->MapOffsetTopLabel->Text = L"Offset Top:";
			// 
			// MapHeightLabel
			// 
			this->MapHeightLabel->AutoSize = true;
			this->MapHeightLabel->Location = System::Drawing::Point(6, 72);
			this->MapHeightLabel->Name = L"MapHeightLabel";
			this->MapHeightLabel->Size = System::Drawing::Size(41, 13);
			this->MapHeightLabel->TabIndex = 2;
			this->MapHeightLabel->Text = L"Height:";
			// 
			// MapWidthLabel
			// 
			this->MapWidthLabel->AutoSize = true;
			this->MapWidthLabel->Location = System::Drawing::Point(6, 59);
			this->MapWidthLabel->Name = L"MapWidthLabel";
			this->MapWidthLabel->Size = System::Drawing::Size(38, 13);
			this->MapWidthLabel->TabIndex = 1;
			this->MapWidthLabel->Text = L"Width:";
			// 
			// DevUpdateTimer
			// 
			this->DevUpdateTimer->Enabled = true;
			this->DevUpdateTimer->Interval = 10;
			this->DevUpdateTimer->Tick += gcnew System::EventHandler(this, &DevScreen::DevUpdateTimer_Tick);
			// 
			// DevScreen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(366, 283);
			this->Controls->Add(this->MapGroupBox);
			this->Controls->Add(this->CharacterGroupBox);
			this->Name = L"DevScreen";
			this->ShowIcon = false;
			this->Text = L"DevScreen";
			this->CharacterGroupBox->ResumeLayout(false);
			this->CharacterGroupBox->PerformLayout();
			this->MapGroupBox->ResumeLayout(false);
			this->MapGroupBox->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void DevUpdateTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
			 MapGroupBox->Text = "Map (" + MapID + ")" + " " + MapName;
			 MapPortalsLabel->Text = "Portals: " + "-";
			 MapNPCsLabel->Text = "NPCs: " + "-";
			 MapWidth->Text = "X: " + MapX;
			 MapHeight->Text = "Y: " + MapY;
			 MapOffsetTopLabel->Text = "Offset Top: " + "";
		 }
};
}
#endif