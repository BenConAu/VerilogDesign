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

ExpressionResult *VariableInfo::CalculateResult(FunctionDeclaratorNode *pScope)
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
            // The register should have been allocated already if it is a struct
            // at the start of the function, so in that case this should never
            // do an allocation. Anything else can get allocated here.
            RegIndex regIndex = EnsureRegister(pScope, nullptr);

            //printf("Returning register %d for result\n", (int)regIndex);

            return new ExpressionResult(Operand(regIndex));
        }

    case TypeClass::Generic:
        throw "Cannot make an expression result from a generic";

    case TypeClass::Array:
        throw "Cannot make an expression result from an array";
    }
}

void VariableInfo::ReferenceFrom(FunctionDeclaratorNode *pScope)
{
    // This should create things if not already created and no-op otherwise
    _regIndexMap[pScope]._referenced = true;
}

RegIndex VariableInfo::EnsureRegister(
    FunctionDeclaratorNode *pScope,
    RegIndex *pIndex)
{
    //printf("Ensuring register for VariableInfo %s\n", GetSymbol());

    if (_pType->GetTypeClass() == TypeClass::Struct && !_regIndexMap[pScope]._referenced)
    {
        throw "Why are you ensuring a register for a struct that was not referenced?";
    }

    if (!_regIndexMap[pScope]._allocated)
    {
        // Upon the first request for a register at a particular scope,
        // allocate the register. If something was provided then use that,
        // otherwise allocate something.
        if (pIndex == nullptr)
        {
            _regIndexMap[pScope]._regIndex = pScope->GetRegCollection()->AllocateRegister();
        }
        else
        {
            pScope->GetRegCollection()->ReserveRegister(*pIndex);
            _regIndexMap[pScope]._regIndex = *pIndex;
        }

        // Mark this as allocated
        _regIndexMap[pScope]._allocated = true;

        //printf(
            //"Allocating register %d for VariableInfo %s at location %x\n",
            //(int)_regIndexMap[pScope]._regIndex,
            //GetSymbol(),
            //_memLocation);
    }

    return _regIndexMap[pScope]._regIndex;
}

const PerFunctionInfo &VariableInfo::GetFunctionInfo(FunctionDeclaratorNode *pScope)
{
    return _regIndexMap[pScope];
}
