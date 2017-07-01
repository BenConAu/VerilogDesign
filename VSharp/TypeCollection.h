#pragma once

#include <vector>
#include <map>
#include <memory>
#include "BasicTypeInfo.h"
#include "StructTypeInfo.h"
#include "PointerTypeInfo.h"
#include "ArrayTypeInfo.h"
#include "GenericTypeInfo.h"

class ModuleDeclaratorNode;

class TypeCollection
{
public:
    TypeCollection();
    StructTypeInfo* GetStructType(int symIndex);
    BasicTypeInfo* GetBasicType(int type);
    PointerTypeInfo* GetPointerType(TypeInfo* pBaseType);
    ArrayTypeInfo* GetArrayType(TypeInfo* pBaseType);
    GenericTypeInfo* GetGenericType(int symIndex, ModuleDeclaratorNode* pScope);

    void AddStructType(int symIndex, StructTypeInfo* pInfo);
    GenericTypeInfo* AddGenericType(int symIndex, ModuleDeclaratorNode* pScope);

private:
    std::map<int, std::unique_ptr<StructTypeInfo> > _structTypes;
    std::map<int, std::unique_ptr<BasicTypeInfo> > _basicTypes;
    std::map<TypeInfo*, std::unique_ptr<PointerTypeInfo> > _pointerTypes;
    std::map<TypeInfo*, std::unique_ptr<ArrayTypeInfo> > _arrayTypes;
    std::vector<std::unique_ptr<GenericTypeInfo> > _genericTypes;
};
