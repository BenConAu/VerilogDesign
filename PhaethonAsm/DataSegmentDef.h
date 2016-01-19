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
    static std::vector<std::unique_ptr<DataSegmentDef> > s_defs;
    static std::vector<std::unique_ptr<DataSegmentDef> >& GlobalList() { return s_defs; }
};
