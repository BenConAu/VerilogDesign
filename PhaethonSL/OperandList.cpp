#include "OperandList.h"

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

OperandList::OperandList(const Operand &o)
{
    _operandList.push_back(o);
    _type = ConvertType(o.GetType());
}

OperandList::OperandList()
{
    _type = ExpressionResultType::None;
}

void OperandList::push_back(const Operand &op)
{
    _operandList.push_back(op);
}

size_t OperandList::size() const
{
    return _operandList.size();
}

ExpressionResultType OperandList::GetResultType() const
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

RegIndex OperandList::GetRegIndex()
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

Operand &OperandList::GetOperand(size_t index)
{
    return _operandList[index];
}
