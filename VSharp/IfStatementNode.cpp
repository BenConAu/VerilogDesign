#include "IfStatementNode.h"
#include "VSharpCompilerContext.h"
#include "ModuleDeclaratorNode.h"
#include "ExpressionNode.h"
#include "ListNode.h"
#include "../PhaethonObjWriter/ObjWriter.h"
#include "VSharp.tab.h"

int IfStatementNode::s_instanceCount = 0;

IfStatementNode::IfStatementNode(PSLCompilerContext *pContext, ASTNode *pTrue, ASTNode *pFalse) : ASTNode(pContext)
{
    s_instanceCount++;
    _instance = s_instanceCount;

    AddNode(pTrue);
    AddNode(pFalse);
}

void IfStatementNode::VerifyNodeImpl()
{
    ExpressionNode *pTest = dynamic_cast<ExpressionNode *>(GetChild(2));
    RegisterTypeInfo *pTestType = dynamic_cast<RegisterTypeInfo *>(pTest->GetTypeInfo());
    if (pTestType == nullptr || pTestType->GetBitLength() != 1)
    {
        throw "If statement must have bool type expression for test";
    }
}

void IfStatementNode::ProcessNodeImpl()
{
    // We are taking over the whole processing, so we have to be careful and
    // replicate everything that the base class does. We just need a specific
    // order.
/*    ExpressionNode *pTest = dynamic_cast<ExpressionNode *>(GetChild(2));
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
        testResult.get());

    char falseLabel[256];
    sprintf(falseLabel, "false_%d", _instance);

    char trueLabel[256];
    sprintf(trueLabel, "true_%d", _instance);

    GetContext()->OutputInstruction(
        OpCode::JzRC,
        wrapper.GetWrapped(),
        Operand(falseLabel));

    // Now the statement list
    pTrue->ProcessNode();

    if (pFalse != nullptr)
    {
        // Jump to the end of the else clause
        GetContext()->OutputInstruction(
            OpCode::JmpC,
            Operand(trueLabel));
    }

    // Now put the label we jump to for test false
    GetContext()->OutputLabel(falseLabel);

    // If we have an else clause then we do more now
    if (pFalse != nullptr)
    {
        pFalse->ProcessNode();
        GetContext()->OutputLabel(trueLabel);
    }*/
}
