#pragma once

#include "TypeInfo.h"
#include <map>

class PSLCompilerContext;

class ClockTypeInfo : public TypeInfo
{
public:
    ClockTypeInfo() {}
    TypeClass GetTypeClass() override { return TypeClass::Clock; }
    std::string DebugPrint() override { return "ClockTypeInfo"; }
    std::string GetTypeName() override { return "ClockTypeInfo"; }
    bool EqualType(TypeInfo* pOther) override { throw "Wat"; }
    TypeInfo* MakeSpecificType(TypeInfo* pGenericArgType, TypeCollection* pCollection) override { throw "Wat"; }
};
