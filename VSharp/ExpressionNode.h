#pragma once

#include "ASTNode.h"
#include "TypeInfo.h"
#include "ExpressionResult.h"
#include "VSharp.tab.h"

class FunctionCallNode;

class ExpressionNode : public ASTNode
{
public:
    ExpressionNode(PSLCompilerContext* pContext, const YYLTYPE &location);

    TypeInfo* GetTypeInfo();
    void PostProcessNodeImpl() override;
    void DumpNodeImpl() override;

    ExpressionResult* TakeResult();
    
    virtual ExpressionResult* CalculateResult() = 0;

    static bool EqualType(ASTNode* pA, ASTNode* pB);

protected:
    void SetType(TypeInfo* pInfo);

private:
    ExpressionResult* _pResult;
    TypeInfo* _pType;
    bool _fResultCalculated;
    bool _fResultTaken;
};
