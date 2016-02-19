#pragma once

#include "ExpressionNode.h"

class IdentifierNode : public ExpressionNode
{
public:
    IdentifierNode(int symIndex)
    {
        _symIndex = symIndex;
    }

    void VerifyNodeImpl() override
    {
        _varCollection.AddReference(_symIndex, this);
    }

    void ProcessNodeImpl() override
    {
        // Get the register we use for this identifier
        SetResultRegister(_regCollection.GetVariableRegister(_symIndex));

        // Mark our use of it
        _varCollection.ProcessReference(_symIndex, this);
    }

private:
    int _symIndex;
};
