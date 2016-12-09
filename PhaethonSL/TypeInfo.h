#pragma once

enum class TypeClass
{
    Basic,
    Struct,
    Pointer,
};

class TypeInfo
{
public:
    virtual unsigned int GetSize() = 0;
    virtual TypeClass GetTypeClass() = 0;
    virtual const char* DebugPrint() = 0;

    static bool IsFloat(TypeInfo*);
};
