#pragma once

#include "PSLCompilerContext.h"
#include "ExpressionNode.h"

class OffsetNode : public ExpressionNode
{
  public:
    OffsetNode(
        PSLCompilerContext *pContext,
        ASTNode *pIdent,
        ASTNode *pExpr) : ExpressionNode(pContext)
    {
        AddNode(pIdent);
        AddNode(pExpr);
    }

    void VerifyNodeImpl() override;
    bool IsConstant() const override;
    ExpressionResult *CalculateResult() override;
};