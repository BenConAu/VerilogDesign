#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class DriveListDefinitionNode : public ASTNode
{
public:
  DriveListDefinitionNode(
      ParserContext *pContext,
      const YYLTYPE &location,
      ASTNode *pList);

  void VerifyNodeImpl() override;
  bool PreProcessNodeImpl(OutputContext* pContext) override;
  void PostProcessNodeImpl(OutputContext* pContext) override;
  const char *GetDebugName() override { return "DriveListDefinitionNode"; }
};
