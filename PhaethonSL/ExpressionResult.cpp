#include "ExpressionResult.h"
#include "VariableInfo.h"

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

ExpressionResult::ExpressionResult(TypeInfo* pTypeInfo, Operand operand)
{
    if (operand.GetType() == OperandType::None)
    {
        throw "Cannot give none operands to ExpressionResult";
    }

    _pTypeInfo = pTypeInfo;
    _operand = operand;
}

ExpressionResult::ExpressionResult(VariableInfo* pVarInfo, Operand operand)
{
    if (operand.GetType() == OperandType::None)
    {
        throw "Cannot give none operands to ExpressionResult";
    }

    _pTypeInfo = pVarInfo->GetTypeInfo();
    _pVarInfo = pVarInfo;
    _operand = operand;
}