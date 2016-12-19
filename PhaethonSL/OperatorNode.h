#pragma once

#include "ExpressionNode.h"
#include "PSLCompilerContext.h"
#include "RegisterWrapper.h"

enum class Operator
{
    Multiply,
    Add,
    Subtract
};

class OperatorNode : public ExpressionNode
{
  public:
    OperatorNode(PSLCompilerContext *pContext, ASTNode *pLeft, ASTNode *pRight, Operator op) : ExpressionNode(pContext)
    {
        AddNode(pLeft);
        AddNode(pRight);
        _op = op;
    }

    void VerifyNodeImpl() override
    {
        ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));

        // TODO: Actually check types match like they should
        SetType(pLeft->GetTypeInfo());
    }

    virtual ExpressionResult *CalculateResult() override;

  private:
    Operator _op;
};
