#pragma once

#include "ExpressionNode.h"

class ConstantNode : public ExpressionNode
{
public:
    enum ConstantType
    {
        Bool,
        Word,
    };

public:
    ConstantNode(PSLCompilerContext* pContext, const YYLTYPE& location, ConstantType t, int v);
    ConstantNode(PSLCompilerContext* pContext, const YYLTYPE& location, ConstantType t);

    bool IsConstant() const override;
    void VerifyNodeImpl() override;
    ExpressionResult* CalculateResult() override;
    const char* GetDebugName() override { return "ConstantNode"; }

private:
    int GetInteger();

private:
    int _intValue;
    ConstantType _type;
};
