#pragma once

#include <map>
#include "RegisterCollection.h"
#include "VariableLocation.h"
#include "SymbolInfo.h"

class ASTNode;
class TypeInfo;
class ExpressionResult;

struct PerFunctionInfo
{
    PerFunctionInfo()
    {
        _referenced = false;
        _allocated = false;
    }

    bool _referenced;
    bool _allocated;
};

// Every variable that is declared has to have data tracked for it. This includes
// where it resides in memory (if anywhere), whether it is assigned to a register
// at all, and what type it is.
class VariableInfo : public SymbolInfo
{
  public:
    VariableInfo(
        PSLCompilerContext *pContext,   // The context that this variable lives in
        int symIndex,                   // The symbol index for the identifier for the variable
        ModuleDeclaratorNode *pScope,   // The scope that the variable is declared in
        TypeInfo *pInfo                 // The type of the variable
        );

    LocationType GetLocationType() const { return _locationType; }
    ExpressionResult *CalculateResult(ModuleDeclaratorNode *pScope);

    void ReferenceFrom(ModuleDeclaratorNode *pScope);
    
    const PerFunctionInfo& GetFunctionInfo(ModuleDeclaratorNode *pScope);

    TypeInfo *GetTypeInfo() { return _pType; }

  private:
    // Type of location (globals are stored in data segment, local backed by register)
    LocationType _locationType;

    // C++ type of variable
    TypeInfo *_pType;

    // Register allocated by scope (globals have multiple register locations mapped)
    std::map<ModuleDeclaratorNode *, PerFunctionInfo> _regIndexMap;
};
