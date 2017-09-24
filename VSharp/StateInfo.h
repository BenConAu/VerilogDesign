#pragma once

#include "SymbolInfo.h"

class TypeInfo;
class GenericTypeInfo;
class VSharpCompiler;
class ModuleDefinitionNode;

class StateInfo : public SymbolInfo
{
  public:
    StateInfo(
        VSharpCompiler *pCompiler,    // The context that this function lives in
        ASTNode *pScope,              // The module that the state is part of
        int symIndex                  // The symbol index for the identifier for the state
        );
};
