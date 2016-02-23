#pragma once

#include "ASTNode.h"
#include "PSLCompilerContext.h"

class VariableDeclarationNode : public ASTNode
{
public:
    VariableDeclarationNode(PSLCompilerContext* pContext, ASTNode* pType, int symIndex);
    void VerifyNodeImpl();
    void ProcessNodeImpl();

private:
    int _symIndex;
};
