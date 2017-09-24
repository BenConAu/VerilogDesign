#include "SymbolInfo.h"
#include "VSharpCompiler.h"

SymbolInfo::SymbolInfo(
    VSharpCompiler *pCompiler,      // The context that this symbol lives in
    ASTNode *pScope,                // The scope of the symbol
    int symIndex                    // The symbol index for the identifier for the symbol
    )
{
    _pCompiler = pCompiler;
    _pScope = pScope;
    _symIndex = symIndex;
}

const char *SymbolInfo::GetSymbol()
{
    return _pCompiler->GetSymbolString(_symIndex).c_str();
}
