#include "VariableInfo.h"
#include "PSLCompilerContext.h"
#include "ModuleDeclaratorNode.h"
#include "ExpressionResult.h"

VariableInfo::VariableInfo(
    PSLCompilerContext *pContext,   // The context that this variable lives in
    ModuleDeclaratorNode *pScope,   // The scope that the variable is declared in
    int symIndex,                   // The symbol index for the identifier for the variable
    VariableLocationType location,  // The location of the variable
    TypeInfo *pInfo                 // The type of the variable
    ) : SymbolInfo(pContext, pScope, symIndex)
{
    if (pInfo == nullptr)
    {
        throw "Variables must have types";
    }

    _pType = pInfo;
    _locationType = location;
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
