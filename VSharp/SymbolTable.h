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
class ExpressionNode;
class ASTNode;
class ModuleDefinitionNode;
class FunctionDeclaratorNode;
enum class VariableLocationType;

class SymbolTable
{
  public:
    SymbolTable(VSharpCompiler *pCompiler);
    void AddBuiltin();

    VariableInfo *AddVariable(
        ASTNode *pScope,
        int symIndex,
        VariableLocationType location,
        TypeModifier modifier,
        TypeInfo *pTypeInfo);

    FunctionInfo *AddFunction(
        FunctionDeclaratorNode *pFuncDecl,
        int symIndex,
        ExpressionNode *pGenericExpr);

    StateInfo *AddState(
        int symIndex,
        ASTNode *pScope);

    SymbolInfo *GetInfo(
        int symIndex,
        ASTNode *pScope);

    void GetFunctionVariables(
        ASTNode *pScope, 
        std::vector<VariableInfo*> &varList
        );

  private:
    VSharpCompiler *_pCompiler;
    std::multimap<int, std::unique_ptr<SymbolInfo>> _symbols;
};
