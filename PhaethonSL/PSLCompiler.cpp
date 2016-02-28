#include "PSLCompilerContext.h"
#include "ASTTree.h"
#include "PSL.tab.h"
#define YY_EXTRA_TYPE PSLCompilerContext*
#include "lex.h"
#include <cstdio>
#include <iostream>

int main(int, char**)
{
	//yydebug = 1;
	// open a file handle to a particular file:
	FILE *myfile = ::fopen("test.psl", "r");

    // make sure it is valid:
	if (!myfile)
    {
		std::cout << "I can't open a.snazzle.file!" << std::endl;
		return -1;
	}

    PSLCompilerContext context(myfile);

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
