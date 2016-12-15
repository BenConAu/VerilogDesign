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

private:
    int _symIndex;
    FunctionDeclaratorNode* _pScope;
};
