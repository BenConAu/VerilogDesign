#pragma once

#include "ASTNode.h"
#include "PSLCompilerContext.h"

class VariableDeclarationNode : public ASTNode
{
public:
    VariableDeclarationNode(PSLCompilerContext* pContext, ASTNode* pType, int symIndex) : ASTNode(pContext)
    {
        AddNode(pType);
        _symIndex = symIndex;
    }

    void VerifyNodeImpl() override
    {
        // Add variable to collection and mark first usage
        GetContext()->_varCollection.AddVariable(_symIndex, this);
    }

    void ProcessNodeImpl() override
    {
        // Reserve a register for this declaration
        GetContext()->_regCollection.AddVariableRegister(_symIndex);
    }

private:
    int _symIndex;
};
