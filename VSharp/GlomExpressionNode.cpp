#include "GlomExpressionNode.h"
#include "VariableInfo.h"
#include "ModuleDefinitionNode.h"
#include "VSharpCompilerContext.h"
#include "ListNode.h"

GlomExpressionNode::GlomExpressionNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pExprList) : ExpressionNode(pContext, location)
{
    AddNode(pExprList);
}

GlomExpressionNode::GlomExpressionNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location) : ExpressionNode(pContext, location)
{
}

void GlomExpressionNode::VerifyNodeImpl()
{
    ListNode* pList =dynamic_cast<ListNode*>(GetChild(0));
    int bitLength = 0;

    for (size_t i = 0; i < pList->GetChildCount(); i++)
    {
        ExpressionNode *pChild = dynamic_cast<ExpressionNode *>(pList->GetChild(i));
        TypeInfo* pType = pChild->GetTypeInfo();
        bitLength += pType->GetBitLength();
    }

    SetType(GetContext()->GetTypeCollection()->GetRegisterType(bitLength));
}

ASTNode* GlomExpressionNode::DuplicateNodeImpl()
{
    return new GlomExpressionNode(GetContext(), GetLocation());
}

ExpressionResult *GlomExpressionNode::CalculateResult()
{
    std::string resultString = "{ ";

    ListNode* pList =dynamic_cast<ListNode*>(GetChild(0));
    for (size_t i = 0; i < pList->GetChildCount(); i++)
    {
        ExpressionNode *pChild = dynamic_cast<ExpressionNode *>(pList->GetChild(i));
        std::unique_ptr<ExpressionResult> childResult(pChild->TakeResult());
        
        if (i != 0)
        {
            resultString.append(", ");
        }

        resultString.append(childResult->GetString());
    }

    resultString.append(" }");

    return new ExpressionResult(resultString);
}
