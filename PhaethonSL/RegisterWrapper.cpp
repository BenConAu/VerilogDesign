#include "RegisterWrapper.h"
#include "PSLCompilerContext.h"

RegisterWrapper::RegisterWrapper(
    RegisterCollection* pCollection, 
    Operand result
    )
{
    _pCollection = pCollection;

    switch (result.GetType())
    {
        case OperandType::Register:
            _converted = result;
            _fAllocated = false;
            break;

        case OperandType::Constant:
        case OperandType::DerefConstant:
        case OperandType::DerefRegisterOffset:
            _converted = Operand(_pCollection->AllocateRegister());
            _fAllocated = true;

            Operand::PrintInstruction("mov", _converted, result);
            break;

        case OperandType::DerefRegister:
            throw "RegisterMemory";

        case OperandType::None:
            throw "Cannot wrap none";
    }
}

const Operand& RegisterWrapper::GetWrapped()
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
