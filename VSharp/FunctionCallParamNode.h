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

    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "FunctionCallParamNode"; }
    ExpressionResult* CalculateResult() override;

private:
    bool _fOut;
    std::string _literal;
};
