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
    ASTNode* DuplicateNodeImpl(FunctionExpandType type) override;
    ExpressionResult *CalculateResult() override;
    const char *GetDebugName() override { return "GlomExpressionNode"; }
    VariableInfo* IsVariableExpression() override { return nullptr; } // Might revisit
};
