#include "VariableDeclarationNode.h"
#include "FunctionDeclaratorNode.h"
#include "TypeNode.h"

VariableDeclarationNode::VariableDeclarationNode(PSLCompilerContext* pContext, ASTNode* pType, int symIndex) : ASTNode(pContext)
{
    AddNode(pType);
    _symIndex = symIndex;
    _fGlobal = false;
}

void VariableDeclarationNode::VerifyNodeImpl()
{
    //printf("Adding variable %s\n", GetContext()->_symbols[_symIndex].c_str());
    // Is this a global?
    FunctionDeclaratorNode* pFunc = GetTypedParent<FunctionDeclaratorNode>();
    if (pFunc == nullptr)
    {
        _fGlobal = true;
    }

    // Add variable to collection and mark first usage
    GetContext()->_varCollection.AddVariable(
        _symIndex,
        pFunc,
        dynamic_cast<TypeNode*>(GetChild(0))->GetTypeInfo(),
        nullptr
    );
}

void VariableDeclarationNode::PostProcessNodeImpl()
{
    // Nothing to output for declarations
}
