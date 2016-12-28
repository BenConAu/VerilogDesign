#include "ExpressionResult.h"
#include "VariableInfo.h"
#include "TypeInfo.h"

ExpressionResultType ConvertType(OperandType type)
{
    switch (type)
    {
    case OperandType::Constant:
        return ExpressionResultType::Constant;

    case OperandType::Register:
        return ExpressionResultType::Register;

    case OperandType::DerefRegisterOffset:
        return ExpressionResultType::DerefRegisterOffset;

    default:
        throw "Unexpected operand type";
    }
}

// ExpressionResult to represent something that needs a temporary register and has no type
ExpressionResult::ExpressionResult(TypeInfo *pTypeInfo, Operand operand, RegisterCollection *pCollection)
{
    switch (operand.GetType())
    {
    case OperandType::None:
        throw "Cannot give none operands to ExpressionResult";

    case OperandType::Register:
    case OperandType::DerefRegisterOffset:
        _type = ConvertType(operand.GetType());
        _pTypeInfo = pTypeInfo;
        _pVarInfo = nullptr;
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
    _type = ExpressionResultType::None;
    _pTypeInfo = pTypeInfo;
    _pVarInfo = nullptr;
    _pCollection = pCollection;
}

// ExpressionResult to represent a constant
ExpressionResult::ExpressionResult(TypeInfo *pTypeInfo, Operand operand)
{
    if (operand.GetType() == OperandType::None)
    {
        throw "Cannot give none operands to ExpressionResult";
    }

    _type = ConvertType(operand.GetType());
    _pTypeInfo = pTypeInfo;
    _pVarInfo = nullptr;
    _operandList.push_back(operand);
}

// ExpressionResult to represent a variable
ExpressionResult::ExpressionResult(VariableInfo *pVarInfo, Operand operand)
{
    if (operand.GetType() == OperandType::None)
    {
        throw "Cannot give none operands to ExpressionResult";
    }

    _type = ConvertType(operand.GetType());
    _pTypeInfo = pVarInfo->GetTypeInfo();
    _pVarInfo = pVarInfo;
    _operandList.push_back(operand);
}

void ExpressionResult::DebugPrint()
{
    printf("ExpressionResult _pTypeInfo = %s, _operand = %s\n", _pTypeInfo->DebugPrint().c_str(), _operandList[0].DebugPrint());
}

void ExpressionResult::AddOperand(const Operand &op, bool temp)
{
    _operandList.push_back(op);
    _tempRegisters.emplace_back(new SmartRegister(op.GetRegIndex(), _pCollection));
}

ExpressionResultType ExpressionResult::GetResultType()
{
    if (_type == ExpressionResultType::None)
    {
        // Try to calculate it now that somebody wants it
        if (_operandList.size() == 1)
        {
            _type = ConvertType(_operandList[0].GetType());
        }
        else if (_operandList.size() == 2)
        {
            if (_operandList[0].GetType() == OperandType::DerefRegisterIndex &&
                _operandList[1].GetType() == OperandType::Register)
            {
                _type = ExpressionResultType::DerefRegisterIndex;
            }
            else
            {
                throw "Unexpected double operand result";
            }
        }
        else
        {
            throw "Unexpected multiple operand result";
        }
    }

    return _type;
}
