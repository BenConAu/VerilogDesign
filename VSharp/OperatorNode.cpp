#include "OperatorNode.h"
#include "ModuleDefinitionNode.h"
#include "VSharp.tab.h"

OperatorInfo OperatorNode::_opTable[] = {
    { Operator::Multiply,           "*",    ResultTypeMethod::Both },
    { Operator::Divide,             "/",    ResultTypeMethod::Both },
    { Operator::Add,                "+",    ResultTypeMethod::Both },
    { Operator::Subtract,           "-",    ResultTypeMethod::Both },
    { Operator::ShiftLeft,          "<<",   ResultTypeMethod::Both },
    { Operator::ShiftRight,         ">>",   ResultTypeMethod::Both },
    { Operator::BitwiseXor,         "^",    ResultTypeMethod::Both },
    { Operator::BitwiseOr,          "|",    ResultTypeMethod::Both },
    { Operator::Equal,              "==",   ResultTypeMethod::Bool },
    { Operator::NotEqual,           "!=",   ResultTypeMethod::Bool },
    { Operator::LessThan,           "<",    ResultTypeMethod::Bool },
    { Operator::GreaterThan,        ">",    ResultTypeMethod::Bool },
    { Operator::LessThanEqual,      "<=",   ResultTypeMethod::Bool },
    { Operator::GreaterThanEqual,   ">=",   ResultTypeMethod::Bool },
    { Operator::LogicalAnd,         "&&",   ResultTypeMethod::Bool },
    { Operator::LogicalOr,          "||",   ResultTypeMethod::Bool },
};

ASTNode* OperatorNode::DuplicateNodeImpl(FunctionExpandType type)
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
                pResultType = GetContext()->GetTypeCollection()->GetRegisterType(1);
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

bool OperatorNode::ConstEvaluate(UIntConstant* pVal)
{
    ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));
    ExpressionNode *pRight = dynamic_cast<ExpressionNode *>(GetChild(1));
        
    UIntConstant leftConstant;
    UIntConstant rightConstant;
    if (pLeft->ConstEvaluate(&leftConstant) && pRight->ConstEvaluate(&rightConstant))
    {
        if (leftConstant._bitLength != rightConstant._bitLength)
        {
            // For now, you have to be picky about size of constant expressions
            GetContext()->ReportError(GetLocation(), "Incompatible sizing for constant evaluation");            
        }

        // Set size of result
        pVal->_bitLength = leftConstant._bitLength;

        switch (_op)
        {
            case Operator::Subtract:
                pVal->_value = leftConstant._value - rightConstant._value;
                break;

            case Operator::Add:
                pVal->_value = leftConstant._value + rightConstant._value;
                break;

            case Operator::Multiply:
                pVal->_value = leftConstant._value * rightConstant._value;
                break;

            case Operator::Divide:
                pVal->_value = leftConstant._value / rightConstant._value;
                break;

            case Operator::Equal:
                pVal->_value = (leftConstant._value == rightConstant._value) ? 1 : 0;
                pVal->_bitLength = 1;
                break;

            default:
                //GetContext()->ReportError(GetLocation(), "Unsupported operator in constant expression");
                // Don't know how to do this yet
                return false;
        }

        return true;
    }

    return false;
}
