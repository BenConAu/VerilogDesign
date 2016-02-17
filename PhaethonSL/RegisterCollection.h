#pragma once

#include <map>
#include <deque>

typedef unsigned char RegIndex;

class RegisterCollection
{
public:
    RegisterCollection(int regCount)
    {
        for (RegIndex i = 0; i < regCount; i++)
        {
            _availableReg.push_back(i);
        }
    }

    RegIndex GetSymbolRegister(int symbol)
    {
        auto iter = _symbolToReg.find(symbol);
        if (iter != _symbolToReg.end())
        {
            //printf("Symbol already exists, mapped to %d\n", _symbolToReg[symbol]);
            return _symbolToReg[symbol];
        }
        else
        {
            if (_availableReg.size() == 0)
            {
                printf("Crap I ran out of registers guv\n");
                throw 0;
            }

            RegIndex ret = _availableReg.front();
            _availableReg.pop_front();
            _symbolToReg[symbol] = ret;

            //printf("Found a register index %d\n", ret);
            return ret;
        }
    }

    void ClearSymbolRegister(RegIndex reg)
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

private:
    std::map<int, RegIndex> _symbolToReg;
    std::deque<RegIndex> _availableReg;
};
