#pragma once

#include "ExpressionNode.h"
#include "PSL.tab.h"

class RegisterNode : public ExpressionNode
{
public:
  RegisterNode(
      PSLCompilerContext *pContext,
      const YYLTYPE &location,
      RegIndex index);

  void VerifyNodeImpl() override;
  ExpressionResult *CalculateResult() override;
  const char *GetDebugName() override { return "RegisterNode"; }

private:
  YYLTYPE _location;
  RegIndex _index;
};
