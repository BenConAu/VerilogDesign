#pragma once

#include "ASTNode.h"
#include "VSharp.tab.h"

class IfStatementNode : public ASTNode
{
public:
  IfStatementNode(PSLCompilerContext *pContext, YYLTYPE location, ASTNode *pLeft, ASTNode *pRight);
  void VerifyNodeImpl() override;
  void ProcessNodeImpl() override;

  void SetExpression(ASTNode *pList)
  {
    AddNode(pList);
  }

  const char *GetDebugName() override { return "IfStatementNode"; }

private:
  static int s_instanceCount;

  int _instance;
  YYLTYPE _location;
};
