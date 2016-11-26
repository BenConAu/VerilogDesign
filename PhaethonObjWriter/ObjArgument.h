#pragma once

#include "../PhaethonISA/OperandType.h"

// An instruction argument could potentially have a value and an offset,
// as well as the type of the argument.
struct ObjArgument
{
    // Type information
   	OperandType _argType;

    // Binary information
    unsigned int _value;    // The constant value or the register index
    unsigned int _offset;   // The offset (if any)

    // Symbolic information (optional)
    std::string _typeName;
    std::string _memberName;    
};
