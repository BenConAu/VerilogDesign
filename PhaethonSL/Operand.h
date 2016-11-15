#pragma once

#include "VariableLocation.h"
#include <string>

class PSLCompilerContext;
class VariableInfo;
class StructMember;

// This enumeration represents the different types of operand arguments that
// the assembly can represent. In practice most of them will need to be
// converted to a register.
enum class OperandType
{
    None,           // Used for error conditions and the such
    Constant,       // The result is a constant
    Register,       // The result is stored in a register
    Memory,         // The result is a memory location (also a constant, technically)
    MemoryOffset,   // The result is a memory location plus an offset
};

// If you want an offset you need to make a register for it
struct OffsetInfo
{
    RegIndex _regIndex;
    VariableInfo* _pVarInfo;
    StructMember* _pTypeMember;
};

// An Operand is a representation of an operand in PASM. This is part of what an
// expression will output. Many leaf nodes of expression trees are very simple (such 
// as a constant). 
struct Operand
{
    explicit Operand();
    explicit Operand(RegIndex index);
    explicit Operand(int constant);
    explicit Operand(VariableInfo* pInfo);
    explicit Operand(RegIndex regIndex, VariableInfo* pVarInfo, StructMember* pTypeMember);

    bool IsNone() const;
    std::string GetOperand(PSLCompilerContext*) const;

    OperandType _type;
    union
    {
        int _constant;
        RegIndex _regIndex;
        VariableInfo* _pVarInfo;
        OffsetInfo  _offsetInfo;
    };
};

