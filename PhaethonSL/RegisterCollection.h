#pragma once

#include <deque>
#include "VariableLocation.h"

class RegisterCollection
{
public:
    RegisterCollection(int regCount);
    RegIndex AllocateRegister();
    void DeallocateRegister(RegIndex reg);
    void ReserveRegister(RegIndex reg);

private:
    std::deque<RegIndex> _availableReg;
};
