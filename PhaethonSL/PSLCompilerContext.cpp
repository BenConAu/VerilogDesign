#include "PSLCompilerContext.h"
#include "ASTTree.h"
#include "PSL.tab.h"
#define YY_EXTRA_TYPE PSLCompilerContext*
#include "lex.h"

RegisterCollection _regCollection(32);
VariableCollection _varCollection;

PSLCompilerContext::PSLCompilerContext()
{
    yylex_init(&pScanner);
    yyset_extra(this, pScanner);
}

PSLCompilerContext::~PSLCompilerContext()
{
    yylex_destroy(pScanner);
}

int PSLCompilerContext::AddSymbol(const char* pszSymbol)
{
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
