#include "VariableCollection.h"
#include "VariableDeclarationNode.h"
#include "VariableInfo.h"
#include "FunctionInfo.h"
#include "PSL.tab.h"
#include <sstream>

VariableCollection::VariableCollection(PSLCompilerContext* pContext)
{
    _pContext = pContext;
}

void VariableCollection::AddBuiltin()
{
    int dseIndex = _pContext->AddSymbol("__datasegmentend");
    PointerTypeInfo* pDseType = _pContext->_typeCollection.GetPointerType(nullptr);
    AddVariable(dseIndex, nullptr, pDseType);
}

VariableInfo* VariableCollection::AddVariable(
    int symIndex, 
    FunctionDeclaratorNode* pScope, 
    TypeInfo* pTypeInfo
    )
{
    auto iter = _variables.find(symIndex);

    if (iter == _variables.end())
    {
        VariableInfo* pNewInfo = new VariableInfo(_pContext, symIndex, pScope, pTypeInfo);
        _variables[symIndex] = std::unique_ptr<SymbolInfo>(pNewInfo);
        return pNewInfo;
    }
    else
    {
        throw "Cannot add variable more than once";
    }
}

FunctionInfo* VariableCollection::AddFunction(
    int symIndex,
    GenericTypeInfo *pGenType,
    TypeInfo* pReturnTypeInfo
    )
{
    //printf("Adding info for function %s\n", _pContext->_symbols[symIndex].c_str());

    auto iter = _variables.find(symIndex);

    if (iter == _variables.end())
    {
        FunctionInfo* pNewInfo = new FunctionInfo(_pContext, symIndex, pGenType, pReturnTypeInfo);
        _variables[symIndex] = std::unique_ptr<SymbolInfo>(pNewInfo);
        return pNewInfo;
    }
    else
    {
        throw "Cannot add variable more than once";
    }
}

SymbolInfo* VariableCollection::GetInfo(int symIndex)
{
    //printf("Attempting GetInfo of symbol %s\n", _pContext->_symbols[symIndex].c_str());

    auto iter = _variables.find(symIndex);

    if (iter != _variables.end())
    {
        return _variables[symIndex].get();
    }

    return nullptr;
}
