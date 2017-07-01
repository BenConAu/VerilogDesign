#pragma once

#include "ASTNode.h"

class WhileStatementNode : public ASTNode
{
public:
  WhileStatementNode(PSLCompilerContext *pContext, ASTNode *pLeft, ASTNode *pRight);
  void VerifyNodeImpl() override;
  void ProcessNode() override;

  void SetStatementList(ASTNode *pList)
  {
    AddNode(pList);
  }

  const char *GetDebugName() override { return "WhileStatementNode"; }

private:
  static int s_instanceCount;

  int _instance;
};
