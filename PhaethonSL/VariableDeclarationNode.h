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
        printf("Verify decl\n");
        _regCollection.AddVariableRegister(_symIndex);
        _varCollection.AddVariable(_symIndex, this);
    }

private:
    int _symIndex;
};
