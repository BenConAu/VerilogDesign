#pragma once

#include "AssemblerListNode.h"

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

    static int GetSize(int typeSymbol)
    {
        for (size_t i = 0; i < s_defs.size(); i++)
        {
            //printf("Name of struct %d is %d\n", (int)i, s_defs[i]->GetIntProperty("name"));

            if (s_defs[i]->GetIntProperty("name") == typeSymbol)
            {
                int storedSize = s_defs[i]->GetIntProperty("size");

                if (storedSize != 0)
                {
                    return storedSize;
                }
                else
                {
                    //printf("Size of struct %d is %d\n", typeSymbol, (int)(s_defs[i]->GetItemCount() * 4));
                    return s_defs[i]->GetItemCount() * 4;
                }
            }
        }

        printf("Unknown size for type %d\n", typeSymbol);
        return -1;
    }

    static std::vector<std::unique_ptr<StructDef> > s_defs;
    static std::vector<std::unique_ptr<StructDef> >& GlobalList() { return s_defs; }

private:
    class StructDefInfo
    {
    public:
        StructDefInfo()
        {
            StructDef* pWordStruct = StructDef::Construct(nullptr);
            pWordStruct->SetIntProperty("name", AddSymbol("word"));
            pWordStruct->SetIntProperty("size", 4);

            //printf("Number of structs is now %d\n", (int)s_defs.size());
        }
    };

    static StructDefInfo s_defInfo;
};
