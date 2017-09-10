#pragma once

#include "SymbolInfo.h"

class TypeInfo;
class GenericTypeInfo;

class StateInfo : public SymbolInfo
{
  public:
    StateInfo(
        PSLCompilerContext *pContext, // The context that this function lives in
        ModuleDefinitionNode *pScope, // The module that the state is part of
        int symIndex                  // The symbol index for the identifier for the state
        );
};
