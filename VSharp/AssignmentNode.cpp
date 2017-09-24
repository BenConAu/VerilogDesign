#include "AssignmentNode.h"
#include "ParserContext.h"
#include "ModuleDefinitionNode.h"
#include "DriveDefinitionNode.h"
#include "OutputContext.h"
#include "VariableInfo.h"

AssignmentNode::AssignmentNode(
    ParserContext *pContext, 
    const YYLTYPE &location, 
    ASTNode *pLeft, 
    ASTNode *pRight) : StatementNode(pContext, location)
{
    AddNode(pLeft);
    AddNode(pRight);
}

AssignmentNode::AssignmentNode(
    ParserContext *pContext, 
    const YYLTYPE &location) : StatementNode(pContext, location)
{
}

void AssignmentNode::VerifyNodeImpl()
{
    ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));
    ExpressionNode *pRight = dynamic_cast<ExpressionNode *>(GetChild(1));

    if (!ExpressionNode::EqualType(GetChild(0), GetChild(1)))
    {
        printf("Type %s and type %s are not equal\n", pLeft->GetTypeInfo()->DebugPrint().c_str(), pRight->GetTypeInfo()->DebugPrint().c_str());

        GetContext()->ReportError(GetLocation(), "Assignment must have equal types on each side");
    }

    // No assigning to wires, please
    VariableInfo* pVarInfo = pLeft->IsVariableExpression();
    if (pVarInfo == nullptr || pVarInfo->GetModifier() == TypeModifier::Wire)
    {
        GetContext()->ReportError(GetLocation(), "Not a valid LValue for assignment");
    }

    // Must be not an input
    if (pVarInfo->GetLocationType() == VariableLocationType::Input)
    {
        GetContext()->ReportError(GetLocation(), "Inputs are not valid LValue for assignment");
    }
}

ASTNode* AssignmentNode::DuplicateNodeImpl()
{
    return new AssignmentNode(GetContext(), GetLocation());
}

void AssignmentNode::PostProcessNodeImpl(OutputContext* pContext)
{
    ModuleDefinitionNode *pFunc = GetTypedParent<ModuleDefinitionNode>();
    DriveDefinitionNode *pDrive = GetTypedParent<DriveDefinitionNode>();

    ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));
    ExpressionNode *pRight = dynamic_cast<ExpressionNode *>(GetChild(1));

    std::unique_ptr<ExpressionResult> leftResult(pLeft->TakeResult());
    std::unique_ptr<ExpressionResult> rightResult(pRight->TakeResult());

    //printf("Assignment between these two expressions\n");
    //printf("Left = %s\n", leftResult->DebugPrint().c_str());
    //printf("Right = %s\n", rightResult->DebugPrint().c_str());

    if (leftResult.get() == nullptr || rightResult.get() == nullptr)
    {
        printf("Assignment on node %p between two expressions\n", this);
        GetContext()->DumpTree();
        GetContext()->ReportError(GetLocation(), "Assignment needs a valid expression on each side");
    }

    if (pDrive == nullptr)
    {
        // Regular NBA somewhere
        pContext->OutputLine("%s <= %s;", leftResult->GetString().c_str(), rightResult->GetString().c_str());
    }
    else
    {
        // Part of an initial block, get the timing information
        pContext->OutputLine(
            "# %d %s = %s;", 
            pDrive->GetDelta(),
            leftResult->GetString().c_str(), 
            rightResult->GetString().c_str());
    }
}
