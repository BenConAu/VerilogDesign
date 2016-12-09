#include "OffsetNode.h"
#include "IdentifierNode.h"
#include "PSL.tab.h"

void OffsetNode::VerifyNodeImpl()
{
    IdentifierNode *pIdent = dynamic_cast<IdentifierNode *>(GetChild(0));
    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(1));

    if (pIdent == nullptr || pExpr == nullptr)
    {
        throw "Wrong children nodes for OffsetPtr";
    }

    PointerTypeInfo *pIdentInfo = dynamic_cast<PointerTypeInfo *>(pIdent->GetTypeInfo());
    BasicTypeInfo *pExprInfo = dynamic_cast<BasicTypeInfo *>(pExpr->GetTypeInfo());

    if (pIdentInfo == nullptr || pExprInfo == nullptr)
    {
        throw "Wrong types given to offsetptr";
    }

    BasicTypeInfo *pPointerBase = dynamic_cast<BasicTypeInfo *>(pIdentInfo->GetBaseType());
    if (pPointerBase == nullptr)
    {
        throw "Not a pointer to basic type in offsett";
    }

    if (pPointerBase->GetTypeToken() != VOID_TOKEN)
    {
        throw "Can only offset a pointer to void";
    }

    if (pExprInfo->GetTypeToken() != WORD_TOKEN)
    {
        throw "Can only offset pointer by a word";
    }
}

bool OffsetNode::IsConstant() const
{
    // Sometimes it might be, but basically not
    return false;
}

ExpressionResult *OffsetNode::CalculateResult()
{
    IdentifierNode *pIdent = dynamic_cast<IdentifierNode *>(GetChild(0));
    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(1));

    PointerTypeInfo *pIdentInfo = dynamic_cast<PointerTypeInfo *>(pIdent->GetTypeInfo());
    BasicTypeInfo *pExprInfo = dynamic_cast<BasicTypeInfo *>(pExpr->GetTypeInfo());

    throw "Not yet implemented, coming soon!";
}
