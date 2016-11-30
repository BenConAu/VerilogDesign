#include "TypeCollection.h"
#include "ASTNode.h"
#include "PSL.tab.h"
#include "BasicTypeInfo.h"
#include "StructTypeInfo.h"

TypeCollection::TypeCollection()
{
    // Built in types
    _basicTypes[VOID_TOKEN] = std::unique_ptr<BasicTypeInfo>(new BasicTypeInfo(VOID_TOKEN));
    _basicTypes[WORD_TOKEN] = std::unique_ptr<BasicTypeInfo>(new BasicTypeInfo(WORD_TOKEN));
    _basicTypes[FLOAT_TOKEN] = std::unique_ptr<BasicTypeInfo>(new BasicTypeInfo(FLOAT_TOKEN));
}

StructTypeInfo* TypeCollection::GetStructType(int symIndex)
{
    if (_structTypes.find(symIndex) != _structTypes.end())
    {
        return _structTypes[symIndex].get();
    }

    return nullptr;
}

BasicTypeInfo* TypeCollection::GetBasicType(int type)
{
    if (_basicTypes.find(type) != _basicTypes.end())
    {
        return _basicTypes[type].get();
    }

    throw "That basic type does not exist";
}

PointerTypeInfo* TypeCollection::GetPointerType(TypeInfo* pBaseType)
{
    if (pBaseType == nullptr)
    {
        pBaseType = GetBasicType(VOID_TOKEN);
    }

    if (_pointerTypes.find(pBaseType) == _pointerTypes.end())
    {
        _pointerTypes[pBaseType] = std::unique_ptr<PointerTypeInfo>(new PointerTypeInfo(pBaseType));
    }

    return _pointerTypes[pBaseType].get();
}

void TypeCollection::AddStructType(int symIndex, StructTypeInfo* pInfo)
{
    _structTypes[symIndex] = std::unique_ptr<StructTypeInfo>(pInfo);
}
