#include "VariableCollection.h"
#include "VariableDeclarationNode.h"

void VariableCollection::AddVariable(int symIndex, VariableDeclarationNode* pNode)
{
    auto iter = _variables.find(symIndex);

    if (iter == _variables.end())
    {
        _variables[symIndex].symIndex = symIndex;
        _variables[symIndex].pDecl = pNode;
        _variables[symIndex].pLastRef = pNode;
        _variables[symIndex].fLastProcessed = false;
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
        _variables[symIndex].pLastRef = pNode;
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
        if (_variables[symIndex].pLastRef == pNode)
        {
            // The last reference to this variable has been processed
            _variables[symIndex].fLastProcessed = true;
        }
    }
    else
    {
        throw "Cannot process reference for nonexistent variable";
    }
}
