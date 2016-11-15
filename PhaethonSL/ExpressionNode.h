#pragma once

#include "ASTNode.h"
#include "TypeInfo.h"
#include "ExpressionResult.h"

enum class ExpressionType
{
    Unset,
    Read,
    Write
};

class ExpressionNode : public ASTNode
{
public:
    ExpressionNode(PSLCompilerContext* pContext) : ASTNode(pContext)
    {
        _pType = nullptr;
        _exprType = ExpressionType::Unset;
    }

    TypeInfo* GetType()
    {
        if (_pType == nullptr)
        {
            throw "Unset type";
        }

        return _pType;
    }

    void SetExpressionType(ExpressionType t)
    {
        _exprType = t;
    }

    virtual ExpressionType GetExpressionType()
    {
        if (_exprType == ExpressionType::Unset)
        {
            ExpressionNode* pParentExpr = dynamic_cast<ExpressionNode*>(GetParent());
            if (pParentExpr == nullptr)
            {
                return ExpressionType::Unset;
            }

            return pParentExpr->GetExpressionType();
        }

        return _exprType;
    }

    virtual ExpressionResult* CalculateResult() = 0;

protected:
    void SetType(TypeInfo* pInfo)
    {
        if (pInfo == nullptr)
        {
            throw "Should not set type to null";
        }

        _pType = pInfo;
    }

private:
    ExpressionType _exprType;
    TypeInfo* _pType;
};
