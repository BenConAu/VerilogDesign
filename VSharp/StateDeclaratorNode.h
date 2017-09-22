#pragma once

#include "ConstantNode.h"
#include "ASTNode.h"
#include "VSharp.tab.h"

enum class KnownStates
{
  None,
  Initial,
  Always,
};

class StateDeclaratorNode : public ASTNode
{
public:
  StateDeclaratorNode(
    ParserContext *pContext,
    const YYLTYPE &location,
    int ident,
    ASTNode *pStatementList);

  StateDeclaratorNode(
    ParserContext *pContext,
    const YYLTYPE &location,
    KnownStates state,
    ASTNode *pStatementList);

  void VerifyNodeImpl() override;
  bool PreProcessNodeImpl(OutputContext* pContext) override;
  void PostProcessNodeImpl(OutputContext* pContext) override;
  const char *GetDebugName() override { return "StateDeclaratorNode"; }
  int GetIdentifier() const { return _identifier; }
  KnownStates GetKnownState() const { return _KnownState; }

private:
  int _identifier;
  KnownStates _KnownState;
};
