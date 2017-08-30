#include "BitSelectionNode.h"
#include "StructMember.h"
#include "StructTypeInfo.h"
#include "VariableInfo.h"
#include "ModuleDeclaratorNode.h"
#include "VSharpCompilerContext.h"

BitSelectionNode::BitSelectionNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pPostFix,
    const UIntConstant &i1,
    const UIntConstant &i2) : ExpressionNode(pContext, location)
{
    AddNode(pPostFix);

    _i1 = i1._value;
    _i2 = i2._value;
}

void BitSelectionNode::VerifyNodeImpl()
{
    // Must be a uint type
    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(0));

    // Should verify that the type exists
    TypeInfo *pTypeInfo = pExpr->GetTypeInfo();
    RegisterTypeInfo* pRegTypeInfo = dynamic_cast<RegisterTypeInfo*>(pTypeInfo);
    if (pRegTypeInfo == nullptr)
    {
        GetContext()->ReportError(GetLocation(), "Can only select bits from uint types");
    }

    if (_i1 < 0 || _i2 < 0)
    {
        GetContext()->ReportError(GetLocation(), "Must have positive bit indices to select bits");
    }

    if (_i1 >= pRegTypeInfo->GetBitLength() || _i2 >= pRegTypeInfo->GetBitLength())
    {
        GetContext()->ReportError(GetLocation(), "Bit index out of range");
    }

    if (_i1 < _i2)
    {
        GetContext()->ReportError(GetLocation(), "Bit indices out of order");
    }

    SetType(GetContext()->_typeCollection.GetRegisterType(_i1 - _i2 + 1));
}

ExpressionResult *BitSelectionNode::CalculateResult()
{
    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(0));
    std::unique_ptr<ExpressionResult> exprResult(pExpr->TakeResult());

    char result[1024];
    sprintf(
        result, 
        "%s[%d:%d]", 
        exprResult->GetString().c_str(),
        _i1,
        _i2);

    return new ExpressionResult(result);
}
