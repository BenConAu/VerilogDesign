#include "ExpressionResult.h"
#include "VariableInfo.h"
#include "TypeInfo.h"

// ExpressionResult to represent something that needs a temporary register and has no type
ExpressionResult::ExpressionResult(TypeInfo *pTypeInfo, Operand operand, RegisterCollection *pCollection)
{
    switch (operand.GetType())
    {
    case OperandType::None:
        throw "Cannot give none operands to ExpressionResult";

    case OperandType::Register:
    case OperandType::DerefRegisterOffset:
        _pTypeInfo = pTypeInfo;
        _operandList.push_back(operand);
        _tempRegisters.emplace_back(new SmartRegister(operand.GetRegIndex(), pCollection));
        break;

    default:
        printf("Attempting temporary register with operand type %d\n", operand.GetObjArgument()._argType);
        throw "Dude you can't go making a temporary register object without a register";
    }
}

// ExpressionResult to represent something that needs a temporary register and has no type
ExpressionResult::ExpressionResult(TypeInfo *pTypeInfo, RegisterCollection *pCollection)
{
    _pTypeInfo = pTypeInfo;
    _pCollection = pCollection;
}

// ExpressionResult to represent a constant
ExpressionResult::ExpressionResult(TypeInfo *pTypeInfo, Operand operand)
{
    if (operand.GetType() == OperandType::None)
    {
        throw "Cannot give none operands to ExpressionResult";
    }

    _pTypeInfo = pTypeInfo;
    _operandList.push_back(operand);
}

void ExpressionResult::DebugPrint()
{
    printf(
        "ExpressionResult _pTypeInfo = %s, _operand = %s\n",
        _pTypeInfo->DebugPrint().c_str(),
        _operandList.GetOperand(0).DebugPrint());
}

void ExpressionResult::AddOperand(const Operand &op, bool temp)
{
    _operandList.push_back(op);
    _tempRegisters.emplace_back(new SmartRegister(op.GetRegIndex(), _pCollection));
}
