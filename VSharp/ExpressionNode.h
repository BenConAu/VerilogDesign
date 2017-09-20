#pragma once

#include "ASTNode.h"
#include "TypeInfo.h"
#include "ExpressionResult.h"
#include "VSharp.tab.h"

class FunctionCallNode;



class ExpressionNode : public ASTNode
{
public:
    ExpressionNode(ParserContext* pContext, const YYLTYPE &location);

    TypeInfo* GetTypeInfo();
    void PostProcessNodeImpl(OutputContext* pContext) override;
    void DumpNodeImpl() override;

    ExpressionResult* TakeResult();
    
    virtual ExpressionResult* CalculateResult() = 0;
    virtual VariableInfo* IsVariableExpression() = 0;
    virtual bool ConstEvaluate(UIntConstant* pVal);

    static bool EqualType(ASTNode* pA, ASTNode* pB);

protected:
    void SetType(TypeInfo* pInfo);

private:
    ExpressionResult* _pResult;
    TypeInfo* _pType;
    bool _fResultCalculated;
    bool _fResultTaken;
};
