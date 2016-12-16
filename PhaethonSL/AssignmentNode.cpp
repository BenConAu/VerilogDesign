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
    ExpressionNode* pRight = dynamic_cast<ExpressionNode *>(GetChild(0));

    TypeInfo* pLeftType = pLeft->GetTypeInfo();
    TypeInfo* pRightType = pRight->GetTypeInfo();

    if (!pLeftType->EqualType(pRightType))
    {
        throw "Assignment must have equal types on each side";
    }
}

void AssignmentNode::PostProcessNodeImpl()
{
    FunctionDeclaratorNode* pFunc = GetTypedParent<FunctionDeclaratorNode>();

    ExpressionNode* pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));
    ExpressionNode* pRight = dynamic_cast<ExpressionNode *>(GetChild(1));

    std::unique_ptr<ExpressionResult> leftResult(pLeft->TakeResult());
    std::unique_ptr<ExpressionResult> rightResult(pRight->TakeResult());

    if (leftResult.get() == nullptr || rightResult.get() == nullptr)
    {
        throw "Assignment needs a valid expression on each side";
    }

    //leftResult->DebugPrint();
    //rightResult->DebugPrint();

    // Figure out what kind of LHS expression we have
    switch (leftResult->_operand.GetType())
    {
    case OperandType::Register:
    {
        // The great thing about registers is that everything can move into them
        GetContext()->OutputMovInstruction(
            leftResult->_operand,
            rightResult->_operand
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
            rightResult->_operand
            );

        // Push the wrapped register into the memory
        GetContext()->OutputMovInstruction(
            leftResult->_operand,
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
