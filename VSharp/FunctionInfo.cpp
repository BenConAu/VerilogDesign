#include "FunctionInfo.h"
#include "FunctionDeclaratorNode.h"
#include "ModuleDefinitionNode.h"

FunctionInfo::FunctionInfo(
    VSharpCompiler *pCompiler,          // The context that this function lives in
    FunctionDeclaratorNode *pFunction,  // The scope that the variable is declared in
    int symIndex,                       // The symbol index for the identifier for the function
    bool fGeneric,
    UIntConstant* pGenValue             // The value of the generic symbol (nullptr)
  ) : SymbolInfo(pCompiler, pFunction != nullptr ? pFunction->GetTypedParent<ModuleDefinitionNode>() : nullptr, symIndex)
{
    _fGeneric = fGeneric; 

    if (pGenValue != nullptr)
    {
        _spGenValues.push_back(*pGenValue); 
    }

    _pFunctionDecl = pFunction;

    if (pFunction != nullptr)
    {
        UpdateInfo(pFunction);
    }
    else
    {
        _pReturnType = nullptr;
    }
}

FunctionInfo::FunctionInfo(
    VSharpCompiler *pCompiler,          // The context that this function lives in
    int symIndex,                       // The symbol index for the identifier for the function
    TypeInfo* pRetType,                 // The return type
    size_t numParam,                    // The parameter count
    const char* pszVerilogName          // What we call in Verilog to do this
    ) : SymbolInfo(pCompiler, nullptr, symIndex)
{
    _pFunctionDecl = nullptr;
    _verilogName = pszVerilogName;
    _paramCount = numParam;
    _pReturnType = pRetType;
}

void FunctionInfo::UpdateInfo(
    FunctionDeclaratorNode *pFunction   // The scope that the variable is declared in
  )
{
    _pFunctionDecl = pFunction;
    _paramCount = pFunction->GetParameterCount();
    _pReturnType = pFunction->GetReturnType()->GetTypeInfo();
}

