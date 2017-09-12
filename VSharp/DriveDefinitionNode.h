#pragma once

#include "ExpressionNode.h"

class DriveDefinitionNode : public ASTNode
{
public:
  DriveDefinitionNode(
      PSLCompilerContext *pContext,
      const YYLTYPE &location,
      const UIntConstant &delta,
      ASTNode *pExpr);

  void VerifyNodeImpl() override;
  void PostProcessNodeImpl(OutputContext* pContext) override;
  const char *GetDebugName() override { return "DriveDefinitionNode"; }

  unsigned int GetDelta() const { return _delta; }

private:
  unsigned int _delta;
};
