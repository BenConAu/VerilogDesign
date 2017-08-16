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
        // Not using a structure, bad for our health
        GetContext()->ReportError(GetLocation(), "Can only field select static types right now");
    }

    EnumTypeInfo* pEnumInfo = dynamic_cast<EnumTypeInfo*>(_pStaticTypeInfo->GetTypeInfo());
    if (!pEnumInfo->IsMember(_fieldSymIndex))
    {
        GetContext()->ReportError(GetLocation(), "Unknown member of enum");        
    }

    // The type of this expression is the size of the enum type
    SetType(pEnumInfo);
}

ExpressionResult *FieldSelectionNode::CalculateResult()
{
    // Get the child expression
    ExpressionNode *pChildExpr = dynamic_cast<ExpressionNode *>(GetChild(0));

    // Find the result of the child
    std::unique_ptr<ExpressionResult> childResult(pChildExpr->TakeResult());

    EnumTypeInfo* pEnumInfo = dynamic_cast<EnumTypeInfo*>(_pStaticTypeInfo->GetTypeInfo());
    int value = pEnumInfo->GetValue(_fieldSymIndex);

    char result[1024];
    sprintf(
        result, 
        "%d", 
        value);

    return new ExpressionResult(result);
}
