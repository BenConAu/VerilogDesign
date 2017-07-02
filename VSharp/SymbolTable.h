#pragma once

#include <map>
#include <memory>
#include <vector>
#include "SymbolInfo.h"

class PSLCompilerContext;
class VariableInfo;
class ModuleInfo;
class TypeInfo;
class StateInfo;
class GenericTypeInfo;
class ModuleDeclaratorNode;

class SymbolTable
{
  public:
    SymbolTable(PSLCompilerContext *pContext);
    void AddBuiltin();

    VariableInfo *AddVariable(
        int symIndex,
        ModuleDeclaratorNode *pScope,
        TypeInfo *pTypeInfo);

    ModuleInfo *AddModule(
        int symIndex,
        GenericTypeInfo *pGenType);

    StateInfo *AddState(
        int symIndex,
        ModuleDeclaratorNode *pScope);

    SymbolInfo *GetInfo(
        int symIndex,
        ModuleDeclaratorNode *pScope);

    void GetFunctionVariables(
        ModuleDeclaratorNode *pScope, 
        std::vector<VariableInfo*> &varList
        );

  private:
    PSLCompilerContext *_pContext;
    std::multimap<int, std::unique_ptr<SymbolInfo>> _symbols;
};
