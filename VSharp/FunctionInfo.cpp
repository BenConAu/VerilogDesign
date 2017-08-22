#include "FunctionInfo.h"
#include "FunctionDeclaratorNode.h"
#include "ModuleDeclaratorNode.h"

FunctionInfo::FunctionInfo(
    PSLCompilerContext *pContext,       // The context that this function lives in
    FunctionDeclaratorNode *pFunction,  // The scope that the variable is declared in
    int symIndex,                       // The symbol index for the identifier for the function
    GenericTypeInfo *pGenInfo           // The type info for the generic of the function
    ) : SymbolInfo(pContext, pFunction->GetTypedParent<ModuleDeclaratorNode>(), symIndex)
{
    _pGenTypeInfo = pGenInfo;
    _pFunctionDecl = pFunction;
    _paramCount = pFunction->GetParameterCount();
    _pReturnType = pFunction->GetReturnType()->GetTypeInfo();
}

FunctionInfo::FunctionInfo(
    PSLCompilerContext *pContext,       // The context that this function lives in
    int symIndex,                       // The symbol index for the identifier for the function
    TypeInfo* pRetType,                 // The return type
    size_t numParam,                    // The parameter count
    const char* pszVerilogName          // What we call in Verilog to do this
    ) : SymbolInfo(pContext, nullptr, symIndex)
{
    _pGenTypeInfo = nullptr;
    _pFunctionDecl = nullptr;
    _verilogName = pszVerilogName;
    _paramCount = numParam;
    _pReturnType = pRetType;
}
