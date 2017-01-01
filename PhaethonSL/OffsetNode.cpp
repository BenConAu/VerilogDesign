#include "OffsetNode.h"
#include "IdentifierNode.h"
#include "TypeNode.h"

OffsetNode::OffsetNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pType,
    ASTNode *pIdent,
    ASTNode *pExpr) : OperatorNode(pContext, pIdent, pExpr, Operator::Add)
{
    AddNode(pType);

    _location = location;
}

void OffsetNode::VerifyNodeImpl()
{
    OperatorNode::VerifyNodeImpl();

    TypeNode *pTypeNode = dynamic_cast<TypeNode *>(GetChild(2));
    ExpressionNode *pPointerNode = dynamic_cast<ExpressionNode *>(GetChild(0));
    ExpressionNode *pExpr = dynamic_cast<ExpressionNode *>(GetChild(1));

    if (pTypeNode == nullptr || pPointerNode == nullptr || pExpr == nullptr)
    {
        GetContext()->ReportError(_location, "Wrong children nodes for OffsetPtr");
    }

    TypeInfo *pReturnTypeInfo = pTypeNode->GetTypeInfo();
    PointerTypeInfo *pIdentInfo = dynamic_cast<PointerTypeInfo *>(pPointerNode->GetTypeInfo());
    BasicTypeInfo *pExprInfo = dynamic_cast<BasicTypeInfo *>(pExpr->GetTypeInfo());

    if (pIdentInfo == nullptr || pExprInfo == nullptr)
    {
        GetContext()->ReportError(_location, "Wrong types given to offsetptr");
    }

    TypeInfo* pIdentTypeInfo = pIdentInfo->GetBaseType();
    if (!pReturnTypeInfo->EqualType(pIdentTypeInfo))
    {
        GetContext()->ReportError(_location, "Types of offset and argument do not match");
    }

    if (pExprInfo->GetTypeToken() != WORD_TOKEN)
    {
        throw "Can only offset pointer by a word";
    }

    SetType(pIdentInfo);
}
