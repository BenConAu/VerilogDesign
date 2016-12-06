#pragma once

#include "PSLCompilerContext.h"
#include "ASTNode.h"
#include "PSL.tab.h"

class AddressOfNode : public ExpressionNode
{
  public:
    AddressOfNode(
        PSLCompilerContext *pContext,
        ASTNode *pExpr) : ExpressionNode(pContext)
    {
        AddNode(pExpr);
    }

    void VerifyNodeImpl() override
    {
        // TODO: 
    }

    bool IsConstant() const override { return true; }

    ExpressionResult *CalculateResult() override
    {
        // We are getting the address of an identifier
        IdentifierNode *pIdentifierNode = dynamic_cast<IdentifierNode*>(GetChild(0));

        // Get the info for the thing we get the address for
        VariableInfo *pVariableInfo = pIdentifierNode->GetVariableInfo();

        // Our expression type is pointer to the other expression type
        TypeInfo *pNewTypeInfo = GetContext()->_typeCollection.GetPointerType(pVariableInfo->GetTypeInfo());

        return new ExpressionResult(pNewTypeInfo, Operand(pVariableInfo, GetContext()));     
    }
};