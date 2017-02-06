#include "EmitNode.h"
#include "ExpressionNode.h"
#include "RegisterWrapper.h"
#include "FunctionDeclaratorNode.h"

OpCodes::Enum OpCodeFromToken(int token)
{
    switch (token)
    {
    case DOUTR_TOKEN:
        return OpCodes::DoutR;

    case EXECR_TOKEN:
        return OpCodes::ExecR;

    case EXIT_TOKEN:
        return OpCodes::Exit;

    default:
        throw "Unknown opcode";
    }
}

EmitNode::EmitNode(
    PSLCompilerContext *pContext,
    int opCodeToken,
    ASTNode *pExpr) : ASTNode(pContext)
{
    AddNode(pExpr);

    _opCodeToken = opCodeToken;
}

void EmitNode::VerifyNodeImpl()
{
    // TODO: Make sure function name is unique
}

void EmitNode::PostProcessNodeImpl()
{
    FunctionDeclaratorNode *pFunc = GetTypedParent<FunctionDeclaratorNode>();

    if (GetChild(0) != nullptr)
    {
        // The input to the debug is an expression
        ExpressionNode *pChild = dynamic_cast<ExpressionNode *>(GetChild(0));

        std::unique_ptr<ExpressionResult> childResult(pChild->TakeResult());

        // Wrap in a register
        RegisterWrapper wrapper(GetContext(), pFunc->GetRegCollection(), childResult.get());

        GetContext()->OutputInstruction(
            OpCodeFromToken(_opCodeToken),
            wrapper.GetWrapped());
    }
    else
    {
        GetContext()->OutputInstruction(
            OpCodeFromToken(_opCodeToken));
    }
}
