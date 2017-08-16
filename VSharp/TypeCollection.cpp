#include "TypeCollection.h"
#include "ASTNode.h"
#include "VSharp.tab.h"
#include "GenericTypeInfo.h"
#include "StructTypeInfo.h"

TypeCollection::TypeCollection()
{
}

StructTypeInfo* TypeCollection::GetStructType(int symIndex)
{
    if (_structTypes.find(symIndex) != _structTypes.end())
    {
        return _structTypes[symIndex].get();
    }

    return nullptr;
}

VoidTypeInfo* TypeCollection::GetVoidType()
{
    return _voidType.get();
}

RegisterTypeInfo* TypeCollection::GetRegisterType(int bitLength)
{
    if (_registerTypes.find(bitLength) == _registerTypes.end())
    {
        _registerTypes[bitLength] = std::unique_ptr<RegisterTypeInfo>(new RegisterTypeInfo(bitLength));
    }

    return _registerTypes[bitLength].get();
}

ArrayTypeInfo* TypeCollection::GetArrayType(TypeInfo* pBaseType)
{
    if (pBaseType == nullptr)
    {
        throw "Cannot have array without base type";
    }

    if (_arrayTypes.find(pBaseType) == _arrayTypes.end())
    {
        _arrayTypes[pBaseType] = std::unique_ptr<ArrayTypeInfo>(new ArrayTypeInfo(pBaseType));
    }

    return _arrayTypes[pBaseType].get();
}

GenericTypeInfo* TypeCollection::AddGenericType(int symIndex, ModuleDeclaratorNode* pScope)
{
    //printf("Adding generic type %d for function %p\n", symIndex, pScope);
    
    GenericTypeInfo* pNewType = new GenericTypeInfo(symIndex, pScope);
    _genericTypes.emplace_back(pNewType);
    return pNewType;
}

GenericTypeInfo* TypeCollection::GetGenericType(int symIndex, ModuleDeclaratorNode* pScope)
{
    //printf("Searching for generic type %d for function %p\n", symIndex, pScope);

    for (size_t i = 0; i < _genericTypes.size(); i++)
    {
        if (_genericTypes[i]->GetSymbolIndex() == symIndex && _genericTypes[i]->GetScope() == pScope)
        {
            return _genericTypes[i].get();
        }
    }

    return nullptr;
}

void TypeCollection::AddStructType(int symIndex, StructTypeInfo* pInfo)
{
    _structTypes[symIndex] = std::unique_ptr<StructTypeInfo>(pInfo);
}

void TypeCollection::AddEnumType(int symIndex, EnumTypeInfo* pInfo)
{
    _enumTypes[symIndex] = std::unique_ptr<EnumTypeInfo>(pInfo);
}

EnumTypeInfo* TypeCollection::GetEnumType(int symIndex)
{
    if (_enumTypes.find(symIndex) != _enumTypes.end())
    {
        return _enumTypes[symIndex].get();
    }

    return nullptr;
}
