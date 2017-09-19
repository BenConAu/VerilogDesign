#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class TernaryExpressionNode : public ExpressionNode
{
  public:
    TernaryExpressionNode(
        ParserContext *pContext,
        const YYLTYPE &location,
        ASTNode *pTest,
        ASTNode *pTrue,
        ASTNode *pFalse);

    TernaryExpressionNode(
      ParserContext *pContext,
      const YYLTYPE &location);
  
    void VerifyNodeImpl() override;
    ASTNode* DuplicateNodeImpl() override;    
    ExpressionResult *CalculateResult() override;
    const char *GetDebugName() override { return "TernaryExpressionNode"; }
    bool IsLValue() override;    
};