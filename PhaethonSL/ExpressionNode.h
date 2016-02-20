#pragma once

#include "ASTNode.h"

class ExpressionNode : public ASTNode
{
public:
    ExpressionNode(PSLCompilerContext* pContext) : ASTNode(pContext)
    {
    }

    RegIndex GetResultRegister()
    {
        return _result;
    }

protected:
    void SetResultRegister(RegIndex result)
    {
        _result = result;
    }

private:
    RegIndex _result;
};
