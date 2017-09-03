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

    ASTNode* DuplicateNodeImpl() override
    {
        return new ListNode(GetContext(), nullptr);
    }

    const char *GetDebugName() override { return "ListNode"; }
};
