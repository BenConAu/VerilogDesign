#pragma once

#include "ObjWriter.h"

class BinaryObjWriter : public ObjWriter
{
  public:
    BinaryObjWriter(const char* pszFilename)
    {
        _pOutFile = ::fopen(pszFilename, "w");
    }

     ~BinaryObjWriter()
    {
        ::fprintf(_pOutFile, "@7ff\n");
        ::fclose(_pOutFile);
    }

   void OutputBytes(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4);
    void OutputWord(unsigned int w);

    void OutputInstruction(
        OpCodes::Enum opCode,
        ObjArgument *args
        ) override;

    void OutputLabel(
        const char* pszLabel
        ) override;

  private:
    FILE* _pOutFile;
};

