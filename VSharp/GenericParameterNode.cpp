#include "GenericParameterNode.h"
#include "ModuleDefinitionNode.h"
#include "TypeNode.h"
#include "VariableInfo.h"

ASTNode* GenericParameterNode::DuplicateNodeImpl(FunctionExpandType type)
{
    return new GenericParameterNode(GetContext(), GetLocation(), GetChild(0)->DuplicateNode(type), _symIndex);
}

void GenericParameterNode::VerifyNodeImpl()
{
    ModuleDefinitionNode *pModule = GetTypedParent<ModuleDefinitionNode>();
    TypeInfo* pTypeInfo = dynamic_cast<TypeNode *>(GetChild(0))->GetTypeInfo();

    VariableInfo* pVarInfo = GetContext()->GetSymbolTable()->AddVariable(
        pModule,
        _symIndex,
        VariableLocationType::Generic,
        TypeModifier::None,
        pTypeInfo);
}

int GenericParameterNode::GetSymbolIndex() const 
{ 
    return _symIndex; 
}

const char* GenericParameterNode::GetSymbol() 
{ 
    return GetContext()->GetSymbolString(_symIndex).c_str(); 
}

bool GenericParameterNode::IsTypename() const 
{ 
    return _fTypename; 
}

TypeNode* GenericParameterNode::GetTypeNode() 
{ 
    return dynamic_cast<TypeNode*>(GetChild(0)); 
}

TypeInfo* GenericParameterNode::GetTypeInfo() 
{ 
    return GetTypeNode()->GetTypeInfo(); 
}
