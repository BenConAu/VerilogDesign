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
    TypeInfo *pDseType = new BasicTypeInfo(INTPTR_TOKEN);
    AddVariable(dseIndex, nullptr, pDseType);
}

void VariableCollection::AddVariable(int symIndex, FunctionDeclaratorNode* pScope, TypeInfo* pTypeInfo)
{
    auto iter = _variables.find(symIndex);

    if (iter == _variables.end())
    {
        _variables[symIndex] = std::unique_ptr<VariableInfo>(new VariableInfo(_pContext, symIndex, pScope, pTypeInfo));
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
        std::string error = sstr.str();

        throw error.c_str();
    }
}
