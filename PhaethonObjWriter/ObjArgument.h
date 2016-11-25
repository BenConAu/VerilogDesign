#pragma once

#include "../PhaethonISA/OperandType.h"

// An instruction argument could potentially have a value and an offset,
// as well as the type of the argument.
struct ObjArgument
{
   	OperandType _argType;
    unsigned int _value;    // The constant value or the register index
    unsigned int _offset;   // The offset (if any)
};
