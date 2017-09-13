#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class GlomExpressionNode : public ExpressionNode
{
  public:
    GlomExpressionNode(
        ParserContext *pContext,
        const YYLTYPE &location,
        ASTNode *pExprList);

    GlomExpressionNode(
        ParserContext *pContext,
        const YYLTYPE &location);

    void VerifyNodeImpl() override;
    ASTNode* DuplicateNodeImpl() override;
    ExpressionResult *CalculateResult() override;
    const char *GetDebugName() override { return "GlomExpressionNode"; }
    bool IsLValue() override { return false; }  // We might revisit this   
};
