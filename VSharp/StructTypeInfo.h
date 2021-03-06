#pragma once

#include "RegisterTypeInfo.h"
#include "StructMember.h"
#include <vector>
#include <memory>

class ParserContext;

class StructTypeInfo : public RegisterTypeInfo
{
public:
    StructTypeInfo(int symIndex, ParserContext* pContext) : RegisterTypeInfo(0)
    {
        _symIndex = symIndex;
        _pContext = pContext;
    }

    void AddMember(
        ParserContext *pContext,
        int symIndex, 
        TypeInfo* pType, 
        int dimension);

    size_t GetMemberCount() const
    {
        return _members.size();
    }

    StructMember* GetMemberBySymbol(int symIndex)
    {
        size_t index;

        if (GetMemberIndex(symIndex, &index))
        {
            return _members[index].get();
        }

        return nullptr;
    }

    StructMember* GetMemberByIndex(size_t i)
    {
        return _members[i].get();
    }

    bool GetMemberIndex(int symIndex, size_t* pIndex)
    {
        for (size_t i = 0; i < _members.size(); i++)
        {
            if (_members[i]->GetSymbolIndex() == symIndex)
            {
                (*pIndex) = i;
                return true;
            }
        }

        return false;
    }

    unsigned int GetBaseLocation(int fieldSymIndex);

    TypeClass GetTypeClass() override
    {
        return TypeClass::Struct;
    }

    std::string DebugPrint() override
    {
        return "StructTypeInfo";
    }

    std::string GetTypeName() override;

    int GetSymbolIndex()
    {
        return _symIndex;
    }

    bool EqualType(TypeInfo* pOther) override
    {
        // Could do this for all of them, but maybe not forever
        return (static_cast<TypeInfo*>(this) == pOther);
    }

    TypeInfo* MakeSpecificType(TypeInfo* pGenericArgType, TypeCollection* pCollection) override
    {
        // Structs cannot currently have generic arguments
        return this;
    }

private:
    int _symIndex;
    ParserContext* _pContext;
    std::vector<std::unique_ptr<StructMember> > _members;
};
