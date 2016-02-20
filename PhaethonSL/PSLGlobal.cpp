#include "PSLGlobal.h"
#include "ASTTree.h"
#include <memory>
#include <vector>
#include <string>

RegisterCollection _regCollection(32);
VariableCollection _varCollection;

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
