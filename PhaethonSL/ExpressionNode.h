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

    TypeInfo* GetTypeInfo();
    void SetExpressionType(ExpressionType t);

    virtual ExpressionType GetExpressionType();
    virtual ExpressionResult* CalculateResult() = 0;

protected:
    void SetType(TypeInfo* pInfo);

private:
    ExpressionType _exprType;
    TypeInfo* _pType;
};
