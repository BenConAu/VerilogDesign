#pragma once

#include <deque>
#include <vector>
#include <cstdlib>
#include "VariableLocation.h"

class RegisterCollection
{
public:
    RegisterCollection(int regCount);
    RegIndex AllocateRegister(); 
    void DeallocateRegister(RegIndex reg);
    void ReserveRegister(RegIndex reg);

    void Push();
    void Pop();

    RegIndex FirstUnused();

    size_t GetUsedCount() const { return _usedReg.size(); }
    RegIndex GetUsedReg(size_t index) { return _usedReg[index]; }

private:
    std::deque<RegIndex> _availableReg;
    std::vector<RegIndex> _usedReg;
    std::vector<RegIndex> _delayedDeallocations;
    int _delayStack;
};
