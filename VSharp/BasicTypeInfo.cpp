#include "BasicTypeInfo.h"
#include "PSLCompilerContext.h"
#include "VSharp.tab.h"

BasicTypeInfo::BasicTypeInfo(int typeToken)
{
    _typeToken = typeToken;
}

unsigned int BasicTypeInfo::GetSize()
{
    // All basic types are size 4
    return 4;
}

TypeClass BasicTypeInfo::GetTypeClass()
{
    return TypeClass::Basic;
}

std::string BasicTypeInfo::DebugPrint()
{
    return "BasicTypeInfo";
}

std::string BasicTypeInfo::GetTypeName()
{
    switch (_typeToken)
    {
    case BYTE_TOKEN:
        return "Byte";
        
    case WORD_TOKEN:
        return "Word";

    case FLOAT_TOKEN:
        return "Float";

    default:
        throw "Unknown type name";
    }
}

int BasicTypeInfo::GetTypeToken() const
{
    return _typeToken;
}

bool BasicTypeInfo::EqualType(TypeInfo *pOther)
{
    if (pOther->GetTypeClass() != TypeClass::Basic)
    {
        return false;
    }

    BasicTypeInfo *pOtherBasic = dynamic_cast<BasicTypeInfo *>(pOther);
    if (_typeToken != pOtherBasic->GetTypeToken())
    {
        return false;
    }

    return true;
}

TypeInfo *BasicTypeInfo::MakeSpecificType(TypeInfo *pGenericArgType, TypeCollection *pCollection)
{
    // Basic types cannot have generic arguments
    return this;
}