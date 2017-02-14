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

    case MOVRC_TOKEN:
        return OpCodes::MovRC;

    case MOVRR_TOKEN:
        return OpCodes::MovRR;

    default:
        throw "Unknown opcode";
    }
}

EmitNode::EmitNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    int opCodeToken,
    ASTNode *pExpr1,
    ASTNode *pExpr2) : ASTNode(pContext)
{
    AddNode(pExpr1);
    AddNode(pExpr2);

    _opCodeToken = opCodeToken;
    _location = location;
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
        ExpressionNode *pChild1 = dynamic_cast<ExpressionNode *>(GetChild(0));
        std::unique_ptr<ExpressionResult> childResult1(pChild1->TakeResult());

        // Wrap in a register (all supported instructions take registers)
        RegisterWrapper wrapper1(GetContext(), pFunc->GetRegCollection(), childResult1.get());

        if (GetChild(1) != nullptr)
        {
            ExpressionNode *pChild2 = dynamic_cast<ExpressionNode *>(GetChild(1));
            std::unique_ptr<ExpressionResult> childResult2(pChild2->TakeResult());

            OpCodes::Enum opCode = OpCodeFromToken(_opCodeToken);

            switch (opCode)
            {
            case OpCodes::MovRC:
                if (childResult2->GetResultType() != ExpressionResultType::Constant)
                {
                    GetContext()->ReportError(_location, "2nd arg for movrc has to be a constant");
                }
                break;

            case OpCodes::MovRR:
                if (childResult2->GetResultType() != ExpressionResultType::Register)
                {
                    GetContext()->ReportError(_location, "2nd arg for movrr has to be a constant");
                }
                break;

            default:
                GetContext()->ReportError(_location, "Unknown opcode for __emit");
                break;
            }

            GetContext()->OutputInstruction(
                opCode,
                wrapper1.GetWrapped(),
                *(childResult2.get()));
        }
        else
        {
            GetContext()->OutputInstruction(
                OpCodeFromToken(_opCodeToken),
                wrapper1.GetWrapped());
        }
    }
    else
    {
        GetContext()->OutputInstruction(
            OpCodeFromToken(_opCodeToken));
    }
}
