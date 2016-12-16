#pragma once

class StatementListNode : public ASTNode
{
  public:
    StatementListNode(PSLCompilerContext *pContext, ASTNode *pFirst) : ASTNode(pContext)
    {
        if (pFirst != nullptr)
        {
            AddNode(pFirst);
        }
    }

    void VerifyNodeImpl() override
    {
    }

    const char *GetDebugName() override { return "StatementListNode"; }
};
