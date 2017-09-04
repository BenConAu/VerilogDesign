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
