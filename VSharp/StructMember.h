#pragma once

class StructMember
{
public:
    StructMember(int symIndex, TypeInfo* pType, int dimension)
    {
        _symIndex = symIndex;
        _dimension = dimension;
        _pType = pType;

        //printf("Creating member with type %p:%s\n", pType, pType->DebugPrint().c_str());
    }

    int GetSymbolIndex()
    {
        return _symIndex;
    }

    TypeInfo* GetType()
    {
        return _pType;
    }

    unsigned int GetSize()
    {
/*        if (_dimension == -1)
        {
            return _pType->GetSize();
        }
        else
        {
            //printf("About to deref type %p\n", _pType);
            return _pType->GetSize() * _dimension;
        }*/
        return -1;
    }

private:
    int _symIndex;
    int _dimension;
    TypeInfo* _pType;
};
