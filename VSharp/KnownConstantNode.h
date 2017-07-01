#pragma once

#include "ExpressionNode.h"

class KnownConstantNode : public ExpressionNode
{
public:
    KnownConstantNode(PSLCompilerContext* pContext, KnownConstants known);

    bool IsConstant() const override;
    void VerifyNodeImpl() override;
    ExpressionResult* CalculateResult() override;
    const char* GetDebugName() override { return "KnownConstantNode"; }

private:
    KnownConstants _known;
};
