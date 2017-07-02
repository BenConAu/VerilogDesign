#include "StateInfo.h"

StateInfo::StateInfo(
    PSLCompilerContext *pContext, // The context that this function lives in
    ModuleDeclaratorNode *pScope, // The module that the state is part of
    int symIndex                  // The symbol index for the identifier for the state
    ) : SymbolInfo(pContext, pScope, symIndex)
{
}
