#pragma once

#include "TypeInfo.h"

class PointerTypeInfo : public TypeInfo
{
public:
    PointerTypeInfo(TypeInfo* pBaseType)
    {
        _pBaseType = pBaseType;
    }

    unsigned int GetSize() override
    {
        // Pointers are word sized
        return 4;
    }

    bool IsBasic() override
    {
        return true;
    }

private:
    TypeInfo* _pBaseType;  // Type being pointed to
};
