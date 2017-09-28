#include "ExpressionStatementNode.h"
#include "ParserContext.h"
#include "FunctionCallNode.h"
#include "OutputContext.h"

ExpressionStatementNode::ExpressionStatementNode(
    ParserContext* pContext, 
    const YYLTYPE &location, 
    ASTNode* pExpression) : StatementNode(pContext, location)
{
    AddNode(pExpression);
}

ExpressionStatementNode::ExpressionStatementNode(
    ParserContext* pContext, 
    const YYLTYPE &location) : StatementNode(pContext, location)
{
}

ASTNode* ExpressionStatementNode::DuplicateNodeImpl(DuplicateType type)
{
    return new ExpressionStatementNode(GetContext(), GetLocation());
}

void ExpressionStatementNode::PostProcessNodeImpl(OutputContext* pContext)
{
    ExpressionNode *pChildExpr = dynamic_cast<ExpressionNode *>(GetChild(0));
    
    std::unique_ptr<ExpressionResult> childResult(pChildExpr->TakeResult());

    pContext->OutputLine("%s;", childResult->GetString().c_str());
}
