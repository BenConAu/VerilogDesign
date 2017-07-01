#pragma once

#include "ConstantNode.h"
#include "ExpressionNode.h"
#include "PSL.tab.h"

class ReadPortNode : public ExpressionNode
{
public:
  ReadPortNode(
      PSLCompilerContext *pContext,
      const YYLTYPE &location,
      ASTNode *pPort);

  void VerifyNodeImpl() override;
  ExpressionResult* CalculateResult() override;
  const char *GetDebugName() override { return "ReadPortNode"; }

private:
  YYLTYPE _location;
};
