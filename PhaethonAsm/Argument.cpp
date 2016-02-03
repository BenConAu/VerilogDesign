#include "Argument.h"
#include "DataSegmentDef.h"

void Argument::ResolveSymbol()
{
    switch (_symType)
    {
        case SymbolType::VarAddress:
            _value = DataSegmentDef::CalcAddress(_value);
            //printf("Resolving symbol to %x\n", _value);
            break;

        case SymbolType::LabelAddress:
            _value = GetLabelAddress(_value);
            break;

        default:;
          // Nothing to do here
    }
}
