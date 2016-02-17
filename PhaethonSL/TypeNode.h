#pragma once

class TypeNode : public ASTNode
{
public:
    TypeNode(int type)
    {
        _type = type;
    }

private:
    int _type;
};
