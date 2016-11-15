#pragma once

#include "ExpressionNode.h"

class FieldSelectionNode : public ExpressionNode
{
public:
    FieldSelectionNode(PSLCompilerContext* pContext, ASTNode* pExpr, int symIndex);

    void VerifyNodeImpl() override;

    ExpressionResult* CalculateResult() override;

private:
    int _fieldSymIndex;
};
