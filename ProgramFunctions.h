#pragma once
#include "ProgramSettings.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

using namespace System::IO;
using namespace System::Collections::Generic;


public ref class ProgramFunctions
{

private:

	List<String^>^ directories = gcnew List<String^>();
	List<String^>^ filesForScan = gcnew List<String^>();
	List<String^>^ datesFinded = gcnew List<String^>(); //indexed
	List<String^>^ filesFinded = gcnew List<String^>(); //indexed
	List<String^>^ consoleText = gcnew List<String^>();
	List<String^>^ directoryInFilter = gcnew List<String^>();
	List<String^>^ nameMustContain = gcnew List<String^>();
	UInt32 scannedDirectories = 0;

	Int64 minDate = 19000101000000; //date format eg.: "20130622081147" extract from "2013:06:22 08:11:47" (colon,colon,space,colon,colon)
	Int64 maxDate = 23001231000000; // 2300:12:31 00:00:00

	int delayResended = 200;

	int consoleActiveIndex = 0;
	ProgramSettings^ Settings;
public:
	bool scanningNow = false;
	bool scanned = false;

public: 
	String^ functionTesting()
	{
		return "";
	}

	void initializeSettings(ProgramSettings^ SettingObj)
	{
		Settings = SettingObj;
	}

	//SCAN-CONTROL FUNCTIONS START________________________________________________

	bool runScan(bool repeated) //false = function Scan complete, true = function must be repeated
	{
		addConsoleOutputs();
		if (repeated == false) directories->AddRange(directoryInFilter); //get all paths from DirectoryFilter (eg."C:\Users" ... )
		int lastIndex = directories->Count - 1;
		size_t maxScanLength = 0;
		if (directories->Count > 0 ) //NEED REWORK -> "&& scanned == false"
		{
			scanningNow = true;
			do //from last to index 0 (not owerhelmed by new directories)
			{
				findNewFilesInDirectory(directories[lastIndex], lastIndex);
				lastIndex = directories->Count - 1;
				maxScanLength++;
			} while (lastIndex >= 0 && maxScanLength < 51); 
		}
		//else addToConsole("No directory finded: try add new directory in Directory filter");

		if (maxScanLength == 51)
		{
			scannedDirectories += 51;

			return true; //repeat function
		}
		scannedDirectories += maxScanLength;
		if (runScanimages()) return true;
		return false;
	}

	bool runScanimages()
	{
		if (filesForScan->Count > 0)
		{
			if (FindDateFormat(filesForScan[0]))
			{
				filesFinded->Add(filesForScan[0]);
				filesForScan->RemoveAt(0);
				return true;
			}
			filesForScan->RemoveAt(0);
		}
		else
		{
			if (filesForScan->Count == 0 && directories->Count == 0)
			{
				scanningNow = false;
				scanned = true;
			}
			return false;
		}

	}

	int getFilesFindedCount()
	{
		return filesFinded->Count;
	}

	int getDelay()
	{
		return delayResended;
	}

	void resetScanInFunctions()
	{

		if (scanningNow == false)
		{
			filesFinded->Clear();
			datesFinded->Clear();
			clearConsole();
			addToConsole("reset applied...");
			//need refresh console by function "printConsole();"
			scanned = false;
		}
		else addToConsole("Scan still running...");

	}

	//CONSOLE START

	void addToConsole(String^ text)
	{
		consoleText->Add(text + "\r\n");
		if (consoleText->Count > 7)
		{
			consoleActiveIndex = consoleText->Count - 8;
		}
	}

	void clearConsole()
	{
		consoleText->Clear();
	}

	void addToConsoleIndex(int addToIndex)
	{
		if (consoleActiveIndex + addToIndex > consoleText->Count - 7)
		{
			if (addToIndex > 0) consoleActiveIndex = consoleText->Count - 7;
		}
		consoleActiveIndex += addToIndex;
		if (consoleActiveIndex < 0) consoleActiveIndex = 0;
	}

	String^ getConsoleOutput()
	{
		String^ outputStr;
		if (consoleActiveIndex + 7 >= consoleText->Count) //CONSOLE LENGTH = 8 LINES
		{
			for (size_t i = consoleActiveIndex; i < consoleText->Count; i++)
			{
				outputStr += consoleText[i];
			}
		}
		else
		{
			for (size_t i = consoleActiveIndex; i <= consoleActiveIndex + 7; i++)
			{
				outputStr += consoleText[i];
			}
		}
		return outputStr;
	}

	size_t getConsoleLength()
	{
		return static_cast<size_t>(consoleText->Count);
	}

	bool scanAgain()
	{
		if (directories->Count == 0 && filesForScan->Count == 0) return false;
		return true;
	}

	//DIRECTORY FILTER FUNCTIONS START________________________________________________

	void addDirectoryPath(String^ path)
	{
		directoryInFilter->Add(path);
	}

	void removeDirectory(int index)
	{
		directoryInFilter->RemoveAt(index);
	}

	//METADATA FILTER FUNCTIONS START________________________________________________

	bool minAndMaxDateCondition(String^ dateStringChecked)
	{
		Int64 checkedDate = Int64::Parse(dateStringChecked);
		if (Settings->checkMinDate && minDate > checkedDate)return false;
		if (Settings->checkMaxDate && maxDate < checkedDate) return false;
		return true;
	}

	void setMinDate(Int64 newMinDate)
	{
		minDate = newMinDate;
	}

	void setMaxDate(Int64 newMaxDate)
	{
		maxDate = newMaxDate;
	}

	List<String^>^ getFindedItemsPaths()
	{
		return filesFinded;
	}

	String^ getFindedItemPath(int index)
	{
		if (filesFinded->Count - 1 >= index)
		{
			return filesFinded[index];
		}

	}

	String^ setMinYYYY(String^ newYYYY)
	{
		Int32 numDate;
		if (Int32::TryParse(newYYYY, numDate))
		{
			if (numDate > 9999)
			{
				return "1900";
			}
			else if (newYYYY->Length == 0)
			{
				return "0001";
			}
			return newYYYY;
		}
		else
		{
			return "1900";
		}
	}

	String^ setMinMM(String^ newMM)
	{
		Int32 numDate;
		if (Int32::TryParse(newMM, numDate))
		{
			if (numDate > 12)
			{
				return "12";
			}
			else if (newMM->Length == 0)
			{
				return "01";
			}
			return newMM;
		}
		else
		{
			return "01";
		}
	}

	String^ setMinDD(String^ newDD)
	{
		Int32 numDate;
		if (Int32::TryParse(newDD, numDate))
		{
			if (numDate > 31)
			{
				return "31";
			}
			else if (newDD->Length == 0)
			{
				return "01";
			}
			return newDD;
		}
		else
		{
			return "01";
		}
	}

	String^ setMaxYYYY(String^ newYYYY)
	{
		Int32 numDate;
		if (Int32::TryParse(newYYYY, numDate))
		{
			if (numDate > 9999)
			{
				return "9999";
			}
			else if (newYYYY->Length == 0)
			{
				return "0001";
			}
			return newYYYY;
		}
		else
		{
			return "2300";
		}
	}

	String^ setMaxMM(String^ newMM)
	{
		Int32 numDate;
		if (Int32::TryParse(newMM, numDate))
		{
			if (numDate > 12)
			{
				return "12";
			}
			else if (newMM->Length == 0)
			{
				return "01";
			}
			return newMM;
		}
		else
		{
			return "01";
		}
	}

	String^ setMaxDD(String^ newDD)
	{
		Int32 numDate;
		if (Int32::TryParse(newDD, numDate))
		{
			if (numDate > 31)
			{
				return "31";
			}
			else if (newDD->Length == 0)
			{
				return "01";
			}
			return newDD;
		}
		else
		{
			return "01";
		}
	}

	//FILE SPECIFICATION FILTER FUNCTIONS START________________________________________________

	void addNameToFilter(String^ name)
	{
		nameMustContain->Add(name);
	}

	void removeNameFromFilter(int index)
	{
		nameMustContain->RemoveAt(index);
	}

	private: //PRIVATE FUNCTIONS START________________________________________________
	

	bool FindDateFormat(String^ path)
	{
		try
		{
			array<Byte>^ byteArray = File::ReadAllBytes(path);
			List<Byte>^ bytesVec = gcnew List<Byte>(byteArray);
			size_t scanSize = 0;
			if (Settings->maxByteFileScan < bytesVec->Count)
			{
				scanSize = Settings->maxByteFileScan;
			}
			else
			{
				scanSize = bytesVec->Count;
			}

			if (Settings->maxByteFileScan < 18 && bytesVec->Count < 18)
			{
				return false;
			}
			delayResended = static_cast<int>(scanSize) / 20000+80;
			if (Settings->checkExif) return scanJpgExif(bytesVec, scanSize);
			else return scanJpgNoExif(bytesVec, scanSize);
		}
		catch (Exception^ ex)
		{
			return false;
		}
	}

	void findNewFilesInDirectory(String^ path, int lastIndexPath)
	{
		try
		{
			//VERSION 2
			for each (String ^ file in Directory::GetDirectories(path)) //.NET not contain search for files+directories?!?!
				//recursive!!!!!
			{
				if (Directory::Exists(file))
				{
					directories->Add(file);

				}
			}
			for each (String ^ file in Directory::GetFiles(path))
			{
				//fileInfo->Extension - REWORK??
				if (Path::GetExtension(file)->Equals(".jpg", StringComparison::InvariantCultureIgnoreCase) || Path::GetExtension(file)->Equals(".JPG", StringComparison::InvariantCultureIgnoreCase))
				{
					if (nameMustContain->Count > 0)
					{
						if (!containName(file)) continue; //The file does not contain the requested text in its name or in its directory path
					}
					if (Settings->checkMinFileSize)
					{
						FileInfo^ fileInfo = gcnew FileInfo(file);
						if (fileInfo->Length >= Settings->minFileSize * 1000)
						{
							filesForScan->Add(file);
						}
					}
					else
					{
						filesForScan->Add(file);
					}
				}
				//else if
				//{
				// next file formats?
				//}
			}
			directories->RemoveAt(lastIndexPath);
		}
		catch (Exception^ e)
		{
			//errors - nothing impl.
		}
	}

	bool scanDateFormatOfJpg(List<Byte>^ fileOpened, int index)
	{
		if (fileOpened[index] == ':' && fileOpened[index + 6] == ' ') // test first colon + space
		{
			// test colon char
			if (fileOpened[index + 3] == ':' && fileOpened[index + 9] == ':' && fileOpened[index + 12] == ':')
			{
				array<Char>^ testNumChar = gcnew array<Char>(14);
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

				// test numbers format
				for (size_t l = 0; l < testNumChar->Length; l++)
				{
					//addToConsole(testNumChar[l].ToString());
					if (!Char::IsDigit(testNumChar[l])) return false;
				}
				String^ returnDate = gcnew String(testNumChar);
				if (minAndMaxDateCondition(returnDate)) //check min and max date condition (metadataFilter)
				{
					datesFinded->Add(returnDate);
					//returned format eg.: "20130622081147" extract from "2013:06:22 08:11:47" (colon,colon,space,colon,colon)
					return true;
				}
				else return false; 
			}
		}
		return false;
	}

	bool scanJpgNoExif(List<Byte>^ fileOpened, size_t maxScanSize)
	{
		for (size_t i = 0; i < maxScanSize; i++)
		{
			if (scanDateFormatOfJpg(fileOpened, i))
			{
				return true;
			}
		}
		return false;
	}

	bool scanJpgExif(List<Byte>^ fileOpened, size_t maxScanSize)
	{
		bool exifChecked = false;
		for (size_t i = 0; i < maxScanSize; i++)
		{
			if (static_cast<unsigned char>(fileOpened[i]) == 0xFF && static_cast<unsigned char>(fileOpened[i + 1]) == 0XE1)
			{
				exifChecked = true; //EXIF FINDED!
			}
			else if (scanDateFormatOfJpg(fileOpened, i)) return true;
			else if (exifChecked == false && i >= Settings->maxByteExifScan) return false;
		}
		return false;
	}

	bool containName(String^ pathAndName)
	{
		int count = nameMustContain->Count;
		for (int i = 0; i < count; i++)
		{
			if (pathAndName->Contains(nameMustContain[i])) return true;
		}
		return false;

	}

	void addConsoleOutputs()
	{
	addToConsole("directories scanned: " + scannedDirectories.ToString());
	addToConsole("directories for scan remaining: " + directories->Count.ToString());
	addToConsole("files for scan scan remaining: " + filesForScan->Count.ToString());
	}
	
};







