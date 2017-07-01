#include "EmitNode.h"
#include "ExpressionNode.h"
#include "FunctionDeclaratorNode.h"

EmitNode::EmitNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    OpCode opCode,
    ASTNode *pExpr1,
    ASTNode *pExpr2) : ASTNode(pContext)
{
    AddNode(pExpr1);
    AddNode(pExpr2);

    _opCode = opCode;
    _location = location;
}

void EmitNode::VerifyNodeImpl()
{
    // TODO: Make sure function name is unique
}

void EmitNode::PostProcessNodeImpl()
{
    /*FunctionDeclaratorNode *pFunc = GetTypedParent<FunctionDeclaratorNode>();

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

            switch (_opCode)
            {
            case OpCode::MovRC:
                if (childResult2->GetResultType() != ExpressionResultType::Constant)
                {
                    GetContext()->ReportError(_location, "2nd arg for movrc has to be a constant");
                }
                break;

            case OpCode::MovRR:
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
                _opCode,
                wrapper1.GetWrapped(),
                *(childResult2.get()));
        }
        else
        {
            GetContext()->OutputInstruction(
                _opCode,
                wrapper1.GetWrapped());
        }
    }
    else
    {
        GetContext()->OutputInstruction(
            _opCode);
    }*/
}
