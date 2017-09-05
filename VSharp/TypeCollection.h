#pragma once

#include <vector>
#include <map>
#include <memory>
#include "RegisterTypeInfo.h"
#include "StructTypeInfo.h"
#include "ArrayTypeInfo.h"
#include "GenericTypeInfo.h"
#include "VoidTypeInfo.h"
#include "EnumTypeInfo.h"
#include "ClockTypeInfo.h"

class ModuleDeclaratorNode;

class TypeCollection
{
public:
    TypeCollection();
    EnumTypeInfo* GetEnumType(int symIndex);
    StructTypeInfo* GetStructType(int symIndex);
    RegisterTypeInfo* GetRegisterType(int bitLength);
    ArrayTypeInfo* GetArrayType(TypeInfo* pBaseType, int arraySize);
    GenericTypeInfo* GetGenericType(int symIndex, ModuleDeclaratorNode* pScope);
    VoidTypeInfo* GetVoidType();
    ClockTypeInfo* GetClockType();

    void AddStructType(int symIndex, StructTypeInfo* pInfo);
    void AddEnumType(int symIndex, EnumTypeInfo* pInfo);
    GenericTypeInfo* AddGenericType(int symIndex, ModuleDeclaratorNode* pScope);

private:
    std::map<int, std::unique_ptr<StructTypeInfo> > _structTypes;
    std::map<int, std::unique_ptr<EnumTypeInfo> > _enumTypes;
    std::map<int, std::unique_ptr<RegisterTypeInfo> > _registerTypes;
    std::map<TypeInfo*, std::unique_ptr<ArrayTypeInfo> > _arrayTypes;
    std::vector<std::unique_ptr<GenericTypeInfo> > _genericTypes;
    std::unique_ptr<VoidTypeInfo> _voidType;
    std::unique_ptr<ClockTypeInfo> _clockType;
};
