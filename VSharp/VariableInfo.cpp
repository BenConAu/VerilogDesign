#include "VariableInfo.h"
#include "PSLCompilerContext.h"
#include "ModuleDeclaratorNode.h"
#include "Operand.h"
#include "ExpressionResult.h"

unsigned int VariableInfo::_dataSegEnd = 0;

VariableInfo::VariableInfo(
    PSLCompilerContext *pContext,   // The context that this variable lives in
    int symIndex,                   // The symbol index for the identifier for the variable
    ModuleDeclaratorNode *pScope,   // The scope that the variable is declared in
    TypeInfo *pInfo                 // The type of the variable
    ) : SymbolInfo(pContext, pScope, symIndex)
{
    if (pInfo == nullptr)
    {
        throw "Variables must have types";
    }

    _pType = pInfo;

    if (GetScope() == nullptr)
    {
        //printf("New memory location for %s at %x\n", GetSymbol(), _dataSegEnd);

        // Globals are always backed with memory storage
        _locationType = LocationType::Memory;

        // Decide on the location
        _memLocation = _dataSegEnd;

        // And adjust for the new location
        _dataSegEnd += pInfo->GetSize();
    }
    else
    {
        _locationType = LocationType::Register;
        _memLocation = 0xFFFFFFFF;
    }
}

ExpressionResult *VariableInfo::CalculateResult(ModuleDeclaratorNode *pScope)
{
    switch (_pType->GetTypeClass())
    {
    case TypeClass::Basic:
    case TypeClass::Pointer:
    case TypeClass::Struct:
        if (_pType->GetTypeClass() == TypeClass::Struct && !GetFunctionInfo(pScope)._referenced)
        {
            //printf("Returning address of struct for result\n");

            // If the struct was not referenced then just return the address and use it
            return new ExpressionResult(Operand(this, pScope->GetContext()));
        }
        else
        {
            return nullptr;
        }

    case TypeClass::Generic:
        throw "Cannot make an expression result from a generic";

    case TypeClass::Array:
        throw "Cannot make an expression result from an array";
    }
}

void VariableInfo::ReferenceFrom(ModuleDeclaratorNode *pScope)
{
    // This should create things if not already created and no-op otherwise
    _regIndexMap[pScope]._referenced = true;
}

const PerFunctionInfo &VariableInfo::GetFunctionInfo(ModuleDeclaratorNode *pScope)
{
    return _regIndexMap[pScope];
}
