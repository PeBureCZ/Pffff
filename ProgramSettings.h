#pragma once
#include "ProgramFunctions.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public ref class ProgramSettings
{
//public:
//


public: 
    size_t maxByteExifScan;
    size_t maxByteFileScan;
    bool checkExif;
    String^ testString = L"subClass communication";
    void testFunction()
    {

    }
    String^ testFunction2()
    {
        return testString;
    }




//
    //ProgramSettings() : checkExif(true), maxByteExifScan(120), maxByteFileScan(10000000)
    //{
    //    //constructor...
    //}
//
//    //size_t nothingYet();
//
//private:
};



