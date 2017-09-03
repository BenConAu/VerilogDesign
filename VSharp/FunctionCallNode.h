#pragma once

#include "ExpressionNode.h"
#include "FunctionCallParamNode.h"
#include "VSharp.tab.h"

class ModuleInfo;
class FunctionDeclaratorNode;
class FunctionInfo;
class AssignmentNode;

class FunctionCallNode : public ExpressionNode
{
public:
  FunctionCallNode(
      PSLCompilerContext *pContext,
      const YYLTYPE &location,
      int symIndex,
      ASTNode *pGenericType,
      ASTNode *pFirstArg);

  FunctionCallNode(
      PSLCompilerContext *pContext,
      const YYLTYPE &location,
      int symIndex);

  void VerifyNodeImpl() override;
  ExpressionResult *CalculateResult() override;
  const char *GetDebugName() override { return "FunctionCallNode"; }
  ASTNode* DuplicateNode() override;
  ASTNode* DuplicateNodeImpl() override;
  const char *GetFunctionName();

  FunctionCallParamNode* GetParameter(size_t index) { return dynamic_cast<FunctionCallParamNode*>(GetChild(index + 1)); }
  size_t GetParameterCount() const { return (GetChildCount() - 1); }
  ASTNode* ExpandFunction(AssignmentNode* pOwningExpression);
  
private:
  FunctionInfo* GetFunctionInfo();
  
private:
  // Symbol of function being called
  int _symIndex;
};
