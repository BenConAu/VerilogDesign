#pragma once

class DataSegmentItemDef : public AssemblerListNode<DataSegmentItemDef,DataSegmentItemEntry>
{
public:
    int CalcSize()
    {
        // Calculate size of the base type
        int baseSize = StructDef::GetSize(GetIntProperty("type"));

        // If the item is an array then use the size
        int arraySize = GetIntProperty("arraySize");
        if (arraySize != 0)
        {
            baseSize *= arraySize;
        }

        //printf("Size of data segment item is %d\n", baseSize);
        return baseSize;
    }

public:
    static std::vector<std::unique_ptr<DataSegmentItemDef> > s_defs;
    static std::vector<std::unique_ptr<DataSegmentItemDef> >& GlobalList() { return s_defs; }
};
