#pragma once

#include "StatementNode.h"
#include "VSharp.tab.h"

class CaseStatementNode : public StatementNode
{
public:
  CaseStatementNode(ParserContext *pContext, YYLTYPE location, ASTNode *pValue, ASTNode *pList);
  CaseStatementNode(ParserContext *pContext, YYLTYPE location);
  void VerifyNodeImpl() override;
  void ProcessNodeImpl(OutputContext* pOutputContext) override;
  ASTNode* DuplicateNodeImpl(DuplicateType type) override;

  const char *GetDebugName() override { return "CaseStatementNode"; }
};
