#pragma once

class ListNode : public ASTNode
{
  public:
    ListNode(ParserContext *pContext, const YYLTYPE &location, ASTNode *pFirst) : ASTNode(pContext, location)
    {
        if (pFirst != nullptr)
        {
            AddNode(pFirst);
        }
    }

    ASTNode* DuplicateNodeImpl(FunctionExpandType type) override
    {
        return new ListNode(GetContext(), GetLocation(), nullptr);
    }

    const char *GetDebugName() override { return "ListNode"; }
};
