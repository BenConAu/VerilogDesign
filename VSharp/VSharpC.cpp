#define YYDEBUG 1
#include "ParserContext.h"
#include "VSharpCompiler.h"
#include "OutputContext.h"
#include "ASTTree.h"
#include "VSharp.tab.h"
#define YY_EXTRA_TYPE ParserContext *
#include "lex.h"
#include <cstdio>
#include <iostream>
#include <boost/filesystem.hpp>

bool ends_with(std::string const &value, std::string const &ending)
{
    if (ending.size() > value.size())
    {
	return false;
    }

    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

int main(int argc, char **argv)
{
    try
    {
        // Construct output file from input file
        boost::filesystem::path OutFilePath(argv[1]);
        
        // Remove any directory from filename, output is in pwd
        OutFilePath = OutFilePath.filename();

        // Need a new extension
        OutFilePath.replace_extension("sv");

        //yydebug = 1;
        VSharpCompiler compiler;
        ParserContext context(argv[1], &compiler);
        OutputContext outputContext(OutFilePath.c_str(), context.GetDebugContext());
        context.Parse();
        context.Process(&outputContext);
        outputContext.Finish();
    }
    catch (char *pszMessage)
    {
		printf("Error: %s\n", pszMessage);
    }
	catch (const std::string message)
	{
		printf("Error: %s\n", message.c_str());
	}
}

void yyerror(YYLTYPE* pLocation, void *, const char *pszError)
{
	printf("Error on line: %d and col: %d with message: %s\n", pLocation->first_line, pLocation->first_column, pszError);

    // might as well halt now:
    exit(-1);
}
