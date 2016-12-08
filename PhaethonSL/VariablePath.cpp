#include "VariablePath.h"
#include "FunctionDeclaratorNode.h"
#include <sstream>

RegIndex VariablePath::EnsurePathRegister(FunctionDeclaratorNode* pScope)
{
    printf("Ensuring register for path %s\n", DebugPrint());

    if (_regIndexMap.find(pScope) == _regIndexMap.end())
    {
        printf("Allocating register for path %s\n", DebugPrint());

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

const char* VariablePath::DebugPrint()
{
    std::stringstream sstream;

    sstream << _pVarInfo->GetSymbol();
    
    for (size_t i = 0; i < _memberPath.size(); i++)
    {
        sstream << " " << _memberPath[i]->GetSymbolIndex();
    }

    static std::string str = sstream.str();
    return str.c_str();
}