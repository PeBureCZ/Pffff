#pragma once

#include "UserControl1.h"
#include "UserControl2.h"
#include "UserControl3.h"
#include "UserControl4.h"
#include "UserControl5.h"

namespace Pffff {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for basicForm
	/// </summary>
	public ref class basicForm : public System::Windows::Forms::Form
	{
	public:
		basicForm(void)
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
		~basicForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ leftPanel;
	private: System::Windows::Forms::Button^ but_ui1;
	private: System::Windows::Forms::Button^ but_ui5;
	private: System::Windows::Forms::Button^ but_ui4;
	private: System::Windows::Forms::Button^ but_ui3;
	private: System::Windows::Forms::Button^ but_ui2;
	private: Pffff::UserControl1^ userControl11;








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
			this->leftPanel = (gcnew System::Windows::Forms::Panel());
			this->but_ui5 = (gcnew System::Windows::Forms::Button());
			this->but_ui4 = (gcnew System::Windows::Forms::Button());
			this->but_ui3 = (gcnew System::Windows::Forms::Button());
			this->but_ui2 = (gcnew System::Windows::Forms::Button());
			this->but_ui1 = (gcnew System::Windows::Forms::Button());
			this->userControl11 = (gcnew Pffff::UserControl1());
			this->leftPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// leftPanel
			// 
			this->leftPanel->Controls->Add(this->but_ui5);
			this->leftPanel->Controls->Add(this->but_ui4);
			this->leftPanel->Controls->Add(this->but_ui3);
			this->leftPanel->Controls->Add(this->but_ui2);
			this->leftPanel->Controls->Add(this->but_ui1);
			this->leftPanel->Dock = System::Windows::Forms::DockStyle::Left;
			this->leftPanel->Location = System::Drawing::Point(0, 0);
			this->leftPanel->Name = L"leftPanel";
			this->leftPanel->Size = System::Drawing::Size(200, 411);
			this->leftPanel->TabIndex = 0;
			// 
			// but_ui5
			// 
			this->but_ui5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->but_ui5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->but_ui5->Location = System::Drawing::Point(0, 332);
			this->but_ui5->Name = L"but_ui5";
			this->but_ui5->Size = System::Drawing::Size(200, 77);
			this->but_ui5->TabIndex = 4;
			this->but_ui5->Text = L"Advanced";
			this->but_ui5->UseVisualStyleBackColor = false;
			// 
			// but_ui4
			// 
			this->but_ui4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->but_ui4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->but_ui4->Location = System::Drawing::Point(0, 249);
			this->but_ui4->Name = L"but_ui4";
			this->but_ui4->Size = System::Drawing::Size(200, 77);
			this->but_ui4->TabIndex = 3;
			this->but_ui4->Text = L"File specification filter";
			this->but_ui4->UseVisualStyleBackColor = false;
			// 
			// but_ui3
			// 
			this->but_ui3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->but_ui3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->but_ui3->Location = System::Drawing::Point(0, 166);
			this->but_ui3->Name = L"but_ui3";
			this->but_ui3->Size = System::Drawing::Size(200, 77);
			this->but_ui3->TabIndex = 2;
			this->but_ui3->Text = L"Metadata filter";
			this->but_ui3->UseVisualStyleBackColor = false;
			// 
			// but_ui2
			// 
			this->but_ui2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->but_ui2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->but_ui2->Location = System::Drawing::Point(0, 83);
			this->but_ui2->Name = L"but_ui2";
			this->but_ui2->Size = System::Drawing::Size(200, 77);
			this->but_ui2->TabIndex = 1;
			this->but_ui2->Text = L"Directory filter";
			this->but_ui2->UseVisualStyleBackColor = false;
			// 
			// but_ui1
			// 
			this->but_ui1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->but_ui1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->but_ui1->Location = System::Drawing::Point(0, 0);
			this->but_ui1->Name = L"but_ui1";
			this->but_ui1->Size = System::Drawing::Size(200, 77);
			this->but_ui1->TabIndex = 0;
			this->but_ui1->Text = L"SCAN";
			this->but_ui1->UseVisualStyleBackColor = false;
			// 
			// userControl11
			// 
			this->userControl11->AccessibleName = L"";
			this->userControl11->AutoSize = true;
			this->userControl11->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->userControl11->Location = System::Drawing::Point(194, 0);
			this->userControl11->MaximumSize = System::Drawing::Size(650, 415);
			this->userControl11->MinimumSize = System::Drawing::Size(650, 415);
			this->userControl11->Name = L"userControl11";
			this->userControl11->Size = System::Drawing::Size(650, 415);
			this->userControl11->TabIndex = 1;
			// 
			// basicForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(844, 411);
			this->Controls->Add(this->userControl11);
			this->Controls->Add(this->leftPanel);
			this->MaximumSize = System::Drawing::Size(860, 450);
			this->MinimumSize = System::Drawing::Size(860, 450);
			this->Name = L"basicForm";
			this->Text = L"Pffff (Personal filter for file find)";
			this->leftPanel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
