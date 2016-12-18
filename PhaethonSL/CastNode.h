#pragma once

#include "PSLCompilerContext.h"
#include "OperatorNode.h"

class CastNode : public ExpressionNode
{
  public:
    CastNode(
        PSLCompilerContext *pContext,
        ASTNode *pType,
        ASTNode *pExpr) : ExpressionNode(pContext)
    {
        AddNode(pType);
        AddNode(pExpr);
    }

    void VerifyNodeImpl() override;
    ExpressionResult* CalculateResult() override;
    const char* GetDebugName() override { return "CastNode"; }    
};