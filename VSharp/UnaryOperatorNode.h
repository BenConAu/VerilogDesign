#pragma once

#include "ExpressionNode.h"
#include "VSharpCompilerContext.h"
#include "OperatorInfo.h"

class UnaryOperatorNode : public ExpressionNode
{
  public:
    UnaryOperatorNode(
      PSLCompilerContext *pContext, 
      const YYLTYPE &location, 
      ASTNode *pLeft, 
      Operator op) : ExpressionNode(pContext, location)
    {
        AddNode(pLeft);
        _op = op;
    }

    void VerifyNodeImpl() override;
    virtual ExpressionResult *CalculateResult() override;
    const char* GetDebugName() override { return "UnaryOperatorNode"; }
    
  private:
    Operator _op;
    OperatorInfo _opInfo;

    static OperatorInfo _opTable[];
};
