#include "StructTypeInfo.h"
#include "ParserContext.h"
#include "VariableInfo.h"

void StructTypeInfo::AddMember(
    ParserContext *pContext,
    int symIndex,
    TypeInfo *pType,
    int dimension)
{
    TypeInfo *pMemberType = pType;

    if (dimension != -1)
    {
        // If the dimension is provided, then the type is of a pointer
        pMemberType = pContext->GetTypeCollection()->GetArrayType(pType, dimension);
    }

    StructMember* pNewMember = new StructMember(symIndex, pMemberType, dimension);
    _members.push_back(std::unique_ptr<StructMember>(pNewMember));

    int currentBitLength = GetBitLength();
    SetBitLength(currentBitLength + pNewMember->GetBitLength());
}

std::string StructTypeInfo::GetTypeName()
{
    return _pContext->GetSymbolString(_symIndex);
}

unsigned int StructTypeInfo::GetBaseLocation(int fieldSymIndex)
{
    unsigned int offset = 0;

    for (int i = (int)_members.size() - 1; i >= 0; i--)
    {
        if (_members[i]->GetSymbolIndex() == fieldSymIndex)
        {
            return offset;
        }

        offset += _members[i]->GetBitLength();
    }

    throw "Unknown member";
}
