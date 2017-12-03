#pragma once

#include "ExpressionNode.h"
#include "OperatorInfo.h"

class OperatorNode : public ExpressionNode
{
  public:
    OperatorNode(
      ParserContext *pContext, 
      const YYLTYPE &location,
      ASTNode *pLeft, 
      ASTNode *pRight,
      Operator op) : ExpressionNode(pContext, location)
    {
        AddNode(pLeft);
        AddNode(pRight);
        _op = op;
    }

    OperatorNode(
      ParserContext *pContext, 
      const YYLTYPE &location,
      Operator op,
      OperatorInfo opInfo) : ExpressionNode(pContext, location)
    {
        _op = op;
        _opInfo = opInfo;
    }
    
    ASTNode* DuplicateNodeImpl(FunctionExpandType type) override;

    void VerifyNodeImpl() override;
    virtual ExpressionResult *CalculateResult() override;
    const char* GetDebugName() override { return "OperatorNode"; }
    VariableInfo* IsVariableExpression() override { return nullptr; }
    bool ConstEvaluate(UIntConstant* pVal) override;
    
  private:
    Operator _op;
    OperatorInfo _opInfo;

    static OperatorInfo _opTable[];
};
