#include "ExpressionNode.h"
#include "VSharpCompilerContext.h"

TypeInfo *ExpressionNode::GetTypeInfo()
{
    if (_pType == nullptr)
    {
        GetContext()->ReportError(_location, "Internal compiler error: Unset type on expression");
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

bool ExpressionNode::EqualType(ASTNode *pA, ASTNode *pB)
{
    ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(pA);
    ExpressionNode *pRight = dynamic_cast<ExpressionNode *>(pB);

    TypeInfo *pLeftType = pLeft->GetTypeInfo();
    TypeInfo *pRightType = pRight->GetTypeInfo();

    return pLeftType->EqualType(pRightType);
}
