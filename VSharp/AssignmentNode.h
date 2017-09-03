#pragma once

#include "ConstantNode.h"
#include "ExpressionNode.h"
#include "VSharp.tab.h"

class FunctionCallNode;

class AssignmentNode : public ASTNode
{
public:
  AssignmentNode(
      PSLCompilerContext *pContext,
      const YYLTYPE &location,
      ASTNode *pLeft,
      ASTNode *pRight);

  AssignmentNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location);
  
  void VerifyNodeImpl() override;
  bool PreProcessNodeImpl() override;
  void PostProcessNodeImpl() override;
  const char *GetDebugName() override { return "AssignmentNode"; }
  ASTNode* DuplicateNodeImpl() override;

  void SetCallReplacement(FunctionCallNode* pCallNode, ASTNode* pReplacement);

  FunctionCallNode* GetCallNode() { return _pCallNode; }
  ASTNode* GetReplacementNode() { return _pReplacement; }

private:
  YYLTYPE _location;
  FunctionCallNode* _pCallNode;   // When duplicating, the call node to replace
  ASTNode* _pReplacement;         // When duplicating, the thing to replace with
};
