#pragma once

#include "PSLCompilerContext.h"
#include "OperatorNode.h"

class OffsetNode : public OperatorNode
{
  public:
    OffsetNode(
        PSLCompilerContext *pContext,
        ASTNode *pIdent,
        ASTNode *pExpr) : OperatorNode(pContext, pIdent, pExpr, Operator::Add)
    {
    }

    void VerifyNodeImpl() override;
};