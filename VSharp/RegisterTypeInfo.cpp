#include "RegisterTypeInfo.h"
#include "VSharpCompilerContext.h"
#include "VSharp.tab.h"

RegisterTypeInfo::RegisterTypeInfo(int bitLength)
{
    _bitLength = bitLength;

    if (_bitLength > 64)
    {
        throw "Gotcha!";
    }
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