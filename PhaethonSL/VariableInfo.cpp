#include "VariableInfo.h"
#include "PSLCompilerContext.h"
#include "FunctionDeclaratorNode.h"
#include "Operand.h"
#include "ExpressionResult.h"

unsigned int VariableInfo::_dataSegEnd = 0;

VariableInfo::VariableInfo(
    PSLCompilerContext *pContext,   // The context that this variable lives in
    int symIndex,                   // The symbol index for the identifier for the variable
    FunctionDeclaratorNode *pScope, // The scope that the variable is declared in
    TypeInfo *pInfo                 // The type of the variable
    ) : SymbolInfo(pContext, symIndex)
{
    if (pInfo == nullptr)
    {
        throw "Variables must have types";
    }

    _pType = pInfo;
    _pScope = pScope;

    if (_pScope == nullptr)
    {
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

ExpressionResult *VariableInfo::CalculateResult(FunctionDeclaratorNode *pScope)
{
    switch (_pType->GetTypeClass())
    {
    case TypeClass::Basic:
    case TypeClass::Pointer:
    case TypeClass::Struct:
        if (_pType->GetTypeClass() == TypeClass::Struct && !HasRegister(pScope))
        {
            // Structs we don't ensure a register for until we absolutely need to, which
            // is currently only during field selection of the struct. So load the address
            // into a constant operand for now.
            return new ExpressionResult(Operand(this, pScope->GetContext()));
        }
        else
        {
            // Structs that already have registers and non-struct things can all go
            // down the path of being in a register and loading the operand with that.
            RegIndex regIndex = EnsureRegister(pScope);
            return new ExpressionResult(Operand(regIndex));
        }

    case TypeClass::Generic:
        throw "Cannot make an expression result from a generic";

    case TypeClass::Array:
        throw "Cannot make an expression result from an array";
    }
}

RegIndex VariableInfo::EnsureRegister(FunctionDeclaratorNode *pScope)
{
    //printf("Ensuring register for VariableInfo %s\n", GetSymbol());

    if (_regIndexMap.find(pScope) == _regIndexMap.end())
    {
        //printf("Allocating register for VariableInfo %s\n", GetSymbol());

        // Upon the first request for a register at a particular scope,
        // allocate the register.
        _regIndexMap[pScope] = pScope->GetRegCollection()->AllocateRegister();
    }

    return _regIndexMap[pScope];
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
