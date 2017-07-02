#pragma once

#include "SymbolInfo.h"

class TypeInfo;
class GenericTypeInfo;

class ModuleInfo : public SymbolInfo
{
  public:
    ModuleInfo(
        PSLCompilerContext *pContext, // The context that this function lives in
        int symIndex,                 // The symbol index for the identifier for the function
        GenericTypeInfo *pGenInfo,    // The type info for the generic of the function
        TypeInfo *pReturnTypeInfo     // The return type
        );

    TypeInfo* GetReturnTypeInfo() { return _pReturnTypeInfo; }
    GenericTypeInfo* GetGenericTypeInfo() { return _pGenTypeInfo; }

  private:
    TypeInfo *_pReturnTypeInfo;
    GenericTypeInfo* _pGenTypeInfo;
};
