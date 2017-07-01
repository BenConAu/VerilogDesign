#include "KnownConstantNode.h"
#include "PSLCompilerContext.h"
#include "VSharp.tab.h"
#include "BasicTypeInfo.h"

KnownConstantNode::KnownConstantNode(PSLCompilerContext* pContext, KnownConstants known) : ExpressionNode(pContext)
{
    _known = known;
}

bool KnownConstantNode::IsConstant() const 
{ 
    return true; 
}

void KnownConstantNode::VerifyNodeImpl()
{
    TypeInfo *pTypeInfo = nullptr;

    switch (_known)
    {
    case KnownConstants::DataSegmentEnd:
        pTypeInfo = GetContext()->_typeCollection.GetPointerType(nullptr);
        break;

    default:
        throw "Unknown type so cannot calculate result";
    }

    SetType(pTypeInfo);
}

ExpressionResult *KnownConstantNode::CalculateResult()
{
    return new ExpressionResult(Operand(_known));
}
