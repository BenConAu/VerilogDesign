#include "FunctionInfo.h"

FunctionInfo::FunctionInfo(
    PSLCompilerContext *pContext, // The context that this function lives in
    int symIndex,                 // The symbol index for the identifier for the function
    TypeInfo *pReturnTypeInfo     // The return type
    ) : SymbolInfo(pContext, symIndex)
{
    _pReturnTypeInfo = pReturnTypeInfo;
}
