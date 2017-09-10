#include "ModuleTypeInfo.h"
#include "VSharpCompilerContext.h"
#include "ModuleDefinitionNode.h"
#include "VariableInfo.h"

std::string ModuleTypeInfo::GetTypeName()
{
    return _pModuleDef->GetContext()->_symbols[_symIndex];
}

std::string ModuleTypeInfo::GetDeclaration(VariableInfo* pInfo)
{
    char buffer[1024];
    sprintf(buffer, "%s", pInfo->GetSymbol());
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
