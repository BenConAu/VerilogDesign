#pragma once

#include "../PhaethonISA/OperandType.h"

// An instruction argument could potentially have a value and an offset,
// as well as the type of the argument.
struct ObjArgument
{
    ObjArgument()
    {
        _argType = OperandType::None;
        _fMemoryLocation = false;
        _value = 0xef;
        _offset = -1;
    }

    std::string DebugPrint()
    {
        char debug[200];

        switch (_argType)
        {
            case OperandType::Register:
                ::sprintf(debug, "r:%d", _value);
                break;

            case OperandType::DerefRegisterOffset:
                ::sprintf(debug, "dro:%d|%d", _value, _offset);
                break;

            default:
                ::sprintf(debug, "OpType:%d", _argType);
                break;
        }
        
        return debug;
    }

    // Type information
    OperandType _argType;

    // Binary information
    unsigned int _value;  // The constant value or the register index
    unsigned int _offset; // The offset (if any)

    // Whether the argument stores a memory location
    bool _fMemoryLocation;

    // A nonzero length string here for a constant will represent a label
    std::string _label;

    // Symbolic information (optional)
    std::string _typeName;
    std::string _memberName;
};
