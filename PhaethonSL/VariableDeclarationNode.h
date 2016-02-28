#pragma once

#include "ASTNode.h"
#include "PSLCompilerContext.h"

class VariableDeclarationNode : public ASTNode
{
public:
    VariableDeclarationNode(PSLCompilerContext* pContext, ASTNode* pType, int symIndex);
    void VerifyNodeImpl() override;
    void PostProcessNodeImpl() override;

private:
    int _symIndex;
    bool _fGlobal;
};
