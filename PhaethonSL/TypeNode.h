#pragma once

class TypeNode : public ASTNode
{
public:
    TypeNode(PSLCompilerContext* pContext, int type) : ASTNode(pContext)
    {
        _type = type;
    }

    void VerifyNodeImpl() override
    {
    }

private:
    int _type;
};
