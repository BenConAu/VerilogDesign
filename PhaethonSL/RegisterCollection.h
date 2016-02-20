#pragma once

#include <map>
#include <deque>

typedef unsigned char RegIndex;

class RegisterCollection
{
public:
    RegisterCollection(int regCount);
    RegIndex AddVariableRegister(int symbol);
    RegIndex GetNextRegister();
    RegIndex GetVariableRegister(int symbol);
    void ClearVariableRegister(RegIndex reg);

private:
    std::map<int, RegIndex> _symbolToReg;
    std::deque<RegIndex> _availableReg;
};
