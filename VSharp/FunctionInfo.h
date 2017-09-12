#pragma once

#include "SymbolInfo.h"
#include <string>

class TypeInfo;
class GenericTypeInfo;
class ModuleDefinitionNode;
class FunctionDeclaratorNode;
class VSharpCompiler;

class FunctionInfo : public SymbolInfo
{
  public:
    FunctionInfo(
      VSharpCompiler *pCompiler,          // The context that this function lives in
      FunctionDeclaratorNode *pFunction,  // The scope that the variable is declared in
      int symIndex,                       // The symbol index for the identifier for the function
      GenericTypeInfo *pGenInfo           // The type info for the generic of the function
      );

    FunctionInfo(
      VSharpCompiler *pCompiler,          // The context that this function lives in
      int symIndex,                       // The symbol index for the identifier for the function
      TypeInfo* pRetType,                 // The return type
      size_t numParam,                    // The parameter count
      const char* pszVerilogName          // What we call in Verilog to do this
      );

    GenericTypeInfo* GetGenericTypeInfo() { return _pGenTypeInfo; }
    FunctionDeclaratorNode* GetFunctionDeclarator() { return _pFunctionDecl; }
    const std::string& GetVerilogName() { return _verilogName; }
    size_t GetParameterCount() const { return _paramCount; }
    TypeInfo* GetReturnType() { return _pReturnType; }

  private:
    GenericTypeInfo* _pGenTypeInfo;
    FunctionDeclaratorNode* _pFunctionDecl;
    TypeInfo* _pReturnType;
    std::string _verilogName;
    size_t _paramCount;
};
