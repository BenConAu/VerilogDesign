#pragma once

#include <string>

class TypeCollection;

enum class TypeClass
{
    Struct,
    Array,
    Generic,
    Register
};

class TypeInfo
{
  public:
    virtual unsigned int GetSize() = 0;
    virtual TypeClass GetTypeClass() = 0;
    virtual std::string DebugPrint() = 0;
    virtual std::string GetTypeName() = 0;
    virtual bool EqualType(TypeInfo *pOther) = 0;
    virtual TypeInfo* MakeSpecificType(TypeInfo* pGenericArgType, TypeCollection* pCollection) = 0;

    static bool IsFloat(TypeInfo *);
    static bool IsNonFloat(TypeInfo *);
};