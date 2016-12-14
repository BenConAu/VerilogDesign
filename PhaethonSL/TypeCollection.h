#pragma once

#include <vector>
#include <map>
#include <memory>
#include "BasicTypeInfo.h"
#include "StructTypeInfo.h"
#include "PointerTypeInfo.h"
#include "GenericTypeInfo.h"

class FunctionDeclaratorNode;

class TypeCollection
{
public:
    TypeCollection();
    StructTypeInfo* GetStructType(int symIndex);
    BasicTypeInfo* GetBasicType(int type);
    PointerTypeInfo* GetPointerType(TypeInfo* pBaseType);
    GenericTypeInfo* GetGenericType(int symIndex, FunctionDeclaratorNode* pScope);
    void AddStructType(int symIndex, StructTypeInfo* pInfo);

private:
    std::map<int, std::unique_ptr<StructTypeInfo> > _structTypes;
    std::map<int, std::unique_ptr<BasicTypeInfo> > _basicTypes;
    std::map<TypeInfo*, std::unique_ptr<PointerTypeInfo> > _pointerTypes;
    std::vector<std::unique_ptr<GenericTypeInfo> > _genericTypes;
};
