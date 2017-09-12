#include "ExpressionStatementNode.h"
#include "VSharpCompilerContext.h"
#include "FunctionCallNode.h"

ExpressionStatementNode::ExpressionStatementNode(
    PSLCompilerContext* pContext, 
    const YYLTYPE &location, 
    ASTNode* pExpression) : StatementNode(pContext, location)
{
    AddNode(pExpression);
}

ExpressionStatementNode::ExpressionStatementNode(
    PSLCompilerContext* pContext, 
    const YYLTYPE &location) : StatementNode(pContext, location)
{
}

ASTNode* ExpressionStatementNode::DuplicateNodeImpl()
{
    return new ExpressionStatementNode(GetContext(), GetLocation());
}

void ExpressionStatementNode::PostProcessNodeImpl(OutputContext* pContext)
{
    ExpressionNode *pChildExpr = dynamic_cast<ExpressionNode *>(GetChild(0));
    
    std::unique_ptr<ExpressionResult> childResult(pChildExpr->TakeResult());

    pContext->OutputLine("%s;", childResult->GetString().c_str());
}
