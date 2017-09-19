#pragma once

#include "UIntConstant.h"

struct EnumItem
{
    EnumItem() = default;

    EnumItem(int a, UIntConstant b)
    {
        _SymIndex = a;
        _Value = b._value;
        _HasValue = true;
    }

    EnumItem(int a)
    {
        _SymIndex = a;
        _HasValue = false;
    }

    int _SymIndex;
    bool _HasValue;
    unsigned int _Value;
};
