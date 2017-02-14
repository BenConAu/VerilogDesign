#pragma once

#include <deque>
#include <vector>
#include "VariableLocation.h"

class RegisterCollection
{
public:
    RegisterCollection(int regCount);
    RegIndex AllocateRegister(); 
    void DeallocateRegister(RegIndex reg);
    void ReserveRegister(RegIndex reg);

    RegIndex FirstUnused();

    size_t GetUsedCount() const { return _usedReg.size(); }
    RegIndex GetUsedReg(size_t index) { return _usedReg[index]; }

private:
    std::deque<RegIndex> _availableReg;
    std::vector<RegIndex> _usedReg;
};
