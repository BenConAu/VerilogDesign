#pragma once

#include "../PhaethonISA/Generated/PhaethonOpCode.h"

struct ObjArgument;

class ObjWriter
{
    virtual void OutputInstruction(
    OpCodes::Enum opCode,
    ObjArgument* args,
    int wordArg
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
        ObjArgument* args,
        int wordArg
    ) override;
};

class AsmObjWriter : public ObjWriter
{
    AsmObjWriter()
    {
    }

    void OutputInstruction(
        OpCodes::Enum opCode,
        ObjArgument* args,
        int wordArg
    ) override;
};
