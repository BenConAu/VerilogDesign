#pragma once

#include "VariableLocation.h"

class RegisterCollection;

class SmartRegister
{
public:
    SmartRegister(RegIndex index, RegisterCollection* pCollection);
    SmartRegister();
    ~SmartRegister();

private:
    RegIndex _index;
    RegisterCollection* _pCollection;
};