#pragma once

#include "ExpressionNode.h"

class ConstantNode : public ExpressionNode
{
public:
    ConstantNode(ParserContext* pContext, const YYLTYPE& location, const UIntConstant&);

    bool IsConstant() const override;
    void VerifyNodeImpl() override;
    ExpressionResult* CalculateResult() override;
    const char* GetDebugName() override { return "ConstantNode"; }
    ASTNode* DuplicateNodeImpl() override;
    bool IsLValue() override { return false; }    
    
private:
    unsigned int GetUInt();

private:
    UIntConstant _value;
};
