#pragma once

#include "ExpressionNode.h"

class FunctionInfo;

class FunctionCallNode : public ExpressionNode
{
  public:
    FunctionCallNode(
        PSLCompilerContext *pContext,
        int symIndex,
        ASTNode *pFirstArg);

    void VerifyNodeImpl() override;
    ExpressionResult *CalculateResult() override;
    const char *GetDebugName() override { return "FunctionCallNode"; }

    FunctionInfo *GetFunctionInfo();

  private:
    int _symIndex;
};
