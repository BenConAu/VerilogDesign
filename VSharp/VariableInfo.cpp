#include "VariableInfo.h"
#include "VSharpCompilerContext.h"
#include "ModuleDefinitionNode.h"
#include "ExpressionResult.h"

VariableInfo::VariableInfo(
    PSLCompilerContext *pContext,   // The context that this variable lives in
    ModuleDefinitionNode *pScope,   // The scope that the variable is declared in
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

ExpressionResult *VariableInfo::CalculateResult(ModuleDefinitionNode *pScope)
{
    return new ExpressionResult(GetSymbol());
}
