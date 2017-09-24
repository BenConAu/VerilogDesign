#include "BitSelectionNode.h"
#include "StructMember.h"
#include "StructTypeInfo.h"
#include "VariableInfo.h"
#include "ModuleDefinitionNode.h"
#include "ParserContext.h"

BitSelectionNode::BitSelectionNode(
    ParserContext *pContext,
    const YYLTYPE &location,
    ASTNode *pPostFix,
    ASTNode *pInt1,
    ASTNode *pInt2) : ExpressionNode(pContext, location)
{
    AddNode(pPostFix);
    AddNode(pInt1);
    AddNode(pInt2);
}

BitSelectionNode::BitSelectionNode(
    ParserContext *pContext,
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
        StructTypeInfo* pStructTypeInfo = dynamic_cast<StructTypeInfo*>(pTypeInfo);
        if (pStructTypeInfo == nullptr)
        {
            GetContext()->ReportError(GetLocation(), "Can only select bits from uint and struct types");            
        }
    }

    // Calculate the indices
    ExpressionNode* pInt1 = dynamic_cast<ExpressionNode*>(GetChild(1));
    ExpressionNode* pInt2 = dynamic_cast<ExpressionNode*>(GetChild(2));

    UIntConstant constVal1;
    if (pInt1->ConstEvaluate(&constVal1))
    {
        _i1 = constVal1._value;
    }
    else
    {
        GetContext()->ReportError(GetLocation(), "Bit selection must be done with constant indices");
    }

    UIntConstant constVal2;
    if (pInt2->ConstEvaluate(&constVal2))
    {
        _i2 = constVal2._value;
    }
    else
    {
        GetContext()->ReportError(GetLocation(), "Bit selection must be done with constant indices");
    }

    if (_i1 < 0 || _i2 < 0)
    {
        GetContext()->ReportError(GetLocation(), "Must have positive bit indices to select bits");
    }

    if (_i1 >= pTypeInfo->GetBitLength() || _i2 >= pTypeInfo->GetBitLength())
    {
        GetContext()->ReportError(GetLocation(), "Bit index out of range");
    }

    if (_i1 < _i2)
    {
        GetContext()->ReportError(GetLocation(), "Bit indices out of order");
    }

    SetType(GetContext()->GetTypeCollection()->GetRegisterType(_i1 - _i2 + 1));
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

VariableInfo* BitSelectionNode::IsVariableExpression()
{
    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(0));
    
    // Index selecting a variable expression will yield one
    return pExpr->IsVariableExpression();
}  
