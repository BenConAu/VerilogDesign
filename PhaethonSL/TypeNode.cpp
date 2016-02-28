#include "TypeNode.h"
#include "PSLCompilerContext.h"
#include "BasicTypeInfo.h"
#include "StructTypeInfo.h"

TypeNode::TypeNode(PSLCompilerContext* pContext, TypeType t, int type) : ASTNode(pContext)
{
    _type = type;
    _typeType = t;
}

TypeInfo* TypeNode::GetTypeInfo()
{
    if (_typeType == BasicType)
    {
        return GetContext()->_typeCollection.GetBasicType(_type);
    }
    else
    {
        return GetContext()->_typeCollection.GetStructType(_type);
    }
}

void TypeNode::VerifyNodeImpl()
{
}
