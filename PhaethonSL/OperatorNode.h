#pragma once

#include "ExpressionNode.h"
#include "PSLCompilerContext.h"
#include "RegisterWrapper.h"

enum class Operator
{
    Multiply,
    Add
};

class OperatorNode : public ExpressionNode
{
  public:
    OperatorNode(PSLCompilerContext *pContext, ASTNode *pLeft, ASTNode *pRight, Operator op) : ExpressionNode(pContext)
    {
        AddNode(pLeft);
        AddNode(pRight);
    }

    void VerifyNodeImpl() override
    {
        ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));

        SetType(pLeft->GetType());
    }

    virtual ExpressionResult *CalculateResult() override;

  private:
    Operator _op;
};
