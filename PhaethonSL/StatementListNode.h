#pragma once

class StatementListNode : public ASTNode
{
public:
    StatementListNode(ASTNode* pFirst)
    {
        AddNode(pFirst);
    }

    void VerifyNodeImpl() override
    {
    }
};
