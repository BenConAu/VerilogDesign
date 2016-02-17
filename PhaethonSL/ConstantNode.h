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
    ConstantNode(int v)
    {
        _intValue = v;
        _type = Int;
    }

    ConstantNode(float v)
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

private:
    int _intValue;
    float _floatValue;
    ConstantType _type;
};
