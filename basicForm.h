#pragma once

//Deff Classes start
#include "DirectoryFilter.h"
#include "MetadataFilter.h"
#include "FileSpecificationFilter.h"
#include "Advanced.h"
#include "ScanControl.h"
//Deff Classes end

//Custom Classes start
#include "ProgramSettings.h"
#include "ProgramFunctions.h"
//Custom Classes end

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
		basicForm(ProgramSettings^ setting, ProgramFunctions^ functions)
		{
			InitializeComponent(setting, functions);
			but_scan->Click += gcnew System::EventHandler(this, &basicForm::but_scan_Click);
			but_direcFilter->Click += gcnew System::EventHandler(this, &basicForm::but_direcFilter_Click);
			but_metaFilter->Click += gcnew System::EventHandler(this, &basicForm::but_metaFilter_Click);
			but_specFilter->Click += gcnew System::EventHandler(this, &basicForm::but_specFilter_Click);
			but_advancedFilter->Click += gcnew System::EventHandler(this, &basicForm::but_advancedFilter_Click);
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
	private: System::Windows::Forms::Button^ but_scan;
	private: System::Windows::Forms::Button^ but_direcFilter;
	private: System::Windows::Forms::Button^ but_metaFilter;
	private: System::Windows::Forms::Button^ but_specFilter;
	private: System::Windows::Forms::Button^ but_advancedFilter;

	private: Pffff::DirectoryFilter^ directoryFilter1;
	private: Pffff::MetadataFilter^ metadataFilter1;
	private: Pffff::FileSpecificationFilter^ fileSpecificationFilter1;
	private: Pffff::Advanced^ advanced1;
	private: Pffff::ScanControl^ scanControl1;



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
		void InitializeComponent(ProgramSettings^ settingObject, ProgramFunctions^ functionObject)
		{
			this->leftPanel = (gcnew System::Windows::Forms::Panel());
			this->but_advancedFilter = (gcnew System::Windows::Forms::Button());
			this->but_specFilter = (gcnew System::Windows::Forms::Button());
			this->but_metaFilter = (gcnew System::Windows::Forms::Button());
			this->but_direcFilter = (gcnew System::Windows::Forms::Button());
			this->but_scan = (gcnew System::Windows::Forms::Button());
			//UserControls INTERFACES start
			this->scanControl1 = (gcnew Pffff::ScanControl(settingObject, functionObject));
			this->directoryFilter1 = (gcnew Pffff::DirectoryFilter(settingObject, functionObject));
			this->metadataFilter1 = (gcnew Pffff::MetadataFilter(settingObject, functionObject));
			this->fileSpecificationFilter1 = (gcnew Pffff::FileSpecificationFilter(settingObject, functionObject));
			this->advanced1 = (gcnew Pffff::Advanced(settingObject, functionObject));
			//UserControls INTERFACES end


			this->leftPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// leftPanel
			// 
			this->leftPanel->Controls->Add(this->but_advancedFilter);
			this->leftPanel->Controls->Add(this->but_specFilter);
			this->leftPanel->Controls->Add(this->but_metaFilter);
			this->leftPanel->Controls->Add(this->but_direcFilter);
			this->leftPanel->Controls->Add(this->but_scan);
			this->leftPanel->Dock = System::Windows::Forms::DockStyle::Left;
			this->leftPanel->Location = System::Drawing::Point(0, 0);
			this->leftPanel->Name = L"leftPanel";
			this->leftPanel->Size = System::Drawing::Size(200, 411);
			this->leftPanel->TabIndex = 0;
			// 
			// but_advancedFilter
			// 
			this->but_advancedFilter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->but_advancedFilter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->but_advancedFilter->Location = System::Drawing::Point(0, 332);
			this->but_advancedFilter->Name = L"but_advancedFilter";
			this->but_advancedFilter->Size = System::Drawing::Size(200, 77);
			this->but_advancedFilter->TabIndex = 4;
			this->but_advancedFilter->Text = L"Advanced";
			this->but_advancedFilter->UseVisualStyleBackColor = false;
			// 
			// but_specFilter
			// 
			this->but_specFilter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->but_specFilter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->but_specFilter->Location = System::Drawing::Point(0, 249);
			this->but_specFilter->Name = L"but_specFilter";
			this->but_specFilter->Size = System::Drawing::Size(200, 77);
			this->but_specFilter->TabIndex = 3;
			this->but_specFilter->Text = L"File specification filter";
			this->but_specFilter->UseVisualStyleBackColor = false;
			// 
			// but_metaFilter
			// 
			this->but_metaFilter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->but_metaFilter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->but_metaFilter->Location = System::Drawing::Point(0, 166);
			this->but_metaFilter->Name = L"but_metaFilter";
			this->but_metaFilter->Size = System::Drawing::Size(200, 77);
			this->but_metaFilter->TabIndex = 2;
			this->but_metaFilter->Text = L"Metadata filter";
			this->but_metaFilter->UseVisualStyleBackColor = false;
			// 
			// but_direcFilter
			// 
			this->but_direcFilter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->but_direcFilter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->but_direcFilter->Location = System::Drawing::Point(0, 83);
			this->but_direcFilter->Name = L"but_direcFilter";
			this->but_direcFilter->Size = System::Drawing::Size(200, 77);
			this->but_direcFilter->TabIndex = 1;
			this->but_direcFilter->Text = L"Directory filter";
			this->but_direcFilter->UseVisualStyleBackColor = false;
			// 
			// but_scan
			// 
			this->but_scan->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->but_scan->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->but_scan->Location = System::Drawing::Point(0, 0);
			this->but_scan->Name = L"but_scan";
			this->but_scan->Size = System::Drawing::Size(200, 77);
			this->but_scan->TabIndex = 0;
			this->but_scan->Text = L"SCAN";
			this->but_scan->UseVisualStyleBackColor = false;
			// 
			// scanControl1
			// 
			this->scanControl1->AccessibleName = L"";
			this->scanControl1->AutoSize = true;
			this->scanControl1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->scanControl1->Location = System::Drawing::Point(197, 0);
			this->scanControl1->MaximumSize = System::Drawing::Size(650, 415);
			this->scanControl1->MinimumSize = System::Drawing::Size(650, 415);
			this->scanControl1->Name = L"scanControl1";
			this->scanControl1->Size = System::Drawing::Size(650, 415);
			this->scanControl1->TabIndex = 5;
			// 
			// advanced1
			// 
			this->advanced1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->advanced1->Location = System::Drawing::Point(197, 0);
			this->advanced1->MaximumSize = System::Drawing::Size(650, 415);
			this->advanced1->MinimumSize = System::Drawing::Size(650, 415);
			this->advanced1->Name = L"advanced1";
			this->advanced1->Size = System::Drawing::Size(650, 415);
			this->advanced1->TabIndex = 4;
			// 
			// fileSpecificationFilter1
			// 
			this->fileSpecificationFilter1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->fileSpecificationFilter1->Location = System::Drawing::Point(197, 0);
			this->fileSpecificationFilter1->MaximumSize = System::Drawing::Size(650, 415);
			this->fileSpecificationFilter1->MinimumSize = System::Drawing::Size(650, 415);
			this->fileSpecificationFilter1->Name = L"fileSpecificationFilter1";
			this->fileSpecificationFilter1->Size = System::Drawing::Size(650, 415);
			this->fileSpecificationFilter1->TabIndex = 3;
			// 
			// metadataFilter1
			// 
			this->metadataFilter1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->metadataFilter1->Location = System::Drawing::Point(197, 0);
			this->metadataFilter1->MaximumSize = System::Drawing::Size(650, 415);
			this->metadataFilter1->MinimumSize = System::Drawing::Size(650, 415);
			this->metadataFilter1->Name = L"metadataFilter1";
			this->metadataFilter1->Size = System::Drawing::Size(650, 415);
			this->metadataFilter1->TabIndex = 2;
			// 
			// directoryFilter1
			// 
			this->directoryFilter1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->directoryFilter1->Location = System::Drawing::Point(197, 0);
			this->directoryFilter1->MaximumSize = System::Drawing::Size(650, 415);
			this->directoryFilter1->MinimumSize = System::Drawing::Size(650, 415);
			this->directoryFilter1->Name = L"directoryFilter1";
			this->directoryFilter1->Size = System::Drawing::Size(650, 415);
			this->directoryFilter1->TabIndex = 1;
			// 
			// basicForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(844, 411);
			this->Controls->Add(this->scanControl1);
			this->Controls->Add(this->advanced1);
			this->Controls->Add(this->fileSpecificationFilter1);
			this->Controls->Add(this->metadataFilter1);
			this->Controls->Add(this->directoryFilter1);
			this->Controls->Add(this->leftPanel);
			this->MaximumSize = System::Drawing::Size(860, 450);
			this->MinimumSize = System::Drawing::Size(860, 450);
			this->Name = L"basicForm";
			this->Text = L"Pffff (Personal filter for file)";
			this->leftPanel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		private: System::Void but_scan_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->scanControl1->Visible = true;
			this->directoryFilter1->Visible = false;
			this->metadataFilter1->Visible = false;
			this->fileSpecificationFilter1->Visible = false;
			this->advanced1->Visible = false;
			scanControl1->printConsole();
		}

		private: System::Void but_direcFilter_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->scanControl1->Visible = false;
			this->directoryFilter1->Visible = true;
			this->metadataFilter1->Visible = false;
			this->fileSpecificationFilter1->Visible = false;
			this->advanced1->Visible = false;
		}
		private: System::Void but_metaFilter_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->scanControl1->Visible = false;
			this->directoryFilter1->Visible = false;
			this->metadataFilter1->Visible = true;
			this->fileSpecificationFilter1->Visible = false;
			this->advanced1->Visible = false;
		}
		private: System::Void but_specFilter_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->scanControl1->Visible = false;
			this->directoryFilter1->Visible = false;
			this->metadataFilter1->Visible = false;
			this->fileSpecificationFilter1->Visible = true;
			this->advanced1->Visible = false;
		}
		private: System::Void but_advancedFilter_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->scanControl1->Visible = false;
			this->directoryFilter1->Visible = false;
			this->metadataFilter1->Visible = false;
			this->fileSpecificationFilter1->Visible = false;
			this->advanced1->Visible = true;			
		}
	};
}
