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
    long long maxByteExifScan = 120; //advanced setting
    long long maxByteFileScan = 22020608; //advanced setting
    long long minFileSize = 8; //fileSpecificationFilter setting

    bool checkMinDate = false; //metaFilter
    bool checkMaxDate = false; //metaFilter
    bool checkExif = false; //metaFilter

    bool checkMinFileSize = false;
    String^ programVersion = " " + "Beta v.0.9.1" + "   ";
    
   /* 
    v 1.0.0
    - clear code


    v 1.1.0
    - add optimization mode in advance
    - add foto rotation (buttons) and auto foto dimension 

    v 1.2.0
    - add "open folder" button in directory filter
    - ability to remove finded files from selected (finded list box)
  
    
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



