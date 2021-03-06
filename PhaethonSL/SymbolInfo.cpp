#include "SymbolInfo.h"
#include "PSLCompilerContext.h"

SymbolInfo::SymbolInfo(
    PSLCompilerContext *pContext,   // The context that this symbol lives in
    FunctionDeclaratorNode *pScope, // The scope of the symbol
    int symIndex                    // The symbol index for the identifier for the symbol
    )
{
    _pContext = pContext;
    _pScope = pScope;
    _symIndex = symIndex;
}

const char *SymbolInfo::GetSymbol()
{
    return _pContext->_symbols[_symIndex].c_str();
}
