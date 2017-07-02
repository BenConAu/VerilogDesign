#include "VariableInfo.h"
#include "PSLCompilerContext.h"
#include "ModuleDeclaratorNode.h"
#include "ExpressionResult.h"

VariableInfo::VariableInfo(
    PSLCompilerContext *pContext,   // The context that this variable lives in
    int symIndex,                   // The symbol index for the identifier for the variable
    ModuleDeclaratorNode *pScope,   // The scope that the variable is declared in
    TypeInfo *pInfo                 // The type of the variable
    ) : SymbolInfo(pContext, pScope, symIndex)
{
    if (pInfo == nullptr)
    {
        throw "Variables must have types";
    }

    _pType = pInfo;

    if (GetScope() == nullptr)
    {
        //printf("New memory location for %s at %x\n", GetSymbol(), _dataSegEnd);

        // Globals are always backed with memory storage
        _locationType = LocationType::Memory;
    }
    else
    {
        _locationType = LocationType::Register;
    }
}

ExpressionResult *VariableInfo::CalculateResult(ModuleDeclaratorNode *pScope)
{
    return new ExpressionResult(GetSymbol());
}

void VariableInfo::ReferenceFrom(ModuleDeclaratorNode *pScope)
{
    // This should create things if not already created and no-op otherwise
    _regIndexMap[pScope]._referenced = true;
}

const PerFunctionInfo &VariableInfo::GetFunctionInfo(ModuleDeclaratorNode *pScope)
{
    return _regIndexMap[pScope];
}
