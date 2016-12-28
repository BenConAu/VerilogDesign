#include "AssignmentNode.h"
#include "PSLCompilerContext.h"
#include "RegisterWrapper.h"
#include "FunctionDeclaratorNode.h"
#include "../PhaethonObjWriter/ObjWriter.h"
#include "PSL.tab.h"

AssignmentNode::AssignmentNode(PSLCompilerContext *pContext, ASTNode *pLeft, ASTNode *pRight) : ASTNode(pContext)
{
    AddNode(pLeft);
    AddNode(pRight);
}

void AssignmentNode::VerifyNodeImpl()
{
    if (!ExpressionNode::EqualType(GetChild(0), GetChild(1)))
    {
        ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));
        ExpressionNode *pRight = dynamic_cast<ExpressionNode *>(GetChild(1));

        PointerTypeInfo *pLeftType = dynamic_cast<PointerTypeInfo *>(pLeft->GetTypeInfo());
        PointerTypeInfo *pRightType = dynamic_cast<PointerTypeInfo *>(pRight->GetTypeInfo());

        if (pLeftType != nullptr &&
            pRightType != nullptr &&
            pLeftType->GetBaseType()->GetTypeClass() == TypeClass::Basic &&
            dynamic_cast<BasicTypeInfo *>(pLeftType->GetBaseType())->GetTypeToken() == VOID_TOKEN)
        {
            // We can allow void pointers to be on the left if there is another pointer on the right
        }
        else if (
            pLeftType != nullptr &&
            pRightType != nullptr &&
            pRightType->GetBaseType()->GetTypeClass() == TypeClass::Basic &&
            dynamic_cast<BasicTypeInfo *>(pRightType->GetBaseType())->GetTypeToken() == VOID_TOKEN &&
            pRight->IsConstant())
        {
            // We can allow void pointers to be on the right if they are constant
        }
        else
        {
            printf("Type %s and type %s are not equal\n", pLeft->GetTypeInfo()->DebugPrint().c_str(), pRight->GetTypeInfo()->DebugPrint().c_str());

            throw "Assignment must have equal types on each side";
        }
    }
}

void AssignmentNode::PostProcessNodeImpl()
{
    FunctionDeclaratorNode *pFunc = GetTypedParent<FunctionDeclaratorNode>();

    ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));
    ExpressionNode *pRight = dynamic_cast<ExpressionNode *>(GetChild(1));

    std::unique_ptr<ExpressionResult> leftResult(pLeft->TakeResult());
    std::unique_ptr<ExpressionResult> rightResult(pRight->TakeResult());

    if (leftResult.get() == nullptr || rightResult.get() == nullptr)
    {
        throw "Assignment needs a valid expression on each side";
    }

    //leftResult->DebugPrint();
    //rightResult->DebugPrint();

    // Figure out what kind of LHS expression we have
    switch (leftResult->GetOperandType())
    {
    case OperandType::Register:
    {
        // The great thing about registers is that everything can move into them
        GetContext()->OutputMovInstruction(
            leftResult->GetOperands(),
            rightResult->GetOperands());
    }
    break;

    case OperandType::DerefConstant:
    case OperandType::DerefRegisterOffset:
    case OperandType::DerefRegisterIndex:
    {
        // Need to make a register for this to work
        RegisterWrapper wrapper(
            GetContext(),
            pFunc->GetRegCollection(),
            rightResult.get());

        // Push the wrapped register into the memory
        GetContext()->OutputMovInstruction(
            leftResult->GetOperands(),
            wrapper.GetWrapped());

        // Now we have generated code, the temporary register will
        // go out of scope and be returned back.
    }
    break;

    default:
        throw "Unexpected LHS expression result";
    }
}
