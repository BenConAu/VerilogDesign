#include "RegisterWrapper.h"
#include "PSLCompilerContext.h"

RegisterWrapper::RegisterWrapper(
    PSLCompilerContext* pContext,
    RegisterCollection* pCollection,
    Operand result
    )
{
    _pCollection = pCollection;

    if (result.GetType() != OperandType::Register)
    {
        _converted = Operand(_pCollection->AllocateRegister());
        _fAllocated = true;
    }
    else
    {
        _converted = result;
        _fAllocated = false;
    }

    OpCodes::Enum opCode = OpCodes::Unknown;

    switch (result.GetType())
    {
    case OperandType::Register:
        // Do nothing
        break;

    case OperandType::Constant:
        opCode = OpCodes::MovRC;
        break;

    case OperandType::DerefConstant:
        opCode = OpCodes::MovRdC;
        break;

    case OperandType::DerefRegisterOffset:
        opCode = OpCodes::MovRdRo;
        break;

    default:
        throw "Unexpected operand type";
    }

    if (opCode != OpCodes::Unknown)
    {
        pContext->OutputInstruction(
            opCode,
            _converted,
            result
            );
    }
}

const Operand &RegisterWrapper::GetWrapped()
{
    return _converted;
}

RegisterWrapper::~RegisterWrapper()
{
    if (_fAllocated)
    {
        _pCollection->DeallocateRegister(_converted.GetRegIndex());
    }
}
