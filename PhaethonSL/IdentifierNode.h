#pragma once

#include "ExpressionNode.h"

class IdentifierNode : public ExpressionNode
{
public:
    IdentifierNode(PSLCompilerContext* pContext, int symIndex);
    void VerifyNodeImpl() override;
    int GetSymbolIndex() const { return _symIndex; }
    ExpressionResult* CalculateResult() override;

private:
    int _symIndex;
};
