#pragma once

class ListNode : public ASTNode
{
  public:
    ListNode(PSLCompilerContext *pContext, ASTNode *pFirst) : ASTNode(pContext)
    {
        if (pFirst != nullptr)
        {
            AddNode(pFirst);
        }
    }

    void VerifyNodeImpl() override
    {
    }

    const char *GetDebugName() override { return "ListNode"; }
};
