#pragma once

#include "TypeInfo.h"

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

    const char* DebugPrint() override
    {
        return "GenericTypeInfo";
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
            return false;
        }

        GenericTypeInfo* pOtherGen = dynamic_cast<GenericTypeInfo*>(pOther);
        if (_symIndex != pOtherGen->GetSymbolIndex())
        {
            return false;
        }

        if (_pScope != pOtherGen->GetScope())
        {
            return false;
        }

        return true;
    }

private:
    int _symIndex;
    FunctionDeclaratorNode* _pScope;
};
