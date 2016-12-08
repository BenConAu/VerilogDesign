#pragma once

#include "PSLCompilerContext.h"
#include "ExpressionNode.h"
#include "PSL.tab.h"

class AddressOfNode : public ExpressionNode
{
  public:
    AddressOfNode(
        PSLCompilerContext *pContext,
        ASTNode *pExpr) : ExpressionNode(pContext)
    {
        AddNode(pExpr);
    }

    void VerifyNodeImpl() override;
    bool IsConstant() const override { return true; }
    ExpressionResult *CalculateResult() override;
};