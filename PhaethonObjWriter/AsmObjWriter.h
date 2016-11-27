#pragma once

#include "ObjWriter.h"

class AsmObjWriter : public ObjWriter
{
  public:
    AsmObjWriter(const char* pszFilename)
    {
        _pOutFile = ::fopen(pszFilename, "w");
    }

    ~AsmObjWriter()
    {
        ::fclose(_pOutFile);
    }

    std::string GetOpString(const ObjArgument &obj) const;

    void OutputInstruction(
        OpCodes::Enum opCode,
        ObjArgument* args
        ) override;

    void OutputLabel(
        const char* pszLabel
        ) override;

  private:
    FILE* _pOutFile;
};
