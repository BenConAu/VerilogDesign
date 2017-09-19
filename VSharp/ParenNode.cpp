#include "ParenNode.h"
#include "ParserContext.h"

ParenNode::ParenNode(
    ParserContext *pContext,
    const YYLTYPE &location,
    ASTNode *pChild) : ExpressionNode(pContext, location)
{
    AddNode(pChild);
}

ParenNode::ParenNode(
    ParserContext *pContext,
    const YYLTYPE &location) : ExpressionNode(pContext, location)
{
}

ASTNode* ParenNode::DuplicateNodeImpl()
{
    return new ParenNode(GetContext(), GetLocation());
}

void ParenNode::VerifyNodeImpl()
{
    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(0));
    SetType(pExpr->GetTypeInfo());
}

ExpressionResult *ParenNode::CalculateResult()
{
    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(0));
    std::unique_ptr<ExpressionResult> exprResult(pExpr->TakeResult());

    char result[1024];
    sprintf(
        result, 
        "(%s)", 
        exprResult->GetString().c_str());

    return new ExpressionResult(result);
}

bool ParenNode::IsLValue()
{
    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(0));
    
    // Bit selecting a valid L value will give an L value
    return pExpr->IsLValue();
}  
