#pragma once

#include "ExpressionNode.h"
#include "FunctionCallParamNode.h"
#include "VSharp.tab.h"

class ModuleTypeInfo;
class ModuleDefinitionNode;
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
      ParserContext *pContext,
      const YYLTYPE &location,
      int symIndex,
      ASTNode *pGenericValue,
      ASTNode *pFirstArg);

  FunctionCallNode(
      ParserContext *pContext,
      const YYLTYPE &location,
      int symIndex,
      FunctionType type,
      FunctionInfo* pInfo,
      UIntConstant GenericParam);

  // Overrides
  void VerifyNodeImpl() override;
  ExpressionResult *CalculateResult() override;
  const char *GetDebugName() override { return "FunctionCallNode"; }
  ASTNode* DuplicateNode(DuplicateType type) override;
  ASTNode* DuplicateNodeImpl(DuplicateType type) override;
  void DumpNodeImpl() override;
  VariableInfo* IsVariableExpression() override { return nullptr; }
  
  // Parameter management and other properties
  FunctionCallParamNode* GetParameter(size_t index) { return dynamic_cast<FunctionCallParamNode*>(GetChild(index + 1)); }
  UIntConstant* GetGenericValue();
  size_t GetParameterCount() const;
  const char *GetFunctionName();

  // Function expansion
  ASTNode* ExpandFunction(StatementNode* pOwningStatement);
  FunctionInfo* GetFunctionInfo() { return _pFunctionInfo; }
  ModuleTypeInfo* GetModuleTypeInfo();
  ExpressionResult* CreateMemberResult(int fieldSymIndex);

  // Helpers
  void AppendParameterList(std::string& str);
  
private:
  void SearchFunctionInfo(
    FunctionInfo** ppFunctionInfo,
    FunctionInfo** ppGenericInfo    
  );

private:
  // Symbol of function being called
  int _symIndex;

  // The function info (filled in by Verify)
  FunctionInfo* _pFunctionInfo;

  // Type of function being called (filled in by Verify)
  FunctionType _functionType;

  // Generic value (filled in by Verify)
  UIntConstant _GenericParam;  

  // Parameter results
  std::vector<std::string> _parameterResults;
};
