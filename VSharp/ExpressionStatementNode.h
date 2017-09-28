#pragma once

#include "StatementNode.h"

class ExpressionStatementNode : public StatementNode
{
public:
    ExpressionStatementNode(
        ParserContext* pContext, 
        const YYLTYPE &location, 
        ASTNode* pExpr);

    ExpressionStatementNode(
        ParserContext* pContext, 
        const YYLTYPE &location);
    
    const char* GetDebugName() override { return "ExpressionStatementNode"; }
    ASTNode* DuplicateNodeImpl(DuplicateType type) override;
    void PostProcessNodeImpl(OutputContext* pContext) override;
};
