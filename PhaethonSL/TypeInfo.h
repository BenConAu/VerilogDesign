#pragma once

#include <string>

class TypeCollection;

enum class TypeClass
{
    Basic,
    Struct,
    Pointer,
    Array,
    Generic,
};

class TypeInfo
{
  public:
    virtual unsigned int GetSize() = 0;
    virtual TypeClass GetTypeClass() = 0;
    virtual std::string DebugPrint() = 0;
    virtual bool EqualType(TypeInfo *pOther) = 0;
    virtual TypeInfo* MakeSpecificType(TypeInfo* pGenericArgType, TypeCollection* pCollection) = 0;

    static bool IsFloat(TypeInfo *);
    static bool IsNonFloat(TypeInfo *);
};
