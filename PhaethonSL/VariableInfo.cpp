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
        RegIndex regIndex = pVarPath->EnsurePathRegister(pScope);

        return new ExpressionResult(GetTypeInfo(), Operand(regIndex));
    }

    case TypeClass::Pointer:
    {
        // Basic things are always word sized and stored
        // in registers allocated to them. Find out which register it is
        // and make an operand out of that.
        RegIndex regIndex = pVarPath->EnsurePathRegister(pScope);

        return new ExpressionResult(GetTypeInfo(), pVarPath, Operand(regIndex));
    }
    
    case TypeClass::Struct:
        // A pointer is always pointing to memory by definition, as is
        // a struct. For memory located things, create an operand with
        // the constant memory address involved. We might add an offset
        // later.
        return new ExpressionResult(GetTypeInfo(), pVarPath, Operand(this, pScope->GetContext()));
    }
}
