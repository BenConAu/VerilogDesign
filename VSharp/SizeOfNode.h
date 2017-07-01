#pragma once

#include "PSLCompilerContext.h"
#include "ASTNode.h"
#include "VSharp.tab.h"

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

        return new ExpressionResult(Operand((int)pTypeNode->GetTypeInfo()->GetSize()));
    }

    const char *GetDebugName() override { return "SizeOfNode"; }
};