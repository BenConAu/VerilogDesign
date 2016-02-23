#pragma once

#include "ExpressionNode.h"
#include "PSLCompilerContext.h"

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

    void ProcessNodeImpl() override
    {
        ExpressionNode* pLeft = dynamic_cast<ExpressionNode*>(GetChild(0));
        ExpressionNode* pRight = dynamic_cast<ExpressionNode*>(GetChild(1));

        // Get the register for the left side
        RegIndex leftIndex = pLeft->GetResultRegister();

        // Right side is either a constant or another register
        RegIndex rightIndex = pRight->GetResultRegister();

        // Get register for our result
        RegIndex resultIndex = GetContext()->_regCollection.AllocateRegister();

        // print out our code
        printf("mov r%d, r%d\n", resultIndex, leftIndex);
        printf("mul r%d, r%d\n", resultIndex, rightIndex);

        // Our result is the left index now
        SetResultRegister(resultIndex);
    }
};
