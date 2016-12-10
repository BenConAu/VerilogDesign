#pragma once

#include "VariableLocation.h"

class RegisterCollection;

class SmartRegister
{
public:
    explicit SmartRegister(RegIndex index, RegisterCollection* pCollection);
    ~SmartRegister();

    void operator=(SmartRegister&) = delete;
    void operator=(SmartRegister&&) = delete;

private:
    RegIndex _index;
    RegisterCollection* _pCollection;
};