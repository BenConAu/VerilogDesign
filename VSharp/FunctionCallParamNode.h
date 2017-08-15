#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class FunctionCallParamNode : public ExpressionNode
{
public:
    FunctionCallParamNode(PSLCompilerContext* pContext, const YYLTYPE &location, bool fOut, ASTNode* pExpr) : ExpressionNode(pContext, location)
    {
        AddNode(pExpr);
        _fOut = fOut;
    }

    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "FunctionCallParamNode"; }
    ExpressionResult* CalculateResult() override;

private:
    bool _fOut;
};
