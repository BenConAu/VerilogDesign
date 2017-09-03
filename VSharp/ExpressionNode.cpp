#include "ExpressionNode.h"
#include "VSharpCompilerContext.h"
#include "FunctionCallNode.h"

TypeInfo *ExpressionNode::GetTypeInfo()
{
    if (_pType == nullptr)
    {
        //GetContext()->ReportError(_location, "Internal compiler error: Unset type on expression");
        //throw "Unset type on expression";
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

FunctionCallNode* ExpressionNode::GetFunctionCall(ASTNode* pNode)
{
    // Do we have a child that is a function call?
    FunctionCallNode* pCallNode = dynamic_cast<FunctionCallNode*>(pNode);
    if (pCallNode != nullptr)
    {
        return pCallNode;
    }

    for (size_t i = 0; i < pNode->GetChildCount(); i++)
    {
        // Do we have a child that is a function call?
        pCallNode = GetFunctionCall(pNode->GetChild(i));
        if (pCallNode != nullptr)
        {
            return pCallNode;
        }
    }

    //printf("GetFunctionCall failed on all children and this node is not a function call\n");
    return nullptr;
}

FunctionCallNode* ExpressionNode::GetFirstFunctionCall()
{
    return GetFunctionCall(this);
}