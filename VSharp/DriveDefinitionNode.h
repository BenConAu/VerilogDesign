#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class DriveDefinitionNode : public ASTNode
{
public:
  DriveDefinitionNode(
      PSLCompilerContext *pContext,
      const YYLTYPE &location,
      int delta,
      ASTNode *pExpr);

  void VerifyNodeImpl() override;
  const char *GetDebugName() override { return "DriveDefinitionNode"; }

  int GetDelta() const { return _delta; }

private:
  YYLTYPE _location;
  int _delta;
};
