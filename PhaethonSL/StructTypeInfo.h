#pragma once

#include "TypeInfo.h"
#include "StructMember.h"

class StructTypeInfo : public TypeInfo
{
public:
    StructTypeInfo(int symIndex)
    {
        _symIndex = symIndex;
    }

    void AddMember(int symIndex, TypeInfo* pType)
    {
        _members.push_back(std::unique_ptr<StructMember>(new StructMember(symIndex, pType)));
    }

    StructMember* GetMember(int symIndex)
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

    unsigned int GetSize() override
    {
        unsigned int totalSize = 0;

        for (size_t i = 0; i < _members.size(); i++)
        {
            totalSize += _members[i]->GetSize();
        }

        return totalSize;
    }

    unsigned int GetOffset(int fieldSymIndex)
    {
        unsigned int offset = 0;

        for (size_t i = 0; i < _members.size(); i++)
        {
            if (_members[i]->GetSymbolIndex() == fieldSymIndex)
            {
                return offset;
            }

            offset += _members[i]->GetSize();
        }

        throw "Unknown member";
    }

    TypeClass GetTypeClass() override
    {
        return TypeClass::Struct;
    }

    const char* DebugPrint() override
    {
        return "StructTypeInfo";
    }

    int GetSymbolIndex()
    {
        return _symIndex;
    }

    bool EqualType(TypeInfo* pOther) override
    {
        // Could do this for all of them, but maybe not forever
        return (static_cast<TypeInfo*>(this) == pOther);
    }

private:
    int _symIndex;
    std::vector<std::unique_ptr<StructMember> > _members;
};
