#include "PSLCompilerContext.h"
#include "ASTTree.h"
#include "PSL.tab.h"
#define YY_EXTRA_TYPE PSLCompilerContext*
#include "lex.h"

PSLCompilerContext::PSLCompilerContext(FILE *pFile) : _regCollection(32)
{
    yylex_init(&pScanner);
    yyset_extra(this, pScanner);

    // set flex to read from file instead of defaulting to STDIN:
    yyrestart(pFile, pScanner);
}

PSLCompilerContext::~PSLCompilerContext()
{
    yylex_destroy(pScanner);
}

int PSLCompilerContext::AddSymbol(const char* pszSymbol)
{
//    printf("Adding symbol\n");

    static std::vector<std::string> g_symbols;

	for (size_t i = 0; i < g_symbols.size(); i++)
	{
		if (g_symbols[i].compare(pszSymbol) == 0)
		{
			return i;
		}
	}

	g_symbols.push_back(pszSymbol);
	return (g_symbols.size() - 1);
}

void PSLCompilerContext::AddExternalDeclaration(ASTNode* pNode)
{
    _rootNodes.push_back(std::unique_ptr<ASTNode>(pNode));
}

void PSLCompilerContext::Parse()
{
    // parse through the input until there is no more:
    yyparse(this);

    for (size_t i = 0; i < _rootNodes.size(); i++)
    {
        _rootNodes[i]->VerifyNode();
    }

    for (size_t i = 0; i < _rootNodes.size(); i++)
    {
        _rootNodes[i]->ProcessNode();
    }
}
