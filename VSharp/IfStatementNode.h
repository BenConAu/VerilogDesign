#pragma once

#include "ASTNode.h"

class IfStatementNode : public ASTNode
{
public:
  IfStatementNode(PSLCompilerContext *pContext, ASTNode *pLeft, ASTNode *pRight);
  void VerifyNodeImpl() override;
  void ProcessNodeImpl() override;

  void SetStatementList(ASTNode *pList)
  {
    AddNode(pList);
  }

  const char *GetDebugName() override { return "IfStatementNode"; }

private:
  static int s_instanceCount;

  int _instance;
};
