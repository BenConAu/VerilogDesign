#include "PointerTypeInfo.h"
#include "TypeCollection.h"

PointerTypeInfo::PointerTypeInfo(TypeInfo *pBaseType)
{
    _pBaseType = pBaseType;
}

unsigned int PointerTypeInfo::GetSize()
{
    // Pointers are word sized
    return 4;
}

TypeClass PointerTypeInfo::GetTypeClass()
{
    return TypeClass::Pointer;
}

std::string PointerTypeInfo::DebugPrint()
{
    char buffer[100];
    sprintf(buffer, "PointerTypeInfo (to %s)", _pBaseType->DebugPrint().c_str());
    return buffer;
}

std::string PointerTypeInfo::GetTypeName()
{
    char buffer[1024];
    sprintf(buffer, "ptr<%s>", _pBaseType->GetTypeName().c_str());
    return buffer;
}

TypeInfo *PointerTypeInfo::GetBaseType()
{
    return _pBaseType;
}

bool PointerTypeInfo::EqualType(TypeInfo *pOther)
{
    if (pOther->GetTypeClass() != TypeClass::Pointer)
    {
        printf("Other is not a pointer type\n");
        return false;
    }

    PointerTypeInfo *pOtherPointer = dynamic_cast<PointerTypeInfo *>(pOther);
    if (!_pBaseType->EqualType(pOtherPointer->GetBaseType()))
    {
        //printf("Base types %s and %s not equal\n", _pBaseType->DebugPrint().c_str(), pOtherPointer->GetBaseType()->DebugPrint().c_str());
        return false;
    }

    //printf("Pointer types equal\n");
    return true;
}

TypeInfo *PointerTypeInfo::MakeSpecificType(TypeInfo *pGenericArgType, TypeCollection *pCollection)
{
    return pCollection->GetPointerType(_pBaseType->MakeSpecificType(pGenericArgType, pCollection));
}
