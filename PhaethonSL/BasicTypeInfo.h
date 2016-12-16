#pragma once

#include "TypeInfo.h"

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

    const char* DebugPrint() override
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

private:
    int _typeToken;
};
