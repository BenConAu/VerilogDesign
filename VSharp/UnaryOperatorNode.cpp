#include "UnaryOperatorNode.h"
#include "ModuleDeclaratorNode.h"
#include "VSharp.tab.h"

OperatorInfo UnaryOperatorNode::_opTable[] = {
    { Operator::Negate,  "-", ResultTypeMethod::Both },
};

void UnaryOperatorNode::VerifyNodeImpl()
{
    // The inputs to the multiply must be expressions themselves. Ideally this part
    // could be factored into the expression class itself.
    ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));

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
                throw "This is a boolean result";
                //pResultType = GetContext()->_typeCollection.GetBasicType(BOOL_TOKEN);
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

ExpressionResult *UnaryOperatorNode::CalculateResult()
{
/*    FunctionDeclaratorNode *pFunc = GetTypedParent<FunctionDeclaratorNode>();

    // The inputs to the multiply must be expressions themselves. Ideally this part
    // could be factored into the expression class itself.
    ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));

    // Calculate the result of each of the inputs so that they will go out of scope
    // after consumption. The result holds the location of the expression result
    // (either a register or memory or such) as well as the lifetime of the usage
    // of the resources it needs (if any).
    std::unique_ptr<ExpressionResult> leftResult(pLeft->TakeResult());

    // Multiplication only works with registers so we make wrappers
    RegisterWrapper leftWrap(GetContext(), pFunc->GetRegCollection(), leftResult.get());

    int bothType = -1;
    if (TypeInfo::IsFloat(pLeft->GetTypeInfo()))
    {
        bothType = FLOAT_TOKEN;
    }
    else if (TypeInfo::IsNonFloat(pLeft->GetTypeInfo()))
    {
        bothType = WORD_TOKEN;
    }
    else
    {
        throw "Invalid arguments to binary operator";
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
        throw "Unknown opcode for binary operation";
    }

    // Get register for our result
    RegIndex resultIndex = pFunc->GetRegCollection()->AllocateRegister();
    Operand resultOperand(resultIndex);

    GetContext()->OutputInstruction(
        opCode,
        resultOperand,
        leftWrap.GetWrapped());

    //printf("Operator with result of type = %s\n", GetTypeInfo()->DebugPrint().c_str());
    //printf("Making result for %p with register collection %p\n", this, pFunc->GetRegCollection());
    return new ExpressionResult(resultOperand, pFunc->GetRegCollection());*/
    return nullptr;
}
