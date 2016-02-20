#include "RegisterCollection.h"

RegisterCollection::RegisterCollection(int regCount)
{
    for (RegIndex i = 0; i < regCount; i++)
    {
        _availableReg.push_back(i);
    }
}

RegIndex RegisterCollection::AddVariableRegister(int symbol)
{
    auto iter = _symbolToReg.find(symbol);
    if (iter != _symbolToReg.end())
    {
        throw "Already added";
    }
    else
    {
        if (_availableReg.size() == 0)
        {
            throw "Crap I ran out of registers guv";
        }

        RegIndex ret = GetNextRegister();
        _symbolToReg[symbol] = ret;

        //printf("Add register index %d for variable %d\n", ret, symbol);
        return ret;
    }
}

RegIndex RegisterCollection::GetNextRegister()
{
    RegIndex ret = _availableReg.front();
    _availableReg.pop_front();
    return ret;
}

RegIndex RegisterCollection::GetVariableRegister(int symbol)
{
    auto iter = _symbolToReg.find(symbol);
    if (iter == _symbolToReg.end())
    {
        throw "Symbol not found";
    }
    else
    {
        return _symbolToReg[symbol];
    }
}

void RegisterCollection::ClearVariableRegister(RegIndex reg)
{
    for (auto iter = _symbolToReg.begin(); iter != _symbolToReg.end(); iter++)
    {
        if (iter->second == reg)
        {
            _symbolToReg.erase(iter);
            break;
        }
    }
}
