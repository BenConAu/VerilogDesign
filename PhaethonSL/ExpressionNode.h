#pragma once

#include "ASTNode.h"
#include "TypeInfo.h"
#include "ExpressionResult.h"

class ExpressionNode : public ASTNode
{
public:
    ExpressionNode(PSLCompilerContext* pContext) : ASTNode(pContext)
    {
        _pType = nullptr;
        _pResult = nullptr;
    }

    TypeInfo* GetTypeInfo();
    void PostProcessNodeImpl() override;

    ExpressionResult* TakeResult() { ExpressionResult* pRet = _pResult; _pResult = nullptr; return pRet; }

protected:
    virtual ExpressionResult* CalculateResult() = 0;
    void SetType(TypeInfo* pInfo);

private:
    ExpressionResult* _pResult;
    TypeInfo* _pType;
};
