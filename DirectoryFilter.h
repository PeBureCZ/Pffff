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

	public ref class DirectoryFilter : public System::Windows::Forms::UserControl
	{
	public:
		DirectoryFilter(ProgramSettings^ settingObj, ProgramFunctions^ functionObj)
		{
			InitializeComponent();
			Add_but->Click += gcnew System::EventHandler(this, &Pffff::DirectoryFilter::addButtClick);
			Remove_but->Click += gcnew System::EventHandler(this, &Pffff::DirectoryFilter::removeButtClick);
			initializeMain (settingObj, functionObj);
		}

	protected:
		~DirectoryFilter()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ NameTextBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ Add_but;
	private: System::Windows::Forms::ListBox^ DirectoryBox;
	private: System::Windows::Forms::Button^ Remove_but;
	private: System::Windows::Forms::Label^ versionText;
	private: System::Windows::Forms::Button^ Find_but;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DirectoryFilter::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->NameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Add_but = (gcnew System::Windows::Forms::Button());
			this->DirectoryBox = (gcnew System::Windows::Forms::ListBox());
			this->Remove_but = (gcnew System::Windows::Forms::Button());
			this->versionText = (gcnew System::Windows::Forms::Label());
			this->Find_but = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(31, 40);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(49, 83);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// NameTextBox
			// 
			this->NameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->NameTextBox->Location = System::Drawing::Point(141, 40);
			this->NameTextBox->Name = L"NameTextBox";
			this->NameTextBox->Size = System::Drawing::Size(257, 20);
			this->NameTextBox->TabIndex = 3;
			this->NameTextBox->Text = L"Add directory here...";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(138, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Allowed text formats:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(248, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(122, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"C:\\UserX\\directoryX";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(376, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(16, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"or";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(398, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(122, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"C:/UserX/directoryX";
			// 
			// Add_but
			// 
			this->Add_but->AutoSize = true;
			this->Add_but->BackColor = System::Drawing::Color::White;
			this->Add_but->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Add_but.Image")));
			this->Add_but->Location = System::Drawing::Point(86, 14);
			this->Add_but->Name = L"Add_but";
			this->Add_but->Size = System::Drawing::Size(46, 46);
			this->Add_but->TabIndex = 8;
			this->Add_but->UseVisualStyleBackColor = false;
			// 
			// DirectoryBox
			// 
			this->DirectoryBox->Font = (gcnew System::Drawing::Font(L"Sitka Banner", 8.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->DirectoryBox->FormattingEnabled = true;
			this->DirectoryBox->ItemHeight = 16;
			this->DirectoryBox->Location = System::Drawing::Point(20, 174);
			this->DirectoryBox->MultiColumn = true;
			this->DirectoryBox->Name = L"DirectoryBox";
			this->DirectoryBox->Size = System::Drawing::Size(612, 228);
			this->DirectoryBox->TabIndex = 9;
			// 
			// Remove_but
			// 
			this->Remove_but->BackColor = System::Drawing::Color::White;
			this->Remove_but->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Remove_but.Image")));
			this->Remove_but->Location = System::Drawing::Point(86, 66);
			this->Remove_but->Name = L"Remove_but";
			this->Remove_but->Size = System::Drawing::Size(46, 44);
			this->Remove_but->TabIndex = 10;
			this->Remove_but->UseVisualStyleBackColor = false;
			// 
			// versionText
			// 
			this->versionText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->versionText->Location = System::Drawing::Point(422, 0);
			this->versionText->Name = L"versionText";
			this->versionText->Size = System::Drawing::Size(228, 22);
			this->versionText->TabIndex = 11;
			this->versionText->Text = L"versionText";
			this->versionText->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// Find_but
			// 
			this->Find_but->AutoSize = true;
			this->Find_but->BackColor = System::Drawing::Color::White;
			this->Find_but->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Find_but.Image")));
			this->Find_but->Location = System::Drawing::Point(86, 116);
			this->Find_but->Name = L"Find_but";
			this->Find_but->Size = System::Drawing::Size(46, 46);
			this->Find_but->TabIndex = 12;
			this->Find_but->UseVisualStyleBackColor = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::Red;
			this->label5->Location = System::Drawing::Point(138, 133);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(169, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Find directory (Not supported now)";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(138, 82);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(404, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"To remove a directory, it is necessary to have the directory selected as shown be"
				L"low";
			// 
			// DirectoryFilter
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->Find_but);
			this->Controls->Add(this->versionText);
			this->Controls->Add(this->Remove_but);
			this->Controls->Add(this->DirectoryBox);
			this->Controls->Add(this->Add_but);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->NameTextBox);
			this->Controls->Add(this->pictureBox1);
			this->MaximumSize = System::Drawing::Size(650, 415);
			this->MinimumSize = System::Drawing::Size(650, 415);
			this->Name = L"DirectoryFilter";
			this->Size = System::Drawing::Size(650, 415);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		ProgramSettings^ Setting;
		ProgramFunctions^ Functions;
		int selectedDirecoryIndex = -1;

		void initializeMain(ProgramSettings^ setting, ProgramFunctions^ functions)
		{
			Setting = setting;
			Functions = functions;
			versionText->Text = Setting->getProgramVersion();
		}
		
		private: System::Void addButtClick(System::Object^ sender, System::EventArgs^ e)
		{
			String^ checkAlternativePath = NameTextBox->Text;
			String^ updatedPath = "";
			for each (Char character in checkAlternativePath)
			{
				if (character == L'\\') updatedPath += "/";
				else updatedPath += character.ToString();
			}
			if (Directory::Exists(updatedPath))
			{
				DirectoryBox->Items->Add(updatedPath);
				Functions->addDirectoryPath(updatedPath);
				NameTextBox->Text = L"Add directory here...";
			}
			else NameTextBox->Text = updatedPath;
		}

		private: System::Void removeButtClick(System::Object^ sender, System::EventArgs^ e)
		{
			if (DirectoryBox->SelectedIndex != -1 && DirectoryBox->Items->Count != 0)
			{
				Functions->removeDirectory(DirectoryBox->SelectedIndex);
				DirectoryBox->Items->RemoveAt(DirectoryBox->SelectedIndex);		
			}
		}
	};
}