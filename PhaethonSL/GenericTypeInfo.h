#pragma once

#include "TypeInfo.h"
#include <string>

class FunctionDeclaratorNode;

class GenericTypeInfo : public TypeInfo
{
public:
    GenericTypeInfo(int symIndex, FunctionDeclaratorNode* pScope)
    {
        _symIndex = symIndex;
        _pScope = pScope;
    }

    unsigned int GetSize() override
    {
        throw "Generic member being asked for size is a bug";
    }

    TypeClass GetTypeClass() override
    {
        return TypeClass::Generic;
    }

    std::string DebugPrint() override
    {
        char buffer[100];
        sprintf(buffer, "GenericTypeInfo (to %d in %p)", _symIndex, _pScope);
        return buffer;
    }

    std::string GetTypeName() override
    {
        throw "Should not be asking for type name of generic";
    }

    int GetSymbolIndex() const
    {
        return _symIndex;
    }

    FunctionDeclaratorNode* GetScope() const
    {
        return _pScope;
    }

    bool EqualType(TypeInfo* pOther) override
    {
        if (pOther->GetTypeClass() != TypeClass::Generic)
        {
            printf("Other is not a generic type\n");
            return false;
        }

        GenericTypeInfo* pOtherGen = dynamic_cast<GenericTypeInfo*>(pOther);
        if (_symIndex != pOtherGen->GetSymbolIndex())
        {
            printf("Other is different symbol\n");
            return false;
        }

        if (_pScope != pOtherGen->GetScope())
        {
            printf("Other is different scope");
            return false;
        }

        printf("Generic types are equal\n");
        return true;
    }

    TypeInfo* MakeSpecificType(TypeInfo* pGenericArgType, TypeCollection* pCollection) override
    {
        return pGenericArgType;
    }

private:
    int _symIndex;
    FunctionDeclaratorNode* _pScope;
};
