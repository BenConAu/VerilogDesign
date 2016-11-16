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
            _converted = Operand(_pCollection->AllocateRegister());
            _fAllocated = true;

            printf("mov r%d, %d\n", _converted._regIndex, result._constant);
            break;

        case OperandType::Memory:
        case OperandType::MemoryOffset:
            _converted = Operand(_pCollection->AllocateRegister());
            _fAllocated = true;

            printf("mov r%d, %s\n", _converted._regIndex, result.GetOperand().c_str());
            break;

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
