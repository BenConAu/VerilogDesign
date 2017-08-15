#pragma once

#include "ASTNode.h"
#include "TypeInfo.h"
#include "ExpressionResult.h"
#include "VSharp.tab.h"

class ExpressionNode : public ASTNode
{
public:
    ExpressionNode(PSLCompilerContext* pContext, const YYLTYPE &location) : ASTNode(pContext)
    {
        _pType = nullptr;
        _pResult = nullptr;
        _location = location;
    }

    TypeInfo* GetTypeInfo();
    void PostProcessNodeImpl() override;

    ExpressionResult* TakeResult() { ExpressionResult* pRet = _pResult; _pResult = nullptr; return pRet; }
    virtual ExpressionResult* CalculateResult() = 0;

    static bool EqualType(ASTNode* pA, ASTNode* pB);

protected:
    void SetType(TypeInfo* pInfo);
    const YYLTYPE& GetLocation() { return _location; }

private:
    ExpressionResult* _pResult;
    TypeInfo* _pType;
    YYLTYPE _location;    
};
