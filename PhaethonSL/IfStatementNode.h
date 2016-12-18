#pragma once

#include "ASTNode.h"

class IfStatementNode : public ASTNode
{
public:
  IfStatementNode(PSLCompilerContext *pContext, ASTNode *pLeft, ASTNode *pRight);
  void VerifyNodeImpl() override;
  void ProcessNode() override;

  void SetStatementList(ASTNode *pList)
  {
    AddNode(pList);
  }

  const char *GetDebugName() override { return "IfStatementNode"; }
};
