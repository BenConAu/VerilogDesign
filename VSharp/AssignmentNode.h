#pragma once

#include "StatementNode.h"
#include "VSharp.tab.h"

class FunctionCallNode;

class AssignmentNode : public StatementNode
{
public:
    AssignmentNode(
        ParserContext *pContext,
        const YYLTYPE &location,
        ASTNode *pLeft,
        ASTNode *pRight);

    AssignmentNode(
        ParserContext *pContext,
        const YYLTYPE &location);
  
    ASTNode* DuplicateNode(DuplicateType type) override;
    void VerifyNodeImpl() override;
    void PostProcessNodeImpl(OutputContext* pContext) override;
    const char *GetDebugName() override { return "AssignmentNode"; }
    ASTNode* DuplicateNodeImpl(DuplicateType type) override;
};
