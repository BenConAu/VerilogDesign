#include "SymbolTable.h"
#include "VariableDeclarationNode.h"
#include "VariableInfo.h"
#include "FunctionInfo.h"
#include "PSL.tab.h"
#include <sstream>

SymbolTable::SymbolTable(PSLCompilerContext* pContext)
{
    _pContext = pContext;
}

void SymbolTable::AddBuiltin()
{
    int dseIndex = _pContext->AddSymbol("__datasegmentend");
    PointerTypeInfo* pDseType = _pContext->_typeCollection.GetPointerType(nullptr);
    AddVariable(dseIndex, nullptr, pDseType);
}

VariableInfo* SymbolTable::AddVariable(
    int symIndex, 
    FunctionDeclaratorNode* pScope, 
    TypeInfo* pTypeInfo
    )
{
    auto iter = _symbols.find(symIndex);

    if (iter == _symbols.end())
    {
        VariableInfo* pNewInfo = new VariableInfo(_pContext, symIndex, pScope, pTypeInfo);
        _symbols[symIndex] = std::unique_ptr<SymbolInfo>(pNewInfo);
        return pNewInfo;
    }
    else
    {
        throw "Cannot add variable more than once";
    }
}

FunctionInfo* SymbolTable::AddFunction(
    int symIndex,
    GenericTypeInfo *pGenType,
    TypeInfo* pReturnTypeInfo
    )
{
    //printf("Adding info for function %s\n", _pContext->_symbols[symIndex].c_str());

    auto iter = _symbols.find(symIndex);

    if (iter == _symbols.end())
    {
        FunctionInfo* pNewInfo = new FunctionInfo(_pContext, symIndex, pGenType, pReturnTypeInfo);
        _symbols[symIndex] = std::unique_ptr<SymbolInfo>(pNewInfo);
        return pNewInfo;
    }
    else
    {
        throw "Cannot add variable more than once";
    }
}

SymbolInfo* SymbolTable::GetInfo(int symIndex)
{
    //printf("Attempting GetInfo of symbol %s\n", _pContext->_symbols[symIndex].c_str());

    auto iter = _symbols.find(symIndex);

    if (iter != _symbols.end())
    {
        return _symbols[symIndex].get();
    }

    return nullptr;
}
