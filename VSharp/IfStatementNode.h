#pragma once

#include "StatementNode.h"
#include "VSharp.tab.h"

class IfStatementNode : public StatementNode
{
public:
  IfStatementNode(PSLCompilerContext *pContext, YYLTYPE location, ASTNode *pLeft, ASTNode *pRight);
  IfStatementNode(PSLCompilerContext *pContext, YYLTYPE location);
  void VerifyNodeImpl() override;
  void ProcessNodeImpl() override;
  ASTNode* DuplicateNodeImpl() override;

  void SetExpression(ASTNode *pList)
  {
    AddNode(pList);
  }

  const char *GetDebugName() override { return "IfStatementNode"; }
};
