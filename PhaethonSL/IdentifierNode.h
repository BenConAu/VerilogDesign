#pragma once

#include "ExpressionNode.h"

class IdentifierNode : public ExpressionNode
{
public:
    IdentifierNode(PSLCompilerContext* pContext, int symIndex);
    void VerifyNodeImpl() override;
    void ProcessNodeImpl() override;

private:
    int _symIndex;
};
