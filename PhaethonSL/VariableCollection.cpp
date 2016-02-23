#include "VariableCollection.h"
#include "VariableDeclarationNode.h"
#include "VariableInfo.h"

VariableCollection::VariableCollection(PSLCompilerContext* pContext)
{
    _pContext = pContext;
}

void VariableCollection::AddVariable(int symIndex, VariableDeclarationNode* pNode, TypeInfo* pTypeInfo)
{
    auto iter = _variables.find(symIndex);

    if (iter == _variables.end())
    {
        _variables[symIndex] = std::unique_ptr<VariableInfo>(new VariableInfo(_pContext, symIndex, pNode, pTypeInfo));
    }
    else
    {
        throw "Cannot add variable more than once";
    }
}

void VariableCollection::AddReference(int symIndex, ASTNode* pNode)
{
    auto iter = _variables.find(symIndex);

    if (iter != _variables.end())
    {
        _variables[symIndex]->pLastRef = pNode;
    }
    else
    {
        throw "Cannot add reference for nonexistent variable";
    }
}

void VariableCollection::ProcessReference(int symIndex, ASTNode *pNode)
{
    auto iter = _variables.find(symIndex);

    if (iter != _variables.end())
    {
        if (_variables[symIndex]->pLastRef == pNode)
        {
            // The last reference to this variable has been processed
            _variables[symIndex]->fLastProcessed = true;
        }
    }
    else
    {
        throw "Cannot process reference for nonexistent variable";
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

bool VariableCollection::IsLastReference(int symIndex, ASTNode* pNode)
{
    return (pNode == GetInfo(symIndex)->pLastRef);
}
