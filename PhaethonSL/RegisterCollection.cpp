#include "RegisterCollection.h"

RegisterCollection::RegisterCollection(int regCount)
{
    for (RegIndex i = 0; i < regCount; i++)
    {
        _availableReg.push_back(i);
    }
}

RegIndex RegisterCollection::AllocateRegister()
{
    RegIndex ret = _availableReg.front();
    _availableReg.pop_front();
    return ret;
}

void RegisterCollection::DeallocateRegister(RegIndex reg)
{
    _availableReg.push_front(reg);
}

void RegisterCollection::ReserveRegister(RegIndex reg)
{
    auto regIter = std::find(_availableReg.begin(), _availableReg.end(), reg);
    _availableReg.erase(regIter);
}