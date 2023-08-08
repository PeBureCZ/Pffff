#include "Loader.h"
//

//Loader::Loader(ProgramSettings& setting) :settingRefObj(setting)
//{
//    settingRefObj = setting;
//}
//
//void Loader::testFunction()
//{
//
//}
//
//void Loader::runScan(std::string firstPath)
//{
////    recursiveFiles.push_back(firstPath);
////    size_t lastIndex = recursiveFiles.size() - 1;
////    do
////    {
////        findNewFilesInDirectory(recursiveFiles[lastIndex], lastIndex);
////    } while (!recursiveFiles.empty());
////
////    if (filesForScan.size() > 0)
////    {
////        do
////        {
////            if (findDateFormat(filesForScan[datesFinded.size()]))
////            {
////            }
////            else
////            {
////                std::cout << "erase: " << datesFinded.size() << std::endl;
////                filesForScan.erase(filesForScan.begin() + datesFinded.size());
////            }
////
////
////        } while (datesFinded.size() != filesForScan.size());
////    }
////    else
////    {
////
////    }
////    testFunction();
//}
////
//void Loader::findNewFilesInDirectory(std::string path, size_t lastIndexPath)
//{
////    if (std::filesystem::exists(path) and std::filesystem::is_directory(path))
////    {
////        try
////        {
////            for (const auto& entry : std::filesystem::directory_iterator(path))
////            {
////
////                if (entry.is_directory())
////                {
////                    std::cout << entry.path().string() << std::endl;
////                    recursiveFiles.push_back(entry.path().string());
////                }
////                else if (entry.is_regular_file())
////                {
////
////                    if (entry.path().extension() == ".jpg" or entry.path().extension() == ".JPG")
////                    {
////
////                        filesForScan.push_back(entry.path().string());
////                    }
////                    // WHAT ELSE? .pgn?
////                }
////                else
////                {
////                    //std::cout << "UNKNOWN FILE SCAN (LOADER)" << std::endl;
////                }
////            }
////        }
////        catch (const std::filesystem::filesystem_error& e)
////        {
////            //PERMISSION ERROR (DIRECTORY_ITERATOR)
////            recursiveFiles.erase(recursiveFiles.begin() + lastIndexPath);
////            return;
////        }
////    }
////    else
////    {
////        //CONSOLE ONLY!!!!
////        //std::cout << "error (LoaderClass): file path is not directory file!" << std::endl;
////
////    }
////    recursiveFiles.erase(recursiveFiles.begin() + lastIndexPath);
//}
////
////
//bool Loader::findDateFormat(std::string path)
//{
////    std::ifstream file(path, std::ios::binary);
////
////    if (!file)
////    {
////        return false;
////    }
////    else
////    {
////        size_t scanSize = 0;
////        std::vector<char> bytesVec((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
////        if (settingRefObj.maxByteFileScan < bytesVec.size() ? scanSize = settingRefObj.maxByteFileScan : scanSize = bytesVec.size()); //set smaler size of scan (file size or max byte scan from setting)
////        if (settingRefObj.maxByteFileScan < 18 and bytesVec.size() < 18) return false;
////
////        if (settingRefObj.checkExif) //CONDITION - ONLY EXIF FILES
////        {
////            return scanJpgExif(bytesVec, scanSize); //true from scanJpgNoExif=> add new index to vector "datesFinded" in function
////        }
////        else// 18 = minimal date format size
////        {
////            return scanJpgNoExif(bytesVec, scanSize); //true from scanJpgNoExif=> add new index to vector "datesFinded" in function
////        }
////    }
////    //PUSH NO DATE (NULL?) INTO INDEX OF PATH!
//    return false;
//}
//
//bool Loader::scanJpgNoExif(const std::vector<char>& fileOpened, size_t maxScanSize)
//{
////
////    for (size_t i = 0; i < maxScanSize; i++)
////    {
////        if (scanDateFormatOfJpg(fileOpened, i)) return true;
////    }
//    return false;
//}
////
//bool Loader::scanJpgExif(const std::vector<char>& fileOpened, size_t maxScanSize)
//{
////    bool exifChecked = false;
////    for (size_t i = 0; i < maxScanSize; i++)
////    {
////        if (static_cast<unsigned char>(fileOpened[i]) == 0xFF and static_cast<unsigned char>(fileOpened[i + 1]) == 0XE1)
////        {
////            //EXIF FINDED!
////            std::cout << "exif finded" << std::endl;
////            exifChecked = true;
////        }
////        else if (scanDateFormatOfJpg(fileOpened, i)) return true;
////        /*      else if (exifChecked == false && i >= settingRefObj.maxByteExifScan) return false;*/
////    }
//    return false;
//}
////
//bool Loader::scanDateFormatOfJpg(const std::vector<char>& fileOpened, size_t index)
//{
////    if (fileOpened[index] == ':' and fileOpened[index + 6] == ' ') //test first colon + space 
////    {
////        //test colon char
////        if (fileOpened[index + 3] == ':' and fileOpened[index + 9] == ':' and fileOpened[index + 12] == ':')
////        {
////
////            std::vector<char> testNumChar;
////            testNumChar.push_back(fileOpened[index - 4]);
////            testNumChar.push_back(fileOpened[index - 3]);
////            testNumChar.push_back(fileOpened[index - 2]);
////            testNumChar.push_back(fileOpened[index - 1]);
////            //start index
////            testNumChar.push_back(fileOpened[index + 1]);
////            testNumChar.push_back(fileOpened[index + 2]);
////            //colon
////            testNumChar.push_back(fileOpened[index + 4]);
////            testNumChar.push_back(fileOpened[index + 5]);
////            //space char
////            testNumChar.push_back(fileOpened[index + 7]);
////            testNumChar.push_back(fileOpened[index + 8]);
////            //colon
////            testNumChar.push_back(fileOpened[index + 10]);
////            testNumChar.push_back(fileOpened[index + 11]);
////            //colon
////            testNumChar.push_back(fileOpened[index + 13]);
////            testNumChar.push_back(fileOpened[index + 14]);
////
////            //test numbers format
////            for (size_t l = 0; l < testNumChar.size(); l++)
////            {
////                if (static_cast<int>(testNumChar[l]) > 57 or static_cast<int>(testNumChar[l]) < 48)
////                {
////                    return false;
////                }
////            }
////            std::string returnDate(testNumChar.data(), testNumChar.size());
////            datesFinded.push_back(returnDate);
////            return true;
////        }
////
////    }
//    return false;
//}

