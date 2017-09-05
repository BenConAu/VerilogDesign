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

    GlomExpressionNode(
        PSLCompilerContext *pContext,
        const YYLTYPE &location);

    void VerifyNodeImpl() override;
    ASTNode* DuplicateNodeImpl() override;
    
    ExpressionResult *CalculateResult() override;
    const char *GetDebugName() override { return "GlomExpressionNode"; }
};
