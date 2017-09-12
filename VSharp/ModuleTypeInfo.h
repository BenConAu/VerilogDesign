#pragma once

#include "TypeInfo.h"
#include <vector>
#include <memory>

class ParserContext;
class ModuleDefinitionNode;
class ModuleParameterNode;

class ModuleTypeInfo : public TypeInfo
{
public:
    ModuleTypeInfo(int symIndex, ModuleDefinitionNode* pModuleDef)
    {
        _symIndex = symIndex;
        _pModuleDef = pModuleDef;
    }

    TypeClass GetTypeClass() override
    {
        return TypeClass::Module;
    }

    std::string DebugPrint() override
    {
        return "ModuleTypeInfo";
    }

    std::string GetTypeName() override;

    int GetSymbolIndex()
    {
        return _symIndex;
    }

    bool EqualType(TypeInfo* pOther) override
    {
        // Could do this for all of them, but maybe not forever
        return (static_cast<TypeInfo*>(this) == pOther);
    }

    TypeInfo* MakeSpecificType(TypeInfo* pGenericArgType, TypeCollection* pCollection) override
    {
        // Structs cannot currently have generic arguments
        return this;
    }

    std::string GetDeclaration(VariableInfo* pInfo, ExpressionNode* pInitExpr) override;

    ModuleDefinitionNode* GetModuleDefinition() { return _pModuleDef; }
    size_t GetParameterCount();
    ModuleParameterNode* GetParameter(size_t index);

private:
    int _symIndex;
    ModuleDefinitionNode* _pModuleDef;
};
