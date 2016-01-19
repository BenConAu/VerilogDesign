#pragma once

#include "ListDef.h"

class StructMember : public AssemblerNode<StructMember>
{
public:
    static std::vector<std::unique_ptr<StructMember> > s_defs;
    static std::vector<std::unique_ptr<StructMember> >& GlobalList() { return s_defs; }
};

class StructDef : public AssemblerListNode<StructDef, StructMember>
{
public:
    static bool Match(StructMember* member, int name)
    {
        return (member->GetIntProperty("name") == name);
    }

    static int CalcOffset(int structIndex, int memberSymIndex)
    {
        return s_defs[structIndex]->Find(memberSymIndex) * 4;
    }

    static std::vector<std::unique_ptr<StructDef> > s_defs;
    static std::vector<std::unique_ptr<StructDef> >& GlobalList() { return s_defs; }
};
