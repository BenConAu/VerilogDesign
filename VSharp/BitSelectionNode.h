#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class BitSelectionNode : public ExpressionNode
{
  public:
    BitSelectionNode(
        ParserContext *pContext,
        const YYLTYPE &location,
        ASTNode *pPostFix,
        ASTNode *pInt1,
        ASTNode *pInt2);

    BitSelectionNode(
      ParserContext *pContext,
      const YYLTYPE &location,
      int i1,
      int i2);
  
    void VerifyNodeImpl() override;
    ASTNode* DuplicateNodeImpl(DuplicateType type) override;    
    ExpressionResult *CalculateResult() override;
    const char *GetDebugName() override { return "BitSelectionNode"; }
    VariableInfo* IsVariableExpression() override;
    
  private:
    int _i1;
    int _i2;
};
