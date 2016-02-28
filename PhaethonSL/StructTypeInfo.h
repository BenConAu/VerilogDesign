#pragma once

#include "TypeInfo.h"
#include "TypeMember.h"

class StructTypeInfo : public TypeInfo
{
public:
    StructTypeInfo(int symIndex)
    {
        _symIndex = symIndex;
    }

    void AddMember(int symIndex, TypeInfo* pType)
    {
        _members.push_back(std::unique_ptr<TypeMember>(new TypeMember(symIndex, pType)));
    }

    TypeMember* GetMember(int symIndex)
    {
        for (size_t i = 0; i < _members.size(); i++)
        {
            if (_members[i]->GetSymbolIndex() == symIndex)
            {
                return _members[i].get();
            }
        }

        throw "Unknown member";
    }

    int GetSize() override
    {
        int totalSize = 0;

        for (size_t i = 0; i < _members.size(); i++)
        {
            totalSize += _members[i]->GetSize();
        }

        return totalSize;
    }

    bool IsBasic() override
    {
        return false;
    }

private:
    int _symIndex;
    std::vector<std::unique_ptr<TypeMember> > _members;
};
