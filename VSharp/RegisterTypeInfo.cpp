#include "RegisterTypeInfo.h"
#include "PSLCompilerContext.h"
#include "VSharp.tab.h"

RegisterTypeInfo::RegisterTypeInfo(int bitLength)
{
    _bitLength = bitLength;
}

unsigned int RegisterTypeInfo::GetSize()
{
    // All basic types are size 4
    return 4;
}

TypeClass RegisterTypeInfo::GetTypeClass()
{
    return TypeClass::Register;
}

std::string RegisterTypeInfo::DebugPrint()
{
    char result[100];
    sprintf(result, "RegisterTypeInfo bitLength = %d", _bitLength);
    return result;
}

std::string RegisterTypeInfo::GetTypeName()
{
    char result[100];
    sprintf(result, "Register%d", _bitLength);
    return result;
}

bool RegisterTypeInfo::EqualType(TypeInfo *pOther)
{
    if (pOther->GetTypeClass() != TypeClass::Register)
    {
        return false;
    }

    RegisterTypeInfo *pOtherBasic = dynamic_cast<RegisterTypeInfo *>(pOther);
    if (_bitLength != pOtherBasic->GetBitLength())
    {
        return false;
    }

    return true;
}

TypeInfo *RegisterTypeInfo::MakeSpecificType(TypeInfo *pGenericArgType, TypeCollection *pCollection)
{
    // Basic types cannot have generic arguments
    return this;
}