#pragma once

#include "ASTNode.h"

class FunctionParameterNode : public ASTNode
{
public:
    FunctionParameterNode(PSLCompilerContext* pContext, ASTNode* pType, int symIndex) : ASTNode(pContext)
    {
        AddNode(pType);
        _symIndex = symIndex;
    }

    void VerifyNodeImpl() override;

private:
    int _symIndex;
};
