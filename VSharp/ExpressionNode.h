#pragma once

#include "ASTNode.h"
#include "TypeInfo.h"
#include "ExpressionResult.h"
#include "VSharp.tab.h"

class FunctionCallNode;

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
    FunctionCallNode* GetFirstFunctionCall();

    static bool EqualType(ASTNode* pA, ASTNode* pB);

protected:
    void SetType(TypeInfo* pInfo);
    const YYLTYPE& GetLocation() { return _location; }

private:
    static FunctionCallNode* GetFunctionCall(ASTNode* pNode);

private:
    ExpressionResult* _pResult;
    TypeInfo* _pType;
    YYLTYPE _location;    
};
