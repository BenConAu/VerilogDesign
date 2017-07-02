#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class ModuleInfo;

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

  ModuleInfo *GetModuleInfo();

private:
  int _symIndex;
  YYLTYPE _location;
};
