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
#include "ModuleTypeInfo.h"

class ModuleDefinitionNode;

class TypeCollection
{
public:
    TypeCollection();
    EnumTypeInfo* GetEnumType(int symIndex);
    StructTypeInfo* GetStructType(int symIndex);
    ModuleTypeInfo* GetModuleType(int symIndex);
    RegisterTypeInfo* GetRegisterType(int bitLength);
    ArrayTypeInfo* GetArrayType(TypeInfo* pBaseType, int arraySize);
    GenericTypeInfo* GetGenericType(int symIndex, ModuleDefinitionNode* pScope);
    VoidTypeInfo* GetVoidType();
    ClockTypeInfo* GetClockType();

    void AddStructType(int symIndex, StructTypeInfo* pInfo);
    void AddModuleType(int symIndex, ModuleTypeInfo* pInfo);
    void AddEnumType(int symIndex, EnumTypeInfo* pInfo);

private:
    std::map<int, std::unique_ptr<StructTypeInfo> > _structTypes;
    std::map<int, std::unique_ptr<ModuleTypeInfo> > _moduleTypes;
    std::map<int, std::unique_ptr<EnumTypeInfo> > _enumTypes;
    std::map<int, std::unique_ptr<RegisterTypeInfo> > _registerTypes;
    std::map<TypeInfo*, std::unique_ptr<ArrayTypeInfo> > _arrayTypes;
    std::vector<std::unique_ptr<GenericTypeInfo> > _genericTypes;
    std::unique_ptr<VoidTypeInfo> _voidType;
    std::unique_ptr<ClockTypeInfo> _clockType;
};
