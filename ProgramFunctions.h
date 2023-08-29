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

#define MAX_DIRECTORIES_SCAN_PER_CHUNK 51

public ref class ProgramFunctions
{
private:
	List<String^>^ directories = gcnew List<String^>(); //remaining directories for scan
	List<String^>^ filesForScan = gcnew List<String^>(); //remaining files for scan 
	List<String^>^ datesFinded = gcnew List<String^>(); //INDEXED - custom date format (finded items/files)
	List<String^>^ filesFinded = gcnew List<String^>(); //INDEXED paths (finded items/files)
	List<String^>^ consoleText = gcnew List<String^>(); //console text
	List<String^>^ directoryInFilter = gcnew List<String^>(); //directories added (from directory filter)
	List<String^>^ nameMustContain = gcnew List<String^>(); //names list (condition)
	UInt32 scannedDirectories = 0; //console output
	UInt32 filesCanotBeScaned = 0; //console output

	int bonusDirectoriesScan = 0;//advanced scan option
	int consoleActiveIndex = 0; //console line to show (manual)

	bool scanningNow = false;
	bool scanned = false;
	bool readyToScan = true; //output - "wait or can scan again"
	bool optimizationMode = false; //true = not clear console after chunk scan, run scan, stop scan, atc.

	Int64 minDate = 19000101000000; //date format eg.: "20130622081147" extract from "2013:06:22 08:11:47" (colon,colon,space,colon,colon)
	Int64 maxDate = 23001231000000; // 2300:12:31 00:00:00

	ProgramSettings^ Settings;

public: 

	void initializeSettings(ProgramSettings^ SettingObj)
	{
		Settings = SettingObj;
	}

	//SCAN-CONTROL FUNCTIONS START (PUBLIC) ________________________________________________

	bool runScan(bool repeated) //false = function Scan complete, true = function must be repeated
	{
		addToConsole("scan running...");
		readyToScan = false;
		if (repeated == false) directories->AddRange(directoryInFilter); //get all paths from DirectoryFilter (eg."C:\Users" ... )
		int lastIndex = directories->Count - 1;
		unsigned int maxScanLength = 0;
		scanningNow = true;
		if (directories->Count > 0 )
		{
			do //from last to index 0 (not owerhelmed by new directories)
			{
				findNewFilesInDirectory(directories[lastIndex], lastIndex);
				lastIndex = directories->Count - 1;
				maxScanLength++;
			} while (lastIndex >= 0 && static_cast<int>(maxScanLength) < (MAX_DIRECTORIES_SCAN_PER_CHUNK+bonusDirectoriesScan));
		}

		if (maxScanLength == (MAX_DIRECTORIES_SCAN_PER_CHUNK + bonusDirectoriesScan))
		{
			scannedDirectories += (MAX_DIRECTORIES_SCAN_PER_CHUNK + bonusDirectoriesScan);
			readyToScan = true;
			return true; //repeat function
		}
		scannedDirectories += maxScanLength;
		if (runScanimages()) return true;
		readyToScan = true;
		return false;
	}

	bool runScanimages()
	{
		if (filesForScan->Count > 0)
		{
			if (containName(filesForScan[0]))
			{
				if (Settings->checkMinFileSize)
				{
					FileInfo^ fileInfo = gcnew FileInfo(filesForScan[0]);
					if (fileInfo->Length >= Settings->minFileSize * 1000 && FindDateFormat(filesForScan[0]))
					{
						filesFinded->Add(filesForScan[0]);
					}
				}
				else
				{
					if (FindDateFormat(filesForScan[0]))
					{
						filesFinded->Add(filesForScan[0]);
					}
				}
			}
			filesForScan->RemoveAt(0);
			readyToScan = true;
			return true;
		}
		else
		{
			if (filesForScan->Count == 0 && directories->Count == 0)
			{
				scanningNow = false;
			}
			readyToScan = true;
			return false;
		}

	}

	void addFileForScan(String^ path)
	{
		filesForScan->Add(path);
	}

	int getFilesFindedCount()
	{
		return filesFinded->Count;
	}

	bool getScanningNow()
	{
		return scanningNow;
	}

	bool getScanned()
	{
		return scanned;
	}

	bool getReadyToScan()
	{
		return readyToScan;
	}

	void setScanningNow(bool newBool)
	{
		scanningNow = newBool;
	}

	void setScanned(bool newBool)
	{
		scanned = newBool;
	}

	void setReadyToScan(bool newBool)
	{
		readyToScan = newBool;
	}

	void resetScanInFunctions()
	{
		filesFinded->Clear();
		datesFinded->Clear();
		directories->Clear();
		filesForScan->Clear();
		clearConsole();
		addToConsole("reset applied...");
		//need refresh console by function "printConsole();"
		scanned = false;
		filesCanotBeScaned = 0;
		scannedDirectories = 0;
	}

	List<String^>^ getFilesFinded()
	{
		return filesFinded;
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
		if (optimizationMode == false) consoleText->Clear();
	}

	void addToConsoleIndex(int addToIndex)
	{
		if (consoleActiveIndex + addToIndex > consoleText->Count - 7 && addToIndex > 0)
		{
			consoleActiveIndex = consoleText->Count - 7;
		}
		consoleActiveIndex += addToIndex;
		if (consoleActiveIndex < 0) consoleActiveIndex = 0;
	}

	String^ getConsoleOutput()
	{
		String^ outputStr;
		if (consoleActiveIndex + 7 >= consoleText->Count) //CONSOLE LENGTH = 8 LINES
		{
			for (int i = consoleActiveIndex; i < consoleText->Count; i++)
			{
				outputStr += consoleText[i];
			}
		}
		else
		{
			for (int i = consoleActiveIndex; i <= consoleActiveIndex + 7; i++)
			{
				outputStr += consoleText[i];
			}
		}
		return outputStr;
	}

	void addOutputToConsole()
	{
		addToConsole("directories scanned: " + scannedDirectories.ToString());
		addToConsole("directories for scan remaining: " + directories->Count.ToString());
		addToConsole("files for scan scan remaining: " + filesForScan->Count.ToString());
		addToConsole("files can´t be opened (with error): " + filesCanotBeScaned.ToString());
	}

	int getConsoleLength()
	{
		return consoleText->Count;
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

	void removeAllDirectories()
	{
		directoryInFilter->Clear();
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
		addToConsole("error in console line!");
		return ""; //empty return
	}

	String^ setMinYYYY(String^ newYYYY)
	{
		Int32 numDate;
		if (Int32::TryParse(newYYYY, numDate))
		{
			if (numDate > 9999) return "1900";
			else if (newYYYY->Length == 0) return "0001";
			return newYYYY;
		}
		else return "1900";
	}

	String^ setMinMM(String^ newMM)
	{
		Int32 numDate;
		if (Int32::TryParse(newMM, numDate))
		{
			if (numDate > 12) return "12";
			else if (newMM->Length == 0) return "01";
			return newMM;
		}
		else return "01";
	}

	String^ setMinDD(String^ newDD)
	{
		Int32 numDate;
		if (Int32::TryParse(newDD, numDate))
		{
			if (numDate > 31) return "31";
			else if (newDD->Length == 0) return "01";
			return newDD;
		}
		else return "01";
	}

	String^ setMaxYYYY(String^ newYYYY)
	{
		Int32 numDate;
		if (Int32::TryParse(newYYYY, numDate))
		{
			if (numDate > 9999) return "9999";
			else if (newYYYY->Length == 0) return "0001";
			return newYYYY;
		}
		else return "2300";
	}

	String^ setMaxMM(String^ newMM)
	{
		Int32 numDate;
		if (Int32::TryParse(newMM, numDate))
		{
			if (numDate > 12) return "12";
			else if (newMM->Length == 0) return "01";
			return newMM;
		}
		else return "01";
	}

	String^ setMaxDD(String^ newDD)
	{
		Int32 numDate;
		if (Int32::TryParse(newDD, numDate))
		{
			if (numDate > 31) return "31";
			else if (newDD->Length == 0) return "01";
			return newDD;
		}
		else return "01";
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

	//ADVANCED FUNCTIONS START________________________________________________

	void setBonusDirectoriesScan(int bonus)
	{
		if (bonus + MAX_DIRECTORIES_SCAN_PER_CHUNK <= 0) bonusDirectoriesScan = (-1 * MAX_DIRECTORIES_SCAN_PER_CHUNK) + 1; //cannot be negative or zero!
		else bonusDirectoriesScan = bonus;		
	}

	//PRIVATE FUNCTIONS START________________________________________________
	private: 

	bool FindDateFormat(String^ path)
	{
		try
		{
			array<Byte>^ byteArray = File::ReadAllBytes(path);
			List<Byte>^ bytesVec = gcnew List<Byte>(byteArray);
			size_t scanSize = 0;
			if (Settings->maxByteFileScan < bytesVec->Count) scanSize = Settings->maxByteFileScan;
			else scanSize = bytesVec->Count;
			if (Settings->maxByteFileScan < 18 && bytesVec->Count < 18) return false;
			if (Settings->checkExif) return scanJpgExif(bytesVec, scanSize);
			else return scanJpgNoExif(bytesVec, scanSize);
		}
		catch (Exception^)
		{
			return false;
		}
	}

	void findNewFilesInDirectory(String^ path, int lastIndexPath)
	{
		try
		{
			for each (String ^ file in Directory::GetDirectories(path)) 
			{
				if (Directory::Exists(file))
				{
					directories->Add(file);
				}
			}
			for each (String ^ file in Directory::GetFiles(path))
			{
				if (Path::GetExtension(file)->Equals(".jpg", StringComparison::InvariantCultureIgnoreCase) || Path::GetExtension(file)->Equals(".JPG", StringComparison::InvariantCultureIgnoreCase))
				{
					filesForScan->Add(file);
					
				}
				//else if
				//{
				// next file formats? (png?)
				//}
			}
			directories->RemoveAt(lastIndexPath);
		}
		catch (Exception^)
		{
			//errors - nothing impl.
			filesCanotBeScaned++;
			directories->RemoveAt(lastIndexPath);
		}
	}

	bool scanDateFormatOfJpg(List<Byte>^ fileOpened, int index)
	{
		if (fileOpened[index] == ':' && fileOpened[index + 6] == ' ') // test first colon + space
		{
			// test colon char
			if (fileOpened[index + 3] == ':' && fileOpened[index + 9] == ':' && fileOpened[index + 12] == ':')
			{
				array<Char>^ testNumChar = gcnew array<Char>(14); //THIS IS DATE FORMAT (DATE CTEATED - .jpg)
				testNumChar[0] = fileOpened[index - 4];
				testNumChar[1] = fileOpened[index - 3];
				testNumChar[2] = fileOpened[index - 2];
				testNumChar[3] = fileOpened[index - 1];
				// start index = 0
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

				// test numbers format, not digit = return (false) = invalid date format
				for (int l = 0; l < testNumChar->Length; l++)
				{
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
		for (int i = 0; i < maxScanSize; i++)
		{
			if (scanDateFormatOfJpg(fileOpened, i)) return true;
		}
		return false;
	}

	bool scanJpgExif(List<Byte>^ fileOpened, size_t maxScanSize)
	{
		bool exifChecked = false;
		for (int i = 0; i < maxScanSize; i++)
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
		if (count > 0)
		{
			for (int i = 0; i < count; i++)
			{
				if (!(pathAndName->Contains(nameMustContain[i]))) return false;
			}
		}
		return true;
	}	
};







