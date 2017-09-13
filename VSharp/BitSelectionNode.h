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
        const UIntConstant &i1,
        const UIntConstant &i2);

    BitSelectionNode(
      ParserContext *pContext,
      const YYLTYPE &location,
      int i1,
      int i2);
  
    void VerifyNodeImpl() override;
    ASTNode* DuplicateNodeImpl() override;    
    ExpressionResult *CalculateResult() override;
    const char *GetDebugName() override { return "BitSelectionNode"; }
    bool IsLValue() override;    
    
  private:
    int _i1;
    int _i2;
};
