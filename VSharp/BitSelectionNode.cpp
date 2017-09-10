#include "BitSelectionNode.h"
#include "StructMember.h"
#include "StructTypeInfo.h"
#include "VariableInfo.h"
#include "ModuleDefinitionNode.h"
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

BitSelectionNode::BitSelectionNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    int i1,
    int i2) : ExpressionNode(pContext, location)
{
    _i1 = i1;
    _i2 = i2;
}

ASTNode* BitSelectionNode::DuplicateNodeImpl()
{
    return new BitSelectionNode(GetContext(), GetLocation(), _i1, _i2);
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
    if (exprResult->GetFieldSelect() != nullptr)
    {
        // Bit selecting a field selection needs to reformat the field
        // selection, rather than add a bit selection into the mix.
        //
        // We offset starting from the base of the expression that we
        // are starting with.
        sprintf(
            result,
            "%s[%d:%d]",
            exprResult->GetFieldSelect()->_structResult.c_str(),
            exprResult->GetFieldSelect()->_i2 + _i1,
            exprResult->GetFieldSelect()->_i2 + _i2);
    }
    else
    {
        // Regular bit selection
        sprintf(
            result, 
            "%s[%d:%d]", 
            exprResult->GetString().c_str(),
            _i1,
            _i2);

    }

    return new ExpressionResult(result);
}
