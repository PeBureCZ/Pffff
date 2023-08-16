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
    size_t maxByteFileScan = 8388608; //for advanced

    bool checkMinDate = false;
    bool checkMaxDate = false;
    bool checkExif = false;
    String^ programVersion = L" Alfa v.0.1.230816a   ";

    void testFunction()
    {

    }
    String^ getProgramVersion()
    {
        return programVersion;
    }
};



