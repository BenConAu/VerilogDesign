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

    TypeClass GetTypeClass() override
    {
        return TypeClass::Pointer;
    }

    const char* DebugPrint() override
    {
        return "PointerTypeInfo";
    }

    TypeInfo* GetBaseType()
    {
        return _pBaseType;
    }

    bool EqualType(TypeInfo* pOther) override
    {
        if (pOther->GetTypeClass() != TypeClass::Pointer)
        {
            return false;
        }

        PointerTypeInfo* pOtherPointer = dynamic_cast<PointerTypeInfo*>(pOther);
        return _pBaseType->EqualType(pOtherPointer->GetBaseType());
    }

private:
    TypeInfo* _pBaseType;  // Type being pointed to
};
