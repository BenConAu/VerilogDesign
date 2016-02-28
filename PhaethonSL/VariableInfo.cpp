#include "VariableInfo.h"
#include "PSLCompilerContext.h"

VariableInfo::VariableInfo(PSLCompilerContext* pContext, int symIndex, bool fGlobal, TypeInfo* pInfo)
{
    _pContext = pContext;
    _pType = pInfo;
    _symIndex = symIndex;
    _fGlobal = fGlobal;
    _regIndex = 0xFF;
}

RegIndex VariableInfo::GetRegIndex()
{
    if (_regIndex == 0xFF)
    {
        _regIndex = _pContext->_regCollection.AllocateRegister();
    }

    return _regIndex;
}
