#pragma once

#include "ExpressionNode.h"
#include "VSharpCompilerContext.h"
#include "OperatorInfo.h"

class OperatorNode : public ExpressionNode
{
  public:
    OperatorNode(
      PSLCompilerContext *pContext, 
      const YYLTYPE &location,
      ASTNode *pLeft, 
      ASTNode *pRight,
      Operator op) : ExpressionNode(pContext, location)
    {
        AddNode(pLeft);
        AddNode(pRight);
        _op = op;
    }

    void VerifyNodeImpl() override;
    virtual ExpressionResult *CalculateResult() override;

  private:
    Operator _op;
    OperatorInfo _opInfo;

    static OperatorInfo _opTable[];
};
