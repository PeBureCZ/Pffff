#pragma once
#include "ProgramFunctions.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//CUSTOM START
using namespace System::IO;
using namespace System::Collections::Generic;
//CUSTOM END

public ref class ProgramFunctions
{

private:
	List<String^>^ directories = gcnew List<String^>();
	List<String^>^ filesFinded = gcnew List<String^>();
	List<String^>^ datesFinded = gcnew List<String^>();

public:
	

	String^ functionTesting()
	{
		//List<String^>^ directories2 = gcnew List<String^>();
		//array<String^>^ initialItems = { L"1", L"2", L"3" };
		//directories2->AddRange(initialItems);
		//directories2->Add(L"8");
		//return directories2[3];
		findNewFilesInDirectory(directories[0], 0);
		return "directory: " + directories->Count.ToString() + "files: " + filesFinded->Count.ToString();
	}

	array<String^>^ filesOld;




	

	void findNewFilesInDirectory(String^ path, size_t lastIndexPath)
	{
		try
		{
			for each (String^ file in Directory::GetFileSystemEntries(path))
			{
				if (Directory::Exists(file))
				{
					directories->Add(file);
				}
				else if (Path::GetExtension(file)->Equals(".jpg", StringComparison::InvariantCultureIgnoreCase) or Path::GetExtension(file)->Equals(".JPG", StringComparison::InvariantCultureIgnoreCase))
				{
					filesFinded->Add(file);
				}
				//else if
				//{
				// next file formats?
				//}
			}
		}
		catch (IOException^ e)
		{
		//errors - nothing impl.
		}
	}

	bool scanDateFormatOfJpg (array<Char>^ fileOpened, size_t index)
	{
		if (fileOpened[index] == ':' && fileOpened[index + 6] == ' ') // test first colon + space
		{
			// test colon char
			if (fileOpened[index + 3] == ':' && fileOpened[index + 9] == ':' && fileOpened[index + 12] == ':')
			{
				array<Char>^ testNumChar = gcnew array<Char>(15);
				testNumChar[0] = fileOpened[index - 4];
				testNumChar[1] = fileOpened[index - 3];
				testNumChar[2] = fileOpened[index - 2];
				testNumChar[3] = fileOpened[index - 1];
				// start index
				testNumChar[4] = fileOpened[index + 1];
				testNumChar[5] = fileOpened[index + 2];
				// colon
				testNumChar[6] = fileOpened[index + 4];
				testNumChar[7] = fileOpened[index + 5];
				// space char
				testNumChar[8] = fileOpened[index + 7];
				testNumChar[9] = fileOpened[index + 8];
				// colon
				testNumChar[10] = fileOpened[index + 10];
				testNumChar[11] = fileOpened[index + 11];
				// colon
				testNumChar[12] = fileOpened[index + 13];
				testNumChar[13] = fileOpened[index + 14];
				testNumChar[14] = '\0'; // Null-terminate the string

				// test numbers format
				for (size_t l = 0; l < testNumChar->Length; l++)
				{
					if (!Char::IsDigit(testNumChar[l]))
					{
						return false;
					}
				}
				String^ returnDate = gcnew String(testNumChar);
				datesFinded->Add(returnDate);
				return true;
			}
		}
		return false;
	}

	void addDirectoryPath(String^ path)
	{
		directories->Add(path);
	}

	void removeDirectory(int index)
	{
		directories->RemoveAt(index);
	}
};







