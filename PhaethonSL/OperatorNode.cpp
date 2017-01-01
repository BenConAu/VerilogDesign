#include "OperatorNode.h"
#include "FunctionDeclaratorNode.h"
#include "PSL.tab.h"

OperatorInfo OperatorNode::_opTable[] = {
    {Operator::Multiply,    OpCodes::Unknown,   OpCodes::FmulRRR, ResultTypeMethod::Both},
    {Operator::Add,         OpCodes::AddRRR,    OpCodes::FaddRRR, ResultTypeMethod::Both},
    {Operator::Subtract,    OpCodes::SubRRR,    OpCodes::Unknown, ResultTypeMethod::Both},
    {Operator::ShiftLeft,   OpCodes::ShlRRR,    OpCodes::Unknown, ResultTypeMethod::Both},
    {Operator::ShiftRight,  OpCodes::ShrRRR,    OpCodes::Unknown, ResultTypeMethod::Both},
    {Operator::Equal,       OpCodes::CmpERRR,   OpCodes::Unknown, ResultTypeMethod::Bool},
    {Operator::NotEqual,    OpCodes::CmpNeRRR,  OpCodes::Unknown, ResultTypeMethod::Bool},
    {Operator::LessThan,    OpCodes::CmpLtRRR,  OpCodes::Unknown, ResultTypeMethod::Bool},
    {Operator::GreaterThan, OpCodes::CmpGtRRR,  OpCodes::Unknown, ResultTypeMethod::Bool},
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
                throw "Unknown type for result of binary operation";
            }

            break;
        }
    }

    SetType(pResultType);
}

ExpressionResult *OperatorNode::CalculateResult()
{
    FunctionDeclaratorNode *pFunc = GetTypedParent<FunctionDeclaratorNode>();

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
        throw "Invalid arguments to binary operator";
    }

    // Figure out opCode
    OpCodes::Enum opCode = OpCodes::Unknown;
    if (bothType == FLOAT_TOKEN)
    {
        opCode = _opInfo._opCodeFloat;
    }
    else if (bothType == WORD_TOKEN)
    {
        opCode = _opInfo._opCodeWord;
    }

    if (opCode == OpCodes::Unknown)
    {
        throw "Unknown opcode for binary operation";
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
    return new ExpressionResult(resultOperand, pFunc->GetRegCollection());
}
