#pragma once

#include <map>
#include "SymbolInfo.h"

class PSLCompilerContext;
class VariableInfo;
class FunctionInfo;
class TypeInfo;
class FunctionDeclaratorNode;

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
