#include "OperatorNode.h"
#include "ModuleDefinitionNode.h"
#include "VSharp.tab.h"

OperatorInfo OperatorNode::_opTable[] = {
    { Operator::Multiply,    "*",    ResultTypeMethod::Both },
    { Operator::Add,         "+",    ResultTypeMethod::Both },
    { Operator::Subtract,    "-",    ResultTypeMethod::Both },
    { Operator::ShiftLeft,   "<<",   ResultTypeMethod::Both },
    { Operator::ShiftRight,  ">>",   ResultTypeMethod::Both },
    { Operator::BitwiseXor,  "^",    ResultTypeMethod::Both },
    { Operator::Equal,       "==",   ResultTypeMethod::Bool },
    { Operator::NotEqual,    "!=",   ResultTypeMethod::Bool },
    { Operator::LessThan,    "<",    ResultTypeMethod::Bool },
    { Operator::GreaterThan, ">",    ResultTypeMethod::Bool },
    { Operator::LogicalAnd,  "&&",   ResultTypeMethod::Bool },
    { Operator::LogicalOr,   "||",   ResultTypeMethod::Bool },
};

ASTNode* OperatorNode::DuplicateNodeImpl()
{
    return new OperatorNode(GetContext(), GetLocation(), _op, _opInfo);
}

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
                pResultType = GetContext()->_typeCollection.GetRegisterType(1);
            }
            else
            {
                GetContext()->ReportError(GetLocation(), "Unknown type for result of binary operation");
            }

            break;
        }
    }

    SetType(pResultType);
}

ExpressionResult *OperatorNode::CalculateResult()
{
    //printf("Operation on node %p between two expressions\n", this);
    //GetContext()->DumpTree();

    ModuleDefinitionNode *pFunc = GetTypedParent<ModuleDefinitionNode>();

    ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));
    ExpressionNode *pRight = dynamic_cast<ExpressionNode *>(GetChild(1));
    
    std::unique_ptr<ExpressionResult> leftResult(pLeft->TakeResult());
    std::unique_ptr<ExpressionResult> rightResult(pRight->TakeResult());

    //printf("Left = %s\n", leftResult != nullptr ? leftResult->DebugPrint().c_str() : "null result!");
    //printf("Right = %s\n", leftResult != nullptr ? rightResult->DebugPrint().c_str() : "null result!");

    if (leftResult.get() == nullptr || rightResult.get() == nullptr)
    {
        //GetContext()->ReportError(GetLocation(), "Operator needs a valid expression on each side");
        return new ExpressionResult("OperatorNull");
    }

    char result[1024];
    sprintf(
        result, 
        "%s %s %s", 
        leftResult->GetString().c_str(),
        _opInfo._pszVerilog,
        rightResult->GetString().c_str());

    return new ExpressionResult(result);
}
