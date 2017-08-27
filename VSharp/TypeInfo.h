#pragma once

#include <string>

class TypeCollection;

enum class TypeClass
{
    Unknown,
    Void,
    Struct,
    Array,
    Generic,
    Register,
    Enum,
    Static,
    Clock,
};

class TypeInfo
{
  public:
    virtual TypeClass GetTypeClass() = 0;
    virtual std::string DebugPrint() = 0;
    virtual std::string GetTypeName() = 0;
    virtual bool EqualType(TypeInfo *pOther) = 0;
    virtual TypeInfo* MakeSpecificType(TypeInfo* pGenericArgType, TypeCollection* pCollection) = 0;
    virtual bool IsVerilogRegister() const { return false; }
    virtual int GetBitLength() const { throw "Not a Verilog register type"; }

    static bool IsFloat(TypeInfo *);
    static bool IsNonFloat(TypeInfo *);
};
