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
    //printf("Allocated %d\n", (int)ret);
    _availableReg.pop_front();
    return ret;
}

RegIndex RegisterCollection::FirstUnused()
{
    RegIndex lowest = 0xFF;

    for (size_t i = 0 ; i < _availableReg.size(); i++)
    {
        if (_availableReg[i] < lowest)
        {
            lowest = _availableReg[i];
        }
    }

    return lowest;
}

void RegisterCollection::DeallocateRegister(RegIndex reg)
{
    _availableReg.push_front(reg);
}

void RegisterCollection::ReserveRegister(RegIndex reg)
{
    auto regIter = std::find(_availableReg.begin(), _availableReg.end(), reg);
    if (regIter == _availableReg.end())
    {
        throw "Reserving register that is not available";
    }
    
    _availableReg.erase(regIter);
}