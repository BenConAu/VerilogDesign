#include "FunctionInfo.h"

FunctionInfo::FunctionInfo(
    PSLCompilerContext *pContext, // The context that this function lives in
    int symIndex,                 // The symbol index for the identifier for the function
    GenericTypeInfo *pGenInfo,    // The type info for the generic of the function
    TypeInfo *pReturnTypeInfo     // The return type
    ) : SymbolInfo(pContext, nullptr, symIndex)
{
    _pReturnTypeInfo = pReturnTypeInfo;
    _pGenTypeInfo = pGenInfo;
}
