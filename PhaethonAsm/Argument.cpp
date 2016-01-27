#include "Argument.h"
#include "DataSegmentDef.h"

void Argument::ResolveSymbol()
{
    switch (_symType)
    {
        case SymbolType::VarAddress:
           //printf("Resolving symbol to %x\n", _value);
            _value = DataSegmentDef::CalcAddress(_value);
            break;

        case SymbolType::LabelAddress:
            _value = GetLabelAddress(_value);
            break;

        default:;
          // Nothing to do here
    }
}
