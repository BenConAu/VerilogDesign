#pragma once

#include "ObjWriter.h"

class BinaryObjWriter : public ObjWriter
{
  public:
    BinaryObjWriter()
    {
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
};

