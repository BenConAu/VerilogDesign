#pragma once

class ConstantNode : public ASTNode
{
public:
    enum ConstantType
    {
        Int,
        Float
    };

public:
    ConstantNode(PSLCompilerContext* pContext, int v)  : ASTNode(pContext)
    {
        _intValue = v;
        _type = Int;
    }

    ConstantNode(PSLCompilerContext* pContext, float v) : ASTNode(pContext)
    {
        _floatValue = v;
        _type = Float;
    }

    int GetInteger()
    {
        if (_type == Int)
        {
            return _intValue;
        }
        else
        {
            throw "Not an integer";
        }
    }

    bool IsConstant() const override { return true; }

    void VerifyNodeImpl() override
    {
        // Make sure in range
    }

private:
    int _intValue;
    float _floatValue;
    ConstantType _type;
};
