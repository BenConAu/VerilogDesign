#include "VariableDeclarationNode.h"
#include "ModuleDefinitionNode.h"
#include "AssignmentNode.h"
#include "IdentifierNode.h"
#include "TypeNode.h"
#include "VariableLocationType.h"
#include "VariableInfo.h"

VariableDeclarationNode::VariableDeclarationNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pType,
    int symIndex,
    const UIntConstant& arraySize,
    ASTNode *pInitExpr) : ASTNode(pContext, location)
{
    AddNode(pType);
    AddNode(pInitExpr);

    _symIndex = symIndex;
    _arraySize = arraySize._value;
}

VariableDeclarationNode::VariableDeclarationNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pType,
    int symIndex,
    ASTNode *pInitExpr) : ASTNode(pContext, location)
{
    AddNode(pType);
    AddNode(pInitExpr);

    _symIndex = symIndex;
    _arraySize = -1;
}

void VariableDeclarationNode::PreVerifyNodeImpl()
{
    //printf("Adding variable %s\n", GetContext()->GetSymbolString(_symIndex).c_str());
    ModuleDefinitionNode *pFunc = GetTypedParent<ModuleDefinitionNode>();

    TypeInfo* pInfo = GetTypeNode()->GetTypeInfo();
    if (_arraySize != -1)
    {
        pInfo = GetContext()->GetTypeCollection()->GetArrayType(pInfo, _arraySize);
    }

    // Add variable to collection and mark first usage
    GetContext()->GetSymbolTable()->AddVariable(
        pFunc,
        _symIndex,
        VariableLocationType::Member,
        GetTypeNode()->IsWire() ? TypeModifier::Wire : TypeModifier::None,
        pInfo);
}

void VariableDeclarationNode::PostProcessNodeImpl()
{
    ModuleDefinitionNode *pModule = GetTypedParent<ModuleDefinitionNode>();

    // Spit out the preamble
    VariableInfo* pInfo = dynamic_cast<VariableInfo*>(GetContext()->GetSymbolTable()->GetInfo(_symIndex, pModule));
    ExpressionNode* pInitExpr = dynamic_cast<ExpressionNode*>(GetChild(1));

    // Each type should know how to make a declaration
    std::string decl = pInfo->GetTypeInfo()->GetDeclaration(pInfo, pInitExpr);

    // This node owns putting the semicolon on it
    GetContext()->OutputLine("%s;", decl.c_str());    
}

TypeNode* VariableDeclarationNode::GetTypeNode()
{
    return dynamic_cast<TypeNode *>(GetChild(0));
}