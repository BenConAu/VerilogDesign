#include "Argument.h"
#include "DataSegmentDef.h"

void Argument::ResolveSymbol()
{
    switch (_symType)
    {
    case SymbolType::VarAddress:
        _objArg._value = DataSegmentDef::CalcAddress(_objArg._value);
        //printf("Resolving symbol to %x\n", _value);
        break;

    case SymbolType::LabelAddress:
        _objArg._value = GetLabelAddress(_objArg._value);
        break;

    default:;
        // Nothing to do here
    }
}

void Argument::AddressOf()
{
    if (_argType._type == OperandType::Constant && _symType == SymbolType::None)
    {
        printf("Wat - address of non symbol constant makes no sense\n");
    }

    if (_argType._type == OperandType::Register)
    {
        printf("Wat - address of register makes no sense\n");
    }

    if (_argType._type == OperandType::Constant &&
        _argType._modifier == OperandModifier::Deref &&
        _symType == SymbolType::VarAddress)
    {
        // Somebody wants to store the address of a variable, so
        // changing the modifer will give us the right thing after
        // the symbol has been looked up
        _argType._modifier = OperandModifier::None;
    }
}

void Argument::Deref()
{
    if (_argType._modifier != OperandModifier::None)
    {
        printf("You already had a modifer\n");
    }

    _argType._modifier = OperandModifier::Deref;
}
