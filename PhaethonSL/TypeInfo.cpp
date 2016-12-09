#include "TypeInfo.h"
#include "BasicTypeInfo.h"
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