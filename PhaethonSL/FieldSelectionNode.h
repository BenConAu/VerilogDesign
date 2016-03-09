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

    void PostProcessNodeImpl() override
    {
        IdentifierNode* pChildId = dynamic_cast<IdentifierNode*>(GetChild(0));
        if (pChildId != nullptr)
        {
            VariableInfo* pVarInfo = GetContext()->_varCollection.GetInfo(pChildId->GetSymbolIndex());
            StructTypeInfo* pTypeInfo = dynamic_cast<StructTypeInfo*>(pVarInfo->GetTypeInfo());
            if (pTypeInfo == nullptr)
            {
                throw "Can only field select a struct";
            }

            unsigned int offset = pTypeInfo->GetOffset(_fieldSymIndex);

            printf(
                "mov r%d, r%d->%s::%s\n",
                GetResultRegister(),
                pChildId->GetResultRegister(),
                GetContext()->_symbols[pTypeInfo->GetSymbolIndex()].c_str(),
                GetContext()->_symbols[pTypeInfo->GetMember(_fieldSymIndex)->GetSymbolIndex()].c_str()
            );
        }
        else
        {
            throw "Can only field select identifiers";
        }
    }

    void ProcessWrite(RegIndex valueIndex) override
    {
        IdentifierNode* pChildId = dynamic_cast<IdentifierNode*>(GetChild(0));
        if (pChildId != nullptr)
        {
            // Get the identifier to load its register
            pChildId->ProcessNode();

            // Write to the field
            VariableInfo* pVarInfo = GetContext()->_varCollection.GetInfo(pChildId->GetSymbolIndex());
            StructTypeInfo* pTypeInfo = dynamic_cast<StructTypeInfo*>(pVarInfo->GetTypeInfo());
            if (pTypeInfo == nullptr)
            {
                throw "Can only field select a struct";
            }

            unsigned int offset = pTypeInfo->GetOffset(_fieldSymIndex);

            printf(
                "mov r%d->%s::%s, r%d\n",
                pChildId->GetResultRegister(),
                GetContext()->_symbols[pTypeInfo->GetSymbolIndex()].c_str(),
                GetContext()->_symbols[pTypeInfo->GetMember(_fieldSymIndex)->GetSymbolIndex()].c_str(),
                valueIndex
            );
        }
        else
        {
            throw "Can only field select identifiers";
        }
    }

protected:
    RegIndex CalcResultLocationImpl() override
    {
        return GetContext()->_regCollection.AllocateRegister();
    }

private:
    int _fieldSymIndex;
};
