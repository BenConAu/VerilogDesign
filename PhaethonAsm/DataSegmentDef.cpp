#include "DataSegmentDef.h"

DataSegmentDef::DataSegmentDef()
{
    _startAddress = -1;
}

void DataSegmentDef::OutputDataSegment()
{
    for (int i = 0; i < GetItemCount(); i++)
    {
        //		printf("Doing item %d in Data segment\n", i);

        DataSegmentItemDef *itemDef = GetItem(i);
        //		printf("Item %d has count %d\n", i, itemDef->GetItemCount());

        int arraySize = itemDef->GetIntProperty("arraySize");
        if (arraySize != 0)
        {
            for (int j = 0; j < arraySize; j++)
            {
                s_pWriter->OutputWord(0x13371337);
            }
        }
        else
        {
            for (int j = 0; j < itemDef->GetItemCount(); j++)
            {
                DataSegmentItemEntry *entry = itemDef->GetItem(j);

                s_pWriter->OutputWord(entry->GetIntProperty("value"));
            }
        }
    }
}

int DataSegmentDef::GetSize()
{
    int size = 0;

    for (int i = 0; i < GetItemCount(); i++)
    {
        size += GetItem(i)->CalcSize();
    }

    return size;
}

void DataSegmentDef::ResolveSymbols()
{
    // We know the start position of the data segments - end of code
    int startByte = InstructionNode::GetCodeSize();

    // Set the start address of each segment
    for (size_t i = 0; i < AssemblerNode::GetNodes().size(); i++)
    {
        DataSegmentDef *pDef = AssemblerNode::GetNode<DataSegmentDef>(i);
        if (pDef != nullptr)
        {
            //printf("Setting start of segment to %x\n", startByte);
            pDef->_startAddress = startByte;
            startByte += pDef->GetSize();
        }
    }

    // Now we can resolve all of the instructions
    for (size_t i = 0; i < AssemblerNode::GetNodes().size(); i++)
    {
        InstructionNode *pInst = AssemblerNode::GetNode<InstructionNode>(i);
        if (pInst != nullptr)
        {
            pInst->ResolveSymbols();
        }
    }
}

int DataSegmentDef::CalcAddress(int symbol)
{
    for (int ds = 0; ds < AssemblerNode::GetNodes().size(); ds++)
    {
        DataSegmentDef *pDS = AssemblerNode::GetNode<DataSegmentDef>(ds);
        if (pDS != nullptr)
        {
            int startByte = pDS->_startAddress;

            for (int i = 0; i < pDS->GetItemCount(); i++)
            {
                DataSegmentItemDef *itemDef = pDS->GetItem(i);
                if (itemDef->GetIntProperty("name") == symbol)
                {
                    return startByte;
                }

                //printf("Type of item %d is %d\n", i, itemDef->GetIntProperty("type"));

                startByte += itemDef->CalcSize();
            }
        }
    }

    printf("CalcAddress failed for %d\n", symbol);
    return -1;
}
