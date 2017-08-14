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
    int i1,
    int i2) : ExpressionNode(pContext)
{
    AddNode(pPostFix);

    _location = location;
    _i1 = i1;
    _i2 = i2;
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
        GetContext()->ReportError(_location, "Can only select bits from uint types");
    }

    if (_i1 < 0 || _i2 < 0)
    {
        GetContext()->ReportError(_location, "Must have positive bit indices to select bits");
    }

    if (_i1 >= pRegTypeInfo->GetBitLength() || _i2 >= pRegTypeInfo->GetBitLength())
    {
        GetContext()->ReportError(_location, "Bit index out of range");
    }

    if (_i1 < _i2)
    {
        GetContext()->ReportError(_location, "Bit indices out of order");
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
