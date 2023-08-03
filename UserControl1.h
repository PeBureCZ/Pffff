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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->console = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->findedItemsLabel = (gcnew System::Windows::Forms::Label());
			this->findedItemsCount = (gcnew System::Windows::Forms::Label());
			this->versionText = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Gray;
			this->button1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->console->Location = System::Drawing::Point(24, 228);
			this->console->Multiline = true;
			this->console->Name = L"console";
			this->console->Size = System::Drawing::Size(345, 108);
			this->console->TabIndex = 1;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Gray;
			this->button2->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(24, 89);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(345, 35);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Reset all filters , finded files and paths";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// findedItemsLabel
			// 
			this->findedItemsLabel->AutoSize = true;
			this->findedItemsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->findedItemsLabel->Location = System::Drawing::Point(34, 185);
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
			this->findedItemsCount->Location = System::Drawing::Point(141, 185);
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
			this->versionText->Location = System::Drawing::Point(773, 467);
			this->versionText->Name = L"versionText";
			this->versionText->Size = System::Drawing::Size(64, 12);
			this->versionText->TabIndex = 5;
			this->versionText->Text = L"version 0.1.00";
			this->versionText->TextAlign = System::Drawing::ContentAlignment::BottomRight;
			// 
			// UserControl1
			// 
			this->AccessibleName = L"";
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Controls->Add(this->versionText);
			this->Controls->Add(this->findedItemsCount);
			this->Controls->Add(this->findedItemsLabel);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->console);
			this->Controls->Add(this->button1);
			this->Name = L"UserControl1";
			this->Size = System::Drawing::Size(425, 488);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void findedItemsCount_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
