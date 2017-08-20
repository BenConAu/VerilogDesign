#include "AssignmentNode.h"
#include "VSharpCompilerContext.h"
#include "ModuleDeclaratorNode.h"
#include "DriveDefinitionNode.h"

AssignmentNode::AssignmentNode(
    PSLCompilerContext *pContext, 
    const YYLTYPE &location, 
    ASTNode *pLeft, 
    ASTNode *pRight) : ASTNode(pContext)
{
    _location = location;

    AddNode(pLeft);
    AddNode(pRight);
}

void AssignmentNode::VerifyNodeImpl()
{
    if (!ExpressionNode::EqualType(GetChild(0), GetChild(1)))
    {
        ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));
        ExpressionNode *pRight = dynamic_cast<ExpressionNode *>(GetChild(1));

        printf("Type %s and type %s are not equal\n", pLeft->GetTypeInfo()->DebugPrint().c_str(), pRight->GetTypeInfo()->DebugPrint().c_str());

        GetContext()->ReportError(_location, "Assignment must have equal types on each side");
    }
}

void AssignmentNode::PostProcessNodeImpl()
{
    ModuleDeclaratorNode *pFunc = GetTypedParent<ModuleDeclaratorNode>();
    DriveDefinitionNode *pDrive = GetTypedParent<DriveDefinitionNode>();

    ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));
    ExpressionNode *pRight = dynamic_cast<ExpressionNode *>(GetChild(1));
    
    std::unique_ptr<ExpressionResult> leftResult(pLeft->TakeResult());
    std::unique_ptr<ExpressionResult> rightResult(pRight->TakeResult());

    if (leftResult.get() == nullptr || rightResult.get() == nullptr)
    {
        GetContext()->ReportError(_location, "Assignment needs a valid expression on each side");
    }

    //leftResult->DebugPrint();
    //rightResult->DebugPrint();

    if (pDrive == nullptr)
    {
        // Regular NBA somewhere
        GetContext()->OutputLine("%s <= %s;", leftResult->GetString().c_str(), rightResult->GetString().c_str());
    }
    else
    {
        // Part of an initial block, get the timing information
        GetContext()->OutputLine(
            "# %d %s = %s;", 
            pDrive->GetDelta(),
            leftResult->GetString().c_str(), 
            rightResult->GetString().c_str());
    }
}
