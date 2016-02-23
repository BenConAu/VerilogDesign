#pragma once

#include "ConstantNode.h"
#include "ExpressionNode.h"

class AssignmentNode : public ExpressionNode
{
public:
    AssignmentNode(PSLCompilerContext* pContext, ASTNode* pLeft, ASTNode* pRight) : ExpressionNode(pContext)
    {
        AddNode(pLeft);
        AddNode(pRight);
    }

    void VerifyNodeImpl() override
    {
        ExpressionNode* pLeft = dynamic_cast<ExpressionNode*>(GetChild(0));

        // Type is same as left side
        SetType(pLeft->GetType());

        // TODO: Check types on left and right match
    }

    void ProcessNodeImpl() override
    {
        ExpressionNode* pLeft = dynamic_cast<ExpressionNode*>(GetChild(0));

        // Get the register for the left side
        RegIndex leftIndex = pLeft->GetResultRegister();

        if (GetChild(1)->IsConstant())
        {
            ConstantNode* pConstNode = dynamic_cast<ConstantNode*>(GetChild(1));

            printf("mov r%d, %d\n", leftIndex, pConstNode->GetInteger());
        }
        else
        {
            ExpressionNode* pRight = dynamic_cast<ExpressionNode*>(GetChild(1));

            // Right side is either a constant or another register
            RegIndex rightIndex = pRight->GetResultRegister();

            // print out our code
            printf("mov r%d, r%d\n", leftIndex, rightIndex);
        }

        // Our result is the left index now
        SetResultRegister(leftIndex);

        // Recycle the register if the last reference is done
        //if (GetContext()->_varCollection.IsLastReference(this))
    }
};
