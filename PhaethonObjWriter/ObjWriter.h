#pragma once

#include "../PhaethonISA/Generated/PhaethonOpCode.h"
#include <string>

struct ObjArgument;

class ObjWriter
{
  public:
    virtual void OutputInstruction(
        OpCodes::Enum opCode,
        ObjArgument *args
        ) = 0;
};

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
};

class AsmObjWriter : public ObjWriter
{
  public:
    AsmObjWriter()
    {
    }

    std::string GetOpString(const ObjArgument &obj) const;

    void OutputInstruction(
        OpCodes::Enum opCode,
        ObjArgument *args
        ) override;
};
