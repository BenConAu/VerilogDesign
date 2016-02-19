#pragma once

#include "ASTNode.h"

class VariableDeclarationNode : public ASTNode
{
public:
    VariableDeclarationNode(ASTNode* pType, int symIndex)
    {
        AddNode(pType);
        _symIndex = symIndex;
    }

    void VerifyNodeImpl() override
    {
        // Add variable to collection and mark first usage
        _varCollection.AddVariable(_symIndex, this);
    }

    void ProcessNodeImpl() override
    {
        // Reserve a register for this declaration
        _regCollection.AddVariableRegister(_symIndex);        
    }

private:
    int _symIndex;
};
