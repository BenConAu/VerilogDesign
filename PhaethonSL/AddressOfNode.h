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
        // We are getting the address of an identifier
        IdentifierNode *pIdentifierNode = dynamic_cast<IdentifierNode*>(GetChild(0));
        if (pIdentifierNode == nullptr)
        {
            throw "Need an identifier to take address";
        }

        // We are only allowed to get addresses of structs
        VariableInfo *pVariableInfo = pIdentifierNode->GetVariableInfo();
        StructTypeInfo *pStructInfo = dynamic_cast<StructTypeInfo*>(pVariableInfo->GetTypeInfo());
        if (pStructInfo == nullptr)
        {
            throw "Can only take address of structs";
        }
    }

    bool IsConstant() const override { return true; }

    ExpressionResult *CalculateResult() override
    {
        // Find the result of the child
        IdentifierNode *pIdentifierNode = dynamic_cast<IdentifierNode*>(GetChild(0));
        std::unique_ptr<ExpressionResult> childResult(pIdentifierNode->CalculateResult());

        // Since we know it is always a struct, we just need to return the new type with the same
        // operand, since the operand was always loading up the address. Start by getting the
        // child identifier node and the variable info out of it.
        VariableInfo *pVariableInfo = pIdentifierNode->GetVariableInfo();

        // Our expression type is pointer to the other expression type
        TypeInfo *pNewTypeInfo = GetContext()->_typeCollection.GetPointerType(pVariableInfo->GetTypeInfo());

        // The result has the new type but same path and same operand
        return new ExpressionResult(pNewTypeInfo, childResult->_operand);     
    }
};