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
ExpressionResult::ExpressionResult(const Operand &operand, RegisterCollection *pCollection)
{
    _pCollection = pCollection;    
    _type = ExpressionResultType::None;

    switch (operand.GetType())
    {
    case OperandType::None:
        throw "Cannot give none operands to ExpressionResult";

    case OperandType::Register:
    case OperandType::DerefRegisterOffset:
        AddOperand(operand, true);
        break;

    default:
        printf("Attempting temporary register with operand type %d\n", operand.GetObjArgument()._argType);
        throw "Dude you can't go making a temporary register object without a register";
    }
}

// ExpressionResult to represent something that needs a temporary register and has no type
ExpressionResult::ExpressionResult(RegisterCollection *pCollection)
{
    _pCollection = pCollection;
    _type = ExpressionResultType::None;
}

// ExpressionResult to represent a constant
ExpressionResult::ExpressionResult(const Operand &operand)
{
    _pCollection = nullptr;
    _type = ExpressionResultType::None;

    if (operand.GetType() == OperandType::None)
    {
        throw "Cannot give none operands to ExpressionResult";
    }

    AddOperand(operand, false);
}

void ExpressionResult::DebugPrint()
{
    printf(
        "ExpressionResult _operand[0] = %s\n",
        _operandList[0].DebugPrint());
}

void ExpressionResult::AddOperand(const Operand &op, bool temp)
{
    _operandList.push_back(op);

    if (temp)
    {
        _tempRegisters.emplace_back(new SmartRegister(op.GetRegIndex(), _pCollection));
    }
}

size_t ExpressionResult::size() const
{
    return _operandList.size();
}

RegIndex ExpressionResult::GetRegIndex()
{
    if (_type != ExpressionResultType::Register)
    {
        throw "Should not get register index unless it is a register operand list";
    }
    else
    {
        return _operandList[0].GetRegIndex();
    }
}

ExpressionResultType ExpressionResult::GetResultType() const
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
            if (_operandList[0].GetType() == OperandType::DerefRegisterOffset &&
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
