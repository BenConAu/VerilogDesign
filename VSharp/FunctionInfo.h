#pragma once

#include "SymbolInfo.h"

class TypeInfo;
class GenericTypeInfo;
class ModuleDeclaratorNode;
class FunctionDeclaratorNode;

class FunctionInfo : public SymbolInfo
{
  public:
    FunctionInfo(
      PSLCompilerContext *pContext,       // The context that this function lives in
      FunctionDeclaratorNode *pFunction,  // The scope that the variable is declared in
      int symIndex,                       // The symbol index for the identifier for the function
      GenericTypeInfo *pGenInfo           // The type info for the generic of the function
        );

    GenericTypeInfo* GetGenericTypeInfo() { return _pGenTypeInfo; }
    FunctionDeclaratorNode* GetFunctionDeclarator() { return _pFunctionDecl; }

  private:
    GenericTypeInfo* _pGenTypeInfo;
    FunctionDeclaratorNode* _pFunctionDecl;
};
