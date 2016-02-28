#pragma once

#include "ExpressionNode.h"
#include "TypeMember.h"
#include "StructTypeInfo.h"

class FieldSelectionNode : public ExpressionNode
{
public:
    FieldSelectionNode(PSLCompilerContext* pContext, ASTNode* pExpr, int symIndex) : ExpressionNode(pContext)
    {
        AddNode(pExpr);

        _fieldSymIndex = symIndex;
    }

    void VerifyNodeImpl() override
    {
        ExpressionNode* pLeft = dynamic_cast<ExpressionNode*>(GetChild(0));

        // Should verify that the type exists
        TypeInfo* pExpressionInfo = pLeft->GetType();

        if (pExpressionInfo->IsBasic())
        {
            throw "Cannot field select a basic type";
        }

        StructTypeInfo* pStructInfo = dynamic_cast<StructTypeInfo*>(pExpressionInfo);
        TypeMember* pMember = pStructInfo->GetMember(_fieldSymIndex);

        // The type of this expression is the type of the member
        SetType(pMember->GetType());
    }

protected:
    RegIndex CalcResultRegisterImpl() override
    {
        return GetContext()->_regCollection.AllocateRegister();
    }

private:
    int _fieldSymIndex;
};
