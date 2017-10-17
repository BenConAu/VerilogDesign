#pragma once

#include "ExpressionNode.h"
#include "ParserContext.h"
#include <boost/filesystem.hpp>

class ImportStatementNode : public ASTNode
{
public:
    ImportStatementNode(ParserContext* pContext, const YYLTYPE &location);

    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "ImportStatementNode"; }

private:
    boost::filesystem::path _ImportPath;
    std::unique_ptr<ParserContext> _ImportedContext;
};
