#pragma once

#include "TypeInfo.h"
#include "StructMember.h"
#include <vector>

class PSLCompilerContext;

class StructTypeInfo : public TypeInfo
{
public:
    StructTypeInfo(int symIndex, PSLCompilerContext* pContext)
    {
        _symIndex = symIndex;
        _pContext = pContext;
    }

    void AddMember(
        PSLCompilerContext *pContext,
        int symIndex, 
        TypeInfo* pType, 
        int dimension);

    StructMember* GetMember(int symIndex)
    {
        for (size_t i = 0; i < _members.size(); i++)
        {
            if (_members[i]->GetSymbolIndex() == symIndex)
            {
                return _members[i].get();
            }
        }

        return nullptr;
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
    PSLCompilerContext* _pContext;
    std::vector<std::unique_ptr<StructMember> > _members;
};
