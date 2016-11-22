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
