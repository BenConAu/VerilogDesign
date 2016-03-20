#pragma once

#include "RegisterCollection.h"
#include "VariableLocation.h"

class PSLCompilerContext;
class FunctionDeclaratorNode;
class ASTNode;
class TypeInfo;

class VariableInfo
{
public:
    VariableInfo(
        PSLCompilerContext* pContext,
        int symIndex,
        FunctionDeclaratorNode* pScope,
        TypeInfo* pInfo
        );

    LocationType GetLocationType() { return _locationType; }
    unsigned int GetMemLocation();
    RegIndex GetRegIndex(FunctionDeclaratorNode* pScope);
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
