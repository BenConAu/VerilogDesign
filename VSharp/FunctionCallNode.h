#pragma once

#include "ExpressionNode.h"
#include "FunctionCallParamNode.h"
#include "VSharp.tab.h"

class ModuleTypeInfo;
class FunctionDeclaratorNode;
class FunctionInfo;
class StatementNode;

enum class FunctionType
{
  Unknown,      // Don't know yet
  BuiltIn,      // __* functions that are built into the language
  Defined,      // Functions defined in V#
  Constructor,  // Constructors of structs
  ModuleDecl,   // Declaration of module
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
  size_t GetParameterCount() const;
  ASTNode* ExpandFunction(StatementNode* pOwningStatement);
  FunctionInfo* GetFunctionInfo();
  ModuleTypeInfo* GetModuleTypeInfo();
  ExpressionResult* CreateMemberResult(int fieldSymIndex);
  
private:
  // Symbol of function being called
  int _symIndex;

  // Type of function being valled
  FunctionType _functionType;

  // Parameter results
  std::vector<std::string> _parameterResults;
};
