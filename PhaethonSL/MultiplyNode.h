#pragma once

class MultiplyNode : public ASTNode
{
public:
    MultiplyNode(ASTNode* pLeft, ASTNode* pRight)
    {
        AddNode(pLeft);
        AddNode(pRight);
    }

    void ProcessNodeImpl() override
    {
        // Get the register for the left side
        RegIndex leftIndex = GetChild(0)->GetResultRegister();

        // Right side is either a constant or another register
        RegIndex rightIndex = GetChild(1)->GetResultRegister();

        // print out our code
        printf("mul r%d, r%d\n", leftIndex, rightIndex);

        // Register for the left side has been stomped on, so dissociate from symbol
        _regCollection.ClearSymbolRegister(leftIndex);

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
