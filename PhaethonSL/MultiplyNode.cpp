#include "MultiplyNode.h"
#include "FunctionDeclaratorNode.h"

void MultiplyNode::PostProcessNodeImpl()
{
    FunctionDeclaratorNode* pFunc = GetTypedParent<FunctionDeclaratorNode>();

    ExpressionNode* pLeft = dynamic_cast<ExpressionNode*>(GetChild(0));
    ExpressionNode* pRight = dynamic_cast<ExpressionNode*>(GetChild(1));

    RegisterWrapper leftWrap(GetContext(), pFunc->GetRegCollection(), pLeft->GetResult());
    RegisterWrapper rightWrap(GetContext(), pFunc->GetRegCollection(), pRight->GetResult());

    // Get the register for the left side
    RegIndex leftIndex = leftWrap.GetWrapped()._regIndex;

    // Right side is either a constant or another register
    RegIndex rightIndex = rightWrap.GetWrapped()._regIndex;

    // Get register for our result
    RegIndex resultIndex = GetResult()._regIndex;

    // print out our code
    printf("mov r%d, r%d\n", resultIndex, leftIndex);
    printf("mul r%d, r%d\n", resultIndex, rightIndex);
}

ExpressionResult MultiplyNode::CalcResultImpl()
{
    FunctionDeclaratorNode* pFunc = GetTypedParent<FunctionDeclaratorNode>();

    return ExpressionResult(pFunc->GetRegCollection()->AllocateRegister());
}
