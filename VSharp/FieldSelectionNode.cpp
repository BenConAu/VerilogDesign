#include "FieldSelectionNode.h"
#include "StructMember.h"
#include "StaticTypeInfo.h"
#include "VariableInfo.h"
#include "ModuleDeclaratorNode.h"
#include "VSharpCompilerContext.h"
#include "IdentifierNode.h"

FieldSelectionNode::FieldSelectionNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pExpr,
    int symIndex) : ExpressionNode(pContext, location)
{
    AddNode(pExpr);

    _fieldSymIndex = symIndex;
    _pStaticTypeInfo = nullptr;

    //printf("Field symbol index for %p is %d\n", this, _fieldSymIndex);
}

FieldSelectionNode::FieldSelectionNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    int symIndex,
    StaticTypeInfo *pStaticTypeInfo,
    StructTypeInfo *pStructTypeInfo) : ExpressionNode(pContext, location)
{
    _fieldSymIndex = symIndex;
    _pStaticTypeInfo = pStaticTypeInfo;
    _pStructTypeInfo = pStructTypeInfo;
}

ASTNode* FieldSelectionNode::DuplicateNodeImpl()
{
    return new FieldSelectionNode(GetContext(), GetLocation(), _fieldSymIndex, _pStaticTypeInfo, _pStructTypeInfo);
}

void FieldSelectionNode::VerifyNodeImpl()
{
    ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));
    if (pLeft == nullptr)
    {
        GetContext()->ReportError(GetLocation(), "Can only field select expressions");
    }

    // Should verify that the type exists
    TypeInfo *pTypeInfo = pLeft->GetTypeInfo();

    _pStaticTypeInfo = dynamic_cast<StaticTypeInfo*>(pTypeInfo);
    if (_pStaticTypeInfo == nullptr)
    {
        _pStructTypeInfo = dynamic_cast<StructTypeInfo*>(pTypeInfo);
        if (_pStructTypeInfo == nullptr)
        {
            GetContext()->ReportError(GetLocation(), "Type or identifier not found");
        }

        StructMember* pMember = _pStructTypeInfo->GetMember(_fieldSymIndex);        
        if (pMember == nullptr)
        {
            GetContext()->ReportError(GetLocation(), "Unknown member of struct");
        }

        SetType(pMember->GetType());
    }
    else
    {
        EnumTypeInfo* pEnumInfo = dynamic_cast<EnumTypeInfo*>(_pStaticTypeInfo->GetTypeInfo());
        if (!pEnumInfo->IsMember(_fieldSymIndex))
        {
            GetContext()->ReportError(GetLocation(), "Unknown member of enum");        
        }

        // The type of this expression is the size of the enum type
        SetType(pEnumInfo);
    }
}

ExpressionResult *FieldSelectionNode::CalculateResult()
{
    // Get the child expression
    ExpressionNode *pChildExpr = dynamic_cast<ExpressionNode *>(GetChild(0));

    // Find the result of the child - we don't use it, which is probably problematic eventually
    std::unique_ptr<ExpressionResult> childResult(pChildExpr->TakeResult());

    if (_pStaticTypeInfo != nullptr)
    {
        EnumTypeInfo* pEnumInfo = dynamic_cast<EnumTypeInfo*>(_pStaticTypeInfo->GetTypeInfo());
        
        //printf("Field selection for %p with index %d\n", this, _fieldSymIndex);
        int value = pEnumInfo->GetValue(_fieldSymIndex);
    
        char result[1024];
        sprintf(
            result, 
            "%d", 
            value);
    
        return new ExpressionResult(result);
    }
    else
    {
        if (childResult.get() == nullptr)
        {
            printf("Child expression %p returned null result to parent %p\n", pChildExpr, this);
        }

        IdentifierNode* pIdentNode = dynamic_cast<IdentifierNode*>(GetChild(0));
        StructMember* pMember = _pStructTypeInfo->GetMember(_fieldSymIndex);

        unsigned int base = _pStructTypeInfo->GetBaseLocation(_fieldSymIndex);
        unsigned int size = pMember->GetBitLength();

        char result[1024];
        sprintf(
            result,
            "%s[%u:%u]",
            childResult->GetString().c_str(),
            base + size - 1,
            base);

        return new ExpressionResult(result);
    }

}
