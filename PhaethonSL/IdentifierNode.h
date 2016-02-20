#pragma once

#include "ExpressionNode.h"

class IdentifierNode : public ExpressionNode
{
public:
    IdentifierNode(PSLCompilerContext* pContext, int symIndex) : ExpressionNode(pContext)
    {
        _symIndex = symIndex;
    }

    void VerifyNodeImpl() override
    {
        GetContext()->_varCollection.AddReference(_symIndex, this);
    }

    void ProcessNodeImpl() override
    {
        // Get the register we use for this identifier
        SetResultRegister(GetContext()->_regCollection.GetVariableRegister(_symIndex));

        // Mark our use of it
        GetContext()->_varCollection.ProcessReference(_symIndex, this);
    }

private:
    int _symIndex;
};
