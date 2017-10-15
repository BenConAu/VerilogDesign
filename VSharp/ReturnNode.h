#pragma once

#include "ASTNode.h"

class ReturnNode : public ASTNode
{
    public:
        ReturnNode(
            ParserContext *pContext, 
            const YYLTYPE &location, 
            ASTNode *pChild) : ASTNode(pContext, location)
        {
          AddNode(pChild);
        }

        ReturnNode(
            ParserContext *pContext, 
            const YYLTYPE &location) : ASTNode(pContext, location)
        {
        }

        ASTNode* DuplicateNode(FunctionExpandType type) override;
        const char* GetDebugName() override { return "ReturnNode"; }
        ASTNode* DuplicateNodeImpl(FunctionExpandType type) override;
};
