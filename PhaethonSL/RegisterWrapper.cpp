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

        pContext->OutputMovInstruction(_converted, result);
    }
    else
    {
        _converted = result;
        _fAllocated = false;
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
