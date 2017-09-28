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

ASTNode* ParenNode::DuplicateNodeImpl(DuplicateType type)
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

VariableInfo* ParenNode::IsVariableExpression()
{
    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(0));
    
    // Index selecting a variable expression will yield one
    return pExpr->IsVariableExpression();
}  
