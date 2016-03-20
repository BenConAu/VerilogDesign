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

    void PostProcessNodeImpl() override
    {
        ExpressionNode* pLeft = dynamic_cast<ExpressionNode*>(GetChild(0));
        ExpressionNode* pRight = dynamic_cast<ExpressionNode*>(GetChild(1));

        RegisterWrapper leftWrap(GetContext(), pLeft->GetResult());
        RegisterWrapper rightWrap(GetContext(), pRight->GetResult());

        // Get the register for the left side
        RegIndex leftIndex = leftWrap.GetWrapped()._regIndex;

        // Right side is either a constant or another register
        RegIndex rightIndex = rightWrap.GetWrapped()._regIndex;

        // Get register for our result
        RegIndex resultIndex = GetResult()._regIndex;

        // print out our code
        printf("mov r%d, r%d\n", resultIndex, leftIndex);
        printf("mul r%d, r%d\n", resultIndex, rightIndex);
    }

protected:
    ExpressionResult CalcResultImpl() override
    {
        return ExpressionResult(GetContext()->_regCollection.AllocateRegister());
    }
};
