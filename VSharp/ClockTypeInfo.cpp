#include "ClockTypeInfo.h"
#include "VariableInfo.h"

ClockTypeInfo::ClockTypeInfo()
{

}

TypeClass ClockTypeInfo::GetTypeClass()  
{ 
    return TypeClass::Clock; 
}

std::string ClockTypeInfo::GetDeclaration(VariableInfo* pInfo, ExpressionNode* pInitExpr) 
{ 
    if (pInitExpr != nullptr)
    {
        throw "ClockType does not support init expressions";
    }
    
    char buffer[1024]; 
    sprintf(buffer, "reg %s = 0; always #5 %s = !%s", pInfo->GetSymbol(), pInfo->GetSymbol(), pInfo->GetSymbol()); 
    return buffer; 
}

bool ClockTypeInfo::EqualType(TypeInfo* pOther)
{ 
    return (dynamic_cast<ClockTypeInfo*>(pOther) != nullptr);
}
