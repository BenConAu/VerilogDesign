#include "StateInfo.h"

StateInfo::StateInfo(
    VSharpCompiler *pCompiler,      // The context that this function lives in
    ASTNode *pScope,                // The module that the state is part of
    int symIndex                    // The symbol index for the identifier for the state
    ) : SymbolInfo(pCompiler, pScope, symIndex)
{
}
