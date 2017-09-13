#include "UnaryOperatorNode.h"
#include "ModuleDefinitionNode.h"
#include "VSharp.tab.h"

OperatorInfo UnaryOperatorNode::_opTable[] = {
    { Operator::Negate,     "-",    ResultTypeMethod::Both },
    { Operator::LogicalNot, "!",    ResultTypeMethod::Both },
};

UnaryOperatorNode::UnaryOperatorNode(
    ParserContext *pContext, 
    const YYLTYPE &location, 
    ASTNode *pLeft, 
    Operator op) : ExpressionNode(pContext, location)
{
    AddNode(pLeft);
    _op = op;
}

UnaryOperatorNode::UnaryOperatorNode(
    ParserContext *pContext, 
    const YYLTYPE &location,
    Operator op,
    OperatorInfo opInfo) : ExpressionNode(pContext, location)
{
    _op = op;
    _opInfo = opInfo;
}
  
ASTNode* UnaryOperatorNode::DuplicateNodeImpl()
{
    return new UnaryOperatorNode(GetContext(), GetLocation(), _op, _opInfo);
}

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
                //pResultType = GetContext()->GetTypeCollection()->GetBasicType(BOOL_TOKEN);
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
    ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));    
    std::unique_ptr<ExpressionResult> leftResult(pLeft->TakeResult());

    //printf("Left = %s\n", leftResult != nullptr ? leftResult->DebugPrint().c_str() : "null result!");
    //printf("Right = %s\n", leftResult != nullptr ? rightResult->DebugPrint().c_str() : "null result!");

    char result[1024];
    sprintf(
        result, 
        "%s%s", 
        _opInfo._pszVerilog,
        leftResult->GetString().c_str());

    return new ExpressionResult(result);
}
