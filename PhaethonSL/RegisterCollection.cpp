#include "RegisterCollection.h"
#include <algorithm>

RegisterCollection::RegisterCollection(int regCount)
{
    for (RegIndex i = 0; i < regCount; i++)
    {
        _availableReg.push_back(i);
    }

    _delayStack = 0;
}

void RegisterCollection::Push()
{
    _delayStack++;
}

void RegisterCollection::Pop()
{
    _delayStack--;

    if (_delayStack == 0)
    {
        for (int i = (int)_delayedDeallocations.size() - 1; i >= 0; i--)
        {
            //printf("Doing delayed deallocation of %d\n", (int)_delayedDeallocations[i]);
            DeallocateRegister(_delayedDeallocations[i]);
        }

        _delayedDeallocations.clear();
    }
}

RegIndex RegisterCollection::AllocateRegister()
{
    //for (int i = 0; i < 3; i++)
    //{
        //printf("%d, ", _availableReg[i]);
    //}

    RegIndex ret = _availableReg.front();
    _availableReg.pop_front();
    _usedReg.push_back(ret);

    //printf("Allocated %d\n", (int)ret);

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
    //for (int i = 0; i < 3; i++)
    //{
        //printf("%d, ", _availableReg[i]);
    //}

    //printf("Deallocated %d\n", (int)reg);
    if (_delayStack == 0)
    {
        _availableReg.push_front(reg);

        for (size_t i = 0; i < _usedReg.size(); i++)
        {
            if (_usedReg[i] == reg)
            {
                _usedReg.erase(_usedReg.begin() + i);
                break;
            }
        }
    }
    else
    {
        _delayedDeallocations.push_back(reg);        
    }
}

void RegisterCollection::ReserveRegister(RegIndex reg)
{
    auto regIter = std::find(_availableReg.begin(), _availableReg.end(), reg);
    if (regIter == _availableReg.end())
    {
        throw "Reserving register that is not available";
    }
    
    _availableReg.erase(regIter);
    _usedReg.push_back(reg);
}