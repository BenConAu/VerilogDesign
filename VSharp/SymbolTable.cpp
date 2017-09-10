#include "SymbolTable.h"
#include "VariableDeclarationNode.h"
#include "VariableInfo.h"
#include "ModuleInfo.h"
#include "FunctionInfo.h"
#include "StateInfo.h"
#include "VSharp.tab.h"
#include <sstream>

SymbolTable::SymbolTable(PSLCompilerContext *pContext)
{
    _pContext = pContext;
}

void SymbolTable::AddBuiltin()
{
    FunctionInfo *pNewInfo = new FunctionInfo(
        _pContext, 
        _pContext->AddSymbol("__monitor"),
        _pContext->_typeCollection.GetVoidType(),
        -1,
        "$monitor");
    _symbols.emplace(std::make_pair(pNewInfo->GetSymbolIndex(), std::unique_ptr<SymbolInfo>(pNewInfo)));
}

VariableInfo *SymbolTable::AddVariable(
    ModuleDefinitionNode *pScope,
    int symIndex,
    VariableLocationType location,
    TypeInfo *pTypeInfo)
{
    for (auto iter = _symbols.lower_bound(symIndex); iter != _symbols.upper_bound(symIndex); iter++)
    {
        if (iter->second->GetScope() == pScope || iter->second->GetScope() == nullptr)
        {
            // Caller can decide how to report this error
            return nullptr;
        }
    }

    VariableInfo *pNewInfo = new VariableInfo(_pContext, pScope, symIndex, location, pTypeInfo);
    _symbols.emplace(std::make_pair(symIndex, std::unique_ptr<SymbolInfo>(pNewInfo)));
    return pNewInfo;
}

ModuleInfo *SymbolTable::AddModule(
    int symIndex,
    GenericTypeInfo *pGenType)
{
    for (auto iter = _symbols.lower_bound(symIndex); iter != _symbols.upper_bound(symIndex); iter++)
    {
        // Caller can decide how to report this error
        return nullptr;
    }

    ModuleInfo *pNewInfo = new ModuleInfo(_pContext, symIndex, pGenType);
    _symbols.emplace(std::make_pair(symIndex, std::unique_ptr<SymbolInfo>(pNewInfo)));
    return pNewInfo;
}

FunctionInfo *SymbolTable::AddFunction(
    FunctionDeclaratorNode *pFuncDecl,
    int symIndex,
    GenericTypeInfo *pGenType)
{
    for (auto iter = _symbols.lower_bound(symIndex); iter != _symbols.upper_bound(symIndex); iter++)
    {
        // Caller can decide how to report this error
        return nullptr;
    }

    FunctionInfo *pNewInfo = new FunctionInfo(_pContext, pFuncDecl, symIndex, pGenType);
    _symbols.emplace(std::make_pair(symIndex, std::unique_ptr<SymbolInfo>(pNewInfo)));
    return pNewInfo;
}

StateInfo *SymbolTable::AddState(
    int symIndex,
    ModuleDefinitionNode *pScope)
{
    for (auto iter = _symbols.lower_bound(symIndex); iter != _symbols.upper_bound(symIndex); iter++)
    {
        // Caller can decide how to report this error
        return nullptr;
    }

    StateInfo *pNewInfo = new StateInfo(_pContext, pScope, symIndex);
    _symbols.emplace(std::make_pair(symIndex, std::unique_ptr<SymbolInfo>(pNewInfo)));
    return pNewInfo;
}

// Turns out this is for globals only
SymbolInfo *SymbolTable::GetInfo(
    int symIndex, 
    ModuleDefinitionNode *pScope)
{
    //printf("Attempting GetInfo of symbol %s\n", _pContext->_symbols[symIndex].c_str());

    for (auto iter = _symbols.lower_bound(symIndex); iter != _symbols.upper_bound(symIndex); iter++)
    {
        if (iter->second->GetScope() == pScope || iter->second->GetScope() == nullptr)
        {
            return iter->second.get();
        }
    }

    return nullptr;
}

void SymbolTable::GetFunctionVariables(
    ModuleDefinitionNode *pScope, 
    std::vector<VariableInfo*> &varList)
{
    for (auto iter = _symbols.begin(); iter != _symbols.end(); iter++)
    {
        VariableInfo *pVarInfo = dynamic_cast<VariableInfo*>(iter->second.get());

        if (pVarInfo != nullptr)
        {
            if ((pVarInfo->GetScope() == pScope || pVarInfo->GetScope() == nullptr) && 
                pVarInfo->GetTypeInfo()->GetTypeClass() == TypeClass::Struct)
            {
                //printf("Adding variable %s with type %d\n", pVarInfo->GetSymbol(), pVarInfo->GetTypeInfo()->GetTypeClass());
                varList.push_back(pVarInfo);
            }
        }
    }
}