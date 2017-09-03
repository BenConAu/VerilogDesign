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

    OperatorNode(
      PSLCompilerContext *pContext, 
      const YYLTYPE &location,
      Operator op,
      OperatorInfo opInfo) : ExpressionNode(pContext, location)
    {
        _op = op;
        _opInfo = opInfo;
    }
    
    ASTNode* DuplicateNodeImpl() override;

    void VerifyNodeImpl() override;
    virtual ExpressionResult *CalculateResult() override;
    const char* GetDebugName() override { return "OperatorNode"; }
    
  private:
    Operator _op;
    OperatorInfo _opInfo;

    static OperatorInfo _opTable[];
};
