#pragma once

//LIBRARIES
#include <string>
#include <vector>
//#include <iostream>
// 
// 
//LIBRARIES END

//PROGRAM CLASSES
#include "ProgramSettings.h"
//PROGRAM CLASSES END

//ONLY FOR TESTING
// 
//ONLY FOR TESTING

class Loader
{
private:
//
//	//CLASS VARIABLES
	ProgramSettings& settingRefObj;

//	//CLASS VARIABLES END
//
//	//CLASS VECTORS
	std::vector<std::string> recursiveFiles;
	std::vector<std::string> filesForScan; //indexed
	std::vector<std::string> datesFinded; //indexed




//	//CLASS VECTORS END
//
public:
	Loader(ProgramSettings& setting);

	//void findNewFilesInDirectory(std::string path, size_t lastIndexPath); //find all files in file directory (not recursive!)
	//bool scanJpgNoExif(const std::vector<char>& fileOpened, size_t maxScanSize);
	//bool scanJpgExif(const std::vector<char>& fileOpened, size_t maxScanSize);
	//bool findDateFormat(std::string path);
	void testFunction(); //only for test and debug
	//void runScan(std::string firstPath);
	//bool scanDateFormatOfJpg(const std::vector<char>& fileOpened, size_t index);

};







