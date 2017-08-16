#include "ArrayTypeInfo.h"
#include "TypeCollection.h"

ArrayTypeInfo::ArrayTypeInfo(TypeInfo *pBaseType)
{
    _pBaseType = pBaseType;
}

TypeClass ArrayTypeInfo::GetTypeClass()
{
    return TypeClass::Array;
}

std::string ArrayTypeInfo::DebugPrint()
{
    char buffer[100];
    sprintf(buffer, "ArrayTypeInfo (of %s)", _pBaseType->DebugPrint().c_str());
    return buffer;
}

TypeInfo *ArrayTypeInfo::GetBaseType()
{
    return _pBaseType;
}

bool ArrayTypeInfo::EqualType(TypeInfo *pOther)
{
    if (pOther->GetTypeClass() != TypeClass::Array)
    {
        printf("Other is not a pointer type\n");
        return false;
    }

    ArrayTypeInfo *pOtherArray = dynamic_cast<ArrayTypeInfo *>(pOther);
    if (!_pBaseType->EqualType(pOtherArray->GetBaseType()))
    {
        //printf("Base types %s and %s not equal\n", _pBaseType->DebugPrint().c_str(), pOtherPointer->GetBaseType()->DebugPrint().c_str());
        return false;
    }

    //printf("Pointer types equal\n");
    return true;
}

TypeInfo *ArrayTypeInfo::MakeSpecificType(TypeInfo *pGenericArgType, TypeCollection *pCollection)
{
    return pCollection->GetArrayType(_pBaseType->MakeSpecificType(pGenericArgType, pCollection));
}

std::string ArrayTypeInfo::GetTypeName()
{
    throw "Should not be asking for type name of array";
}
