#include "VariableInfo.h"
#include "PSLCompilerContext.h"
#include "FunctionDeclaratorNode.h"

unsigned int VariableInfo::_dataSegEnd = 0;

VariableInfo::VariableInfo(
    PSLCompilerContext* pContext,   // The context that this variable lives in
    int symIndex,                   // The symbol index for the identifier for the variable
    FunctionDeclaratorNode* pScope, // The scope that the variable is declared in
    TypeInfo* pInfo,                // The type of the variable
    RegIndex* pRegIndex             // The register to use, if known
    )
{
    _pContext = pContext;
    _pType = pInfo;
    _symIndex = symIndex;
    _pScope = pScope;

    if (_pScope == nullptr)
    {
        // Globals are always backed with memory storage
        _locationType = LocationType::Memory;

        // Decide on the location
        _memLocation = _dataSegEnd;

        // And adjust for the new location
        _dataSegEnd += 4;
    }
    else
    {
        _locationType = LocationType::Register;
        _memLocation = 0xFFFFFFFF;

        if (pRegIndex != nullptr)
        {
            // We are being told which register to use
            pScope->GetRegCollection()->ReserveRegister(*pRegIndex);
            _regIndexMap[pScope] = (*pRegIndex);
        }
    }
}

RegIndex VariableInfo::GetRegIndex(FunctionDeclaratorNode* pScope)
{
    if (_regIndexMap.find(pScope) == _regIndexMap.end())
    {
        // Upon the first request for a register at a particular scope,
        // allocate the register.
        _regIndexMap[pScope] = pScope->GetRegCollection()->AllocateRegister();
    }

    return _regIndexMap[pScope];
}
