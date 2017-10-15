#include "SwitchStatementNode.h"
#include "ParserContext.h"
#include "ModuleDefinitionNode.h"
#include "ExpressionNode.h"
#include "ListNode.h"
#include "OutputContext.h"

SwitchStatementNode::SwitchStatementNode(
    ParserContext *pContext, 
    YYLTYPE location, 
    ASTNode *pFirst) : StatementNode(pContext, location)
{
    AddNode(pFirst);
}

SwitchStatementNode::SwitchStatementNode(ParserContext *pContext, YYLTYPE location) : StatementNode(pContext, location)
{
}

ASTNode* SwitchStatementNode::DuplicateNodeImpl(FunctionExpandType type)
{
    return new SwitchStatementNode(GetContext(), GetLocation());
}

void SwitchStatementNode::VerifyNodeImpl()
{
}

void SwitchStatementNode::ProcessNodeImpl(OutputContext* pContext)
{
    ExpressionNode *pTest = dynamic_cast<ExpressionNode *>(GetChild(GetChildCount() - 1));

    // Start with the test
    pTest->ProcessNode(pContext);
    std::unique_ptr<ExpressionResult> testResult(pTest->TakeResult());
    if (testResult.get() == nullptr)
    {
        GetContext()->ReportError(GetLocation(), "No valid expression inside if statement");
    }

    pContext->OutputLine("case (%s)", testResult->GetString().c_str());
    pContext->IncreaseIndent();

    for (size_t i = 0; i < GetChildCount() - 1; i++)
    {
        GetChild(i)->ProcessNode(pContext);
    }

    pContext->DecreaseIndent();
    pContext->OutputLine("endcase");

}
