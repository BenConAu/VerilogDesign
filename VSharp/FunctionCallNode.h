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

  ExpressionNode* GetParameter(size_t index) { return dynamic_cast<ExpressionNode*>(GetChild(index + 1)); }
  ModuleInfo *GetModuleInfo();

private:
  // Symbol of function being called
  int _symIndex;

  // Where the call was made in code
  YYLTYPE _location;
};
