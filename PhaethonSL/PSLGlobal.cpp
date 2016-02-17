#include "PSLGlobal.h"
#include "ASTTree.h"
#include <memory>
#include <vector>
#include <string>

RegisterCollection _regCollection(32);

int AddSymbol(const char* pszSymbol)
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

void ProcessStatementList(ASTNode* pRawNode)
{
    StatementListNode* pListNode = dynamic_cast<StatementListNode*>(pRawNode);

    for (size_t i = 0; i < pListNode->GetChildCount(); i++)
    {
        pListNode->GetChild(i)->ProcessNode();
    }
}
