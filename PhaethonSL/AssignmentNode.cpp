#include "AssignmentNode.h"
#include "PSLCompilerContext.h"
#include "RegisterWrapper.h"
#include "FunctionDeclaratorNode.h"
#include "../PhaethonObjWriter/ObjWriter.h"

AssignmentNode::AssignmentNode(PSLCompilerContext* pContext, ASTNode* pLeft, ASTNode* pRight) : ASTNode(pContext)
{
    AddNode(pLeft);
    AddNode(pRight);
}

void AssignmentNode::VerifyNodeImpl()
{
    ExpressionNode* pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));

    // TODO: Check types on left and right match
}

void AssignmentNode::PostProcessNodeImpl()
{
    FunctionDeclaratorNode* pFunc = GetTypedParent<FunctionDeclaratorNode>();

    ExpressionNode* pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));
    ExpressionNode* pRight = dynamic_cast<ExpressionNode *>(GetChild(1));

    std::unique_ptr<ExpressionResult> leftResult(pLeft->CalculateResult());
    std::unique_ptr<ExpressionResult> rightResult(pRight->CalculateResult());

    //leftResult->DebugPrint();
    //rightResult->DebugPrint();

    // Figure out what kind of LHS expression we have
    switch (leftResult.get()->_operand.GetType())
    {
    case OperandType::Register:
    {
        // The great thing about registers is that everything can move into them
        GetContext()->OutputMovInstruction(
            leftResult.get()->_operand,
            rightResult.get()->_operand
            );
    }
    break;

    case OperandType::DerefConstant:
    case OperandType::DerefRegisterOffset:
    {
        // Need to make a register for this to work
        RegisterWrapper wrapper(
            GetContext(), 
            pFunc->GetRegCollection(), 
            rightResult.get()->_operand
            );

        // Push the wrapped register into the memory
        GetContext()->OutputMovInstruction(
            leftResult.get()->_operand,
            wrapper.GetWrapped()
            );

        // Now we have generated code, the temporary register will
        // go out of scope and be returned back.
    }
    break;

    default:
        throw "Unexpected LHS expression result";
    }
}
