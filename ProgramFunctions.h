#pragma once
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




	void setFirstDirectoryPath(String^ path)
	{
		directories->Add(path);
	}

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

	bool ScanDateFormatOfJpg(List<Char>^ fileOpened, size_t index)
	{
		if (fileOpened[index] == ':' && fileOpened[index + 6] == ' ') // test first colon + space
		{
			// test colon char
			if (fileOpened[index + 3] == ':' && fileOpened[index + 9] == ':' && fileOpened[index + 12] == ':')
			{
				List<Char>^ testNumChar = gcnew List<Char>();
				testNumChar->AddRange(gcnew array<Char>{ fileOpened[index - 4], fileOpened[index - 3], fileOpened[index - 2], fileOpened[index - 1] });
				// start index
				testNumChar->AddRange(gcnew array<Char>{ fileOpened[index + 1], fileOpened[index + 2] });
				// colon
				testNumChar->AddRange(gcnew array<Char>{ fileOpened[index + 4], fileOpened[index + 5] });
				// space char
				testNumChar->AddRange(gcnew array<Char>{ fileOpened[index + 7], fileOpened[index + 8] });
				// colon
				testNumChar->AddRange(gcnew array<Char>{ fileOpened[index + 10], fileOpened[index + 11] });
				// colon
				testNumChar->AddRange(gcnew array<Char>{ fileOpened[index + 13], fileOpened[index + 14] });

				// test numbers format
				for each (Char c in testNumChar)
				{
					if (!Char::IsDigit(c))
					{
						return false;
					}
				}
				String^ returnDate = gcnew String(testNumChar->ToArray());
				datesFinded->Add(returnDate);
				return true;
			}
		}
		return false;
	}
};







