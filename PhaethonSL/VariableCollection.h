#pragma once

#include <map>
#include "VariableInfo.h"

class VariableDeclarationNode;
class ASTNode;
class PSLCompilerContext;

class VariableCollection
{
  public:
    VariableCollection(PSLCompilerContext *pContext);
    void AddBuiltin();

    VariableInfo *AddVariable(
        int symIndex,
        FunctionDeclaratorNode *pScope,
        TypeInfo *pTypeInfo);

    FunctionInfo *AddFunction(
        int symIndex,
        TypeInfo *pReturnTypeInfo);

    SymbolInfo *GetInfo(int symIndex);

  private:
    PSLCompilerContext *_pContext;
    std::map<int, std::unique_ptr<SymbolInfo>> _variables;
};
