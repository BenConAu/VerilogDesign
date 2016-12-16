#pragma once

#include "TypeInfo.h"
#include <string>

class BasicTypeInfo : public TypeInfo
{
public:
    BasicTypeInfo(int typeToken)
    {
        _typeToken = typeToken;
    }

    unsigned int GetSize() override
    {
        // All basic types are size 4
        return 4;
    }

    TypeClass GetTypeClass() override
    {
        return TypeClass::Basic;
    }

    std::string DebugPrint() override
    {
        return "BasicTypeInfo";
    }

    int GetTypeToken() const
    {
        return _typeToken;
    }

    bool EqualType(TypeInfo* pOther) override
    {
        if (pOther->GetTypeClass() != TypeClass::Basic)
        {
            return false;
        }

        BasicTypeInfo* pOtherBasic = dynamic_cast<BasicTypeInfo*>(pOther);
        if (_typeToken != pOtherBasic->GetTypeToken())
        {
            return false;
        }

        return true;
    }

    TypeInfo* MakeSpecificType(TypeInfo* pGenericArgType, TypeCollection* pCollection) override
    {
        // Basic types cannot have generic arguments
        return this;
    }

private:
    int _typeToken;
};
