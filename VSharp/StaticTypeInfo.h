#pragma once

#include "TypeInfo.h"
#include <map>

class PSLCompilerContext;

class StaticTypeInfo : public TypeInfo
{
public:
    StaticTypeInfo(TypeInfo* pTypeInfo)
    {
        _pTypeInfo = pTypeInfo;
    }
    TypeClass GetTypeClass() override { return TypeClass::Static; }
    std::string DebugPrint() override { return "StaticTypeInfo"; }
    std::string GetTypeName() override { return "StaticTypeInfo"; }
    bool EqualType(TypeInfo* pOther) override { throw "Wat"; }
    TypeInfo* MakeSpecificType(TypeInfo* pGenericArgType, TypeCollection* pCollection) override { throw "Wat"; }
    std::string GetDeclaration(VariableInfo*, ExpressionNode* pInitExpr) override { throw "Wat"; }
    
    TypeInfo* GetTypeInfo() { return _pTypeInfo; }

private:
    TypeInfo* _pTypeInfo;
};
