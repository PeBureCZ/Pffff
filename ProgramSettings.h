#pragma once


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public ref class ProgramSettings
{
public: 
    size_t maxByteExifScan = 120; //for advanced
    size_t maxByteFileScan = 22020608; //for advanced
    long long minFileSize = 8;

    bool checkMinDate = false;
    bool checkMaxDate = false;
    bool checkExif = false;
    bool checkMinFileSize = false;
    String^ programVersion = L" Alfa v.0.2.230817a   ";

    void testFunction()
    {

    }
    String^ getProgramVersion()
    {
        return programVersion;
    }

    void setMinFileSize(long long newSize)
    {
        minFileSize = newSize;
    }
};



