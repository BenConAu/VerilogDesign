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

protected:
    RegIndex CalcResultRegisterImpl() override
    {
        // No register needed for constants!
        // TODO: investigate throwing on this
        return 0xFF;
    }

private:
    int _intValue;
    float _floatValue;
    ConstantType _type;
};
