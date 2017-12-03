#include "RegisterTypeInfo.h"
#include "ParserContext.h"
#include "VariableInfo.h"
#include "ExpressionNode.h"
#include "VSharp.tab.h"

RegisterTypeInfo::RegisterTypeInfo(int bitLength)
{
    _bitLength = bitLength;

    //if (_bitLength > 512)
    //{
      //  throw "Gotcha!";
    //}
}

TypeClass RegisterTypeInfo::GetTypeClass()
{
    return TypeClass::Register;
}

std::string RegisterTypeInfo::DebugPrint()
{
    char result[100];
    sprintf(result, "RegisterTypeInfo bitLength = %d", _bitLength);
    return result;
}

std::string RegisterTypeInfo::GetTypeName()
{
    char result[100];
    sprintf(result, "Register%d", _bitLength);
    return result;
}

bool RegisterTypeInfo::EqualType(TypeInfo *pOther)
{
    if (pOther->GetTypeClass() != TypeClass::Register)
    {
        return false;
    }

    RegisterTypeInfo *pOtherBasic = dynamic_cast<RegisterTypeInfo *>(pOther);
    if (_bitLength != pOtherBasic->GetBitLength())
    {
        return false;
    }

    return true;
}

TypeInfo *RegisterTypeInfo::MakeSpecificType(TypeInfo *pGenericArgType, TypeCollection *pCollection)
{
    // Basic types cannot have generic arguments
    return this;
}

std::string RegisterTypeInfo::GetDeclaration(VariableInfo* pInfo, ExpressionNode* pInitExpr)
{
    char buffer[1024];

    if (pInitExpr != nullptr)
    {
        std::unique_ptr<ExpressionResult> exprResult(pInitExpr->TakeResult());        

        // This won't work with arrays eventually, but that is cool for now
        sprintf(
            buffer, 
            "%s[%d:0] %s = %s",
            (pInfo->GetModifier() == TypeModifier::Wire) ? "wire" : "reg",
            GetBitLength() - 1, 
            pInfo->GetSymbol(),
            exprResult->GetString().c_str());
    }
    else
    {
        sprintf(
            buffer, 
            "%s[%d:0] %s",
            (pInfo->GetModifier() == TypeModifier::Wire) ? "wire" : "reg",
            GetBitLength() - 1, 
            pInfo->GetSymbol());
    }

    return buffer;
}