#pragma once

#include "StatementNode.h"
#include "VSharp.tab.h"

class FunctionCallNode;

class AssignmentNode : public StatementNode
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
  void PostProcessNodeImpl() override;
  const char *GetDebugName() override { return "AssignmentNode"; }
  ASTNode* DuplicateNodeImpl() override;
};
