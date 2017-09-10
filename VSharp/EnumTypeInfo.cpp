#include "EnumTypeInfo.h"
#include "VSharpCompilerContext.h"
#include "VariableInfo.h"
#include <cmath>

EnumTypeInfo::EnumTypeInfo(int symIndex, PSLCompilerContext* pContext)
{
    _symIndex = symIndex;
    _pContext = pContext;
}

void EnumTypeInfo::AddMember(int symIndex)
{
    //printf("Adding member, size is now %d\n", (int)_values.size());

    _values[symIndex] = _values.size();
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
    return _pContext->_symbols[_symIndex];
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

TypeInfo* EnumTypeInfo::MakeSpecificType(TypeInfo* pGenericArgType, TypeCollection* pCollection)
{
    // Structs cannot currently have generic arguments
    return this;
}    

bool EnumTypeInfo::IsMember(int sym)
{
    return (_values.count(sym) != 0);
}

int EnumTypeInfo::GetValue(int sym)
{
    //printf("Getting value %d for symbol %s\n", _values[sym], _pContext->_symbols[sym].c_str());

    return _values[sym];
}

int EnumTypeInfo::GetBitLength() const
{
    if (_values.size() == 1)
    {
        return 1;
    }
    else
    {
        return static_cast<int>(::ceil(::log2(_values.size())));
    }
}

std::string EnumTypeInfo::GetDeclaration(VariableInfo* pInfo, ExpressionNode* pInitExpr)
{
    if (pInitExpr != nullptr)
    {
        throw "Enum types don't support init expressions";
    }

    char buffer[1024];
    sprintf(buffer, "reg[%d:0] %s", GetBitLength() - 1, pInfo->GetSymbol());
    return buffer;
}