#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class GlomExpressionNode : public ExpressionNode
{
  public:
    GlomExpressionNode(
        PSLCompilerContext *pContext,
        const YYLTYPE &location,
        ASTNode *pExprList);

    void VerifyNodeImpl() override;

    ExpressionResult *CalculateResult() override;
    const char *GetDebugName() override { return "GlomExpressionNode"; }

  private:
    YYLTYPE _location;
};
