#include "RegisterWrapper.h"
#include "PSLCompilerContext.h"

RegisterWrapper::RegisterWrapper(PSLCompilerContext* pContext, ExpressionResult result)
{
    _pContext = pContext;

    switch (result._type)
    {
        case ResultType::Register:
            _converted = result;
            _fAllocated = false;
            break;

        case ResultType::Constant:
            _converted = ExpressionResult(pContext->_regCollection.AllocateRegister());
            _fAllocated = true;

            printf("mov r%d, %d\n", _converted._regIndex, result._constant);
            break;

        case ResultType::Memory:
            _converted = ExpressionResult(pContext->_regCollection.AllocateRegister());
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
        _pContext->_regCollection.DeallocateRegister(_converted._regIndex);
    }
}
