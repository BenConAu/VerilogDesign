#include "ExpressionResult.h"
#include "VariableInfo.h"
#include "TypeInfo.h"

// ExpressionResult to represent something that needs a temporary register and has no type
ExpressionResult::ExpressionResult(TypeInfo* pTypeInfo, Operand operand, RegisterCollection* pCollection) : 
    _tempRegister(operand.GetRegIndex(), pCollection)
{
    if (operand.GetType() == OperandType::None)
    {
        throw "Cannot give none operands to ExpressionResult";
    }

    if (operand.GetType() != OperandType::Register)
    {
        throw "Dude you can't go making a temporary register object without a register";
    }

    _pTypeInfo = pTypeInfo;
    _operand = operand;
}

// ExpressionResult to represent a constant
ExpressionResult::ExpressionResult(TypeInfo* pTypeInfo, Operand operand)
{
    if (operand.GetType() == OperandType::None)
    {
        throw "Cannot give none operands to ExpressionResult";
    }

    _pTypeInfo = pTypeInfo;
    _operand = operand;
}

// ExpressionResult to represent a variable path
ExpressionResult::ExpressionResult(TypeInfo* pTypeInfo, VariablePath* pPathInfo, Operand operand)
{
    if (operand.GetType() == OperandType::None)
    {
        throw "Cannot give none operands to ExpressionResult";
    }

    _pTypeInfo = pTypeInfo;
    _pExprPath = pPathInfo;
    _operand = operand;
}

void ExpressionResult::DebugPrint()
{
    printf("ExpressionResult _pTypeInfo = %s, _operand = %s\n", _pTypeInfo->DebugPrint(), _operand.DebugPrint());
}