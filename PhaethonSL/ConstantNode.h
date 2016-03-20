#pragma once

#include "ExpressionNode.h"

class ConstantNode : public ExpressionNode
{
public:
    enum ConstantType
    {
        Int,
        Float
    };

public:
    ConstantNode(PSLCompilerContext* pContext, int v);
    ConstantNode(PSLCompilerContext* pContext, float v);

    int GetInteger();
    bool IsConstant() const override;
    void VerifyNodeImpl() override;
    void PostProcessNodeImpl() override;

protected:
    ExpressionResult CalcResultImpl() override;

private:
    int _intValue;
    float _floatValue;
    ConstantType _type;
};
