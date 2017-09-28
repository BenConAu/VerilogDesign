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
struct UIntConstant;

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
        UIntConstant* pConstant);

    StateInfo *AddState(
        int symIndex,
        ASTNode *pScope);

    template<typename T>
    void GetSymbols(
        int symIndex,
        ASTNode *pScope,
        std::vector<T*> &SymbolList)
    {
        //printf("Attempting GetInfo of symbol %s\n", _pCompiler->GetSymbolString(symIndex].c_str());

        for (auto iter = _symbols.lower_bound(symIndex); iter != _symbols.upper_bound(symIndex); iter++)
        {
            T* pInfo = dynamic_cast<T*>(iter->second.get());
            if (pInfo != nullptr && (pInfo->GetScope() == pScope || pInfo->GetScope() == nullptr))
            {
                SymbolList.push_back(pInfo);
            }
        }
    }

    void GetFunctionVariables(
        ASTNode *pScope, 
        std::vector<VariableInfo*> &varList
        );

  private:
    VSharpCompiler *_pCompiler;
    std::multimap<int, std::unique_ptr<SymbolInfo>> _symbols;
};
