#include "VariableInfo.h"
#include "PSLCompilerContext.h"
#include "FunctionDeclaratorNode.h"
#include "Operand.h"
#include "ExpressionResult.h"
#include "RegisterCollection.h"

unsigned int VariableInfo::_dataSegEnd = 0;

VariableInfo::VariableInfo(
    PSLCompilerContext *pContext,   // The context that this variable lives in
    int symIndex,                   // The symbol index for the identifier for the variable
    FunctionDeclaratorNode *pScope, // The scope that the variable is declared in
    TypeInfo *pInfo                 // The type of the variable
    ) : SymbolInfo(pContext, symIndex)
{
    _pType = pInfo;
    _pScope = pScope;

    if (pInfo == nullptr)
    {
        throw "Variables must have types";
    }

    if (_pScope == nullptr)
    {
        // Globals are always backed with memory storage
        _locationType = LocationType::Memory;

        // Decide on the location
        _memLocation = _dataSegEnd;

        // And adjust for the new location
        _dataSegEnd += 4;
    }
    else
    {
        _locationType = LocationType::Register;
        _memLocation = 0xFFFFFFFF;
    }
}

ExpressionResult *VariableInfo::CalculateResult(FunctionDeclaratorNode *pScope)
{
    switch (_pType->GetTypeClass())
    {
    case TypeClass::Basic:
    {
        // Basic things are always word sized and stored
        // in registers allocated to them. Find out which register it is
        // and make an operand out of that.
        RegisterLocation location = EnsureRegister(pScope);

        return new ExpressionResult(GetTypeInfo(), Operand(location.GetSingleLocation()));
    }

    case TypeClass::Pointer:
    {
        // Basic things are always word sized and stored
        // in registers allocated to them. Find out which register it is
        // and make an operand out of that.
        RegIndex regIndex = EnsureRegister(pScope);

        return new ExpressionResult(GetTypeInfo(), Operand(regIndex));
    }

    case TypeClass::Struct:
        // A pointer is always pointing to memory by definition, as is
        // a struct. For memory located things, create an operand with
        // the constant memory address involved. We might add an offset
        // later.
        if (HasRegister(pScope))
        {
            //printf("Ensuring register for %s\n", GetSymbol());

            // We already have a register for this thing, so we can make an operand
            // out of that. That can be directly used by other things.
            RegIndex regIndex = EnsureRegister(pScope);

            return new ExpressionResult(GetTypeInfo(), Operand(regIndex));
        }
        else
        {
            //printf("No register for %s, returning constant Operand\n", GetSymbol());

            // Don't make a register if you don't need one
            return new ExpressionResult(this, Operand(this, pScope->GetContext()));
        }
    }
}

RegisterLocation VariableInfo::EnsureRegister(FunctionDeclaratorNode *pScope)
{
    //printf("Ensuring register for VariableInfo %s\n", GetSymbol());

    if (_locationMap.find(pScope) == _locationMap.end())
    {
        //printf("Allocating register for VariableInfo %s\n", GetSymbol());

        // Upon the first request for a register at a particular scope,
        // allocate the register.
        RegisterLocation location(pScope->GetRegCollection()->AllocateRegister());
        _locationMap[pScope] = location;
    }

    return _locationMap[pScope];
}

bool VariableInfo::HasRegister(FunctionDeclaratorNode *pScope)
{
    if (_regIndexMap.find(pScope) == _regIndexMap.end())
    {
        return false;
    }

    return true;
}

void VariableInfo::ReserveRegister(FunctionDeclaratorNode *pScope, RegIndex index)
{
    // We are being told which register to use
    pScope->GetRegCollection()->ReserveRegister(index);
    _regIndexMap[pScope] = index;
}
