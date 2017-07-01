#include "OperatorNode.h"
#include "ModuleDeclaratorNode.h"
#include "VSharp.tab.h"

OperatorInfo OperatorNode::_opTable[] = {
    {Operator::Multiply,    OpCode::Unknown,   OpCode::FmulRRR, ResultTypeMethod::Both},
    {Operator::Add,         OpCode::AddRRR,    OpCode::FaddRRR, ResultTypeMethod::Both},
    {Operator::Subtract,    OpCode::SubRRR,    OpCode::Unknown, ResultTypeMethod::Both},
    {Operator::ShiftLeft,   OpCode::ShlRRR,    OpCode::Unknown, ResultTypeMethod::Both},
    {Operator::ShiftRight,  OpCode::ShrRRR,    OpCode::Unknown, ResultTypeMethod::Both},
    {Operator::Equal,       OpCode::CmpERRR,   OpCode::Unknown, ResultTypeMethod::Bool},
    {Operator::NotEqual,    OpCode::CmpNeRRR,  OpCode::Unknown, ResultTypeMethod::Bool},
    {Operator::LessThan,    OpCode::CmpLtRRR,  OpCode::Unknown, ResultTypeMethod::Bool},
    {Operator::GreaterThan, OpCode::CmpGtRRR,  OpCode::Unknown, ResultTypeMethod::Bool},
};

void OperatorNode::VerifyNodeImpl()
{
    // The inputs to the multiply must be expressions themselves. Ideally this part
    // could be factored into the expression class itself.
    ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));
    ExpressionNode *pRight = dynamic_cast<ExpressionNode *>(GetChild(1));

    TypeInfo *pResultType = nullptr;
    for (int i = 0; i < sizeof(_opTable) / sizeof(_opTable[0]); i++)
    {
        if (_opTable[i]._operator == _op)
        {
            _opInfo = _opTable[i];

            // Figure out type
            if (_opTable[i]._resultType == ResultTypeMethod::Both)
            {
                pResultType = pLeft->GetTypeInfo();
            }
            else if (_opTable[i]._resultType == ResultTypeMethod::Bool)
            {
                pResultType = GetContext()->_typeCollection.GetBasicType(BOOL_TOKEN);
            }
            else
            {
                GetContext()->ReportError(_location, "Unknown type for result of binary operation");
            }

            break;
        }
    }

    SetType(pResultType);
}

ExpressionResult *OperatorNode::CalculateResult()
{
/*    FunctionDeclaratorNode *pFunc = GetTypedParent<FunctionDeclaratorNode>();

    // The inputs to the multiply must be expressions themselves. Ideally this part
    // could be factored into the expression class itself.
    ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));
    ExpressionNode *pRight = dynamic_cast<ExpressionNode *>(GetChild(1));

    // Calculate the result of each of the inputs so that they will go out of scope
    // after consumption. The result holds the location of the expression result
    // (either a register or memory or such) as well as the lifetime of the usage
    // of the resources it needs (if any).
    std::unique_ptr<ExpressionResult> leftResult(pLeft->TakeResult());
    std::unique_ptr<ExpressionResult> rightResult(pRight->TakeResult());

    // Multiplication only works with registers so we make wrappers
    RegisterWrapper leftWrap(GetContext(), pFunc->GetRegCollection(), leftResult.get());
    RegisterWrapper rightWrap(GetContext(), pFunc->GetRegCollection(), rightResult.get());

    int bothType = -1;
    if (TypeInfo::IsFloat(pLeft->GetTypeInfo()) && TypeInfo::IsFloat(pRight->GetTypeInfo()))
    {
        bothType = FLOAT_TOKEN;
    }
    else if (TypeInfo::IsNonFloat(pLeft->GetTypeInfo()) && TypeInfo::IsNonFloat(pRight->GetTypeInfo()))
    {
        bothType = WORD_TOKEN;
    }
    else
    {
        GetContext()->ReportError(_location, "Invalid arguments to binary operator");
    }

    // Figure out opCode
    OpCode opCode = OpCode::Unknown;
    if (bothType == FLOAT_TOKEN)
    {
        opCode = _opInfo._opCodeFloat;
    }
    else if (bothType == WORD_TOKEN)
    {
        opCode = _opInfo._opCodeWord;
    }

    if (opCode == OpCode::Unknown)
    {
        GetContext()->ReportError(_location, "Unknown opcode for binary operation");
    }

    // Get register for our result
    RegIndex resultIndex = pFunc->GetRegCollection()->AllocateRegister();
    Operand resultOperand(resultIndex);

    GetContext()->OutputInstruction(
        opCode,
        resultOperand,
        leftWrap.GetWrapped(),
        rightWrap.GetWrapped());

    //printf("Operator with result of type = %s\n", GetTypeInfo()->DebugPrint().c_str());
    //printf("Making result for %p with register collection %p\n", this, pFunc->GetRegCollection());
    return new ExpressionResult(resultOperand, pFunc->GetRegCollection());*/
    return nullptr;
}
