#pragma once

#include "SymbolTable.h"
#include "TypeCollection.h"
#include "DebugContext.h"
#include <stack>

class VSharpCompiler
{
public:
    VSharpCompiler();

    int AddSymbol(const char *pszSymbol);
    bool EnsureImport(const char *pszImport);
    TypeCollection* GetTypeCollection();
    SymbolTable* GetSymbolTable();
    const std::string& GetSymbolString(int symIndex);
    DebugContext* GetDebugContext() { return &_DebugContext; }

    void ImportContext(ParserContext* pChildContext);

private:
    DebugContext _DebugContext;
    SymbolTable _symbolTable;
    TypeCollection _typeCollection;
    std::vector<std::string> _symbols;
    std::map<std::string, int> _imports;
};
