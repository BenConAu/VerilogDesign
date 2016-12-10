#pragma once

#include "SymbolInfo.h"

class TypeInfo;

class FunctionInfo : public SymbolInfo
{
  public:
    FunctionInfo(
        PSLCompilerContext *pContext, // The context that this function lives in
        int symIndex,                 // The symbol index for the identifier for the function
        TypeInfo *pReturnTypeInfo     // The return type
        );

    TypeInfo* GetReturnTypeInfo() { return _pReturnTypeInfo; }

  private:
    TypeInfo *_pReturnTypeInfo;
};
