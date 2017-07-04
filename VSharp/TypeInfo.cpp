#include "TypeInfo.h"
#include "RegisterTypeInfo.h"
#include "ASTNode.h"
#include "VSharp.tab.h"

bool TypeInfo::IsFloat(TypeInfo* pInfo)
{
    return false;
}

bool TypeInfo::IsNonFloat(TypeInfo* pInfo)
{
    return true;
}