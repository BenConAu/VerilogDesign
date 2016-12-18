#include "IfStatementNode.h"
#include "PSLCompilerContext.h"
#include "RegisterWrapper.h"
#include "FunctionDeclaratorNode.h"
#include "ExpressionNode.h"
#include "StatementListNode.h"
#include "../PhaethonObjWriter/ObjWriter.h"
#include "PSL.tab.h"

IfStatementNode::IfStatementNode(PSLCompilerContext *pContext, ASTNode *pTrue, ASTNode *pFalse) : ASTNode(pContext)
{
    AddNode(pTrue);
    AddNode(pFalse);
}

void IfStatementNode::VerifyNodeImpl()
{
    ExpressionNode *pTest = dynamic_cast<ExpressionNode *>(GetChild(2));
    BasicTypeInfo *pTestType = dynamic_cast<BasicTypeInfo *>(pTest->GetTypeInfo());
    if (pTestType == nullptr || pTestType->GetTypeToken() != WORD_TOKEN)
    {
        throw "If statement must have word type expression for test";
    }
}

void IfStatementNode::ProcessNode()
{
    // We are taking over the whole processing, so we have to be careful and
    // replicate everything that the base class does. We just need a specific
    // order.
    ExpressionNode *pTest = dynamic_cast<ExpressionNode *>(GetChild(2));
    StatementListNode *pTrue = dynamic_cast<StatementListNode *>(GetChild(0));
    StatementListNode *pFalse = dynamic_cast<StatementListNode *>(GetChild(1));

    // Start with the test
    pTest->ProcessNode();
    std::unique_ptr<ExpressionResult> testResult(pTest->TakeResult());
    if (testResult.get() == nullptr)
    {
        throw "Assignment needs a valid expression on each side";
    }

    FunctionDeclaratorNode *pScope = GetTypedParent<FunctionDeclaratorNode>();

    // Need to make a register for this to work
    RegisterWrapper wrapper(
        GetContext(),
        pScope->GetRegCollection(),
        testResult->_operand);

    GetContext()->OutputInstruction(
        OpCodes::CmpRC,
        wrapper.GetWrapped(),
        Operand(0));

    char labelString[256];
    sprintf(labelString, "label%p", this);

    GetContext()->OutputInstruction(
        OpCodes::JeC,
        Operand(labelString));

    // Now the statement list
    pTrue->ProcessNode();

    // Now put the label we jump to for test false
    GetContext()->OutputLabel(labelString);
}
