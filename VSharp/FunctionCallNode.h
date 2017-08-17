#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class ModuleInfo;
class FunctionDeclaratorNode;

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
  size_t GetParameterCount() const { return (GetChildCount() - 1); }
  FunctionDeclaratorNode* GetDeclarator();
  ModuleInfo *GetModuleInfo();

private:
  // Symbol of function being called
  int _symIndex;
};
