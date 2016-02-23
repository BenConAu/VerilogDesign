#pragma once

#include <map>
#include <deque>

typedef unsigned char RegIndex;

class RegisterCollection
{
public:
    RegisterCollection(int regCount);
    RegIndex AllocateRegister();
    void DeallocateRegister(RegIndex reg);

private:
    std::deque<RegIndex> _availableReg;
};
