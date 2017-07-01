#pragma once

#include "ConstantNode.h"
#include "ASTNode.h"
#include "VSharp.tab.h"

class StateDeclaratorNode : public ASTNode
{
public:
  StateDeclaratorNode(
      PSLCompilerContext *pContext,
      const YYLTYPE &location,
      int ident,
      ASTNode *pStatementList);

  void VerifyNodeImpl() override;
  void PostProcessNodeImpl() override;
  const char *GetDebugName() override { return "StateDeclaratorNode"; }

private:
  int _identifier;
  YYLTYPE _location;
};
