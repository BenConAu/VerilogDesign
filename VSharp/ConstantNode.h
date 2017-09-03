#pragma once

#include "ExpressionNode.h"

class ConstantNode : public ExpressionNode
{
public:
    ConstantNode(PSLCompilerContext* pContext, const YYLTYPE& location, const UIntConstant&);

    bool IsConstant() const override;
    void VerifyNodeImpl() override;
    ExpressionResult* CalculateResult() override;
    const char* GetDebugName() override { return "ConstantNode"; }
    ASTNode* DuplicateNodeImpl() override;

private:
    unsigned int GetUInt();

private:
    UIntConstant _value;
};
