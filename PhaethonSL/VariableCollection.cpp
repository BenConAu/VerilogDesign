#include "VariableCollection.h"
#include "VariableDeclarationNode.h"
#include "VariableInfo.h"

VariableCollection::VariableCollection(PSLCompilerContext* pContext)
{
    _pContext = pContext;
}

void VariableCollection::AddVariable(int symIndex, TypeInfo* pTypeInfo)
{
    auto iter = _variables.find(symIndex);

    if (iter == _variables.end())
    {
        _variables[symIndex] = std::unique_ptr<VariableInfo>(new VariableInfo(_pContext, symIndex, pTypeInfo));
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
        throw "Attempting info get of nonexistent var";
    }
}
