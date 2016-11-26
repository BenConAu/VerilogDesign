#pragma once

#include <map>
#include "RegisterCollection.h"
#include "VariableLocation.h"

class PSLCompilerContext;
class FunctionDeclaratorNode;
class ASTNode;
class TypeInfo;

// Every variable that is declared has to have data tracked for it. This includes
// where it resides in memory (if anywhere), whether it is assigned to a register
// at all, and what type it is.
class VariableInfo
{
public:
    VariableInfo(
        PSLCompilerContext* pContext,   // The context that this variable lives in
        int symIndex,                   // The symbol index for the identifier for the variable
        FunctionDeclaratorNode* pScope, // The scope that the variable is declared in
        TypeInfo* pInfo,                // The type of the variable
        RegIndex* pRegIndex             // The register to use, if known
        );

    LocationType GetLocationType() const { return _locationType; }
    unsigned int GetMemLocation() const { return _memLocation; }
    RegIndex EnsureVariableRegister(FunctionDeclaratorNode* pScope);
    int GetSymbolIndex() const { return _symIndex; }

    TypeInfo* GetTypeInfo() { return _pType; }

    PSLCompilerContext* _pContext;
    int _symIndex;

private:
    // Type of location (globals are stored in data segment, local backed by register)
    LocationType _locationType;

    // Location of variable in memory (not valid for register backed)
    unsigned int _memLocation;

    // Register allocated by scope (globals have multiple register locations mapped)
    std::map<FunctionDeclaratorNode*, RegIndex> _regIndexMap;

    // C++ type of variable
    TypeInfo* _pType;

    // Scope variable was declared in (null if global)
    FunctionDeclaratorNode* _pScope;

    // Track data segment allocations
    static unsigned int _dataSegEnd;
};
