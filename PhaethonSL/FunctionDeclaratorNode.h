#pragma once

class FunctionDeclaratorNode : public ASTNode
{
public:
    FunctionDeclaratorNode(ASTNode* pTypeNode, int symIndex)
    {
        AddNode(pTypeNode);
        _symIndex = symIndex;
    }

    void SetStatementList(ASTNode* pList)
    {
        AddNode(pList);
    }

    void ProcessNodeImpl() override
    {
    }

    void VerifyNodeImpl() override
    {
        // Make sure the symbol is unique
        // Figure out parameter stuff?
    }

private:
    int _symIndex;
};
