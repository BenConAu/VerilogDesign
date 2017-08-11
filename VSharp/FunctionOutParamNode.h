#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class FunctionOutParamNode : public ExpressionNode
{
public:
    FunctionOutParamNode(PSLCompilerContext* pContext, const YYLTYPE &location, ASTNode* pIdent) : ExpressionNode(pContext)
    {
        AddNode(pIdent);
        _location = location;
    }

    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "FunctionOutParamNode"; }
    ExpressionResult* CalculateResult() override;

private:
    YYLTYPE _location;
};
