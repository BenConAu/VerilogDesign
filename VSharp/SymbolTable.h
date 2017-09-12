#pragma once

#include <map>
#include <memory>
#include <vector>
#include "SymbolInfo.h"
#include "TypeModifier.h"

class VSharpCompiler;
class VariableInfo;
class FunctionInfo;
class TypeInfo;
class StateInfo;
class GenericTypeInfo;
class ModuleDefinitionNode;
class FunctionDeclaratorNode;
enum class VariableLocationType;

class SymbolTable
{
  public:
    SymbolTable(VSharpCompiler *pCompiler);
    void AddBuiltin();

    VariableInfo *AddVariable(
        ModuleDefinitionNode *pScope,
        int symIndex,
        VariableLocationType location,
        TypeModifier modifier,
        TypeInfo *pTypeInfo);

    FunctionInfo *AddFunction(
        FunctionDeclaratorNode *pFuncDecl,
        int symIndex,
        GenericTypeInfo *pGenType);

    StateInfo *AddState(
        int symIndex,
        ModuleDefinitionNode *pScope);

    SymbolInfo *GetInfo(
        int symIndex,
        ModuleDefinitionNode *pScope);

    void GetFunctionVariables(
        ModuleDefinitionNode *pScope, 
        std::vector<VariableInfo*> &varList
        );

  private:
    VSharpCompiler *_pCompiler;
    std::multimap<int, std::unique_ptr<SymbolInfo>> _symbols;
};
