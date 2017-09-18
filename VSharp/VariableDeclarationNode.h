#pragma once

#include "ASTNode.h"

class TypeNode;
class ExpressionNode;

class VariableDeclarationNode : public ASTNode
{
public:
  VariableDeclarationNode(
    ParserContext *pContext,
    const YYLTYPE &location,
    ASTNode *pType,
    int symIndex,
    ASTNode *pArraySizeExpr,
    ASTNode *pInitExpr);

  void VerifyNodeImpl() override;
  void PostProcessNodeImpl(OutputContext* pContext) override;
  const char *GetDebugName() override { return "VariableDeclarationNode"; }
  TypeNode* GetTypeNode();
  ExpressionNode* GetInitNode();

private:
  int _symIndex;
  int _arraySize;
};
