#include "TypeCollection.h"
#include "ASTNode.h"
#include "PSL.tab.h"
#include "BasicTypeInfo.h"
#include "StructTypeInfo.h"

TypeCollection::TypeCollection()
{
    // Built in types
    _basicTypes[VOID_TOKEN] = std::unique_ptr<BasicTypeInfo>(new BasicTypeInfo(VOID_TOKEN));
    _basicTypes[BOOL_TOKEN] = std::unique_ptr<BasicTypeInfo>(new BasicTypeInfo(BOOL_TOKEN));
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

ArrayTypeInfo* TypeCollection::GetArrayType(TypeInfo* pBaseType)
{
    if (pBaseType == nullptr)
    {
        throw "Cannot have array without base type";
    }

    if (_pointerTypes.find(pBaseType) == _pointerTypes.end())
    {
        _arrayTypes[pBaseType] = std::unique_ptr<ArrayTypeInfo>(new ArrayTypeInfo(pBaseType));
    }

    return _arrayTypes[pBaseType].get();
}

GenericTypeInfo* TypeCollection::AddGenericType(int symIndex, FunctionDeclaratorNode* pScope)
{
    //printf("Adding generic type %d for function %p\n", symIndex, pScope);
    
    GenericTypeInfo* pNewType = new GenericTypeInfo(symIndex, pScope);
    _genericTypes.emplace_back(pNewType);
    return pNewType;
}

GenericTypeInfo* TypeCollection::GetGenericType(int symIndex, FunctionDeclaratorNode* pScope)
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
