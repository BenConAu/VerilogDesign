#include "TypeCollection.h"
#include "ASTNode.h"
#include "PSL.tab.h"
#include "BasicTypeInfo.h"
#include "StructTypeInfo.h"

TypeCollection::TypeCollection()
{
    // Built in types
    _basicTypes[INT_TOKEN] = std::unique_ptr<BasicTypeInfo>(new BasicTypeInfo(INT_TOKEN));
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

    return nullptr;
}

PointerTypeInfo* TypeCollection::GetPointerType(int symIndex)
{
    if (_pointerTypes.find(symIndex) == _pointerTypes.end())
    {
        _pointerTypes[symIndex] = std::unique_ptr<PointerTypeInfo>(new PointerTypeInfo(symIndex));
    }

    return _pointerTypes[symIndex].get();
}

void TypeCollection::AddStructType(int symIndex, StructTypeInfo* pInfo)
{
    _structTypes[symIndex] = std::unique_ptr<StructTypeInfo>(pInfo);
}
