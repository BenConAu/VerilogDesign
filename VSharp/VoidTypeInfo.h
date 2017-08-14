#pragma once

#include "TypeInfo.h"
#include <string>

class VoidTypeInfo : public TypeInfo
{
  public:
    VoidTypeInfo(int bitLength);
    unsigned int GetSize() override { throw "Should not ask for size of void"; return 0; }
    TypeClass GetTypeClass() override { return TypeClass::Void; }
    std::string DebugPrint() override { return "VoidTypeInfo"; }
    std::string GetTypeName() override { return "void"; }
    bool EqualType(TypeInfo *pOther) override { throw "Should not ask for size of void"; return false; }
    TypeInfo *MakeSpecificType(TypeInfo *pGenericArgType, TypeCollection *pCollection) override { throw "Cannot make generic of void"; return nullptr; }
};
