#include "TransitionNode.h"
#include "ExpressionNode.h"
#include "ModuleDeclaratorNode.h"

void TransitionNode::PostProcessNodeImpl()
{
    // What function are we returning from
/*    FunctionDeclaratorNode *pFunc = GetTypedParent<FunctionDeclaratorNode>();

    if (GetChild(0) != nullptr)
    {
        // We have some expression inside us that we are returning
        ExpressionNode *pChild = dynamic_cast<ExpressionNode *>(GetChild(0));

        // Get the result of that
        std::unique_ptr<ExpressionResult> childResult(pChild->TakeResult());

        // Convention is to store the result in r0, so move it there if it
        // is not there already.
        if (childResult->GetResultType() != ExpressionResultType::Register ||
            childResult->GetRegIndex() != 0)
        {
            GetContext()->OutputMovInstruction(
                Operand((RegIndex)0),
                *childResult.get());
        }
    }

    GetContext()->OutputInstruction(OpCode::RRet);*/
}
