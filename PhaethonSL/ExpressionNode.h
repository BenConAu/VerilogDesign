#pragma once

#include "ASTNode.h"
#include "TypeInfo.h"

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
        _result = 0xFF;
        _exprType = ExpressionType::Unset;
    }

    RegIndex GetResultRegister()
    {
        if (_result == 0xFF)
        {
            _result = CalcResultLocationImpl();
        }

        return _result;
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

    virtual void ProcessWrite(RegIndex valueIndex) {}

protected:
    virtual RegIndex CalcResultLocationImpl() = 0;

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
    RegIndex _result;
    TypeInfo* _pType;
};
