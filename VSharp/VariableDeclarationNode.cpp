#include "VariableDeclarationNode.h"
#include "ModuleDeclaratorNode.h"
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
}

void VariableDeclarationNode::PreVerifyNodeImpl()
{
    //printf("Adding variable %s\n", GetContext()->_symbols[_symIndex].c_str());
    ModuleDeclaratorNode *pFunc = GetTypedParent<ModuleDeclaratorNode>();

    // Add variable to collection and mark first usage
    GetContext()->_symbolTable.AddVariable(
        pFunc,
        _symIndex,
        VariableLocationType::Member,
        dynamic_cast<TypeNode *>(GetChild(0))->GetTypeInfo());
}

void VariableDeclarationNode::PreProcessNodeImpl()
{
    ModuleDeclaratorNode *pModule = GetTypedParent<ModuleDeclaratorNode>();

    // Spit out the preamble
    VariableInfo* pInfo = dynamic_cast<VariableInfo*>(GetContext()->_symbolTable.GetInfo(_symIndex, pModule));

    // Find out the bit width
    RegisterTypeInfo* pRegInfo = dynamic_cast<RegisterTypeInfo*>(pInfo->GetTypeInfo());

    GetContext()->OutputLine("reg[%d:0] %s;", pRegInfo->GetBitLength() - 1, pInfo->GetSymbol());
}
