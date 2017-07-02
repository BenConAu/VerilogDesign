#include "ModuleInfo.h"

ModuleInfo::ModuleInfo(
    PSLCompilerContext *pContext, // The context that this function lives in
    int symIndex,                 // The symbol index for the identifier for the function
    GenericTypeInfo *pGenInfo     // The type info for the generic of the function
    ) : SymbolInfo(pContext, nullptr, symIndex)
{
    _pGenTypeInfo = pGenInfo;
}
