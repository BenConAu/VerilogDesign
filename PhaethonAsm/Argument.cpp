#include "Argument.h"
#include "DataSegmentDef.h"

void Argument::ResolveSymbol()
{
    if (_fDelayed)
    {
        _value = DataSegmentDef::CalcAddress(_value);
        _fDelayed = false;

        //printf("Resolving symbol to %x\n", _value);
    }
}
