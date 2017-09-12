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
    TypeCollection* GetTypeCollection();
    SymbolTable* GetSymbolTable();
    const std::string& GetSymbolString(int symIndex);
    
    void ImportContext(ParserContext* pChildContext);

  private:
    ParserContext* _pParent;
    SymbolTable _symbolTable;
    TypeCollection _typeCollection;
    std::vector<std::string> _symbols;
};
