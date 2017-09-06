#include "IfStatementNode.h"
#include "VSharpCompilerContext.h"
#include "ModuleDeclaratorNode.h"
#include "ExpressionNode.h"
#include "ListNode.h"
#include "../PhaethonObjWriter/ObjWriter.h"

IfStatementNode::IfStatementNode(PSLCompilerContext *pContext, YYLTYPE location, ASTNode *pTrue, ASTNode *pFalse) : StatementNode(pContext, location)
{
    AddNode(pTrue);
    AddNode(pFalse);
}

IfStatementNode::IfStatementNode(PSLCompilerContext *pContext, YYLTYPE location) : StatementNode(pContext, location)
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

void IfStatementNode::ProcessNodeImpl()
{
    // We are taking over the whole processing, so we have to be careful and
    // replicate everything that the base class does. We just need a specific
    // order.
    ExpressionNode *pTest = dynamic_cast<ExpressionNode *>(GetChild(2));
    ListNode *pTrue = dynamic_cast<ListNode *>(GetChild(0));
    ListNode *pFalse = dynamic_cast<ListNode *>(GetChild(1));

    // Start with the test
    pTest->ProcessNode();
    std::unique_ptr<ExpressionResult> testResult(pTest->TakeResult());
    if (testResult.get() == nullptr)
    {
        GetContext()->ReportError(GetLocation(), "No valid expression inside if statement");
    }

    if (testResult->IsConstant())
    {
        if (testResult->GetConstantValue())
        {
            pTrue->ProcessNode();            
        }
        else
        {
            if (pFalse != nullptr)
            {
                pFalse->ProcessNode();
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

        GetContext()->OutputLine(result);
        
        GetContext()->OutputLine("begin");
        GetContext()->IncreaseIndent();

        pTrue->ProcessNode();

        GetContext()->DecreaseIndent();
        GetContext()->OutputLine("end");

        if (pFalse != nullptr)
        {
            GetContext()->OutputLine("else");
            GetContext()->OutputLine("begin");
            GetContext()->IncreaseIndent();
        
            pFalse->ProcessNode();
        
            GetContext()->DecreaseIndent();
            GetContext()->OutputLine("end");
        }
    }
}
