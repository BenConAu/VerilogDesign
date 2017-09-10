#include "StructTypeInfo.h"
#include "VSharpCompilerContext.h"
#include "VariableInfo.h"

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
        pMemberType = pContext->_typeCollection.GetArrayType(pType, dimension);
    }

    _members.push_back(std::unique_ptr<StructMember>(new StructMember(symIndex, pMemberType, dimension)));
}

std::string StructTypeInfo::GetTypeName()
{
    return _pContext->_symbols[_symIndex];
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

int StructTypeInfo::GetBitLength() const
{
    int size = 0;

    for (size_t i = 0; i < _members.size(); i++)
    {
        size += _members[i]->GetBitLength();
    }

    return size;
}

std::string StructTypeInfo::GetDeclaration(VariableInfo* pInfo, ExpressionNode* pInitExpr)
{
    if (pInitExpr != nullptr)
    {
        throw "StructTypeInfo does not support init expressions yet";
    }

    char buffer[1024];
    sprintf(buffer, "reg[%d:0] %s", GetBitLength() - 1, pInfo->GetSymbol());
    return buffer;
}