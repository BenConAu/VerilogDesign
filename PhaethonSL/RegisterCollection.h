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

    RegIndex FirstUnused();

private:
    std::deque<RegIndex> _availableReg;
};
