#pragma once

#include <map>
#include <deque>
#include "VariableLocation.h"

class RegisterCollection
{
public:
    RegisterCollection(int regCount);
    RegIndex AllocateRegister();
    void DeallocateRegister(RegIndex reg);

private:
    std::deque<RegIndex> _availableReg;
};

/*class TemporaryRegister
{
public:
    TemporaryRegister(VariableLocation* pLocation, RegisterCollection* pCollection)
    {
        _fAllocatedTemporary = false;
        _pLocation = pLocation;
        _pCollection = pCollection;

        if (_pLocation->_type == LocationType::Memory)
        {
            // We need a temporary register because we cannot multiply memory
            (*_pLocation) = VariableLocation(pCollection->AllocateRegister());
            _fAllocatedTemporary = true;
        }
    }

    ~TemporaryRegister()
    {
        // Return temporary register
        if (_fAllocatedTemporary)
        {
            _pCollection->DeallocateRegister(_pLocation->_regIndex);
        }
    }

private:
    bool _fAllocatedTemporary;
    VariableLocation* _pLocation;
    RegisterCollection* _pCollection;
};*/
