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
    if (_argType == OperandType::Constant && _symType == SymbolType::None)
    {
        printf("Wat - address of non symbol constant makes no sense\n");
    }

    if (_argType == OperandType::Register)
    {
        printf("Wat - address of register makes no sense\n");
    }

    if (_argType == OperandType::DerefConstant &&
        _symType == SymbolType::VarAddress)
    {
        // Somebody wants to store the address of a variable, so
        // changing the modifer will give us the right thing after
        // the symbol has been looked up
        _argType = OperandType::Constant;
    }
}

void Argument::Deref()
{
    switch(_argType)
    {
        case OperandType::Constant:
            _argType = OperandType::DerefConstant;
            break;

        case OperandType::Register:
            _argType = OperandType::DerefRegister;
            break;

        default:
            throw "Not a valid operand to derefence\n";
    }
}
