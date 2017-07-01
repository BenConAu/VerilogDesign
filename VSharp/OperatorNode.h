#pragma once

#include "ExpressionNode.h"
#include "PSLCompilerContext.h"
#include "OperatorInfo.h"

class OperatorNode : public ExpressionNode
{
  public:
    OperatorNode(
      PSLCompilerContext *pContext, 
      const YYLTYPE &location,
      ASTNode *pLeft, 
      ASTNode *pRight,
      Operator op) : ExpressionNode(pContext)
    {
        AddNode(pLeft);
        AddNode(pRight);
        _op = op;
        _location = location;
    }

    void VerifyNodeImpl() override;
    virtual ExpressionResult *CalculateResult() override;

  private:
    Operator _op;
    OperatorInfo _opInfo;
    YYLTYPE _location;

    static OperatorInfo _opTable[];
};
