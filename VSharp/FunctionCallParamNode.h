#pragma once

#include "ExpressionNode.h"

class FunctionCallParamNode : public ExpressionNode
{
public:
    FunctionCallParamNode(ParserContext* pContext, const YYLTYPE &location, bool fOut, ASTNode* pExpr);
    FunctionCallParamNode(ParserContext* pContext, const YYLTYPE &location);
    FunctionCallParamNode(
        ParserContext* pContext, 
        const YYLTYPE &location,
        bool fOut,
        const std::string& literal
        );

    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "FunctionCallParamNode"; }
    ExpressionResult* CalculateResult() override;
    ASTNode* DuplicateNodeImpl() override;
    VariableInfo* IsVariableExpression() override { return nullptr; }
    
    int IsOutParam() const { return _fOut; }
    ExpressionNode* GetParamExpr() { return dynamic_cast<ExpressionNode*>(GetChild(0)); }

private:
    bool _fOut;
    std::string _literal;
};
