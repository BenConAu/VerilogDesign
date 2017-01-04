#pragma once

#include <map>
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

  private:
    PSLCompilerContext *_pContext;
    std::multimap<int, std::unique_ptr<SymbolInfo>> _symbols;
};
