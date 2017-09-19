#include "CaseStatementNode.h"
#include "ParserContext.h"
#include "ExpressionNode.h"
#include "ListNode.h"
#include "OutputContext.h"

CaseStatementNode::CaseStatementNode(ParserContext *pContext, YYLTYPE location, ASTNode *pExpr, ASTNode *pList) : StatementNode(pContext, location)
{
    AddNode(pExpr);
    AddNode(pList);
}

CaseStatementNode::CaseStatementNode(ParserContext *pContext, YYLTYPE location) : StatementNode(pContext, location)
{
}

ASTNode* CaseStatementNode::DuplicateNodeImpl()
{
    return new CaseStatementNode(GetContext(), GetLocation());
}

void CaseStatementNode::VerifyNodeImpl()
{
}

void CaseStatementNode::ProcessNodeImpl(OutputContext* pContext)
{
    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(0));
    pExpr->ProcessNode(pContext);
    std::unique_ptr<ExpressionResult> exprResult(pExpr->TakeResult());
    
    pContext->OutputLine("%s: begin", exprResult->GetString().c_str());
    pContext->IncreaseIndent();

    ListNode *pList = dynamic_cast<ListNode *>(GetChild(1));
    pList->ProcessNode(pContext);

    pContext->DecreaseIndent();
    pContext->OutputLine("end");
}
