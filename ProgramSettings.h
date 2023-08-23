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

    bool checkMinDate = false; //metaFilter
    bool checkMaxDate = false; //metaFilter
    bool checkExif = false; //metaFilter

    bool checkMinFileSize = false;
    String^ programVersion = L" Beta v.0.8.0   ";
    
   /* 
      Beta v.0.9.0
    -Add a function for scanning from already found files

    v 1.0.0
    - repair warnings (posible loss of data, atc.)
    - clear code


    v 1.1.0
    - add foto rotation (buttons) and auto foto dimension 

    v 1.2.0
    - add "open folder" button in directory filter
  
    
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



