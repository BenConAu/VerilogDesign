#pragma once

class DataSegmentItemEntry : public AssemblerNode<DataSegmentItemEntry>
{
public:
    static std::vector<std::unique_ptr<DataSegmentItemEntry> > s_defs;
    static std::vector<std::unique_ptr<DataSegmentItemEntry> >& GlobalList() { return s_defs; }
};

