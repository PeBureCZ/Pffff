#pragma once
#include "ProgramSettings.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;




namespace Pffff 
{

	/// <summary>
	/// Summary for ScanControl
	/// </summary>

	public ref class ScanControl : public System::Windows::Forms::UserControl
	{

	public:
		ScanControl(ProgramSettings^ settingObj, ProgramFunctions^ functionObj)
		//ScanControl()
		{
			InitializeComponent();
			ScanBut->Click += gcnew System::EventHandler(this, &ScanControl::ScanBut_Click);
			initializeMain(settingObj, functionObj);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ScanControl()
		{

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ScanBut;
	protected:

	private: System::Windows::Forms::TextBox^ console;
	private: System::Windows::Forms::Button^ resetBut;

	private: System::Windows::Forms::Label^ findedItemsLabel;
	private: System::Windows::Forms::Label^ findedItemsCount;
	private: System::Windows::Forms::Label^ versionText;
	private: System::Windows::Forms::PictureBox^ imageBox;
	private: System::Windows::Forms::Button^ previousBut;
	private: System::Windows::Forms::Button^ nextBut;

	private: System::Windows::Forms::TextBox^ ImgTextBox;
	private: System::Windows::Forms::ListBox^ FindBox;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ScanControl::typeid));
			this->ScanBut = (gcnew System::Windows::Forms::Button());
			this->console = (gcnew System::Windows::Forms::TextBox());
			this->resetBut = (gcnew System::Windows::Forms::Button());
			this->findedItemsLabel = (gcnew System::Windows::Forms::Label());
			this->findedItemsCount = (gcnew System::Windows::Forms::Label());
			this->versionText = (gcnew System::Windows::Forms::Label());
			this->imageBox = (gcnew System::Windows::Forms::PictureBox());
			this->previousBut = (gcnew System::Windows::Forms::Button());
			this->nextBut = (gcnew System::Windows::Forms::Button());
			this->ImgTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FindBox = (gcnew System::Windows::Forms::ListBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imageBox))->BeginInit();
			this->SuspendLayout();
			// 
			// ScanBut
			// 
			this->ScanBut->BackColor = System::Drawing::Color::Gray;
			this->ScanBut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ScanBut->Location = System::Drawing::Point(24, 38);
			this->ScanBut->Name = L"ScanBut";
			this->ScanBut->Size = System::Drawing::Size(345, 35);
			this->ScanBut->TabIndex = 0;
			this->ScanBut->Text = L"Apply filter and scan";
			this->ScanBut->UseVisualStyleBackColor = false;
			// 
			// console
			// 
			this->console->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->console->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->console->Location = System::Drawing::Point(24, 311);
			this->console->Multiline = true;
			this->console->Name = L"console";
			this->console->ReadOnly = true;
			this->console->Size = System::Drawing::Size(604, 95);
			this->console->TabIndex = 1;
			this->console->Text = L"Welcome to the Pfff (Personal filter for file find) console...";
			// 
			// resetBut
			// 
			this->resetBut->BackColor = System::Drawing::Color::Gray;
			this->resetBut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resetBut->Location = System::Drawing::Point(24, 89);
			this->resetBut->Name = L"resetBut";
			this->resetBut->Size = System::Drawing::Size(345, 35);
			this->resetBut->TabIndex = 2;
			this->resetBut->Text = L"Reset all filters , finded files, and paths";
			this->resetBut->UseVisualStyleBackColor = false;
			// 
			// findedItemsLabel
			// 
			this->findedItemsLabel->AutoSize = true;
			this->findedItemsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->findedItemsLabel->Location = System::Drawing::Point(404, 264);
			this->findedItemsLabel->Name = L"findedItemsLabel";
			this->findedItemsLabel->Size = System::Drawing::Size(101, 20);
			this->findedItemsLabel->TabIndex = 3;
			this->findedItemsLabel->Text = L"Items finded:";
			// 
			// findedItemsCount
			// 
			this->findedItemsCount->AutoSize = true;
			this->findedItemsCount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->findedItemsCount->Location = System::Drawing::Point(511, 264);
			this->findedItemsCount->Name = L"findedItemsCount";
			this->findedItemsCount->Size = System::Drawing::Size(18, 20);
			this->findedItemsCount->TabIndex = 4;
			this->findedItemsCount->Text = L"0";
			// 
			// versionText
			// 
			this->versionText->AutoSize = true;
			this->versionText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->versionText->Location = System::Drawing::Point(539, 12);
			this->versionText->Name = L"versionText";
			this->versionText->Size = System::Drawing::Size(89, 12);
			this->versionText->TabIndex = 5;
			this->versionText->Text = L"version 0.0.230809a";
			this->versionText->TextAlign = System::Drawing::ContentAlignment::BottomRight;
			// 
			// imageBox
			// 
			this->imageBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->imageBox->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->imageBox->Cursor = System::Windows::Forms::Cursors::PanEast;
			this->imageBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imageBox.Image")));
			this->imageBox->Location = System::Drawing::Point(408, 38);
			this->imageBox->Name = L"imageBox";
			this->imageBox->Size = System::Drawing::Size(220, 184);
			this->imageBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->imageBox->TabIndex = 6;
			this->imageBox->TabStop = false;
			// 
			// previousBut
			// 
			this->previousBut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->previousBut->Location = System::Drawing::Point(408, 228);
			this->previousBut->Name = L"previousBut";
			this->previousBut->Size = System::Drawing::Size(75, 23);
			this->previousBut->TabIndex = 7;
			this->previousBut->Text = L"previous";
			this->previousBut->UseVisualStyleBackColor = true;
			// 
			// nextBut
			// 
			this->nextBut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->nextBut->Location = System::Drawing::Point(489, 228);
			this->nextBut->Name = L"nextBut";
			this->nextBut->Size = System::Drawing::Size(75, 23);
			this->nextBut->TabIndex = 8;
			this->nextBut->Text = L"next";
			this->nextBut->UseVisualStyleBackColor = true;
			// 
			// ImgTextBox
			// 
			this->ImgTextBox->Location = System::Drawing::Point(569, 229);
			this->ImgTextBox->Name = L"ImgTextBox";
			this->ImgTextBox->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->ImgTextBox->Size = System::Drawing::Size(59, 20);
			this->ImgTextBox->TabIndex = 9;
			this->ImgTextBox->Text = L"0";
			// 
			// FindBox
			// 
			this->FindBox->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->FindBox->FormattingEnabled = true;
			this->FindBox->Location = System::Drawing::Point(24, 154);
			this->FindBox->Name = L"FindBox";
			this->FindBox->ScrollAlwaysVisible = true;
			this->FindBox->Size = System::Drawing::Size(345, 147);
			this->FindBox->TabIndex = 10;
			// 
			// ScanControl
			// 
			this->AccessibleName = L"";
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Controls->Add(this->FindBox);
			this->Controls->Add(this->ImgTextBox);
			this->Controls->Add(this->nextBut);
			this->Controls->Add(this->previousBut);
			this->Controls->Add(this->imageBox);
			this->Controls->Add(this->versionText);
			this->Controls->Add(this->findedItemsCount);
			this->Controls->Add(this->findedItemsLabel);
			this->Controls->Add(this->resetBut);
			this->Controls->Add(this->console);
			this->Controls->Add(this->ScanBut);
			this->MaximumSize = System::Drawing::Size(650, 415);
			this->MinimumSize = System::Drawing::Size(650, 415);
			this->Name = L"ScanControl";
			this->Size = System::Drawing::Size(650, 415);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imageBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
		
		
	private: System::Void ScanBut_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Functions->addToConsole("test0");
		Functions->addToConsole("test1");
		Functions->addToConsole("test2");
		Functions->addToConsole("test3");
		List <String^>^ consoleOutput = Functions->getConsoleOutput();
		printToConsole(consoleOutput);


		//if (Functions->FindDateFormat("C:/Users/o/Downloads/smazat_C++/narozeniny.JPG"))
		//{
		//	this->findedItemsCount->Text = "true";
		//}
		//else this->findedItemsCount->Text = "false";

		//addToConsole();
	}

	ProgramSettings^ Setting;
	ProgramFunctions^ Functions;
	void initializeMain(ProgramSettings^ setting, ProgramFunctions^ functions)
	{
		Setting = setting;
		Functions = functions;
	}

	void printToConsole(List <String^>^ consoleText)
	{
		String^ consoleFullText;
		for each (String ^ line in consoleText)
		{
			consoleFullText += line + "\r\n";
		
		}
		this->console->Text = consoleFullText;

	}

};
}



