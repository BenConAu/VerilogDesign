#pragma once

class AssignmentNode : public ASTNode
{
public:
    AssignmentNode(ASTNode* pLeft, ASTNode* pRight)
    {
        AddNode(pLeft);
        AddNode(pRight);
    }

    void ProcessNodeImpl() override
    {
        // Get the register for the left side
        RegIndex leftIndex = GetChild(0)->GetResultRegister();

        if (GetChild(1)->IsConstant())
        {
            ConstantNode* pConstNode = dynamic_cast<ConstantNode*>(GetChild(1));

            printf("mov r%d, %d\n", leftIndex, pConstNode->GetInteger());
        }
        else
        {
            // Right side is either a constant or another register
            RegIndex rightIndex = GetChild(1)->GetResultRegister();

            // print out our code
            printf("mov r%d, r%d\n", leftIndex, rightIndex);
        }

        // Our result is the left index now
        _result = leftIndex;
    }

    RegIndex GetResultRegister() override
    {
        return _result;
    }

protected:
    RegIndex _result;
};
