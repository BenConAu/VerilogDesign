#pragma once

#include "AssemblerNode.h"
#include <vector>

template<typename DefType, typename ChildDefType>
class AssemblerListNode : public AssemblerNode
{
public:
    static DefType* Construct(ChildDefType* pFirstItem)
    {
        DefType* pNewList = AssemblerNode::Construct<DefType>();
        if (pFirstItem != nullptr)
        {
            pNewList->AddMember(pFirstItem);
        }

        return pNewList;
    }

    void AddMember(ChildDefType* newMember)
    {
        members.insert(members.begin(), newMember);
        OnAddMember();
    }

    virtual void OnAddMember()
    {
    }

    int Find(int memberSymIndex)
    {
        for (size_t j = 0; j < members.size(); j++)
        {
            if (DefType::Match(members[j], memberSymIndex))
            {
                return j;
            }
        }

        return -1;
    }

    ChildDefType* GetItem(int item) { return members[item]; }
    int GetItemCount() const { return members.size(); }

protected:
    std::vector<ChildDefType*> members;
};
