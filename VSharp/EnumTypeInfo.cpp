#include "EnumTypeInfo.h"
#include "ParserContext.h"
#include "VariableInfo.h"
#include <cmath>

// Passing 1 here is a bit dodgy, and it will come and bite me
EnumTypeInfo::EnumTypeInfo(int symIndex, ParserContext* pContext) : RegisterTypeInfo(1)
{
    _symIndex = symIndex;
    _pContext = pContext;
}

void EnumTypeInfo::AddMember(int symIndex)
{
    //printf("Adding member, size is now %d\n", (int)_values.size());

    _values[symIndex] = _values.size();

    if (_values.size() != 1)
    {
        SetBitLength(static_cast<int>(::ceil(::log2(_values.size()))));
    }
}

TypeClass EnumTypeInfo::GetTypeClass()
{
    return TypeClass::Enum;
}

std::string EnumTypeInfo::DebugPrint()
{
    return "EnumTypeInfo";
}

std::string EnumTypeInfo::GetTypeName()
{
    return _pContext->GetSymbolString(_symIndex);
}

int EnumTypeInfo::GetSymbolIndex()
{
    return _symIndex;
}

bool EnumTypeInfo::EqualType(TypeInfo* pOther)
{
    // Could do this for all of them, but maybe not forever
    return (static_cast<TypeInfo*>(this) == pOther);
}

bool EnumTypeInfo::IsMember(int sym)
{
    return (_values.count(sym) != 0);
}

int EnumTypeInfo::GetValue(int sym)
{
    //printf("Getting value %d for symbol %s\n", _values[sym], _pContext->GetSymbolString(sym].c_str());

    return _values[sym];
}
