#include "RegisterWrapper.h"
#include "PSLCompilerContext.h"

RegisterWrapper::RegisterWrapper(
    PSLCompilerContext* pContext,
    RegisterCollection* pCollection, 
    ExpressionResult result
    )
{
    _pCollection = pCollection;

    switch (result._type)
    {
        case ResultType::Register:
            _converted = result;
            _fAllocated = false;
            break;

        case ResultType::Constant:
            _converted = ExpressionResult(_pCollection->AllocateRegister());
            _fAllocated = true;

            printf("mov r%d, %d\n", _converted._regIndex, result._constant);
            break;

        case ResultType::Memory:
            _converted = ExpressionResult(_pCollection->AllocateRegister());
            _fAllocated = true;

            printf("mov r%d, %s\n", _converted._regIndex, result.GetOperand(pContext).c_str());
            break;

        case ResultType::None:
        case ResultType::MemoryOffset:
            throw "Cannot wrap none";
    }
}

const ExpressionResult& RegisterWrapper::GetWrapped()
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
