#pragma once

class TypeNode : public ASTNode
{
public:
    TypeNode(int type)
    {
        _type = type;
    }

    void VerifyNodeImpl() override
    {
    }

private:
    int _type;
};
