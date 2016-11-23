#pragma once

#include "AssemblerListNode.h"
#include "PhaethonAsmLib.h"
#include "StructDef.h"
#include "InstructionNode.h"
#include "DataSegmentItemEntry.h"
#include "DataSegmentItemDef.h"

class DataSegmentDef : public AssemblerListNode<DataSegmentDef, DataSegmentItemDef>
{
public:
    DataSegmentDef();

    void OutputDataSegment();
    int GetSize();

    static void ResolveSymbols();
    static int CalcAddress(int symbol);

private:
    int _startAddress;
};
