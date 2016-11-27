#pragma once

#include "PSLCompilerContext.h"
#include "ASTNode.h"

class DebugOutNode : public ASTNode
{
  public:
    DebugOutNode(
        PSLCompilerContext *pContext,
        ASTNode *pExpr) : ASTNode(pContext)
    {
        AddNode(pExpr);
    }

    void VerifyNodeImpl() override
    {
        // TODO: Make sure function name is unique
    }

    void PostProcessNodeImpl() override
    {
        FunctionDeclaratorNode *pFunc = GetTypedParent<FunctionDeclaratorNode>();

        // The input to the debug is an expression
        ExpressionNode *pChild = dynamic_cast<ExpressionNode *>(GetChild(0));

        // Calculate the result
        std::unique_ptr<ExpressionResult> childResult(pChild->CalculateResult());

        // Wrap in a register
        RegisterWrapper wrapper(GetContext(), pFunc->GetRegCollection(), childResult.get()->_operand);

        GetContext()->OutputInstruction(
            OpCodes::DoutR,
            wrapper.GetWrapped());
    }
};