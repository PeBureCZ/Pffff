#pragma once
#include "ProgramSettings.h"
#include "ProgramFunctions.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Reflection;

namespace Pffff {

	public ref class MetadataFilter : public System::Windows::Forms::UserControl
	{
	public:
		MetadataFilter(ProgramSettings^ settingObj, ProgramFunctions^ functionObj)
		{
			InitializeComponent();
			initializeMain(settingObj, functionObj);

			minDate_But->Click += gcnew System::EventHandler(this, &Pffff::MetadataFilter::minDate_click);
			maxDate_But->Click += gcnew System::EventHandler(this, &Pffff::MetadataFilter::maxDate_click);
			exif_but->Click += gcnew System::EventHandler(this, &Pffff::MetadataFilter::exif_click);

			minDateYYYY->TextChanged += gcnew System::EventHandler(this, &Pffff::MetadataFilter::onChangeMinYYYY);
			minDateMM->TextChanged += gcnew System::EventHandler(this, &Pffff::MetadataFilter::onChangeMinMM);
			minDateDD->TextChanged += gcnew System::EventHandler(this, &Pffff::MetadataFilter::onChangeMinDD);

			maxDateYYYY->TextChanged += gcnew System::EventHandler(this, &Pffff::MetadataFilter::onChangeMaxYYYY);
			maxDateMM->TextChanged += gcnew System::EventHandler(this, &Pffff::MetadataFilter::onChangeMaxMM);
			maxDateDD->TextChanged += gcnew System::EventHandler(this, &Pffff::MetadataFilter::onChangeMaxDD);
		}

	protected:
		~MetadataFilter()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ helperImg;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ minDateYYYY;
	private: System::Windows::Forms::TextBox^ minDateMM;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ minDateDD;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ maxDateYYYY;
	private: System::Windows::Forms::TextBox^ maxDateMM;
	private: System::Windows::Forms::TextBox^ maxDateDD;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ versionText;
	private: System::Windows::Forms::ImageList^ imageList1;
	private: System::Windows::Forms::Button^ maxDate_But;
	private: System::Windows::Forms::Button^ exif_but;
	private: System::Windows::Forms::Button^ minDate_But;
	private: System::Windows::Forms::Label^ minDateValidText;
	private: System::Windows::Forms::Label^ maxDateValidText;
	private: System::ComponentModel::IContainer^ components;
	private:

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MetadataFilter::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->helperImg = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->minDateYYYY = (gcnew System::Windows::Forms::TextBox());
			this->minDateMM = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->minDateDD = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->maxDateYYYY = (gcnew System::Windows::Forms::TextBox());
			this->maxDateMM = (gcnew System::Windows::Forms::TextBox());
			this->maxDateDD = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->versionText = (gcnew System::Windows::Forms::Label());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->minDate_But = (gcnew System::Windows::Forms::Button());
			this->maxDate_But = (gcnew System::Windows::Forms::Button());
			this->exif_but = (gcnew System::Windows::Forms::Button());
			this->minDateValidText = (gcnew System::Windows::Forms::Label());
			this->maxDateValidText = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->helperImg))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(89, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"EXIF only";
			// 
			// helperImg
			// 
			this->helperImg->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"helperImg.Image")));
			this->helperImg->Location = System::Drawing::Point(182, 41);
			this->helperImg->Name = L"helperImg";
			this->helperImg->Size = System::Drawing::Size(20, 20);
			this->helperImg->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->helperImg->TabIndex = 2;
			this->helperImg->TabStop = false;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(218, 41);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(381, 59);
			this->label2->TabIndex = 3;
			this->label2->Text = resources->GetString(L"label2.Text");
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(89, 120);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L" Min date";
			// 
			// minDateYYYY
			// 
			this->minDateYYYY->Location = System::Drawing::Point(221, 119);
			this->minDateYYYY->Name = L"minDateYYYY";
			this->minDateYYYY->Size = System::Drawing::Size(65, 20);
			this->minDateYYYY->TabIndex = 7;
			this->minDateYYYY->Text = L"1900";
			this->minDateYYYY->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// minDateMM
			// 
			this->minDateMM->Location = System::Drawing::Point(292, 119);
			this->minDateMM->Name = L"minDateMM";
			this->minDateMM->Size = System::Drawing::Size(41, 20);
			this->minDateMM->TabIndex = 8;
			this->minDateMM->Text = L"01";
			this->minDateMM->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(218, 142);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(66, 14);
			this->label4->TabIndex = 10;
			this->label4->Text = L"     YYYY";
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(290, 142);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(43, 14);
			this->label5->TabIndex = 11;
			this->label5->Text = L"   MM";
			// 
			// minDateDD
			// 
			this->minDateDD->Location = System::Drawing::Point(339, 119);
			this->minDateDD->Name = L"minDateDD";
			this->minDateDD->Size = System::Drawing::Size(41, 20);
			this->minDateDD->TabIndex = 12;
			this->minDateDD->Text = L"01";
			this->minDateDD->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label6->Location = System::Drawing::Point(339, 142);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(43, 14);
			this->label6->TabIndex = 13;
			this->label6->Text = L"   DD";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label7->Location = System::Drawing::Point(93, 199);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(82, 20);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Max date";
			// 
			// maxDateYYYY
			// 
			this->maxDateYYYY->Location = System::Drawing::Point(221, 201);
			this->maxDateYYYY->Name = L"maxDateYYYY";
			this->maxDateYYYY->Size = System::Drawing::Size(65, 20);
			this->maxDateYYYY->TabIndex = 17;
			this->maxDateYYYY->Text = L"2300";
			this->maxDateYYYY->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// maxDateMM
			// 
			this->maxDateMM->Location = System::Drawing::Point(292, 201);
			this->maxDateMM->Name = L"maxDateMM";
			this->maxDateMM->Size = System::Drawing::Size(41, 20);
			this->maxDateMM->TabIndex = 18;
			this->maxDateMM->Text = L"12";
			this->maxDateMM->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// maxDateDD
			// 
			this->maxDateDD->Location = System::Drawing::Point(339, 201);
			this->maxDateDD->Name = L"maxDateDD";
			this->maxDateDD->Size = System::Drawing::Size(41, 20);
			this->maxDateDD->TabIndex = 19;
			this->maxDateDD->Text = L"31";
			this->maxDateDD->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label8
			// 
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label8->Location = System::Drawing::Point(220, 224);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(66, 14);
			this->label8->TabIndex = 20;
			this->label8->Text = L"     YYYY";
			// 
			// label9
			// 
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label9->Location = System::Drawing::Point(292, 224);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(43, 14);
			this->label9->TabIndex = 21;
			this->label9->Text = L"   MM";
			// 
			// label10
			// 
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label10->Location = System::Drawing::Point(339, 224);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(43, 14);
			this->label10->TabIndex = 22;
			this->label10->Text = L"   DD";
			// 
			// versionText
			// 
			this->versionText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->versionText->Location = System::Drawing::Point(422, 0);
			this->versionText->Name = L"versionText";
			this->versionText->Size = System::Drawing::Size(228, 22);
			this->versionText->TabIndex = 23;
			this->versionText->Text = L"versionText";
			this->versionText->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::IndianRed;
			this->imageList1->Images->SetKeyName(0, L"false_icon.png");
			this->imageList1->Images->SetKeyName(1, L"true_icon.png");
			// 
			// minDate_But
			// 
			this->minDate_But->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->minDate_But->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->minDate_But->FlatAppearance->BorderSize = 0;
			this->minDate_But->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->minDate_But->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->minDate_But->ForeColor = System::Drawing::Color::Red;
			this->minDate_But->ImageIndex = 0;
			this->minDate_But->ImageList = this->imageList1;
			this->minDate_But->Location = System::Drawing::Point(43, 108);
			this->minDate_But->Name = L"minDate_But";
			this->minDate_But->Size = System::Drawing::Size(46, 48);
			this->minDate_But->TabIndex = 26;
			this->minDate_But->UseVisualStyleBackColor = false;
			// 
			// maxDate_But
			// 
			this->maxDate_But->AutoSize = true;
			this->maxDate_But->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->maxDate_But->FlatAppearance->BorderSize = 0;
			this->maxDate_But->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->maxDate_But->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->maxDate_But->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->maxDate_But->ImageIndex = 0;
			this->maxDate_But->ImageList = this->imageList1;
			this->maxDate_But->Location = System::Drawing::Point(43, 187);
			this->maxDate_But->Name = L"maxDate_But";
			this->maxDate_But->Size = System::Drawing::Size(46, 46);
			this->maxDate_But->TabIndex = 27;
			this->maxDate_But->UseVisualStyleBackColor = false;
			// 
			// exif_but
			// 
			this->exif_but->AutoSize = true;
			this->exif_but->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->exif_but->FlatAppearance->BorderSize = 0;
			this->exif_but->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->exif_but->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->exif_but->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->exif_but->ImageIndex = 0;
			this->exif_but->ImageList = this->imageList1;
			this->exif_but->Location = System::Drawing::Point(43, 29);
			this->exif_but->Name = L"exif_but";
			this->exif_but->Size = System::Drawing::Size(46, 46);
			this->exif_but->TabIndex = 28;
			this->exif_but->UseVisualStyleBackColor = false;
			// 
			// minDateValidText
			// 
			this->minDateValidText->AutoSize = true;
			this->minDateValidText->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->minDateValidText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->minDateValidText->ForeColor = System::Drawing::Color::Red;
			this->minDateValidText->Location = System::Drawing::Point(386, 119);
			this->minDateValidText->Name = L"minDateValidText";
			this->minDateValidText->Size = System::Drawing::Size(147, 17);
			this->minDateValidText->TabIndex = 29;
			this->minDateValidText->Text = L"Invalid date format!";
			this->minDateValidText->Visible = false;
			// 
			// maxDateValidText
			// 
			this->maxDateValidText->AutoSize = true;
			this->maxDateValidText->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->maxDateValidText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->maxDateValidText->ForeColor = System::Drawing::Color::Red;
			this->maxDateValidText->Location = System::Drawing::Point(386, 204);
			this->maxDateValidText->Name = L"maxDateValidText";
			this->maxDateValidText->Size = System::Drawing::Size(147, 17);
			this->maxDateValidText->TabIndex = 30;
			this->maxDateValidText->Text = L"Invalid date format!";
			this->maxDateValidText->Visible = false;
			// 
			// MetadataFilter
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->Controls->Add(this->maxDateValidText);
			this->Controls->Add(this->minDateValidText);
			this->Controls->Add(this->exif_but);
			this->Controls->Add(this->maxDate_But);
			this->Controls->Add(this->minDate_But);
			this->Controls->Add(this->versionText);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->maxDateDD);
			this->Controls->Add(this->maxDateMM);
			this->Controls->Add(this->maxDateYYYY);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->minDateDD);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->minDateMM);
			this->Controls->Add(this->minDateYYYY);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->helperImg);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(650, 415);
			this->MinimumSize = System::Drawing::Size(650, 415);
			this->Name = L"MetadataFilter";
			this->Size = System::Drawing::Size(650, 415);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->helperImg))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		ProgramSettings^ Setting;
		ProgramFunctions^ Functions;

		void initializeMain(ProgramSettings^ setting, ProgramFunctions^ functions)
		{
			Setting = setting;
			Functions = functions;
			versionText->Text = Setting->getProgramVersion();
		}

		private: System::Void minDate_click(System::Object^ sender, System::EventArgs^ e)
		{
			if (minDate_But->ImageIndex == 0)
			{
				minDate_But->ImageIndex = 1;
				Setting->checkMinDate = true;
			}
			else
			{
				minDate_But->ImageIndex = 0;
				Setting->checkMinDate = false;
			}
		}

		private: System::Void maxDate_click(System::Object^ sender, System::EventArgs^ e)
		{
			if (maxDate_But->ImageIndex == 0)
			{
				maxDate_But->ImageIndex = 1;
				Setting->checkMaxDate = true;
			}
			else
			{
				maxDate_But->ImageIndex = 0;
				Setting->checkMaxDate = false;

			}	
		}

		private: System::Void exif_click(System::Object^ sender, System::EventArgs^ e)
		{
			if (exif_but->ImageIndex == 0)
			{
				exif_but->ImageIndex = 1;
				Setting->checkExif = true;
			}
			else
			{
				exif_but->ImageIndex = 0;
				Setting->checkExif = false;
			}
		}

		private: System::Void onChangeMinYYYY(System::Object^ sender, System::EventArgs^ e)
		{
			minDateYYYY->Text = Functions->setMinYYYY(minDateYYYY->Text); //return corected value
			checkLenghtOfMinDateString(); //set min date to Functions!
		}

		private: System::Void onChangeMinMM(System::Object^ sender, System::EventArgs^ e)
		{
			minDateMM->Text = Functions->setMinMM(minDateMM->Text); //return corected value
			checkLenghtOfMinDateString(); //set min date to Functions!
		}

		private: System::Void onChangeMinDD(System::Object^ sender, System::EventArgs^ e)
		{
			this->minDateDD->Text = Functions->setMinDD(minDateDD->Text); //return corected value
			checkLenghtOfMinDateString(); //set min date to Functions!
		}

		private: System::Void onChangeMaxYYYY(System::Object^ sender, System::EventArgs^ e)
		{
			maxDateYYYY->Text = Functions->setMaxYYYY(maxDateYYYY->Text); //return corected value
			checkLenghtOfMaxDateString(); //set max date to Functions!
		}

		private: System::Void onChangeMaxMM(System::Object^ sender, System::EventArgs^ e)
		{
			maxDateMM->Text = Functions->setMaxMM(maxDateMM->Text); //return corected value
			checkLenghtOfMaxDateString(); //set max date to Functions!
		}

		private: System::Void onChangeMaxDD(System::Object^ sender, System::EventArgs^ e)
		{
			maxDateDD->Text = Functions->setMaxDD(maxDateDD->Text); //return corected value
			checkLenghtOfMaxDateString(); //set max date to Functions!
		}

		void checkLenghtOfMinDateString()
		{
			String^ checkedLength = minDateYYYY->Text + minDateMM->Text + minDateDD->Text;
			if (checkedLength->Length == 8)
			{
				minDateValidText->Visible = false;
				Int64 num64;
				String^ newDate = minDateYYYY->Text + minDateMM->Text + minDateDD->Text + "000000"; //6x zero for hours, mins, secs
				if (Int64::TryParse(newDate, num64)) Functions->setMinDate(num64); //convert newDate <String^> to Int64 (custom dateformat)
				else minDateValidText->Visible = true;
				return;
			}
			minDateValidText->Visible = true;
		}

		void checkLenghtOfMaxDateString()
		{
			String^ checkedLength = maxDateYYYY->Text + maxDateMM->Text + maxDateDD->Text;
			if (checkedLength->Length == 8)
			{
				maxDateValidText->Visible = false;
				Int64 num64;
				String^ newDate = maxDateYYYY->Text + maxDateMM->Text + maxDateDD->Text + "000000"; //6x zero for hours, mins, secs
				if (Int64::TryParse(newDate, num64)) //convert newDate <String^> to Int64 (custom dateformat)
				{
					Functions->setMaxDate(num64);
				}
				else
				{
					maxDateValidText->Visible = true;
				}
				return;
			}
			maxDateValidText->Visible = true;
		}

			   

	};
}
