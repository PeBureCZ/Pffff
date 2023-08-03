#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Pffff {

	/// <summary>
	/// Summary for UserControl1
	/// </summary>
	public ref class UserControl1 : public System::Windows::Forms::UserControl
	{
	public:
		UserControl1(void)
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
		~UserControl1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ console;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ findedItemsLabel;
	private: System::Windows::Forms::Label^ findedItemsCount;
	private: System::Windows::Forms::Label^ versionText;
	private: System::Windows::Forms::PictureBox^ imageBox;
	private: System::Windows::Forms::Button^ butImageBack;
	private: System::Windows::Forms::Button^ butImageforward;
	private: System::Windows::Forms::TextBox^ ImgTextBox;

	protected:




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UserControl1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->console = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->findedItemsLabel = (gcnew System::Windows::Forms::Label());
			this->findedItemsCount = (gcnew System::Windows::Forms::Label());
			this->versionText = (gcnew System::Windows::Forms::Label());
			this->imageBox = (gcnew System::Windows::Forms::PictureBox());
			this->butImageBack = (gcnew System::Windows::Forms::Button());
			this->butImageforward = (gcnew System::Windows::Forms::Button());
			this->ImgTextBox = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imageBox))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Gray;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(24, 38);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(345, 35);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Apply filter and scan";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// console
			// 
			this->console->Location = System::Drawing::Point(3, 298);
			this->console->Multiline = true;
			this->console->Name = L"console";
			this->console->Size = System::Drawing::Size(345, 108);
			this->console->TabIndex = 1;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Gray;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(24, 89);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(345, 35);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Reset all filters , finded files, and paths";
			this->button2->UseVisualStyleBackColor = false;
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
			this->findedItemsCount->Click += gcnew System::EventHandler(this, &UserControl1::findedItemsCount_Click);
			// 
			// versionText
			// 
			this->versionText->AutoSize = true;
			this->versionText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->versionText->Location = System::Drawing::Point(544, 394);
			this->versionText->Name = L"versionText";
			this->versionText->Size = System::Drawing::Size(84, 12);
			this->versionText->TabIndex = 5;
			this->versionText->Text = L"version 0.0.230803";
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
			// butImageBack
			// 
			this->butImageBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->butImageBack->Location = System::Drawing::Point(408, 228);
			this->butImageBack->Name = L"butImageBack";
			this->butImageBack->Size = System::Drawing::Size(75, 23);
			this->butImageBack->TabIndex = 7;
			this->butImageBack->Text = L"previous";
			this->butImageBack->UseVisualStyleBackColor = true;
			// 
			// butImageforward
			// 
			this->butImageforward->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->butImageforward->Location = System::Drawing::Point(489, 228);
			this->butImageforward->Name = L"butImageforward";
			this->butImageforward->Size = System::Drawing::Size(75, 23);
			this->butImageforward->TabIndex = 8;
			this->butImageforward->Text = L"next";
			this->butImageforward->UseVisualStyleBackColor = true;
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
			// UserControl1
			// 
			this->AccessibleName = L"";
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Controls->Add(this->ImgTextBox);
			this->Controls->Add(this->butImageforward);
			this->Controls->Add(this->butImageBack);
			this->Controls->Add(this->imageBox);
			this->Controls->Add(this->versionText);
			this->Controls->Add(this->findedItemsCount);
			this->Controls->Add(this->findedItemsLabel);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->console);
			this->Controls->Add(this->button1);
			this->MaximumSize = System::Drawing::Size(650, 415);
			this->MinimumSize = System::Drawing::Size(650, 415);
			this->Name = L"UserControl1";
			this->Size = System::Drawing::Size(650, 415);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imageBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void findedItemsCount_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
