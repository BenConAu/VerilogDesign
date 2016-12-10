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
        _pResult = nullptr;
    }

    TypeInfo* GetTypeInfo();
    void SetExpressionType(ExpressionType t);
    void PostProcessNodeImpl() override;

    virtual ExpressionType GetExpressionType();
    ExpressionResult* TakeResult() { ExpressionResult* pRet = _pResult; _pResult = nullptr; return pRet; }

protected:
    virtual ExpressionResult* CalculateResult() = 0;
    void SetType(TypeInfo* pInfo);

private:
    ExpressionResult* _pResult;
    ExpressionType _exprType;
    TypeInfo* _pType;
};
