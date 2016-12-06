#include "VariableCollection.h"
#include "VariableDeclarationNode.h"
#include "VariableInfo.h"
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
        _variables[symIndex] = std::unique_ptr<VariableInfo>(new VariableInfo(_pContext, symIndex, pScope, pTypeInfo));
        return _variables[symIndex].get();
    }
    else
    {
        throw "Cannot add variable more than once";
    }
}

VariableInfo* VariableCollection::GetInfo(int symIndex)
{
    auto iter = _variables.find(symIndex);

    if (iter != _variables.end())
    {
        return _variables[symIndex].get();
    }
    else
    {
        std::stringstream sstr;
        sstr << "Attempting info get of nonexistent var " << _pContext->_symbols[symIndex];
        static std::string error = sstr.str();

        throw error.c_str();
    }
}
