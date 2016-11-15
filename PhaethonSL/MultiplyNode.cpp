#include "MultiplyNode.h"
#include "FunctionDeclaratorNode.h"

ExpressionResult* MultiplyNode::CalculateResult()
{
    FunctionDeclaratorNode* pFunc = GetTypedParent<FunctionDeclaratorNode>();

    // The inputs to the multiply must be expressions themselves. Ideally this part
    // could be factored into the expression class itself.
    ExpressionNode* pLeft = dynamic_cast<ExpressionNode*>(GetChild(0));
    ExpressionNode* pRight = dynamic_cast<ExpressionNode*>(GetChild(1));

    // Calculate the result of each of the inputs so that they will go out of scope
    // after consumption. The result holds the location of the expression result
    // (either a register or memory or such) as well as the lifetime of the usage
    // of the resources it needs (if any).
    std::unique_ptr<ExpressionResult> leftResult(pLeft->CalculateResult());
    std::unique_ptr<ExpressionResult> rightResult(pRight->CalculateResult());

    // Multiplication only works with registers so we make wrappers
    RegisterWrapper leftWrap(GetContext(), pFunc->GetRegCollection(), leftResult.get()->_operand);
    RegisterWrapper rightWrap(GetContext(), pFunc->GetRegCollection(), rightResult.get()->_operand);

    // Get the register for the left side
    RegIndex leftIndex = leftWrap.GetWrapped()._regIndex;

    // Right side is either a constant or another register
    RegIndex rightIndex = rightWrap.GetWrapped()._regIndex;

    // Get register for our result
    RegIndex resultIndex = pFunc->GetRegCollection()->AllocateRegister();
    Operand resultOperand(resultIndex);

    // print out our code
    printf("mov r%d, r%d\n", resultIndex, leftIndex);
    printf("mul r%d, r%d\n", resultIndex, rightIndex);

    return new ExpressionResult(resultOperand, pFunc->GetRegCollection());
}
