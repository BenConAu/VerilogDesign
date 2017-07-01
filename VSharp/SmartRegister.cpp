#include "SmartRegister.h"
#include "RegisterCollection.h"

SmartRegister::SmartRegister(RegIndex index, RegisterCollection* pCollection)
{
    _index = index;
    _pCollection = pCollection;

    //printf("SmartRegister %p constructor with collection = %p\n", this, _pCollection);
}

SmartRegister::~SmartRegister()
{
    //printf("SmartRegister %p destructor with collection = %p\n", this, _pCollection);

    _pCollection->DeallocateRegister(_index);
}
