#include "ExpressionResult.h"
#include "VariableInfo.h"

ExpressionResult::ExpressionResult(TypeInfo* pTypeInfo, Operand operand, RegisterCollection* pCollection) : 
    _tempRegister(operand._regIndex, pCollection)
{
    if (operand._type != OperandType::Register)
    {
        throw "Dude you can't go making a temporary register object without a register";
    }

    _pTypeInfo = pTypeInfo;
    _operand = operand;
}

ExpressionResult::ExpressionResult(TypeInfo* pTypeInfo, Operand operand)
{
    _pTypeInfo = pTypeInfo;
    _operand = operand;
}

ExpressionResult::ExpressionResult(VariableInfo* pVarInfo, Operand operand)
{
    _pTypeInfo = pVarInfo->GetTypeInfo();
    _pVarInfo = pVarInfo;
    _operand = operand;
}