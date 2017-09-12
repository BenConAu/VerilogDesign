#include "IfStatementNode.h"
#include "ParserContext.h"
#include "ModuleDefinitionNode.h"
#include "ExpressionNode.h"
#include "ListNode.h"
#include "OutputContext.h"

IfStatementNode::IfStatementNode(ParserContext *pContext, YYLTYPE location, ASTNode *pTrue, ASTNode *pFalse) : StatementNode(pContext, location)
{
    AddNode(pTrue);
    AddNode(pFalse);
}

IfStatementNode::IfStatementNode(ParserContext *pContext, YYLTYPE location) : StatementNode(pContext, location)
{
}

ASTNode* IfStatementNode::DuplicateNodeImpl()
{
    return new IfStatementNode(GetContext(), GetLocation());
}

void IfStatementNode::VerifyNodeImpl()
{
    ExpressionNode *pTest = dynamic_cast<ExpressionNode *>(GetChild(2));
    RegisterTypeInfo *pTestType = dynamic_cast<RegisterTypeInfo *>(pTest->GetTypeInfo());
    if (pTestType == nullptr || pTestType->GetBitLength() != 1)
    {
        char result[1024];
        sprintf(
            result, 
            "If statement needs boolean but has %s", 
            pTest->GetTypeInfo()->GetTypeName().c_str());

        GetContext()->ReportError(GetLocation(), result);
    }
}

void IfStatementNode::ProcessNodeImpl(OutputContext* pContext)
{
    // We are taking over the whole processing, so we have to be careful and
    // replicate everything that the base class does. We just need a specific
    // order.
    ExpressionNode *pTest = dynamic_cast<ExpressionNode *>(GetChild(2));
    ListNode *pTrue = dynamic_cast<ListNode *>(GetChild(0));
    ListNode *pFalse = dynamic_cast<ListNode *>(GetChild(1));

    // Start with the test
    pTest->ProcessNode(pContext);
    std::unique_ptr<ExpressionResult> testResult(pTest->TakeResult());
    if (testResult.get() == nullptr)
    {
        GetContext()->ReportError(GetLocation(), "No valid expression inside if statement");
    }

    if (testResult->IsConstant())
    {
        if (testResult->GetConstantValue())
        {
            pTrue->ProcessNode(pContext);            
        }
        else
        {
            if (pFalse != nullptr)
            {
                pFalse->ProcessNode(pContext);
            }
        }
    }
    else
    {
        char result[1024];
        sprintf(
            result, 
            "if (%s)", 
            testResult->GetString().c_str());

        pContext->OutputLine(result);
        
        pContext->OutputLine("begin");
        pContext->IncreaseIndent();

        pTrue->ProcessNode(pContext);

        pContext->DecreaseIndent();
        pContext->OutputLine("end");

        if (pFalse != nullptr)
        {
            pContext->OutputLine("else");
            pContext->OutputLine("begin");
            pContext->IncreaseIndent();
        
            pFalse->ProcessNode(pContext);
        
            pContext->DecreaseIndent();
            pContext->OutputLine("end");
        }
    }
}
