#include "CastNode.h"
#include "TypeNode.h"
#include "VSharp.tab.h"

void CastNode::VerifyNodeImpl()
{
    TypeNode *pTypeNode = dynamic_cast<TypeNode *>(GetChild(0));
    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(1));

    if (pTypeNode == nullptr || pExpr == nullptr)
    {
        GetContext()->ReportError(_location, "Wrong children nodes for CastPtr");
    }

    TypeInfo *pGivenTypeInfo = pTypeNode->GetTypeInfo();
    PointerTypeInfo *pCastTypeInfo = GetContext()->_typeCollection.GetPointerType(pGivenTypeInfo);
    PointerTypeInfo *pExprTypeInfo = dynamic_cast<PointerTypeInfo *>(pExpr->GetTypeInfo());

    if (pExprTypeInfo == nullptr)
    {
        BasicTypeInfo *pBasicTypeInfo = dynamic_cast<BasicTypeInfo *>(pExpr->GetTypeInfo());
        if (pBasicTypeInfo == nullptr)
        {
            GetContext()->ReportError(_location, "Wrong type given to CastPtr");
        }
    }

    SetType(pCastTypeInfo);
}

ExpressionResult *CastNode::CalculateResult()
{
    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(1));

    // Take over the child result
    return pExpr->TakeResult();
}