#define YYDEBUG 1
#include "PSLCompilerContext.h"
#include "ASTTree.h"
#include "PSL.tab.h"
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
		// open a file handle to a particular file:
		FILE *myfile = ::fopen(argv[1], "r");

		// make sure it is valid:
		if (!myfile)
		{
	    	std::cout << argv[1] << std::endl;
	    	return -1;
		}

		const char *pszAsmName = nullptr;
		const char *pszObjName = nullptr;

		for (int i = 2; i < argc; i++)
		{
	    	if (ends_with(argv[i], ".asm"))
		    {
				pszAsmName = argv[i];
		    }

		    if (ends_with(argv[i], ".pao"))
		    {
				pszObjName = argv[i];
		    }
		}

	    PSLCompilerContext context(myfile, pszAsmName, pszObjName);

		context.Parse();
    }
    catch (const char *pszMessage)
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
