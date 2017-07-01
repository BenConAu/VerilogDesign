#pragma once

#include "PSLCompilerContext.h"
#include "OperatorNode.h"
#include "VSharp.tab.h"

class CastNode : public ExpressionNode
{
  public:
    CastNode(
        PSLCompilerContext *pContext,
        const YYLTYPE &Location,
        ASTNode *pType,
        ASTNode *pExpr) : ExpressionNode(pContext)
    {
        _location = Location;

        AddNode(pType);
        AddNode(pExpr);
    }

    void VerifyNodeImpl() override;
    ExpressionResult *CalculateResult() override;
    const char *GetDebugName() override { return "CastNode"; }

  private:
    YYLTYPE _location;
};