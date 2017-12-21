#pragma once

#include <cstdlib>
#include <cstring>

struct UIntConstant
{
    UIntConstant(const char* pszLengthened, int radix)
    {
        const char* pszUStart = ::strstr(pszLengthened, "u");

        _value = ::strtol(pszLengthened, nullptr, radix);
        _bitLength = ::atoi(pszUStart + 1);
    }

    UIntConstant(unsigned int a, unsigned int b)
    {
        _value = a;
        _bitLength = b;
    }

    UIntConstant() = default;

    bool operator== (const UIntConstant& other)
    {
        return (_value == other._value && _bitLength == other._bitLength);
    }

    unsigned int _value;
    unsigned int _bitLength;
};