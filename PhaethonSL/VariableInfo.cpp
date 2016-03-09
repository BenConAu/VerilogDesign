#include "VariableInfo.h"
#include "PSLCompilerContext.h"

unsigned int VariableInfo::_dataSegEnd = 0;

VariableInfo::VariableInfo(
    PSLCompilerContext* pContext,
    int symIndex,
    FunctionDeclaratorNode* pScope,
    TypeInfo* pInfo
    )
{
    _pContext = pContext;
    _pType = pInfo;
    _symIndex = symIndex;
    _pScope = pScope;

    if (_pScope == nullptr)
    {
        _locationType = LocationType::Memory;
        _memLocation = _dataSegEnd;

        _dataSegEnd += 4;
    }
    else
    {
        _locationType = LocationType::Register;
        _memLocation = 0xFFFFFFFF;
    }
}

RegIndex VariableInfo::GetRegIndex(FunctionDeclaratorNode* pScope)
{
    if (_regIndexMap.find(pScope) == _regIndexMap.end())
    {
        _regIndexMap[pScope] = _pContext->_regCollection.AllocateRegister();
    }

    return _regIndexMap[pScope];
}
