#pragma once
#include "ProgramSettings.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Pffff {

	/// <summary>
	/// Summary for UserControl3
	/// </summary>
	public ref class MetadataFilter : public System::Windows::Forms::UserControl
	{
	public:
		MetadataFilter(ProgramSettings^ settingObj, ProgramFunctions^ functionObj)
		{
			InitializeComponent();
			initializeMain(settingObj, functionObj);

			minDate_picBut->Click += gcnew System::EventHandler(this, &Pffff::MetadataFilter::minDate_click);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MetadataFilter()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ exifPicBut;
	protected:

	protected:
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
	private: System::Windows::Forms::PictureBox^ maxDate_picBut;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ maxDateYYYY;
	private: System::Windows::Forms::TextBox^ maxDateMM;
	private: System::Windows::Forms::TextBox^ maxDateDD;




	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ versionText;
	private: System::Windows::Forms::PictureBox^ minDate_picBut;



	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MetadataFilter::typeid));
			this->exifPicBut = (gcnew System::Windows::Forms::PictureBox());
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
			this->maxDate_picBut = (gcnew System::Windows::Forms::PictureBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->maxDateYYYY = (gcnew System::Windows::Forms::TextBox());
			this->maxDateMM = (gcnew System::Windows::Forms::TextBox());
			this->maxDateDD = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->versionText = (gcnew System::Windows::Forms::Label());
			this->minDate_picBut = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->exifPicBut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->helperImg))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxDate_picBut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minDate_picBut))->BeginInit();
			this->SuspendLayout();
			// 
			// exifPicBut
			// 
			this->exifPicBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exifPicBut.Image")));
			this->exifPicBut->Location = System::Drawing::Point(43, 30);
			this->exifPicBut->Name = L"exifPicBut";
			this->exifPicBut->Size = System::Drawing::Size(40, 40);
			this->exifPicBut->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->exifPicBut->TabIndex = 0;
			this->exifPicBut->TabStop = false;
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
			// maxDate_picBut
			// 
			this->maxDate_picBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"maxDate_picBut.Image")));
			this->maxDate_picBut->Location = System::Drawing::Point(43, 190);
			this->maxDate_picBut->Name = L"maxDate_picBut";
			this->maxDate_picBut->Size = System::Drawing::Size(40, 40);
			this->maxDate_picBut->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->maxDate_picBut->TabIndex = 14;
			this->maxDate_picBut->TabStop = false;
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
			// minDate_picBut
			// 
			this->minDate_picBut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"minDate_picBut.Image")));
			this->minDate_picBut->Location = System::Drawing::Point(43, 113);
			this->minDate_picBut->Name = L"minDate_picBut";
			this->minDate_picBut->Size = System::Drawing::Size(40, 40);
			this->minDate_picBut->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->minDate_picBut->TabIndex = 24;
			this->minDate_picBut->TabStop = false;
			// 
			// MetadataFilter
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->Controls->Add(this->minDate_picBut);
			this->Controls->Add(this->versionText);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->maxDateDD);
			this->Controls->Add(this->maxDateMM);
			this->Controls->Add(this->maxDateYYYY);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->maxDate_picBut);
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
			this->Controls->Add(this->exifPicBut);
			this->MaximumSize = System::Drawing::Size(650, 415);
			this->MinimumSize = System::Drawing::Size(650, 415);
			this->Name = L"MetadataFilter";
			this->Size = System::Drawing::Size(650, 415);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->exifPicBut))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->helperImg))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxDate_picBut))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minDate_picBut))->EndInit();
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
			this->versionText->Text = Setting->getProgramVersion();
		}

		private: System::Void minDate_click(System::Object^ sender, System::EventArgs^ e)
		{
			Functions->addToConsole("clicked on minDate");
			//this->minDate_picBut->Image = Image::FromFile("C:\\Users\\o\\source\\repos\\Pffff_git\\Images\\true_icon.png"); // HAVE TO CHANGE TO RELATIVE
		}

	};
}
