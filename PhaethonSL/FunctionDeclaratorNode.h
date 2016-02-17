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

    void ProcessNodeImpl()
    {
    }

private:
    int _symIndex;
};
