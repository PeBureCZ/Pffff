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
	/// Summary for UserControl2
	/// </summary>
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
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DirectoryFilter()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ DirectoryTextBox;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ Add_but;
	private: System::Windows::Forms::ListBox^ DirectoryBox;

	private: System::Windows::Forms::Button^ Remove_but;
	private: System::Windows::Forms::Label^ versionText;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DirectoryFilter::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->DirectoryTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Add_but = (gcnew System::Windows::Forms::Button());
			this->DirectoryBox = (gcnew System::Windows::Forms::ListBox());
			this->Remove_but = (gcnew System::Windows::Forms::Button());
			this->versionText = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(31, 28);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(49, 83);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// DirectoryTextBox
			// 
			this->DirectoryTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->DirectoryTextBox->Location = System::Drawing::Point(151, 66);
			this->DirectoryTextBox->Name = L"DirectoryTextBox";
			this->DirectoryTextBox->Size = System::Drawing::Size(257, 20);
			this->DirectoryTextBox->TabIndex = 3;
			this->DirectoryTextBox->Text = L"Add directory here...";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(151, 50);
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
			this->label2->Location = System::Drawing::Point(261, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(122, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"C:\\UserX\\directoryX";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(412, 50);
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
			this->label4->Location = System::Drawing::Point(468, 50);
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
			this->Add_but->Location = System::Drawing::Point(86, 18);
			this->Add_but->Name = L"Add_but";
			this->Add_but->Size = System::Drawing::Size(59, 57);
			this->Add_but->TabIndex = 8;
			this->Add_but->Text = L"Add";
			this->Add_but->UseVisualStyleBackColor = false;
			// 
			// DirectoryBox
			// 
			this->DirectoryBox->Font = (gcnew System::Drawing::Font(L"Sitka Banner", 8.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->DirectoryBox->FormattingEnabled = true;
			this->DirectoryBox->ItemHeight = 16;
			this->DirectoryBox->Location = System::Drawing::Point(20, 142);
			this->DirectoryBox->MultiColumn = true;
			this->DirectoryBox->Name = L"DirectoryBox";
			this->DirectoryBox->Size = System::Drawing::Size(612, 260);
			this->DirectoryBox->TabIndex = 9;
			this->DirectoryBox->SelectedIndexChanged += gcnew System::EventHandler(this, &DirectoryFilter::DirectoryListBox_SelectedIndexChanged);
			// 
			// Remove_but
			// 
			this->Remove_but->BackColor = System::Drawing::Color::White;
			this->Remove_but->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Remove_but.Image")));
			this->Remove_but->Location = System::Drawing::Point(86, 79);
			this->Remove_but->Name = L"Remove_but";
			this->Remove_but->Size = System::Drawing::Size(59, 57);
			this->Remove_but->TabIndex = 10;
			this->Remove_but->Text = L"Remove";
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
			// DirectoryFilter
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Controls->Add(this->versionText);
			this->Controls->Add(this->Remove_but);
			this->Controls->Add(this->DirectoryBox);
			this->Controls->Add(this->Add_but);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->DirectoryTextBox);
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
			this->versionText->Text = Setting->getProgramVersion();
		}
		
		private: System::Void addButtClick(System::Object^ sender, System::EventArgs^ e)
		{
			if (Directory::Exists(this->DirectoryTextBox->Text))
			{
				this->DirectoryBox->Items->Add(this->DirectoryTextBox->Text);
				Functions->addDirectoryPath(this->DirectoryTextBox->Text);
				this->DirectoryTextBox->Text = L"Add directory here...";
			}
			else
			{
				this->DirectoryTextBox->Text = L"Incorrectly entered or nonexistent directory...";
			}

		}

		private: System::Void removeButtClick(System::Object^ sender, System::EventArgs^ e)
		{
			if (DirectoryBox->Items->Count == 0)
			{
				Functions->addToConsole("NO INDEX TO DELETE");
				Functions->addToConsole(DirectoryBox->SelectedIndex.ToString());

			}
			else if (DirectoryBox->SelectedIndex != -1)
			{
				DirectoryBox->Items->RemoveAt(this->DirectoryBox->SelectedIndex);
			}
		}

/*		private: System::Void directoryIndexSelected(System::Object^ sender, System::EventArgs^ e)
		{
			Functions->addToConsole("index selected");
		}	  */ 

	private: System::Void DirectoryListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
