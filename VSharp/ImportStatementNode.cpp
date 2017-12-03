#include "ImportStatementNode.h"
#include "ParserContext.h"
#include <libgen.h>

ImportStatementNode::ImportStatementNode(ParserContext* pContext, const YYLTYPE &location) : ASTNode(pContext, location)
{
    // Save the literal that was given in the source code
    _ImportPath = boost::filesystem::path(pContext->GetLastString());

    //printf("Creating import with path %s\n", _ImportPath.c_str());    

    // If it is relative, then adjust based on the parent path
    if (_ImportPath.is_relative())
    {
        // We are relative to the file that included us
        boost::filesystem::path IncludingPath(pContext->GetCurrentFile());

        // Remove the filename from the including path
        IncludingPath = IncludingPath.parent_path();

        // Add the given path
        _ImportPath = IncludingPath.append(_ImportPath.string());
    }

    //printf("Path after adjustment is %s\n", _ImportPath.c_str());
}

void ImportStatementNode::VerifyNodeImpl()  
{
    _ImportedContext.reset(new ParserContext(_ImportPath.c_str(), GetContext()->GetCompiler()));
    _ImportedContext->Parse();
}
