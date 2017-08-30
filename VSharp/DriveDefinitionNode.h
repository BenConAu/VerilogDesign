#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class DriveDefinitionNode : public ASTNode
{
public:
  DriveDefinitionNode(
      PSLCompilerContext *pContext,
      const YYLTYPE &location,
      const UIntConstant &delta,
      ASTNode *pExpr);

  void VerifyNodeImpl() override;
  void PostProcessNodeImpl() override;
  const char *GetDebugName() override { return "DriveDefinitionNode"; }

  unsigned int GetDelta() const { return _delta; }

private:
  YYLTYPE _location;
  unsigned int _delta;
};
