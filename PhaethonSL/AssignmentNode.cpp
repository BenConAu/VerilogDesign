#include "AssignmentNode.h"
#include "PSLCompilerContext.h"
#include "RegisterWrapper.h"

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

void AssignmentNode::PostProcessNodeImpl()
{
    ExpressionNode* pLeft = dynamic_cast<ExpressionNode*>(GetChild(0));
    ExpressionNode* pRight = dynamic_cast<ExpressionNode*>(GetChild(1));

    ExpressionResult leftResult = pLeft->GetResult();
    ExpressionResult rightResult = pRight->GetResult();

    // Figure out what kind of LHS expression we have
    switch (leftResult._type)
    {
        case ResultType::Register:
            // The great thing about registers is that everything can move into them
            printf("mov r%d, %s\n", leftResult._regIndex, rightResult.GetOperand(GetContext()).c_str());
            break;

        case ResultType::Memory:
        case ResultType::MemoryOffset:
            {
                // Need to make a register for this to work
                RegisterWrapper wrapper(GetContext(), rightResult);

                printf("mov %s, r%d\n", leftResult.GetOperand(GetContext()).c_str(), rightResult._regIndex);
            }

            break;

        default:
            throw "Unexpected LHS expression result";
    }
}

ExpressionResult AssignmentNode::CalcResultImpl()
{
    throw "AssignmentNode is not an lvalue";
}
