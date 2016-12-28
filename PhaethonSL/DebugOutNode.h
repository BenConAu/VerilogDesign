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

        std::unique_ptr<ExpressionResult> childResult(pChild->TakeResult());

        // Wrap in a register
        RegisterWrapper wrapper(GetContext(), pFunc->GetRegCollection(), childResult.get());

        GetContext()->OutputInstruction(
            OpCodes::DoutR,
            wrapper.GetWrapped());
    }

    const char *GetDebugName() override { return "DebugOutNode"; }    
};