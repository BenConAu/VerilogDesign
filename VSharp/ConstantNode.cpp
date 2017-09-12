#include "ConstantNode.h"
#include "VSharpCompilerContext.h"
#include "VSharp.tab.h"
#include "RegisterTypeInfo.h"
#include <string.h>

ConstantNode::ConstantNode(
    ParserContext *pContext, 
    const YYLTYPE& location, 
    const UIntConstant& v) : ExpressionNode(pContext, location)
{
    _value = v;
}

ASTNode* ConstantNode::DuplicateNodeImpl()
{
    return new ConstantNode(GetContext(), GetLocation(), _value);
}

unsigned int ConstantNode::GetUInt()
{
    return _value._value;
}

bool ConstantNode::IsConstant() const 
{ 
    return true; 
}

void ConstantNode::VerifyNodeImpl()
{
    SetType(GetContext()->GetTypeCollection()->GetRegisterType(_value._bitLength));
}

ExpressionResult *ConstantNode::CalculateResult()
{
    //printf("Creating result for constant of width %u and value %u\n", _value._bitLength, _value._value);

    if (_value._bitLength == 1)
    {
        const char* boolResult = (_value._value == 1) ? "1'b1" : "1'b0";

        return new ExpressionResult(boolResult, (_value._value == 1));
    }
    else
    {
        char result[100];
        sprintf(result, "%u'd%u", _value._bitLength, _value._value);
    
        return new ExpressionResult(result);
    }
}
