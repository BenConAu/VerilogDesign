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
    ASTNode *pInitExpr) : ASTNode(pContext)
{
    AddNode(pType);

    if (pInitExpr != nullptr)
    {
        IdentifierNode *pLeft = new IdentifierNode(pContext, location, symIndex);
        AssignmentNode *pAssignment = new AssignmentNode(pContext, location, pLeft, pInitExpr);

        AddNode(pAssignment);
    }

    _symIndex = symIndex;
    _arraySize = arraySize._value;
    _location = location;
}

VariableDeclarationNode::VariableDeclarationNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pType,
    int symIndex,
    ASTNode *pInitExpr) : ASTNode(pContext)
{
    AddNode(pType);

    if (pInitExpr != nullptr)
    {
        IdentifierNode *pLeft = new IdentifierNode(pContext, location, symIndex);
        AssignmentNode *pAssignment = new AssignmentNode(pContext, location, pLeft, pInitExpr);

        AddNode(pAssignment);
    }

    _symIndex = symIndex;
    _arraySize = -1;
    _location = location;
}

void VariableDeclarationNode::PreVerifyNodeImpl()
{
    //printf("Adding variable %s\n", GetContext()->_symbols[_symIndex].c_str());
    ModuleDefinitionNode *pFunc = GetTypedParent<ModuleDefinitionNode>();

    TypeInfo* pInfo = dynamic_cast<TypeNode *>(GetChild(0))->GetTypeInfo();
    if (_arraySize != -1)
    {
        pInfo = GetContext()->_typeCollection.GetArrayType(pInfo, _arraySize);
    }

    // Add variable to collection and mark first usage
    GetContext()->_symbolTable.AddVariable(
        pFunc,
        _symIndex,
        VariableLocationType::Member,
        pInfo);
}

void VariableDeclarationNode::PostProcessNodeImpl()
{
    ModuleDefinitionNode *pModule = GetTypedParent<ModuleDefinitionNode>();

    // Spit out the preamble
    VariableInfo* pInfo = dynamic_cast<VariableInfo*>(GetContext()->_symbolTable.GetInfo(_symIndex, pModule));

    // Each type should know how to make a declaration
    std::string decl = pInfo->GetTypeInfo()->GetDeclaration(pInfo);

    // This node owns putting the semicolon on it
    GetContext()->OutputLine("%s;", decl.c_str());    
}
