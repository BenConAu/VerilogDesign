#pragma once

#include "ListDef.h"

struct StructMember
{
    static StructMember* Construct(int value)
    {
        StructMember* pNewEntry = new StructMember;
        pNewEntry->nameSym = value;
        std::unique_ptr<StructMember> newEntry(pNewEntry);
        s_defs.push_back(std::move(newEntry));
        return pNewEntry;
    }

    int nameSym;

    static std::vector<std::unique_ptr<StructMember> > s_defs;
};

class StructDef : public ListDef<StructDef, StructMember>
{
public:
    static bool Match(StructMember* member, int name)
    {
        return (member->nameSym == name);
    }

    static int CalcOffset(int structIndex, int memberSymIndex)
    {
        return s_defs[structIndex]->Find(memberSymIndex) * 4;
    }

    static std::vector<std::unique_ptr<StructDef> > s_defs;
    static std::vector<std::unique_ptr<StructDef> >& GlobalList() { return s_defs; }
};
