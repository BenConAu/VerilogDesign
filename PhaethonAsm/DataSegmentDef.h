#pragma once

#include "AssemblerListNode.h"
#include "PhaethonAsmLib.h"
#include "StructDef.h"
#include "InstructionNode.h"

class DataSegmentItemEntry : public AssemblerNode<DataSegmentItemEntry>
{
public:
    static std::vector<std::unique_ptr<DataSegmentItemEntry> > s_defs;
    static std::vector<std::unique_ptr<DataSegmentItemEntry> >& GlobalList() { return s_defs; }
};

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

class DataSegmentDef : public AssemblerListNode<DataSegmentDef, DataSegmentItemDef>
{
public:
    DataSegmentDef()
    {
        _startAddress = -1;
    }

    void OutputDataSegment()
    {
    	for (int i = 0; i < GetItemCount(); i++)
    	{
    		//		printf("Doing item %d in Data segment\n", i);

    		DataSegmentItemDef* itemDef = GetItem(i);
    		//		printf("Item %d has count %d\n", i, itemDef->GetItemCount());

            int arraySize = itemDef->GetIntProperty("arraySize");
            if (arraySize != 0)
            {
                for (int j = 0; j < arraySize; j++)
                {
                    OutputWord(0x13371337);
                }
            }
            else
            {
    		    for (int j = 0; j < itemDef->GetItemCount(); j++)
    		    {
    			    DataSegmentItemEntry* entry = itemDef->GetItem(j);

    	            OutputWord(entry->GetIntProperty("value"));
    		    }
            }
    	}
    }

    int GetSize()
    {
        int size = 0;

        for (int i = 0; i < GetItemCount(); i++)
        {
            size += GetItem(i)->CalcSize();
        }

        return size;
    }

    static void ResolveSymbols()
    {
        // We know the start position of the data segments - end of code
        int startByte = InstructionNode::GetCodeSize();

        // Set the start address of each segment
        for (size_t i = 0; i < DataSegmentDef::s_defs.size(); i++)
        {
            //printf("Setting start of segment to %x\n", startByte);
            s_defs[i]->_startAddress = startByte;
            startByte += s_defs[i]->GetSize();
        }

        // Now we can resolve all of the instructions
        for (size_t i = 0; i < InstructionNode::GlobalList().size(); i++)
        {
            InstructionNode::GlobalList()[i]->ResolveSymbols();
        }
    }

    static int CalcAddress(int symbol)
    {
        for (int ds = 0; ds < DataSegmentDef::s_defs.size(); ds++)
        {
            int startByte = s_defs[ds]->_startAddress;

        	for (int i = 0; i < DataSegmentDef::s_defs[ds]->GetItemCount(); i++)
        	{
        		DataSegmentItemDef* itemDef = DataSegmentDef::s_defs[ds]->GetItem(i);
                if (itemDef->GetIntProperty("name") == symbol)
                {
                    return startByte;
                }

                //printf("Type of item %d is %d\n", i, itemDef->GetIntProperty("type"));

                startByte += itemDef->CalcSize();
        	}
        }

        printf("CalcAddress failed for %d\n", symbol);
        return -1;
    }

    static std::vector<std::unique_ptr<DataSegmentDef> > s_defs;
    static std::vector<std::unique_ptr<DataSegmentDef> >& GlobalList() { return s_defs; }

private:
    int _startAddress;
};
