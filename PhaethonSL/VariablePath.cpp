#include "VariablePath.h"
#include "FunctionDeclaratorNode.h"

RegIndex VariablePath::EnsurePathRegister(FunctionDeclaratorNode* pScope)
{
    if (_regIndexMap.find(pScope) == _regIndexMap.end())
    {
        // Upon the first request for a register at a particular scope,
        // allocate the register.
        _regIndexMap[pScope] = pScope->GetRegCollection()->AllocateRegister();
    }

    return _regIndexMap[pScope];
}

bool VariablePath::HasRegister(FunctionDeclaratorNode* pScope)
{
    if (_regIndexMap.find(pScope) == _regIndexMap.end())
    {
        return false;
    }

    return true;
}

void VariablePath::ReserveRegister(FunctionDeclaratorNode* pScope, RegIndex index)
{
    // We are being told which register to use
    pScope->GetRegCollection()->ReserveRegister(index);
    _regIndexMap[pScope] = index;    
}