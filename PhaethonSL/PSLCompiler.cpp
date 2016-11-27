#define YYDEBUG 1
#include "PSLCompilerContext.h"
#include "ASTTree.h"
#include "PSL.tab.h"
#define YY_EXTRA_TYPE PSLCompilerContext*
#include "lex.h"
#include <cstdio>
#include <iostream>

int main(int argc, char** argv)
{
	//yydebug = 1;
	// open a file handle to a particular file:
	FILE *myfile = ::fopen(argv[1], "r");

    // make sure it is valid:
	if (!myfile)
    {
		std::cout << argv[1] << std::endl;
		return -1;
	}

    PSLCompilerContext context(myfile, argv[2]);

    try
    {
	    context.Parse();
    }
    catch(const char* pszMessage)
    {
        printf("Error: %s\n", pszMessage);
    }
}

void yyerror(void *, const char *s)
{
	std::cout << "EEK, parse error!  Message: " << s << std::endl;
	// might as well halt now:
	exit(-1);
}
