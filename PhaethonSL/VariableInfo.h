#pragma once

#include <map>
#include "RegisterCollection.h"
#include "VariableLocation.h"
#include "SymbolInfo.h"

class FunctionDeclaratorNode;
class ASTNode;
class TypeInfo;
class ExpressionResult;

// Every variable that is declared has to have data tracked for it. This includes
// where it resides in memory (if anywhere), whether it is assigned to a register
// at all, and what type it is.
class VariableInfo : public SymbolInfo
{
  public:
    VariableInfo(
        PSLCompilerContext *pContext,   // The context that this variable lives in
        int symIndex,                   // The symbol index for the identifier for the variable
        FunctionDeclaratorNode *pScope, // The scope that the variable is declared in
        TypeInfo *pInfo                 // The type of the variable
        );

    LocationType GetLocationType() const { return _locationType; }
    unsigned int GetMemLocation() const { return _memLocation; }
    ExpressionResult *CalculateResult(FunctionDeclaratorNode *pScope);
    FunctionDeclaratorNode *GetScope() { return _pScope; }

    void ReserveRegister(FunctionDeclaratorNode *pScope, RegIndex index);
    RegIndex EnsureRegister(FunctionDeclaratorNode *pScope);
    bool HasRegister(FunctionDeclaratorNode *pScope);

    TypeInfo *GetTypeInfo() { return _pType; }

  private:
    // Type of location (globals are stored in data segment, local backed by register)
    LocationType _locationType;

    // Location of variable in memory (not valid for register backed)
    unsigned int _memLocation;

    // C++ type of variable
    TypeInfo *_pType;

    // Scope variable was declared in (null if global)
    FunctionDeclaratorNode *_pScope;

    // Register allocated by scope (globals have multiple register locations mapped)
    std::map<FunctionDeclaratorNode *, RegIndex> _regIndexMap;

    // Track data segment allocations
    static unsigned int _dataSegEnd;
};
