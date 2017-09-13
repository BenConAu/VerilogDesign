#pragma once

#include "ExpressionNode.h"
#include "OperatorInfo.h"

class UnaryOperatorNode : public ExpressionNode
{
  public:
    UnaryOperatorNode(
      ParserContext *pContext, 
      const YYLTYPE &location, 
      ASTNode *pLeft, 
      Operator op);

    UnaryOperatorNode(
      ParserContext *pContext, 
      const YYLTYPE &location,
      Operator op,
      OperatorInfo opInfo);
    
    void VerifyNodeImpl() override;
    virtual ExpressionResult *CalculateResult() override;
    const char* GetDebugName() override { return "UnaryOperatorNode"; }
    bool IsLValue() override { return false; }    
    ASTNode* DuplicateNodeImpl() override;
    
  private:
    Operator _op;
    OperatorInfo _opInfo;

    static OperatorInfo _opTable[];
};
