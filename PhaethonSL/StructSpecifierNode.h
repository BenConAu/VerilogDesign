#pragma once

#include "ASTNode.h"

class StructSpecifierNode : public ASTNode
{
public:
    StructSpecifierNode(PSLCompilerContext* pContext, ASTNode* pTypeNode);
    void SetName(int symIndex);
    void PreProcessNodeImpl() override;
    void VerifyNodeImpl() override;

private:
    int _symIndex;
};
