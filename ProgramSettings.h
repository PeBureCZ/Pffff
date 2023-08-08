#pragma once
class ProgramSettings
{
public:

    bool checkExif;
    size_t maxByteExifScan;
    size_t maxByteFileScan;

    ProgramSettings() : checkExif(true), maxByteExifScan(120), maxByteFileScan(10000000)
    {
        //constructor...
    }

    //size_t nothingYet();

private:
};



