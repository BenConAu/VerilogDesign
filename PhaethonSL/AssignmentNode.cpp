#include "AssignmentNode.h"
#include "PSLCompilerContext.h"

AssignmentNode::AssignmentNode(PSLCompilerContext* pContext, ASTNode* pLeft, ASTNode* pRight) : ExpressionNode(pContext)
{
    AddNode(pLeft);
    AddNode(pRight);
}

void AssignmentNode::VerifyNodeImpl()
{
    ExpressionNode* pLeft = dynamic_cast<ExpressionNode*>(GetChild(0));

    // Type is same as left side
    SetType(pLeft->GetType());

    // TODO: Check types on left and right match
}

void AssignmentNode::ProcessNode()
{
    // Assignment is special enough that we override the whole process
    ExpressionNode* pRight = dynamic_cast<ExpressionNode*>(GetChild(1));
    pRight->ProcessNode();
    RegIndex rightIndex = pRight->GetResultRegister();

    ExpressionNode* pLeft = dynamic_cast<ExpressionNode*>(GetChild(0));
    pLeft->ProcessWrite(rightIndex);
}

RegIndex AssignmentNode::CalcResultLocationImpl()
{
    throw "AssignmentNode is not an lvalue";
}
