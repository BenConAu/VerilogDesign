#pragma once

#include <string>
#include "VariableLocation.h"

class PSLCompilerContext;
class VariableInfo;
class StructMember;

enum class ResultType
{
    None,
    Constant,
    Register,
    Memory,
    MemoryOffset,
};

// If you want an offset you need to make a register for it
struct OffsetInfo
{
    RegIndex _regIndex;
    VariableInfo* _pVarInfo;
    StructMember* _pTypeMember;
};

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
