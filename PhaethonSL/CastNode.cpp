#include "CastNode.h"
#include "TypeNode.h"
#include "PSL.tab.h"

void CastNode::VerifyNodeImpl()
{
    TypeNode *pTypeNode = dynamic_cast<TypeNode *>(GetChild(0));
    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(1));

    if (pTypeNode == nullptr || pExpr == nullptr)
    {
        throw "Wrong children nodes for CastPtr";
    }

    TypeInfo *pGivenTypeInfo = pTypeNode->GetTypeInfo();
    PointerTypeInfo *pCastTypeInfo = GetContext()->_typeCollection.GetPointerType(pGivenTypeInfo);
    PointerTypeInfo *pExprTypeInfo = dynamic_cast<PointerTypeInfo *>(pExpr->GetTypeInfo());

    if (pExprTypeInfo == nullptr)
    {
        throw "Wrong type given to CastPtr";
    }

    BasicTypeInfo *pPointerBase = dynamic_cast<BasicTypeInfo *>(pExprTypeInfo->GetBaseType());
    if (pPointerBase == nullptr)
    {
        throw "Not a pointer to basic type in castptr";
    }

    if (pPointerBase->GetTypeToken() != VOID_TOKEN)
    {
        throw "Can only cast a pointer to void";
    }

    SetType(pCastTypeInfo);
}

ExpressionResult *CastNode::CalculateResult()
{
    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(1));

    // Take over the child result and overwrite the type
    std::unique_ptr<ExpressionResult> childResult(pExpr->TakeResult());
    childResult->_pTypeInfo = GetTypeInfo();

    return childResult.release();
}