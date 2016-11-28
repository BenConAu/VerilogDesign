#pragma once

#include "TypeInfo.h"

class PointerTypeInfo : public TypeInfo
{
public:
    PointerTypeInfo(int typeSym)
    {
        _typeSymIndex = typeSym;
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
    int _typeSymIndex;  // Symbol index for type that is being pointed to
};
