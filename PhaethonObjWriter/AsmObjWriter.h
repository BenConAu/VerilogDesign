#pragma once

#include "ObjWriter.h"

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
