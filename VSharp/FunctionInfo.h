#pragma once

#include "SymbolInfo.h"
#include "FunctionType.h"
#include "UIntConstant.h"
#include <string>
#include <vector>

class TypeInfo;
class GenericTypeInfo;
class ModuleDefinitionNode;
class FunctionDeclaratorNode;
class VSharpCompiler;
class ExpressionNode;

class FunctionInfo : public SymbolInfo
{
  public:
    FunctionInfo(
      VSharpCompiler *pCompiler,          // The context that this function lives in
      FunctionDeclaratorNode *pFunction,  // The scope that the variable is declared in
      int symIndex,                       // The symbol index for the identifier for the function
      bool fGeneric,
      UIntConstant* pGenValue             // The value of the generic symbol (nullptr)
      );
  
    FunctionInfo(
      VSharpCompiler *pCompiler,          // The context that this function lives in
      int symIndex,                       // The symbol index for the identifier for the function
      TypeInfo* pRetType,                 // The return type
      size_t numParam,                    // The parameter count
      const char* pszVerilogName          // What we call in Verilog to do this
      );

    void UpdateInfo(
      FunctionDeclaratorNode *pFunction   // The scope that the variable is declared in
      );
    
    FunctionDeclaratorNode* GetFunctionDeclarator() { return _pFunctionDecl; }
    const std::string& GetVerilogName() { return _verilogName; }
    size_t GetParameterCount() const { return _paramCount; }
    TypeInfo* GetReturnType() { return _pReturnType; }
    UIntConstant GetUIntConstant(int index) { return _spGenValues[index]; }
    size_t GetUIntConstantCount() { return _spGenValues.size(); }
    bool IsGeneric() const { return _fGeneric; }

  private:
    bool _fGeneric;
    std::vector<UIntConstant> _spGenValues;
    FunctionDeclaratorNode* _pFunctionDecl;
    TypeInfo* _pReturnType;
    std::string _verilogName;
    size_t _paramCount;
};
