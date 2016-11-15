#pragma once

#include "ExpressionNode.h"
#include "PSLCompilerContext.h"
#include "RegisterWrapper.h"

class MultiplyNode : public ExpressionNode
{
public:
    MultiplyNode(PSLCompilerContext* pContext, ASTNode* pLeft, ASTNode* pRight) : ExpressionNode(pContext)
    {
        AddNode(pLeft);
        AddNode(pRight);
    }

    void VerifyNodeImpl() override
    {
        ExpressionNode* pLeft = dynamic_cast<ExpressionNode*>(GetChild(0));

        SetType(pLeft->GetType());
    }

    virtual ExpressionResult* CalculateResult() override;
};
