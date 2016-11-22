#include "RegisterWrapper.h"
#include "PSLCompilerContext.h"

RegisterWrapper::RegisterWrapper(
    RegisterCollection* pCollection, 
    Operand result
    )
{
    _pCollection = pCollection;

    switch (result._type)
    {
        case OperandType::Register:
            _converted = result;
            _fAllocated = false;
            break;

        case OperandType::Constant:
        case OperandType::ConstantMemory:
        case OperandType::MemoryOffset:
            _converted = Operand(_pCollection->AllocateRegister());
            _fAllocated = true;

            Operand::PrintInstruction("mov", _converted, result);
            break;

        case OperandType::RegisterMemory:
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
        _pCollection->DeallocateRegister(_converted._regIndex);
    }
}
