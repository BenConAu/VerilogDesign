#pragma once

#include "ExpressionNode.h"

class ConstantNode : public ExpressionNode
{
public:
    enum ConstantType
    {
        Bool,
        Word,
        Float,
    };

public:
    ConstantNode(PSLCompilerContext* pContext, ConstantType t, int v);
    ConstantNode(PSLCompilerContext* pContext, float v);
    ConstantNode(PSLCompilerContext* pContext, ConstantType t);

    bool IsConstant() const override;
    void VerifyNodeImpl() override;
    ExpressionResult* CalculateResult() override;
    const char* GetDebugName() override { return "ConstantNode"; }

private:
    int GetInteger();

private:
    int _intValue;
    float _floatValue;
    ConstantType _type;
};
