#include "ExpressionNode.h"

TypeInfo *ExpressionNode::GetTypeInfo()
{
    if (_pType == nullptr)
    {
        throw "Unset type";
    }

    return _pType;
}

void ExpressionNode::SetExpressionType(ExpressionType t)
{
    _exprType = t;
}

ExpressionType ExpressionNode::GetExpressionType()
{
    if (_exprType == ExpressionType::Unset)
    {
        ExpressionNode *pParentExpr = dynamic_cast<ExpressionNode *>(GetParent());
        if (pParentExpr == nullptr)
        {
            return ExpressionType::Unset;
        }

        return pParentExpr->GetExpressionType();
    }

    return _exprType;
}

void ExpressionNode::SetType(TypeInfo *pInfo)
{
    if (pInfo == nullptr)
    {
        throw "Should not set type to null";
    }

    _pType = pInfo;
}
