#include "TypeInfo.h"
#include "BasicTypeInfo.h"
#include "PointerTypeInfo.h"
#include "ASTNode.h"
#include "PSL.tab.h"

bool TypeInfo::IsFloat(TypeInfo* pInfo)
{
    BasicTypeInfo* pBasicInfo = dynamic_cast<BasicTypeInfo*>(pInfo);
    if (pBasicInfo == nullptr)
    {
        return false;
    }

    return (pBasicInfo->GetTypeToken() == FLOAT_TOKEN);
}

bool TypeInfo::IsNonFloat(TypeInfo* pInfo)
{
    BasicTypeInfo* pBasicInfo = dynamic_cast<BasicTypeInfo*>(pInfo);
    if (pBasicInfo != nullptr)
    {
        return (pBasicInfo->GetTypeToken() == WORD_TOKEN || pBasicInfo->GetTypeToken() == BOOL_TOKEN);
    }
    else
    {
        PointerTypeInfo* pPointerInfo = dynamic_cast<PointerTypeInfo*>(pInfo);
        if (pPointerInfo != nullptr)
        {
            return true;
        }

        return false;
    }
}