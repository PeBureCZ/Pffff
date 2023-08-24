#pragma once
#include "ProgramSettings.h"
#include "ProgramFunctions.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

using namespace System::Threading::Tasks;



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
			initializeMain(settingObj, functionObj);

			ScanBut->Click += gcnew System::EventHandler(this, &ScanControl::ScanBut_Click);
			previousBut->Click += gcnew System::EventHandler(this, &ScanControl::previous_Click);
			nextBut->Click += gcnew System::EventHandler(this, &ScanControl::next_Click);
			ImgTextBox->TextChanged += gcnew System::EventHandler(this, &ScanControl::OnTextChanged);
			FindBox->SelectedValueChanged += gcnew System::EventHandler(this, &ScanControl::selectIndexInFindBox);
			ResetBut->Click += gcnew System::EventHandler(this, &ScanControl::reset_Click);

			//console buttons

			console_upMax_but->Click += gcnew System::EventHandler(this, &ScanControl::upMaxConsoleOnClick);
			console_up_but->Click += gcnew System::EventHandler(this, &ScanControl::upConsoleOnClick);
			console_down_but->Click += gcnew System::EventHandler(this, &ScanControl::downConsoleOnClick);
			console_downMax_but->Click += gcnew System::EventHandler(this, &ScanControl::downMaxConsoleOnClick);
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
	private: System::Windows::Forms::Button^ ResetBut;


	private: System::Windows::Forms::Label^ findedItemsLabel;
	private: System::Windows::Forms::Label^ findedItemsCount;
	private: System::Windows::Forms::Label^ versionText;
	private: System::Windows::Forms::PictureBox^ ImageBox;

	private: System::Windows::Forms::Button^ previousBut;
	private: System::Windows::Forms::Button^ nextBut;

	private: System::Windows::Forms::TextBox^ ImgTextBox;
	private: System::Windows::Forms::ListBox^ FindBox;
	private: System::Windows::Forms::Button^ console_upMax_but;
	private: System::Windows::Forms::Button^ console_downMax_but;
	private: System::Windows::Forms::Button^ console_up_but;
	private: System::Windows::Forms::Button^ console_down_but;

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
			this->ResetBut = (gcnew System::Windows::Forms::Button());
			this->findedItemsLabel = (gcnew System::Windows::Forms::Label());
			this->findedItemsCount = (gcnew System::Windows::Forms::Label());
			this->versionText = (gcnew System::Windows::Forms::Label());
			this->ImageBox = (gcnew System::Windows::Forms::PictureBox());
			this->previousBut = (gcnew System::Windows::Forms::Button());
			this->nextBut = (gcnew System::Windows::Forms::Button());
			this->ImgTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FindBox = (gcnew System::Windows::Forms::ListBox());
			this->console_upMax_but = (gcnew System::Windows::Forms::Button());
			this->console_downMax_but = (gcnew System::Windows::Forms::Button());
			this->console_up_but = (gcnew System::Windows::Forms::Button());
			this->console_down_but = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ImageBox))->BeginInit();
			this->SuspendLayout();
			// 
			// ScanBut
			// 
			this->ScanBut->BackColor = System::Drawing::Color::Green;
			this->ScanBut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ScanBut->Location = System::Drawing::Point(7, 38);
			this->ScanBut->Name = L"ScanBut";
			this->ScanBut->Size = System::Drawing::Size(423, 45);
			this->ScanBut->TabIndex = 0;
			this->ScanBut->Text = L"Apply filter and scan";
			this->ScanBut->UseVisualStyleBackColor = false;
			// 
			// console
			// 
			this->console->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->console->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->console->Location = System::Drawing::Point(7, 294);
			this->console->Multiline = true;
			this->console->Name = L"console";
			this->console->ReadOnly = true;
			this->console->Size = System::Drawing::Size(587, 111);
			this->console->TabIndex = 1;
			this->console->Text = L"Console start...";
			// 
			// ResetBut
			// 
			this->ResetBut->BackColor = System::Drawing::Color::RosyBrown;
			this->ResetBut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ResetBut->Location = System::Drawing::Point(7, 89);
			this->ResetBut->Name = L"ResetBut";
			this->ResetBut->Size = System::Drawing::Size(423, 35);
			this->ResetBut->TabIndex = 2;
			this->ResetBut->Text = L"Reset all finded files, and paths";
			this->ResetBut->UseVisualStyleBackColor = false;
			this->ResetBut->Visible = false;
			// 
			// findedItemsLabel
			// 
			this->findedItemsLabel->AutoSize = true;
			this->findedItemsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->findedItemsLabel->Location = System::Drawing::Point(436, 250);
			this->findedItemsLabel->Name = L"findedItemsLabel";
			this->findedItemsLabel->Size = System::Drawing::Size(116, 24);
			this->findedItemsLabel->TabIndex = 3;
			this->findedItemsLabel->Text = L"Items finded:";
			// 
			// findedItemsCount
			// 
			this->findedItemsCount->AutoSize = true;
			this->findedItemsCount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->findedItemsCount->Location = System::Drawing::Point(558, 250);
			this->findedItemsCount->Name = L"findedItemsCount";
			this->findedItemsCount->Size = System::Drawing::Size(20, 24);
			this->findedItemsCount->TabIndex = 4;
			this->findedItemsCount->Text = L"0";
			// 
			// versionText
			// 
			this->versionText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->versionText->Location = System::Drawing::Point(422, 0);
			this->versionText->Name = L"versionText";
			this->versionText->Size = System::Drawing::Size(228, 22);
			this->versionText->TabIndex = 5;
			this->versionText->Text = L"versionText";
			this->versionText->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// ImageBox
			// 
			this->ImageBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ImageBox->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->ImageBox->Cursor = System::Windows::Forms::Cursors::PanEast;
			this->ImageBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ImageBox.Image")));
			this->ImageBox->Location = System::Drawing::Point(436, 38);
			this->ImageBox->Name = L"ImageBox";
			this->ImageBox->Size = System::Drawing::Size(194, 164);
			this->ImageBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->ImageBox->TabIndex = 6;
			this->ImageBox->TabStop = false;
			// 
			// previousBut
			// 
			this->previousBut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->previousBut->Location = System::Drawing::Point(436, 208);
			this->previousBut->Name = L"previousBut";
			this->previousBut->Size = System::Drawing::Size(54, 23);
			this->previousBut->TabIndex = 7;
			this->previousBut->Text = L"previous";
			this->previousBut->UseVisualStyleBackColor = true;
			// 
			// nextBut
			// 
			this->nextBut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->nextBut->Location = System::Drawing::Point(496, 208);
			this->nextBut->Name = L"nextBut";
			this->nextBut->Size = System::Drawing::Size(64, 23);
			this->nextBut->TabIndex = 8;
			this->nextBut->Text = L"next";
			this->nextBut->UseVisualStyleBackColor = true;
			// 
			// ImgTextBox
			// 
			this->ImgTextBox->Location = System::Drawing::Point(566, 209);
			this->ImgTextBox->Name = L"ImgTextBox";
			this->ImgTextBox->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->ImgTextBox->Size = System::Drawing::Size(64, 20);
			this->ImgTextBox->TabIndex = 9;
			this->ImgTextBox->Text = L"0";
			// 
			// FindBox
			// 
			this->FindBox->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->FindBox->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->FindBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->FindBox->FormattingEnabled = true;
			this->FindBox->HorizontalScrollbar = true;
			this->FindBox->ItemHeight = 12;
			this->FindBox->Location = System::Drawing::Point(7, 130);
			this->FindBox->Name = L"FindBox";
			this->FindBox->ScrollAlwaysVisible = true;
			this->FindBox->Size = System::Drawing::Size(423, 160);
			this->FindBox->TabIndex = 10;
			// 
			// console_upMax_but
			// 
			this->console_upMax_but->AllowDrop = true;
			this->console_upMax_but->AutoSize = true;
			this->console_upMax_but->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->console_upMax_but->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"console_upMax_but.Image")));
			this->console_upMax_but->Location = System::Drawing::Point(600, 294);
			this->console_upMax_but->Name = L"console_upMax_but";
			this->console_upMax_but->Size = System::Drawing::Size(30, 30);
			this->console_upMax_but->TabIndex = 11;
			this->console_upMax_but->UseVisualStyleBackColor = true;
			// 
			// console_downMax_but
			// 
			this->console_downMax_but->AllowDrop = true;
			this->console_downMax_but->AutoSize = true;
			this->console_downMax_but->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->console_downMax_but->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"console_downMax_but.Image")));
			this->console_downMax_but->Location = System::Drawing::Point(600, 375);
			this->console_downMax_but->Name = L"console_downMax_but";
			this->console_downMax_but->Size = System::Drawing::Size(30, 30);
			this->console_downMax_but->TabIndex = 12;
			this->console_downMax_but->UseVisualStyleBackColor = true;
			// 
			// console_up_but
			// 
			this->console_up_but->AllowDrop = true;
			this->console_up_but->AutoSize = true;
			this->console_up_but->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->console_up_but->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"console_up_but.Image")));
			this->console_up_but->Location = System::Drawing::Point(600, 321);
			this->console_up_but->Name = L"console_up_but";
			this->console_up_but->Size = System::Drawing::Size(30, 30);
			this->console_up_but->TabIndex = 13;
			this->console_up_but->UseVisualStyleBackColor = true;
			// 
			// console_down_but
			// 
			this->console_down_but->AllowDrop = true;
			this->console_down_but->AutoSize = true;
			this->console_down_but->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->console_down_but->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"console_down_but.Image")));
			this->console_down_but->Location = System::Drawing::Point(600, 348);
			this->console_down_but->Name = L"console_down_but";
			this->console_down_but->Size = System::Drawing::Size(30, 30);
			this->console_down_but->TabIndex = 14;
			this->console_down_but->UseVisualStyleBackColor = true;
			// 
			// ScanControl
			// 
			this->AccessibleName = L"";
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Controls->Add(this->console_down_but);
			this->Controls->Add(this->console_up_but);
			this->Controls->Add(this->console_downMax_but);
			this->Controls->Add(this->console_upMax_but);
			this->Controls->Add(this->FindBox);
			this->Controls->Add(this->ImgTextBox);
			this->Controls->Add(this->nextBut);
			this->Controls->Add(this->previousBut);
			this->Controls->Add(this->ImageBox);
			this->Controls->Add(this->versionText);
			this->Controls->Add(this->findedItemsCount);
			this->Controls->Add(this->findedItemsLabel);
			this->Controls->Add(this->ResetBut);
			this->Controls->Add(this->console);
			this->Controls->Add(this->ScanBut);
			this->MaximumSize = System::Drawing::Size(650, 415);
			this->MinimumSize = System::Drawing::Size(650, 415);
			this->Name = L"ScanControl";
			this->Size = System::Drawing::Size(650, 415);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ImageBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
		bool stopScanning = false;
		
	private: System::Void ScanBut_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (!Functions->getScanningNow() && !Functions->getScanned())
		{
			Functions->clearConsole();
			ScanBut->Text = "STOP (scanning...)";
			ScanBut->BackColor = System::Drawing::Color::Crimson;
			Functions->addToConsole("Scan start...");
			printConsole(); //new console lines in runScan
			if (Functions->runScan(false))
			{
				printConsole();
				runRepeatedScan();
			}
			else
			{
				Functions->clearConsole();
				Functions->addOutputToConsole();
				stopScan(); //with printConsole();
			}
		}
		else if (!Functions->getScanned())
		{
		stopScanning = true; // click on STOP SCAN
		ScanBut->Text = "ABORTED (unsupported for now)";
		}
		else
		{
			Functions->clearConsole();
			ScanBut->Text = "STOP (scanning...)";
			ScanBut->BackColor = System::Drawing::Color::Crimson;
			Functions->addToConsole("Re-scan start...");
			List<String^>^ copyDirectories = gcnew List<String^>(Functions->getFilesFinded());
			Functions->addToConsole(copyDirectories->Count.ToString());
			//Functions->addToConsole("TEST: " + copyDirectories[0]);
			Functions->resetScanInFunctions();
			//Functions->removeAllDirectories();
			FindBox->Items->Clear();
			Functions->setScanned(true); // due to re-scan!
			for (size_t i = 0; i < copyDirectories->Count; i++)
			{
				Functions->addFileForScan(copyDirectories[i]);
			}
			//for each (String ^ pathImport in copyDirectories)
			//{
			//	Functions->addToConsole("TEST - add path in scan");
			//	Functions->addFileForScan(pathImport);
			//}
			if (Functions->runScan(true))
			{
				printConsole();
				runRepeatedScan();
			}
			else
			{
				Functions->clearConsole();
				Functions->addOutputToConsole();
				stopScan(); //with printConsole();
			}
		}
		



	}		
	void runRepeatedScan()
	{
			   
		if (Functions->scanAgain() && !stopScanning)
		{
			printConsole();
			Task^ timerTask = Task::Run(gcnew Action(this, &ScanControl::checkRepeat));
		}
		else
		{
			stopScan();
		}
	}

	void checkRepeat() //without delegate
	{
		while (!stopScanning)
		{
			if (Functions->getReadyToScan())
			{
				Task::Delay(TimeSpan::FromMilliseconds(10))->Wait(); //BETTER OPTIMALIZATION (smoother on weak computers)
				BeginInvoke(gcnew Action(this, &ScanControl::scanContinue)); 
				Task::Delay(TimeSpan::FromMilliseconds(10))->Wait(); //BETTER OPTIMALIZATION  (smoother on weak computers)
				BeginInvoke(gcnew Action(this, &ScanControl::runRepeatedScan));
				break;
			}
			else
			{
				Task::Delay(TimeSpan::FromMilliseconds(15))->Wait();
			}
		}
	}

	void scanContinue()
	{
		Functions->clearConsole();
		Functions->addOutputToConsole();
		Functions->runScan(true); //true = repeated
		this->findedItemsCount->Text = Functions->getFilesFindedCount().ToString();
		printConsole();
	}

	void stopScan()
	{
		Functions->clearConsole();
		Functions->addOutputToConsole();
		Functions->getConsoleOutput();
		stopScanning = false;
		Functions->setScanned(true);
		Functions->setReadyToScan(true);
		Functions->setScanningNow(false); //due to button: STOP SCAN
		Functions->addToConsole("Scan end...");
		ScanBut->BackColor = System::Drawing::Color::Green;
		this->findedItemsCount->Text = Functions->getFilesFindedCount().ToString();
		List<String^>^ filesFindedCopy = Functions->getFindedItemsPaths();
		FindBox->ClearSelected();
		for (size_t i = 0; i < filesFindedCopy->Count; i++)
		{
			FindBox->Items->Add(filesFindedCopy[i]);
		}
		ResetBut->Visible = true;
		ScanBut->BackColor = System::Drawing::Color::Green;
		ScanBut->Text = "Re-scan from already finded files";
		//if (filesFindedCopy->Count > 0)
		//{
		//	ScanBut->Text = "Scan again from already searched files";
		//	ResetBut->Visible = true;
		//	ScanBut->BackColor = System::Drawing::Color::Green;
		//}
		printConsole(); //new console lines in runScan
	}


	private: System::Void reset_Click(System::Object^ sender, System::EventArgs^ e)
	{
		FindBox->Items->Clear();
		ResetBut->Visible = false;
		ImgTextBox->Text = "0";
		findedItemsCount->Text = "0";
		Functions->resetScanInFunctions(); //need refresh console
		printConsole();
		ScanBut->Text = "Apply filter and scan";
	}

	private: System::Void upMaxConsoleOnClick(System::Object^ sender, System::EventArgs^ e)
	{
		(Functions->addToConsoleIndex(Functions->getConsoleLength() * -1 - 8)); //always index < 0 -> start at index 0;
		printConsole();
	}
	private: System::Void upConsoleOnClick(System::Object^ sender, System::EventArgs^ e)
	{
		Functions->addToConsoleIndex(-1);
		printConsole();

	}
	private: System::Void downConsoleOnClick(System::Object^ sender, System::EventArgs^ e)
	{
		Functions->addToConsoleIndex(1);
		printConsole();
	}
	private: System::Void downMaxConsoleOnClick(System::Object^ sender, System::EventArgs^ e)
	{
		Functions->addToConsoleIndex(Functions->getConsoleLength()-8); //always index > max -> start at end of console -8
		printConsole();
	}

	private: System::Void selectIndexInFindBox(System::Object^ sender, System::EventArgs^ e)
	{
		ImgTextBox->Text = (FindBox->SelectedIndex + 1).ToString();
		//CHANGE TEXT -> CHANGE IMAGE IN FUNCTION "OnTextChanged"
	}

	private: System::Void previous_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Int32 index = Int32::Parse(ImgTextBox->Text);
		ImgTextBox->Text = (index -1).ToString();

	}

	private: System::Void next_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Int32 index = Int32::Parse(ImgTextBox->Text);
		ImgTextBox->Text = (index + 1).ToString();
	}

	private: System::Void OnTextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		Int32 numTested;
		if (Int32::TryParse(ImgTextBox->Text, numTested) && numTested <= FindBox->Items->Count && numTested > 0)
		{
			changeImgByIndex(numTested-1);
		}
		else
		{
			ImgTextBox->Text = "0";
			setDeffaultImage();
		}
	}

	void changeImgByIndex(Int32 index)
	{
		if (isValidImg(Functions->getFindedItemPath(index)))
		{
			try
			{
				ImageBox->Image = Image::FromFile(Functions->getFindedItemPath(static_cast<int>(index)));
			}
			catch (Exception^ ex)
			{
				Functions->addToConsole("Can´t open selected file(E1)...");
				printConsole();
				setDeffaultImage();
			}

		}
		else
		{
			Functions->addToConsole("Can´t open selected file(E2)...");
			printConsole();
			setDeffaultImage();
		}
	}

	ProgramSettings^ Setting;
	ProgramFunctions^ Functions;

	void initializeMain(ProgramSettings^ setting, ProgramFunctions^ functions)
	{
		Setting = setting;
		Functions = functions;
		this->versionText->Text = Setting->getProgramVersion();
	}

	public:
	void printConsole()
	{
		this->console->Text = Functions->getConsoleOutput();
	}

	bool isValidImg(String^ imgPath)
	{
		if (File::Exists(imgPath))
		{
			array<Byte>^ imageBytes = File::ReadAllBytes(imgPath);
			MemoryStream^ stream = gcnew MemoryStream(imageBytes);
			try
			{
				Bitmap^ image = gcnew Bitmap(stream);
				return true;
			}
			catch (Exception^ e)
			{
				return false;
			}
		}
		else return false;
		
	}

	void setDeffaultImage()
	{
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ScanControl::typeid));
		this->ImageBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ImageBox.Image")));
	}

};
}
