#pragma once

#include "ASTNode.h"

class TypeNode;
class ExpressionNode;
class ModuleTypeInfo;

class AttachModuleNode : public ASTNode
{
public:
  AttachModuleNode(
    ParserContext *pContext,
    const YYLTYPE &location,
    ASTNode *pInitExpr);

  void VerifyNodeImpl() override;
  void PostProcessNodeImpl(OutputContext* pContext) override;
  const char *GetDebugName() override { return "AttachModuleNode"; }
  ExpressionNode* GetInitNode();
  ModuleTypeInfo* GetModuleInfo() { return _pModuleTypeInfo; }

private:
  static int s_attachCount;
  int _symIndex;
  ModuleTypeInfo* _pModuleTypeInfo;
};
