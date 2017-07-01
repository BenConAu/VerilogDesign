#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class FunctionInfo;

class FunctionCallNode : public ExpressionNode
{
public:
  FunctionCallNode(
      PSLCompilerContext *pContext,
      const YYLTYPE &location,
      int symIndex,
      ASTNode *pGenericType,
      ASTNode *pFirstArg);

  void VerifyNodeImpl() override;
  ExpressionResult *CalculateResult() override;
  const char *GetDebugName() override { return "FunctionCallNode"; }

  FunctionInfo *GetFunctionInfo();

private:
  int _symIndex;
  YYLTYPE _location;
};
