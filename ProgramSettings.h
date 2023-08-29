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

    bool checkMinFileSize = false; //file specification filter

    String^ programVersion = " " + "v.1.0.1" + "   "; //all
    
   /* 
   *FUTURE UPDATES PLAN
    v 1.1.0
    - add foto rotation (buttons) and auto foto dimension 

    v 1.2.0
    - add "open folder" button in directory filter
    - ability to remove finded files from selected (finded list box)

    v 1.3.0
    - add "filter summary" in "SCAN" 
  
    
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



