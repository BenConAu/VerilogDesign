#pragma once

#include "ListDef.h"

struct DataSegmentItemEntry
{
    static DataSegmentItemEntry* Construct(int value)
    {
        DataSegmentItemEntry* pNewEntry = new DataSegmentItemEntry;
        pNewEntry->_value = value;
        std::unique_ptr<DataSegmentItemEntry> newEntry(pNewEntry);
        s_defs.push_back(std::move(newEntry));
        return pNewEntry;
    }

    static std::vector<std::unique_ptr<DataSegmentItemEntry> > s_defs;
    int _value;
};

class DataSegmentItemDef : public ListDef<DataSegmentItemDef,DataSegmentItemEntry>
{
public:
    static std::vector<std::unique_ptr<DataSegmentItemDef> > s_defs;
    static std::vector<std::unique_ptr<DataSegmentItemDef> >& GlobalList() { return s_defs; }
};

class DataSegmentDef : public ListDef<DataSegmentDef, DataSegmentItemDef>
{
public:
    void SetAddress(int address)
    {
        _address = address;
    }

    int GetAddress() { return _address; }

    static std::vector<std::unique_ptr<DataSegmentDef> > s_defs;
    static std::vector<std::unique_ptr<DataSegmentDef> >& GlobalList() { return s_defs; }

private:
    int _address;
};
