#pragma once

#include "../PhaethonISA/OperandType.h"
#include "VariableLocation.h"
#include <string>

class PSLCompilerContext;
class VariableInfo;
class StructMember;

// If you want an offset you need to make a register for it
struct OffsetInfo
{
    RegIndex _regIndex;
    std::string _typeName;
    std::string _memberName;
};

// An Operand is a representation of an operand in PASM. This is part of what an
// expression will output. Many leaf nodes of expression trees are very simple (such 
// as a constant). 
struct Operand
{
    explicit Operand();
    explicit Operand(RegIndex index);
    explicit Operand(int constant);
    
    explicit Operand(
        VariableInfo* pVarInfo, 
        PSLCompilerContext* pContext
        );

    explicit Operand(
        RegIndex regIndex, 
        VariableInfo* pVarInfo, 
        StructMember* pTypeMember, 
        PSLCompilerContext* pContext
        );

    bool IsNone() const;
    std::string GetOpString() const;

    static void PrintInstruction(
        const std::string& instr,
        const Operand& op1,
        const Operand& op2
        )
    {
        printf(
            "%s %s, %s\n", 
            instr.c_str(), 
            op1.GetOpString().c_str(), 
            op2.GetOpString().c_str()
            );
    }

    OperandType _type;
    union
    {
        int _constant;
        RegIndex _regIndex;
    };

    // Cannot go into the union
    OffsetInfo  _offsetInfo;
};

