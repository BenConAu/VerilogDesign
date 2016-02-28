#pragma once

#include "TypeInfo.h"

class BasicTypeInfo : public TypeInfo
{
public:
    BasicTypeInfo(int typeToken)
    {
        _typeToken = typeToken;
    }

    int GetSize() override
    {
        // All basic types are size 4
        return 4;
    }

    bool IsBasic() override
    {
        return true;
    }

private:
    int _typeToken;
};
