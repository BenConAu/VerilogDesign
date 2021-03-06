#include "FunctionDeclaratorNode.h"
#include "FunctionParameterNode.h"
#include "ModuleDefinitionNode.h"
#include "TypeNode.h"
#include "VariableInfo.h"

ASTNode* FunctionParameterNode::DuplicateNodeImpl(FunctionExpandType type)
{
    if (type == FunctionExpandType::Function)
    {
        throw "You should not be duplicating function parameters";
    }

    return new FunctionParameterNode(GetContext(), GetLocation(), _symIndex, _fOut);
}

void FunctionParameterNode::VerifyNodeImpl()
{
    FunctionDeclaratorNode *pFuncDecl = GetTypedParent<FunctionDeclaratorNode>();

    VariableLocationType location = VariableLocationType::Member;
    if (_fOut)
    {
        location = VariableLocationType::Output;
    }
    else
    {
        location = VariableLocationType::Input;
    }

    TypeInfo* pTypeInfo = dynamic_cast<TypeNode *>(GetChild(0))->GetTypeInfo();

    // Add variable to collection and mark first usage
    VariableInfo *pParamInfo = GetContext()->GetSymbolTable()->AddVariable(
        pFuncDecl,
        _symIndex,
        location,
        TypeModifier::None,
        pTypeInfo
        );
}

int FunctionParameterNode::GetSymbolIndex() const 
{ 
    return _symIndex; 
}

const char* FunctionParameterNode::GetSymbol() 
{ 
    return GetContext()->GetSymbolString(_symIndex).c_str(); 
}

bool FunctionParameterNode::IsOutParam() const 
{ 
    return _fOut; 
}

TypeNode* FunctionParameterNode::GetTypeNode() 
{ 
    return dynamic_cast<TypeNode*>(GetChild(0)); 
}

TypeInfo* FunctionParameterNode::GetTypeInfo() 
{ 
    return GetTypeNode()->GetTypeInfo(); 
}
