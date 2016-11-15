#include "ExpressionResult.h"

ExpressionResult::ExpressionResult(Operand operand, RegisterCollection* pCollection) : 
    _tempRegister(operand._regIndex, pCollection)
{
    if (operand._type != OperandType::Register)
    {
        throw "Dude you can't go making a temporary register object without a register";
    }

    _operand = operand;
}

ExpressionResult::ExpressionResult(Operand operand)
{
    _operand = operand;
}