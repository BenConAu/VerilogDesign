#include "AssignmentNode.h"
#include "PSLCompilerContext.h"
#include "ModuleDeclaratorNode.h"
#include "../PhaethonObjWriter/ObjWriter.h"

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
/*    FunctionDeclaratorNode *pFunc = GetTypedParent<FunctionDeclaratorNode>();

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

    // Figure out what kind of LHS expression we have
    switch (leftResult->GetResultType())
    {
    case ExpressionResultType::Register:
    {
        // The great thing about registers is that everything can move into them
        GetContext()->OutputMovInstruction(
            *leftResult.get(),
            *rightResult.get());
    }
    break;

    case ExpressionResultType::DerefConstant:
    case ExpressionResultType::DerefRegisterOffset:
    case ExpressionResultType::DerefRegisterIndex:
    {
        // Need to make a register for this to work
        RegisterWrapper wrapper(
            GetContext(),
            pFunc->GetRegCollection(),
            rightResult.get());

        // Push the wrapped register into the memory
        GetContext()->OutputMovInstruction(
            *leftResult.get(),
            wrapper.GetWrapped());

        // Now we have generated code, the temporary register will
        // go out of scope and be returned back.
    }
    break;

    default:
        GetContext()->ReportError(_location, "Unexpected LHS expression result");
    }*/
}
