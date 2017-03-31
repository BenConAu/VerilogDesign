#include "RegisterWrapper.h"
#include "PSLCompilerContext.h"

RegisterWrapper::RegisterWrapper(
    PSLCompilerContext* pContext,
    RegisterCollection* pCollection,
    ExpressionResult* pResult
    )
{
    _pCollection = pCollection;

    if (pResult->GetResultType() != ExpressionResultType::Register)
    {
        //printf("Allocating a register in a wrapper\n");

        _converted = Operand(_pCollection->AllocateRegister());
        _fAllocated = true;

        pContext->OutputMovInstruction(_converted, *pResult);
    }
    else
    {
        _converted = pResult->GetOperand(0);
        _fAllocated = false;
    }
}

RegisterWrapper::~RegisterWrapper()
{
    if (_fAllocated)
    {
        _pCollection->DeallocateRegister(_converted.GetRegIndex());
    }
}
