#pragma once

#include "ConstantNode.h"
#include "ASTNode.h"
#include "VSharp.tab.h"

class StateDeclaratorNode : public ASTNode
{
public:
  StateDeclaratorNode(
      ParserContext *pContext,
      const YYLTYPE &location,
      int ident,
      ASTNode *pStatementList);

  void VerifyNodeImpl() override;
  bool PreProcessNodeImpl(OutputContext* pContext) override;
  void PostProcessNodeImpl(OutputContext* pContext) override;
  const char *GetDebugName() override { return "StateDeclaratorNode"; }
  int GetIdentifier() const { return _identifier; }

private:
  int _identifier;
};
