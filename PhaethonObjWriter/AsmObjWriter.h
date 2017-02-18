#pragma once

#include "ObjWriter.h"

class AsmObjWriter : public ObjWriter
{
  public:
    AsmObjWriter(const char *pszFilename)
    {
        _pOutFile = ::fopen(pszFilename, "w");
    }

    ~AsmObjWriter()
    {
        ::fclose(_pOutFile);
    }

    std::string GetOpString(const ObjArgument &obj) const;

    void OutputInstruction(
        OpCode opCode,
        ObjArgument *args) override;

    void OutputLabel(
        const char *pszLabel) override;

    void FinishCode() override {}

  private:
    FILE *_pOutFile;
};
