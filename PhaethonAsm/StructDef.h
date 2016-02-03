#pragma once

#include "AssemblerListNode.h"

class StructMember : public AssemblerNode<StructMember>
{
public:
    int GetSize()
    {
        int arraySize = GetIntProperty("arraySize");
        if (arraySize == 0)
        {
            // Nothing stored means it is not an array
            return 4;
        }
        else
        {
            // Array of word
            return arraySize * 4;
        }
    }

public:
    static std::vector<std::unique_ptr<StructMember> > s_defs;
    static std::vector<std::unique_ptr<StructMember> >& GlobalList() { return s_defs; }
};

class StructDef : public AssemblerListNode<StructDef, StructMember>
{
public:
    int GetSize()
    {
        int storedSize = GetIntProperty("size");
        if (storedSize != 0)
        {
            // This is a built-in type, so return the size
            return storedSize;
        }
        else
        {
            //printf("Size of struct %d is %d\n", typeSymbol, (int)(s_defs[i]->GetItemCount() * 4));
            return GetItemCount() * 4;
        }
    }

    int CalcOffset(int memberSymIndex)
    {
        int offset = 0;

        for (size_t i = 0; i < GetItemCount(); i++)
        {
            StructMember* pMember = GetItem(i);
            if (pMember->GetIntProperty("name") == memberSymIndex)
            {
                //printf("Offset calculated to be %d\n", offset);
                return offset;
            }

            offset += pMember->GetSize();
        }

        printf("Unknown struct member in CalcOffset!\n");
        return -1;
    }

    static int CalcOffset(int structIndex, int memberSymIndex)
    {
        return s_defs[structIndex]->CalcOffset(memberSymIndex);
    }

    static int GetSize(int typeSymbol)
    {
        for (size_t i = 0; i < s_defs.size(); i++)
        {
            //printf("Name of struct %d is %d\n", (int)i, s_defs[i]->GetIntProperty("name"));

            if (s_defs[i]->GetIntProperty("name") == typeSymbol)
            {
                return s_defs[i]->GetSize();
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
