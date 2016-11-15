#pragma once

#include "ExpressionNode.h"

class ConstantNode : public ExpressionNode
{
public:
    enum ConstantType
    {
        Int,
        Float,
        Pointer,
    };

public:
    ConstantNode(PSLCompilerContext* pContext, int v);
    ConstantNode(PSLCompilerContext* pContext, float v);
    ConstantNode(PSLCompilerContext* pContext, ConstantType t);

    int GetInteger();
    bool IsConstant() const override;
    void VerifyNodeImpl() override;
    ExpressionResult* CalculateResult() override;

private:
    int _intValue;
    float _floatValue;
    ConstantType _type;
};
