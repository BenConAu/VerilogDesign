#pragma once

#include "PSLCompilerContext.h"
#include "ASTNode.h"

class ReturnNode : public ASTNode
{
  public:
    ReturnNode(
        PSLCompilerContext *pContext,
        ASTNode *pExpr) : ASTNode(pContext)
    {
        AddNode(pExpr);
    }

    void VerifyNodeImpl() override
    {
    }

    void PostProcessNodeImpl() override;

    const char *GetDebugName() override { return "ReturnNode"; }
};