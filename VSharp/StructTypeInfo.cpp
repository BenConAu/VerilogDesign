#include "StructTypeInfo.h"
#include "VSharpCompilerContext.h"

void StructTypeInfo::AddMember(
    PSLCompilerContext *pContext,
    int symIndex,
    TypeInfo *pType,
    int dimension)
{
    TypeInfo *pMemberType = pType;

    if (dimension != -1)
    {
        // If the dimension is provided, then the type is of a pointer
        pMemberType = pContext->_typeCollection.GetArrayType(pType);
    }

    _members.push_back(std::unique_ptr<StructMember>(new StructMember(symIndex, pMemberType, dimension)));
}

std::string StructTypeInfo::GetTypeName()
{
    return _pContext->_symbols[_symIndex];
}
