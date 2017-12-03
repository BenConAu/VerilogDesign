#include "ModuleTypeInfo.h"
#include "ParserContext.h"
#include "ModuleDefinitionNode.h"
#include "ExpressionNode.h"
#include "VariableInfo.h"

std::string ModuleTypeInfo::GetTypeName()
{
    return _pModuleDef->GetContext()->GetSymbolString(_symIndex);
}

std::string ModuleTypeInfo::GetDeclaration(VariableInfo* pInfo, ExpressionNode* pInitExpr)
{
    // Unlike other types, you *have* to initialize a module with an expression
    if (pInitExpr == nullptr)
    {
        throw "Missing initial expression for module";
    }

    // We will use the result of the init expression (it has the param list)
    std::unique_ptr<ExpressionResult> initResult(pInitExpr->TakeResult());

    char buffer[1024];
    sprintf(
        buffer, 
        "%s %s%s",
        GetTypeName().c_str(),
        pInfo->GetSymbol(), 
        initResult->GetString().c_str());
    return buffer;
}

size_t ModuleTypeInfo::GetParameterCount() 
{ 
    return _pModuleDef->GetParameterCount(); 
}

ModuleParameterNode* ModuleTypeInfo::GetParameter(size_t index)
{
    return _pModuleDef->GetParameter(index);
}

bool ModuleTypeInfo::IsForward() const 
{ 
    return _pModuleDef->IsForward(); 
}
