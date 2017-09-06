#pragma once

#include "ExpressionNode.h"
#include "VSharpCompilerContext.h"
#include "VSharp.tab.h"

class FunctionCallParamNode : public ExpressionNode
{
public:
    FunctionCallParamNode(PSLCompilerContext* pContext, const YYLTYPE &location, bool fOut, ASTNode* pExpr) : ExpressionNode(pContext, location)
    {
        AddNode(pExpr);
        _fOut = fOut;
    }

    FunctionCallParamNode(PSLCompilerContext* pContext, const YYLTYPE &location) : ExpressionNode(pContext, location)
    {
        _fOut = false;
        _literal = pContext->GetLastString();
    }

    FunctionCallParamNode(
        PSLCompilerContext* pContext, 
        const YYLTYPE &location,
        bool fOut,
        const std::string& literal
        ) : ExpressionNode(pContext, location)
    {
        _fOut = fOut;
        _literal = literal;
    }

    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "FunctionCallParamNode"; }
    ExpressionResult* CalculateResult() override;
    ASTNode* DuplicateNodeImpl() override;

    int IsOutParam() const { return _fOut; }
    ExpressionNode* GetParamExpr() { return dynamic_cast<ExpressionNode*>(GetChild(0)); }

private:
    bool _fOut;
    std::string _literal;
};
