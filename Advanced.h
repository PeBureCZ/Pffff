#pragma once
#include "ProgramSettings.h"
#include "ProgramFunctions.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace Pffff {

	public ref class Advanced : public System::Windows::Forms::UserControl
	{
	public:
		Advanced(ProgramSettings^ settingObj, ProgramFunctions^ functionObj)
		{
			InitializeComponent();
			initializeMain(settingObj, functionObj);

			exifByte_text->TextChanged += gcnew System::EventHandler(this, &Pffff::Advanced::OnExifTextChanged);
			fileByte_text->TextChanged += gcnew System::EventHandler(this, &Pffff::Advanced::OnFileTextChanged);
			Bonus_text->TextChanged += gcnew System::EventHandler(this, &Pffff::Advanced::OnBonusTextChanged);
		}

	protected:
		~Advanced()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ exifByte_text;
	private: System::Windows::Forms::Label^ exifByte_label;
	private: System::Windows::Forms::PictureBox^ markImg1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ fileByte_text;
	private: System::Windows::Forms::Label^ fileByte_label;
	private: System::Windows::Forms::PictureBox^ markImg2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ versionText;
	private: System::Windows::Forms::ImageList^ imageList;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ Bonus_text;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Advanced::typeid));
			this->exifByte_text = (gcnew System::Windows::Forms::TextBox());
			this->exifByte_label = (gcnew System::Windows::Forms::Label());
			this->markImg1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->fileByte_text = (gcnew System::Windows::Forms::TextBox());
			this->fileByte_label = (gcnew System::Windows::Forms::Label());
			this->markImg2 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->versionText = (gcnew System::Windows::Forms::Label());
			this->imageList = (gcnew System::Windows::Forms::ImageList(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Bonus_text = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->markImg1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->markImg2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// exifByte_text
			// 
			this->exifByte_text->Location = System::Drawing::Point(284, 42);
			this->exifByte_text->Name = L"exifByte_text";
			this->exifByte_text->Size = System::Drawing::Size(65, 20);
			this->exifByte_text->TabIndex = 12;
			this->exifByte_text->Text = L"120";
			this->exifByte_text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// exifByte_label
			// 
			this->exifByte_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->exifByte_label->Location = System::Drawing::Point(391, 42);
			this->exifByte_label->Name = L"exifByte_label";
			this->exifByte_label->Size = System::Drawing::Size(242, 28);
			this->exifByte_label->TabIndex = 11;
			this->exifByte_label->Text = L"Determines how many bytes are scanned at most to find the Exif mark";
			// 
			// markImg1
			// 
			this->markImg1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"markImg1.Image")));
			this->markImg1->Location = System::Drawing::Point(365, 42);
			this->markImg1->Name = L"markImg1";
			this->markImg1->Size = System::Drawing::Size(20, 20);
			this->markImg1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->markImg1->TabIndex = 10;
			this->markImg1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(41, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(227, 20);
			this->label1->TabIndex = 9;
			this->label1->Text = L"maxByteExifScan (jpg files)";
			// 
			// fileByte_text
			// 
			this->fileByte_text->Location = System::Drawing::Point(284, 103);
			this->fileByte_text->Name = L"fileByte_text";
			this->fileByte_text->Size = System::Drawing::Size(65, 20);
			this->fileByte_text->TabIndex = 17;
			this->fileByte_text->Text = L"22020608";
			this->fileByte_text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// fileByte_label
			// 
			this->fileByte_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->fileByte_label->Location = System::Drawing::Point(391, 103);
			this->fileByte_label->Name = L"fileByte_label";
			this->fileByte_label->Size = System::Drawing::Size(242, 28);
			this->fileByte_label->TabIndex = 16;
			this->fileByte_label->Text = L"Determines how many bytes are scanned at most to find the creation date";
			// 
			// markImg2
			// 
			this->markImg2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"markImg2.Image")));
			this->markImg2->Location = System::Drawing::Point(365, 103);
			this->markImg2->Name = L"markImg2";
			this->markImg2->Size = System::Drawing::Size(20, 20);
			this->markImg2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->markImg2->TabIndex = 15;
			this->markImg2->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(41, 101);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(226, 20);
			this->label4->TabIndex = 14;
			this->label4->Text = L"maxByteFileScan (jpg files)";
			// 
			// versionText
			// 
			this->versionText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->versionText->Location = System::Drawing::Point(422, 0);
			this->versionText->Name = L"versionText";
			this->versionText->Size = System::Drawing::Size(228, 22);
			this->versionText->TabIndex = 18;
			this->versionText->Text = L"versionText";
			this->versionText->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// imageList
			// 
			this->imageList->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList.ImageStream")));
			this->imageList->TransparentColor = System::Drawing::Color::IndianRed;
			this->imageList->Images->SetKeyName(0, L"false_icon.png");
			this->imageList->Images->SetKeyName(1, L"true_icon.png");
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(41, 181);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(186, 20);
			this->label2->TabIndex = 19;
			this->label2->Text = L"bonusDirectoriesScan";
			// 
			// Bonus_text
			// 
			this->Bonus_text->Location = System::Drawing::Point(284, 181);
			this->Bonus_text->Name = L"Bonus_text";
			this->Bonus_text->Size = System::Drawing::Size(65, 20);
			this->Bonus_text->TabIndex = 20;
			this->Bonus_text->Text = L"0";
			this->Bonus_text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(365, 181);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(20, 20);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 21;
			this->pictureBox1->TabStop = false;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(391, 156);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(242, 135);
			this->label3->TabIndex = 22;
			this->label3->Text = resources->GetString(L"label3.Text");
			// 
			// Advanced
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->Bonus_text);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->versionText);
			this->Controls->Add(this->fileByte_text);
			this->Controls->Add(this->fileByte_label);
			this->Controls->Add(this->markImg2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->exifByte_text);
			this->Controls->Add(this->exifByte_label);
			this->Controls->Add(this->markImg1);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(650, 415);
			this->MinimumSize = System::Drawing::Size(650, 415);
			this->Name = L"Advanced";
			this->Size = System::Drawing::Size(650, 415);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->markImg1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->markImg2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void OnExifTextChanged(System::Object^ sender, System::EventArgs^ e)
		{
			exifByte_text->Text = setMaxExifByteScan(exifByte_text->Text);
		}

		private: System::Void OnFileTextChanged(System::Object^ sender, System::EventArgs^ e)
		{
			fileByte_text->Text = setMaxFileByteScan(fileByte_text->Text);
		}

		private: System::Void OnBonusTextChanged(System::Object^ sender, System::EventArgs^ e)
		{
			Bonus_text->Text = setBonusScan(Bonus_text->Text);
		}	   

		ProgramSettings^ Setting;
		ProgramFunctions^ Functions;

		void initializeMain(ProgramSettings^ setting, ProgramFunctions^ functions)
		{
			Setting = setting;
			Functions = functions;
			this->versionText->Text = Setting->getProgramVersion();
		}
	
		String^ setBonusScan(String^ newText)
		{
			Int32 numBonus;
			if (Int32::TryParse(newText, numBonus))
			{
				if (numBonus > 400)
				{
					Functions->setBonusDirectoriesScan(400);
					return "400";
				}
				else if (newText->Length == 0)
				{
					Functions->setBonusDirectoriesScan(0);
					return "0";
				}
				Functions->setBonusDirectoriesScan(numBonus);
				return newText;
			}
			else
			{
				Functions->setBonusDirectoriesScan(0);
				if (newText != "-") return "0";
			}
			return "0";
		}

		String^ setMaxExifByteScan(String^ byteString)
		{
			Int32 numByte;
			if (Int32::TryParse(byteString, numByte))
			{
				if (numByte > 99999999)
				{
					return "99999999";
				}
				else if (byteString->Length == 0 || numByte < 1)
				{
					return "1";
				}
				return byteString;
			}
			else
			{
				return "120";
			}
		}

		String^ setMaxFileByteScan(String^ byteString)
		{
			Int32 numByte;
			if (Int32::TryParse(byteString, numByte))
			{
				if (numByte > 99999999)
				{
					return "99999999";
				}
				else if (byteString->Length == 0 || numByte < 1)
				{
					return "1";
				}
				return byteString;
			}
			else
			{
				return "22020608";
			}
		}

	};
}
