#pragma once

#include "ExpressionNode.h"
#include "FunctionCallParamNode.h"
#include "VSharp.tab.h"

class ModuleInfo;
class FunctionDeclaratorNode;
class FunctionInfo;
class StatementNode;

enum class FunctionType
{
  BuiltIn,      // __* functions that are built into the language
  Defined,      // Functions defined in V#
  Constructor,  // Constructors of structs
};

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
      int symIndex,
      FunctionType type);

  void VerifyNodeImpl() override;
  ExpressionResult *CalculateResult() override;
  const char *GetDebugName() override { return "FunctionCallNode"; }
  ASTNode* DuplicateNode() override;
  ASTNode* DuplicateNodeImpl() override;
  void DumpNodeImpl() override;

  const char *GetFunctionName();
  FunctionCallParamNode* GetParameter(size_t index) { return dynamic_cast<FunctionCallParamNode*>(GetChild(index + 1)); }
  size_t GetParameterCount() const { return (GetChildCount() - 1); }
  ASTNode* ExpandFunction(StatementNode* pOwningStatement);
  FunctionInfo* GetFunctionInfo();
  
private:
  // Symbol of function being called
  int _symIndex;

  // Type of function being valled
  FunctionType _functionType;
};
