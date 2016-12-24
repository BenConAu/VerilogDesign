#pragma once

#include "ExpressionNode.h"
#include "PSLCompilerContext.h"
#include "RegisterWrapper.h"

enum class Operator
{
    Multiply,
    Add,
    Subtract,
    ShiftLeft,
    ShiftRight,
    Equal,
    NotEqual
};

enum class ResultTypeMethod
{
    Both,   // Type of arguments
    Bool,   // Returns bool
};

struct OperatorInfo
{
    Operator _operator;
    OpCodes::Enum _opCodeWord;
    OpCodes::Enum _opCodeFloat;
    ResultTypeMethod _resultType;
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

    void VerifyNodeImpl() override;
    virtual ExpressionResult *CalculateResult() override;

  private:
    Operator _op;
    OperatorInfo _opInfo;

    static OperatorInfo _opTable[7];
};
