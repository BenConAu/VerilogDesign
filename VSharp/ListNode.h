#pragma once

class ListNode : public ASTNode
{
  public:
    ListNode(PSLCompilerContext *pContext, const YYLTYPE &location, ASTNode *pFirst) : ASTNode(pContext, location)
    {
        if (pFirst != nullptr)
        {
            AddNode(pFirst);
        }
    }

    ASTNode* DuplicateNodeImpl() override
    {
        return new ListNode(GetContext(), GetLocation(), nullptr);
    }

    const char *GetDebugName() override { return "ListNode"; }
};
