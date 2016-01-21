#pragma once

#include "AssemblerListNode.h"

class DataSegmentItemEntry : public AssemblerNode<DataSegmentItemEntry>
{
public:
    static std::vector<std::unique_ptr<DataSegmentItemEntry> > s_defs;
    static std::vector<std::unique_ptr<DataSegmentItemEntry> >& GlobalList() { return s_defs; }
};

class DataSegmentItemDef : public AssemblerListNode<DataSegmentItemDef,DataSegmentItemEntry>
{
public:
    static std::vector<std::unique_ptr<DataSegmentItemDef> > s_defs;
    static std::vector<std::unique_ptr<DataSegmentItemDef> >& GlobalList() { return s_defs; }
};

class DataSegmentDef : public AssemblerListNode<DataSegmentDef, DataSegmentItemDef>
{
public:
    static int CalcAddress(int symbol)
    {
        for (int ds = 0; ds < DataSegmentDef::s_defs.size(); ds++)
        {
            int startByte = DataSegmentDef::s_defs[ds]->GetIntProperty("address");

        	for (int i = 0; i < DataSegmentDef::s_defs[ds]->GetItemCount(); i++)
        	{
        		DataSegmentItemDef* itemDef = DataSegmentDef::s_defs[ds]->GetItem(i);
                if (itemDef->GetIntProperty("name") == symbol)
                {
                    return startByte;
                }

                //printf("Type of item %d is %d\n", i, itemDef->GetIntProperty("type"));

                startByte += StructDef::GetSize(itemDef->GetIntProperty("type"));
        	}
        }

        return -1;
    }

    static std::vector<std::unique_ptr<DataSegmentDef> > s_defs;
    static std::vector<std::unique_ptr<DataSegmentDef> >& GlobalList() { return s_defs; }
};
