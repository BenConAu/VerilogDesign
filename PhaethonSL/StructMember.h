#pragma once

class StructMember
{
public:
    StructMember(int symIndex, TypeInfo* pType)
    {
        _symIndex = symIndex;
        _pType = pType;
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
        return _pType->GetSize();
    }

private:
    int _symIndex;
    TypeInfo* _pType;
};
