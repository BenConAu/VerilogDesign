#pragma once

#include <cstdlib>

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

    unsigned int _value;
    unsigned int _bitLength;
};