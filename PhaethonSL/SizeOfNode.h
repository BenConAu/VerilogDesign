#pragma once

#include "PSLCompilerContext.h"
#include "ASTNode.h"
#include "PSL.tab.h"

class SizeOfNode : public ExpressionNode
{
  public:
    SizeOfNode(
        PSLCompilerContext *pContext,
        ASTNode *pExpr) : ExpressionNode(pContext)
    {
        AddNode(pExpr);
    }

    void VerifyNodeImpl() override
    {
        // TODO: Make sure it is an identifier inside
    }

    bool IsConstant() const override { return true; }

    ExpressionResult *CalculateResult() override
    {
        TypeInfo *pTypeInfo = GetContext()->_typeCollection.GetBasicType(WORD_TOKEN);
        IdentifierNode *pId = dynamic_cast<IdentifierNode *>(GetChild(0));
        VariableInfo *pInfo = GetContext()->_varCollection.GetInfo(pId->GetSymbolIndex());

        return new ExpressionResult(pTypeInfo, Operand((int)pInfo->GetTypeInfo()->GetSize()));
    }
};