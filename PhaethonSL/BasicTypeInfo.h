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

private:
    int _typeToken;
};
