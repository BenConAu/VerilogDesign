#pragma once

#include "../PhaethonISA/Generated/PhaethonOpCode.h"
#include <string>

struct ObjArgument;

class ObjWriter
{
  public:
    virtual ~ObjWriter()
    {
    }

    virtual void OutputInstruction(
        OpCode opCode,
        ObjArgument *args) = 0;

    virtual void OutputLabel(
        const char* pszLabel
        ) = 0;

    virtual void FinishCode() = 0;
};
