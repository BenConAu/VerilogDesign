#pragma once

#include <string>
#include "VariableLocation.h"

class PSLCompilerContext;
class VariableInfo;
class StructMember;

// This enumeration represents the different types of operand arguments that
// the assembly can represent. In practice most of them will need to be
// converted to a register.
enum class ResultType
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

// An ExpressionResult is a representation of the output of an expression in
// the tree. Many leaf nodes of expression trees are very simple (such as a 
// constant). 
struct ExpressionResult
{
    explicit ExpressionResult();
    explicit ExpressionResult(RegIndex index);
    explicit ExpressionResult(int constant);
    explicit ExpressionResult(VariableInfo* pInfo);
    explicit ExpressionResult(RegIndex regIndex, VariableInfo* pVarInfo, StructMember* pTypeMember);

    bool IsNone() const;
    std::string GetOperand(PSLCompilerContext*) const;

    ResultType _type;
    union
    {
        int _constant;
        RegIndex _regIndex;
        VariableInfo* _pVarInfo;
        OffsetInfo  _offsetInfo;
    };
};
