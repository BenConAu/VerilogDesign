#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class ParenNode : public ExpressionNode
{
  public:
    ParenNode(
        ParserContext *pContext,
        const YYLTYPE &location,
        ASTNode *pChild);

    ParenNode(
      ParserContext *pContext,
      const YYLTYPE &location);
  
    void VerifyNodeImpl() override;
    ASTNode* DuplicateNodeImpl() override;    
    ExpressionResult *CalculateResult() override;
    const char *GetDebugName() override { return "ParenNode"; }
    bool IsLValue() override;    
};
