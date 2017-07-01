#define YYDEBUG 1
#include "PSLCompilerContext.h"
#include "ASTTree.h"
#include "VSharp.tab.h"
#define YY_EXTRA_TYPE PSLCompilerContext *
#include "lex.h"
#include <cstdio>
#include <iostream>

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
		//yydebug = 1;
	    PSLCompilerContext context(argv[1]);

		context.Parse();
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
	printf("Error on line: %d with message: %s\n", pLocation->first_line, pszError);

    // might as well halt now:
    exit(-1);
}
