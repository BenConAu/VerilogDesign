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
    )
{
    _pContext = pContext;
    _pType = pInfo;
    _symIndex = symIndex;
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

const char*VariableInfo::GetSymbol()
{
    return _pContext->_symbols[_symIndex].c_str();
}

ExpressionResult *VariableInfo::CalculateResult(FunctionDeclaratorNode *pScope)
{
    VariablePath *pVarPath = pScope->GetContext()->_pathCollection.EnsurePath(this);

    switch (_pType->GetTypeClass())
    {
    case TypeClass::Basic:
    {
        // Basic things are always word sized and stored
        // in registers allocated to them. Find out which register it is
        // and make an operand out of that.
        RegIndex regIndex = pVarPath->GetVariableInfo()->EnsurePathRegister(pScope);

        return new ExpressionResult(GetTypeInfo(), Operand(regIndex));
    }

    case TypeClass::Pointer:
    {
        // Basic things are always word sized and stored
        // in registers allocated to them. Find out which register it is
        // and make an operand out of that.
        RegIndex regIndex = pVarPath->GetVariableInfo()->EnsurePathRegister(pScope);

        return new ExpressionResult(GetTypeInfo(), pVarPath, Operand(regIndex));
    }

    case TypeClass::Struct:
        // A pointer is always pointing to memory by definition, as is
        // a struct. For memory located things, create an operand with
        // the constant memory address involved. We might add an offset
        // later.
        if (pVarPath->GetVariableInfo()->HasRegister(pScope))
        {
            printf("Ensuring register for %s\n", GetSymbol());

            // We already have a register for this thing, so we can make an operand
            // out of that. That can be directly used by other things.
            RegIndex index = pVarPath->GetVariableInfo()->EnsurePathRegister(pScope);

            return new ExpressionResult(GetTypeInfo(), pVarPath, Operand(index));
        }
        else
        {
            printf("No register for %s, returning constant Operand\n", GetSymbol());

            // Don't make a register if you don't need one
            return new ExpressionResult(GetTypeInfo(), pVarPath, Operand(this, pScope->GetContext()));
        }
    }
}

RegIndex VariableInfo::EnsurePathRegister(FunctionDeclaratorNode* pScope)
{
    printf("Ensuring register for VariableInfo %s\n", GetSymbol());

    if (_regIndexMap.find(pScope) == _regIndexMap.end())
    {
        printf("Allocating register for VariableInfo %s\n", GetSymbol());

        // Upon the first request for a register at a particular scope,
        // allocate the register.
        _regIndexMap[pScope] = pScope->GetRegCollection()->AllocateRegister();
    }

    return _regIndexMap[pScope];
}

bool VariableInfo::HasRegister(FunctionDeclaratorNode* pScope)
{
    if (_regIndexMap.find(pScope) == _regIndexMap.end())
    {
        return false;
    }

    return true;
}

void VariableInfo::ReserveRegister(FunctionDeclaratorNode* pScope, RegIndex index)
{
    // We are being told which register to use
    pScope->GetRegCollection()->ReserveRegister(index);
    _regIndexMap[pScope] = index;    
}

