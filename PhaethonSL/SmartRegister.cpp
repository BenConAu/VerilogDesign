#include "SmartRegister.h"
#include "RegisterCollection.h"

SmartRegister::SmartRegister(RegIndex index, RegisterCollection* pCollection)
{
    _index = index;
    _pCollection = pCollection;
}

SmartRegister::SmartRegister()
{
    _index = 0xFF;
    _pCollection = nullptr;
}

SmartRegister::~SmartRegister()
{
    if (_pCollection != nullptr)
    {
        _pCollection->DeallocateRegister(_index);
    }
}
