#include "VariableInfo.h"
#include "ParserContext.h"
#include "ModuleDefinitionNode.h"
#include "ExpressionResult.h"

VariableInfo::VariableInfo(
    VSharpCompiler *pCompiler,      // The context that this variable lives in
    ASTNode *pScope,                // The scope that the variable is declared in
    int symIndex,                   // The symbol index for the identifier for the variable
    VariableLocationType location,  // The location of the variable
    TypeModifier modifier,          // The type modifier
    TypeInfo *pInfo                 // The type of the variable
    ) : SymbolInfo(pCompiler, pScope, symIndex)
{
    if (pInfo == nullptr)
    {
        throw "Variables must have types";
    }

    _pType = pInfo;
    _locationType = location;
    _modifier = modifier;
    _pScope = pScope;
}

ExpressionResult *VariableInfo::CalculateResult()
{
    if (_nameOverride.length() == 0)
    {
        return new ExpressionResult(GetSymbol());
    }
    else
    {
        return new ExpressionResult(_nameOverride);
    }
}
