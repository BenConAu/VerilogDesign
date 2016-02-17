#pragma once

class IdentifierNode : public ASTNode
{
public:
    IdentifierNode(int symIndex)
    {
        _symIndex = symIndex;
    }

    void ProcessNodeImpl() override
    {
        _regIndex = _regCollection.GetSymbolRegister(_symIndex);
    }

    RegIndex GetResultRegister() override
    {
        return _regIndex;
    }

private:
    int _symIndex;
    RegIndex _regIndex;
};
