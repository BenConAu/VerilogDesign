#include "VSharpCompiler.h"

VSharpCompiler::VSharpCompiler() : _symbolTable(this)
{
    _symbolTable.AddBuiltin();    
}

int VSharpCompiler::AddSymbol(const char *pszSymbol)
{
    //    printf("Adding symbol\n");
    for (size_t i = 0; i < _symbols.size(); i++)
    {
        if (_symbols[i].compare(pszSymbol) == 0)
        {
            return i;
        }
    }

    _symbols.push_back(pszSymbol);
    return (_symbols.size() - 1);
}

bool VSharpCompiler::EnsureImport(const char *pszImport)
{
    _imports[pszImport]++;

    // We return if this is the first time this is imported
    return (_imports[pszImport] == 1);
}

const std::string& VSharpCompiler::GetSymbolString(int symIndex) 
{
    return _symbols[symIndex];         
}

TypeCollection* VSharpCompiler::GetTypeCollection() 
{
    return &_typeCollection;
}

SymbolTable* VSharpCompiler::GetSymbolTable() 
{ 
    return &_symbolTable; 
}
