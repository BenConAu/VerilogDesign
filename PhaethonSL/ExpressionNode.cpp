#include "ExpressionNode.h"

TypeInfo *ExpressionNode::GetTypeInfo()
{
    if (_pType == nullptr)
    {
        throw "Unset type";
    }

    return _pType;
}

void ExpressionNode::SetType(TypeInfo *pInfo)
{
    if (pInfo == nullptr)
    {
        throw "Should not set type to null";
    }

    _pType = pInfo;
}

void ExpressionNode::PostProcessNodeImpl()
{
    // Calculate our result using the result of the children
    _pResult = CalculateResult();
}
