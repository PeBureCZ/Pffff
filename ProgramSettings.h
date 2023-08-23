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
    String^ programVersion = L" Beta v.0.7.0   ";
    
   /* 
   Beta v.0.8.0
    changelist:
    -add "MAX_DIRECTORIES_SCAN_PER_CHUNK changer" to Advanced(filter)

    Beta v.0.9.0
    changelist:
    -Add a function for scanning from already found files

    v 1.0.0
    changelist:
    - repair warnings (posible loss of data, atc.)
    - clear code
    
    :*/


    String^ getProgramVersion()
    {
        return programVersion;
    }

    void setMinFileSize(long long newSize)
    {
        minFileSize = newSize;
    }

};



