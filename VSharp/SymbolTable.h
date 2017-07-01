#pragma once

#include <map>
#include <memory>
#include <vector>
#include "SymbolInfo.h"

class PSLCompilerContext;
class VariableInfo;
class FunctionInfo;
class TypeInfo;
class GenericTypeInfo;
class FunctionDeclaratorNode;

class SymbolTable
{
  public:
    SymbolTable(PSLCompilerContext *pContext);
    void AddBuiltin();

    VariableInfo *AddVariable(
        int symIndex,
        FunctionDeclaratorNode *pScope,
        TypeInfo *pTypeInfo);

    FunctionInfo *AddFunction(
        int symIndex,
        GenericTypeInfo *pGenType,
        TypeInfo *pReturnTypeInfo);

    SymbolInfo *GetInfo(
        int symIndex,
        FunctionDeclaratorNode *pScope);

    void GetFunctionVariables(
        FunctionDeclaratorNode *pScope, 
        std::vector<VariableInfo*> &varList
        );

  private:
    PSLCompilerContext *_pContext;
    std::multimap<int, std::unique_ptr<SymbolInfo>> _symbols;
};
