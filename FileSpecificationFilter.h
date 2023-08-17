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

	/// <summary>
	/// Summary for UserControl4
	/// </summary>
	public ref class FileSpecificationFilter : public System::Windows::Forms::UserControl
	{
	public:
		FileSpecificationFilter(ProgramSettings^ settingObj, ProgramFunctions^ functionObj)
		{
			InitializeComponent();
			initializeMain(settingObj, functionObj);

			MinSize_but->Click += gcnew System::EventHandler(this, &Pffff::FileSpecificationFilter::minSizeChecked);
			minSize_text->TextChanged += gcnew System::EventHandler(this, &Pffff::FileSpecificationFilter::OnTextChanged);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FileSpecificationFilter()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ minSize_text;


	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ uc2_dirText;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Label^ Support_text;






	private: System::Windows::Forms::Label^ versionText;
	private: System::Windows::Forms::Button^ MinSize_but;

	private: System::Windows::Forms::ImageList^ imageList;
	private: System::Windows::Forms::Button^ checkJpg_but;
	private: System::Windows::Forms::Button^ checkPng_but;


	private: System::ComponentModel::IContainer^ components;


	private:
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FileSpecificationFilter::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->minSize_text = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->uc2_dirText = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->Support_text = (gcnew System::Windows::Forms::Label());
			this->versionText = (gcnew System::Windows::Forms::Label());
			this->MinSize_but = (gcnew System::Windows::Forms::Button());
			this->imageList = (gcnew System::Windows::Forms::ImageList(this->components));
			this->checkJpg_but = (gcnew System::Windows::Forms::Button());
			this->checkPng_but = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(266, 41);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(195, 20);
			this->label2->TabIndex = 7;
			this->label2->Text = L"It scans only files larger than ... (kB)";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(240, 41);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(20, 20);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 6;
			this->pictureBox2->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(89, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 20);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Min size";
			// 
			// minSize_text
			// 
			this->minSize_text->Location = System::Drawing::Point(169, 41);
			this->minSize_text->Name = L"minSize_text";
			this->minSize_text->Size = System::Drawing::Size(65, 20);
			this->minSize_text->TabIndex = 8;
			this->minSize_text->Text = L"8";
			this->minSize_text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox2->Location = System::Drawing::Point(397, 117);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(130, 20);
			this->textBox2->TabIndex = 9;
			this->textBox2->Text = L"Name must contain...";
			// 
			// uc2_dirText
			// 
			this->uc2_dirText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->uc2_dirText->Location = System::Drawing::Point(43, 83);
			this->uc2_dirText->Multiline = true;
			this->uc2_dirText->Name = L"uc2_dirText";
			this->uc2_dirText->ReadOnly = true;
			this->uc2_dirText->Size = System::Drawing::Size(296, 96);
			this->uc2_dirText->TabIndex = 10;
			// 
			// button1
			// 
			this->button1->AutoSize = true;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(345, 117);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(46, 46);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(93, 194);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(70, 70);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 12;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(93, 283);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(70, 70);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 13;
			this->pictureBox4->TabStop = false;
			// 
			// Support_text
			// 
			this->Support_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->Support_text->ForeColor = System::Drawing::Color::Red;
			this->Support_text->Location = System::Drawing::Point(90, 356);
			this->Support_text->Name = L"Support_text";
			this->Support_text->Size = System::Drawing::Size(123, 20);
			this->Support_text->TabIndex = 16;
			this->Support_text->Text = L"not supported yet";
			// 
			// versionText
			// 
			this->versionText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->versionText->Location = System::Drawing::Point(422, 0);
			this->versionText->Name = L"versionText";
			this->versionText->Size = System::Drawing::Size(228, 22);
			this->versionText->TabIndex = 19;
			this->versionText->Text = L"versionText";
			this->versionText->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// MinSize_but
			// 
			this->MinSize_but->AutoSize = true;
			this->MinSize_but->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->MinSize_but->FlatAppearance->BorderSize = 0;
			this->MinSize_but->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->MinSize_but->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->MinSize_but->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->MinSize_but->ImageIndex = 0;
			this->MinSize_but->ImageList = this->imageList;
			this->MinSize_but->Location = System::Drawing::Point(37, 27);
			this->MinSize_but->Name = L"MinSize_but";
			this->MinSize_but->Size = System::Drawing::Size(46, 46);
			this->MinSize_but->TabIndex = 29;
			this->MinSize_but->UseVisualStyleBackColor = false;
			// 
			// imageList
			// 
			this->imageList->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList.ImageStream")));
			this->imageList->TransparentColor = System::Drawing::Color::IndianRed;
			this->imageList->Images->SetKeyName(0, L"false_icon.png");
			this->imageList->Images->SetKeyName(1, L"true_icon.png");
			// 
			// checkJpg_but
			// 
			this->checkJpg_but->AutoSize = true;
			this->checkJpg_but->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->checkJpg_but->FlatAppearance->BorderSize = 0;
			this->checkJpg_but->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->checkJpg_but->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->checkJpg_but->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->checkJpg_but->ImageIndex = 1;
			this->checkJpg_but->ImageList = this->imageList;
			this->checkJpg_but->Location = System::Drawing::Point(37, 208);
			this->checkJpg_but->Name = L"checkJpg_but";
			this->checkJpg_but->Size = System::Drawing::Size(46, 46);
			this->checkJpg_but->TabIndex = 30;
			this->checkJpg_but->UseVisualStyleBackColor = false;
			// 
			// checkPng_but
			// 
			this->checkPng_but->AutoSize = true;
			this->checkPng_but->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->checkPng_but->FlatAppearance->BorderSize = 0;
			this->checkPng_but->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->checkPng_but->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->checkPng_but->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->checkPng_but->ImageIndex = 0;
			this->checkPng_but->ImageList = this->imageList;
			this->checkPng_but->Location = System::Drawing::Point(37, 295);
			this->checkPng_but->Name = L"checkPng_but";
			this->checkPng_but->Size = System::Drawing::Size(46, 46);
			this->checkPng_but->TabIndex = 31;
			this->checkPng_but->UseVisualStyleBackColor = false;
			// 
			// FileSpecificationFilter
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->Controls->Add(this->checkPng_but);
			this->Controls->Add(this->checkJpg_but);
			this->Controls->Add(this->MinSize_but);
			this->Controls->Add(this->versionText);
			this->Controls->Add(this->Support_text);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->uc2_dirText);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->minSize_text);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(650, 415);
			this->MinimumSize = System::Drawing::Size(650, 415);
			this->Name = L"FileSpecificationFilter";
			this->Size = System::Drawing::Size(650, 415);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		private: System::Void minSizeChecked(System::Object^ sender, System::EventArgs^ e)
		{
			if (MinSize_but->ImageIndex == 0)
			{
				MinSize_but->ImageIndex = 1;
				Setting->checkMinFileSize = true;
			}
			else
			{
				MinSize_but->ImageIndex = 0;
				Setting->checkMinFileSize = false;
			}
		}

		private: System::Void OnTextChanged(System::Object^ sender, System::EventArgs^ e)
		{
			minSize_text->Text = setMinFileSize(minSize_text->Text);
			Functions->addToConsole(Setting->minFileSize.ToString());
		}

		ProgramSettings^ Setting;
		ProgramFunctions^ Functions;
		void initializeMain(ProgramSettings^ setting, ProgramFunctions^ functions)
		{
			Setting = setting;
			Functions = functions;
			this->versionText->Text = Setting->getProgramVersion();
		}

		String^ setMinFileSize(String^ byteString)
		{
			Int32 numByte;
			if (Int32::TryParse(byteString, numByte))
			{
				if (numByte > 60000)
				{
					Setting->setMinFileSize(12);
					return "60000";
				}
				else if (byteString->Length == 0 || numByte < 1)
				{
					Setting->setMinFileSize(1);
					return "1";
				}
				Setting->setMinFileSize(numByte);
				return byteString;
			}
			else
			{
				Setting->setMinFileSize(8);
				return "8";
			}
		}

	};
}
