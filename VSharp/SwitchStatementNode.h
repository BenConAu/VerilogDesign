#pragma once

#include "StatementNode.h"
#include "VSharp.tab.h"

class SwitchStatementNode : public StatementNode
{
public:
  SwitchStatementNode(ParserContext *pContext, YYLTYPE location, ASTNode *pFirstCase);
  SwitchStatementNode(ParserContext *pContext, YYLTYPE location);
  void VerifyNodeImpl() override;
  void ProcessNodeImpl(OutputContext* pOutputContext) override;
  ASTNode* DuplicateNodeImpl() override;

  void SetTest(ASTNode *pTest)
  {
    AddNode(pTest);
  }

  const char *GetDebugName() override { return "SwitchStatementNode"; }
};
