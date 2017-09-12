#pragma once

#include "ASTNode.h"

class TypeNode;

class VariableDeclarationNode : public ASTNode
{
public:
  VariableDeclarationNode(
    ParserContext *pContext,
    const YYLTYPE &location,
    ASTNode *pType,
    int symIndex,
    const UIntConstant &arraySize,
    ASTNode *pInitExpr);

  VariableDeclarationNode(
    ParserContext *pContext,
    const YYLTYPE &location,
    ASTNode *pType,
    int symIndex,
    ASTNode *pInitExpr);

  void PreVerifyNodeImpl() override;
  void PostProcessNodeImpl(OutputContext* pContext) override;
  const char *GetDebugName() override { return "VariableDeclarationNode"; }
  TypeNode* GetTypeNode();

private:
  int _symIndex;
  int _arraySize;
};
