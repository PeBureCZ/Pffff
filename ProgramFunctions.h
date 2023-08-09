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


	List<String^>^ directories = gcnew List<String^>();
	List<String^>^ filesFinded = gcnew List<String^>();

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


	//ProgramFunctions() //constructor
	//{
	//	
	//	TODO: Add the constructor code here
	//	
	//}

	////CLASS VARIABLES
	//ProgramSettings& settingRefObj;

	////CLASS VARIABLES END

	////CLASS VECTORS
	//std::vector<std::string> recursiveFiles;
	//std::vector<std::string> filesForScan; //indexed
	//std::vector<std::string> datesFinded; //indexed




	//CLASS VECTORS END

public:
	//ProgramFunctions(ProgramSettings& setting);

	//void findNewFilesInDirectory(std::string path, size_t lastIndexPath); //find all files in file directory (not recursive!)
	//bool scanJpgNoExif(const std::vector<char>& fileOpened, size_t maxScanSize);
	//bool scanJpgExif(const std::vector<char>& fileOpened, size_t maxScanSize);
	//bool findDateFormat(std::string path);
	//void testFunction(); //only for test and debug
	//void runScan(std::string firstPath);
	//bool scanDateFormatOfJpg(const std::vector<char>& fileOpened, size_t index);

};







