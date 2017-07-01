#include "WhileStatementNode.h"
#include "PSLCompilerContext.h"
#include "FunctionDeclaratorNode.h"
#include "ExpressionNode.h"
#include "StatementListNode.h"
#include "../PhaethonObjWriter/ObjWriter.h"
#include "VSharp.tab.h"

int WhileStatementNode::s_instanceCount = 0;

WhileStatementNode::WhileStatementNode(PSLCompilerContext *pContext, ASTNode *pExpr, ASTNode *pList) : ASTNode(pContext)
{
    s_instanceCount++;
    _instance = s_instanceCount;

    AddNode(pExpr);
    AddNode(pList);
}

void WhileStatementNode::VerifyNodeImpl()
{
    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(0));
    BasicTypeInfo *pTestType = dynamic_cast<BasicTypeInfo *>(pExpr->GetTypeInfo());
    if (pTestType == nullptr || pTestType->GetTypeToken() != BOOL_TOKEN)
    {
        throw "While statement must have bool type expression for test";
    }
}

void WhileStatementNode::ProcessNode()
{
/*    // We are taking over the whole processing, so we have to be careful and
    // replicate everything that the base class does. We just need a specific
    // order.
    //
    // One of the first things to do is push the deallocation stack so that
    // any temporary registers used in the expression part of the loop are not
    // reused in other parts of the loop. That causes very bad bugs where
    // register usage is not tracked properly.
    FunctionDeclaratorNode *pScope = GetTypedParent<FunctionDeclaratorNode>();

    //printf("Starting to process while statement\n");
    pScope->GetRegCollection()->Push();

    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(0));
    StatementListNode *pLoop = dynamic_cast<StatementListNode *>(GetChild(1));

    char beginLabel[256];
    sprintf(beginLabel, "loopBegin_%d", _instance);

    char endLabel[256];
    sprintf(endLabel, "loopEnd_%d", _instance);

    // Now put the label we jump to for each loop
    GetContext()->OutputLabel(beginLabel);

    // Start with the test
    pExpr->ProcessNode();
    std::unique_ptr<ExpressionResult> testResult(pExpr->TakeResult());
    if (testResult.get() == nullptr)
    {
        throw "While needs a valid expression";
    }

    // Need to make a register for this to work
    RegisterWrapper wrapper(
        GetContext(),
        pScope->GetRegCollection(),
        testResult.get());

    GetContext()->OutputInstruction(
        OpCode::CmpRC,
        wrapper.GetWrapped(),
        Operand(0));

    GetContext()->OutputInstruction(
        OpCode::JeC,
        Operand(endLabel));

    // Now the statement list
    pLoop->ProcessNode();

    GetContext()->OutputInstruction(
        OpCode::JmpC,
        Operand(beginLabel));

    // Now put the label we jump to for test false
    GetContext()->OutputLabel(endLabel);

    pScope->GetRegCollection()->Pop();

    //printf("Finishing of process while statement\n");*/
}
