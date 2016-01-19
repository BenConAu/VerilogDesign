#pragma once

#include <map>
#include <string>

template<typename DefType, typename ChildDefType>
class ListDef
{
public:
    static DefType* Construct(ChildDefType* pFirstItem)
    {
        DefType* pNewList = new DefType;
        std::unique_ptr<DefType> newList(pNewList);
        newList->AddMember(pFirstItem);
        DefType::GlobalList().push_back(std::move(newList));
        return pNewList;
    }

    void SetSymbolProperty(const char* pszPropName, int nameIndex)
    {
        props[pszPropName] = nameIndex;
    }

    void AddMember(ChildDefType* newMember)
    {
        members.insert(members.begin(), newMember);
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
    std::map<std::string, int> props;
    std::vector<ChildDefType*> members;
};
