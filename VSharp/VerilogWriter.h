#pragma once

class VerilogWriter
{
public:
    VerilogWriter(const char *pszFilename)
    {
        _pOutFile = ::fopen(pszFilename, "w");
    }

    ~VerilogWriter()
    {
        ::fclose(_pOutFile);
    }

    void OutputString(const char* pszOut) 
    {
        fprintf(
            _pOutFile,
            "%s",
            pszOut);
    }

    void FinishCode() {}

private:
    FILE *_pOutFile;
};