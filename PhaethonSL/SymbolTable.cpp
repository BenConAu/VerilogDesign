#include "SymbolTable.h"
#include "VariableDeclarationNode.h"
#include "VariableInfo.h"
#include "FunctionInfo.h"
#include "PSL.tab.h"
#include <sstream>

SymbolTable::SymbolTable(PSLCompilerContext *pContext)
{
    _pContext = pContext;
}

void SymbolTable::AddBuiltin()
{
    int dseIndex = _pContext->AddSymbol("__datasegmentend");
    PointerTypeInfo *pDseType = _pContext->_typeCollection.GetPointerType(nullptr);
    AddVariable(dseIndex, nullptr, pDseType);
}

VariableInfo *SymbolTable::AddVariable(
    int symIndex,
    FunctionDeclaratorNode *pScope,
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

    VariableInfo *pNewInfo = new VariableInfo(_pContext, symIndex, pScope, pTypeInfo);
    _symbols.emplace(std::make_pair(symIndex, std::unique_ptr<SymbolInfo>(pNewInfo)));
    return pNewInfo;
}

FunctionInfo *SymbolTable::AddFunction(
    int symIndex,
    GenericTypeInfo *pGenType,
    TypeInfo *pReturnTypeInfo)
{
    for (auto iter = _symbols.lower_bound(symIndex); iter != _symbols.upper_bound(symIndex); iter++)
    {
        // Caller can decide how to report this error
        return nullptr;
    }

    FunctionInfo *pNewInfo = new FunctionInfo(_pContext, symIndex, pGenType, pReturnTypeInfo);
    _symbols.emplace(std::make_pair(symIndex, std::unique_ptr<SymbolInfo>(pNewInfo)));
    return pNewInfo;
}

// Turns out this is for globals only
SymbolInfo *SymbolTable::GetInfo(
    int symIndex, 
    FunctionDeclaratorNode *pScope)
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
