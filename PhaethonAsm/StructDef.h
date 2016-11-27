#pragma once

#include "StructMember.h"
#include "AssemblerListNode.h"
#include <typeinfo>

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
            //printf("Size of struct %d with %d items is %d\n", GetIntProperty("name"), GetItemCount(), GetItemCount() * 4);
            return GetItemCount() * 4;
        }
    }

    int CalcOffset(int memberSymIndex)
    {
        int offset = 0;

        for (size_t i = 0; i < GetItemCount(); i++)
        {
            StructMember *pMember = GetItem(i);

            //printf("Member %i is %p\n", (int)i, pMember);
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

    void OnAddMember()
    {
        //printf("Member added to struct\n");

        //for (size_t i = 0; i < GetItemCount(); i++)
        //{
        //printf("Member %d of %d is symbol %d\n", (int)i, GetItemCount(), GetItem(i)->GetIntProperty("name"));
        //}
    }

    static int CalcOffset(int structSymIndex, int memberSymIndex)
    {
        for (size_t i = 0; i < AssemblerNode::GetNodes().size(); i++)
        {
            StructDef *pDef = AssemblerNode::GetNode<StructDef>(i);
            if (pDef != nullptr)
            {
                //printf("Name of struct %d is %d\n", (int)i, s_defs[i]->GetIntProperty("name"));

                if (pDef->GetIntProperty("name") == structSymIndex)
                {
                    return pDef->CalcOffset(memberSymIndex);
                }
            }
        }

        printf("Unknown size for type %d\n", structSymIndex);
        return -1;
    }

    static int GetSize(int typeSymbol)
    {
        //printf("Starting size search\n");

        for (size_t i = 0; i < AssemblerNode::GetNodes().size(); i++)
        {
            //            printf("Getting node %d with name %s\n", (int)i, typeid(s_nodeDefs[i].get()).name());
            StructDef *pDef = AssemblerNode::GetNode<StructDef>(i);
            if (pDef != nullptr)
            {
                //printf("Name of struct %d is %d\n", (int)i, pDef->GetIntProperty("name"));

                if (pDef->GetIntProperty("name") == typeSymbol)
                {
                    //printf("Ending size search\n");
                    return pDef->GetSize();
                }
            }
        }

        throw "Unknown size for type";
        return -1;
    }

  private:
    class StructDefInfo
    {
      public:
        StructDefInfo()
        {
            StructDef *pWordStruct = StructDef::Construct(nullptr);
            pWordStruct->SetIntProperty("name", AddSymbol("word"));
            pWordStruct->SetIntProperty("size", 4);

            //            printf("Number of structs is now %d\n", (int)s_nodeDefs.size());
        }
    };

    static StructDefInfo s_defInfo;
};
