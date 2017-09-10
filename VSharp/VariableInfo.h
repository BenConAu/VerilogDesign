#pragma once

#include <map>
#include "VariableLocationType.h"
#include "SymbolInfo.h"

class ASTNode;
class TypeInfo;
class ExpressionResult;
enum class VariableLocationType;

class VariableInfo : public SymbolInfo
{
  public:
    VariableInfo(
        PSLCompilerContext *pContext,   // The context that this variable lives in
        ModuleDefinitionNode *pScope,   // The scope that the variable is declared in
        int symIndex,                   // The symbol index for the identifier for the variable
        VariableLocationType location,  // The location of the variable
        TypeInfo *pInfo                 // The type of the variable
        );

    VariableLocationType GetLocationType() const { return _locationType; }
    ExpressionResult *CalculateResult(ModuleDefinitionNode *pScope);

    TypeInfo *GetTypeInfo() { return _pType; }

  private:
    // Type of location (globals are stored in data segment, local backed by register)
    VariableLocationType _locationType;

    // C++ type of variable
    TypeInfo *_pType;
};
