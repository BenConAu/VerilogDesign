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
        SetType(GetContext()->_typeCollection.GetBasicType(WORD_TOKEN));
    }

    bool IsConstant() const override { return true; }

    ExpressionResult *CalculateResult() override
    {
        TypeInfo *pTypeInfo = GetContext()->_typeCollection.GetBasicType(WORD_TOKEN);
     
        TypeNode *pTypeNode = dynamic_cast<TypeNode *>(GetChild(0));

        return new ExpressionResult(pTypeInfo, Operand((int)pTypeNode->GetTypeInfo()->GetSize()));
    }

    const char *GetDebugName() override { return "SizeOfNode"; }
};