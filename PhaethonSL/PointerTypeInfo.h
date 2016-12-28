#pragma once

#include "TypeInfo.h"
#include <string>

class PointerTypeInfo : public TypeInfo
{
public:
    PointerTypeInfo(TypeInfo* pBaseType);

    unsigned int GetSize() override;
    TypeClass GetTypeClass() override;
    std::string DebugPrint() override;
    std::string GetTypeName() override;
    bool EqualType(TypeInfo* pOther) override;
    TypeInfo* MakeSpecificType(TypeInfo* pGenericArgType, TypeCollection* pCollection) override;

    TypeInfo* GetBaseType();

private:
    TypeInfo* _pBaseType;  // Type being pointed to
};
