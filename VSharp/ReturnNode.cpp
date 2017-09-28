#include "ReturnNode.h"
#include "FunctionDeclaratorNode.h"
#include "StatementNode.h"
#include "VSharp.tab.h"

ASTNode* ReturnNode::DuplicateNodeImpl(DuplicateType type)
{
    if (type == DuplicateType::ExpandFunction)
    {
        throw "You should not be duplicating return statements";
    }

    return new ReturnNode(GetContext(), GetLocation());
}

ASTNode* ReturnNode::DuplicateNode(DuplicateType type)
{
    if (type == DuplicateType::ExpandFunction)
    {
        // Find out what function declared this return statement
        FunctionDeclaratorNode *pFuncDecl = GetTypedParent<FunctionDeclaratorNode>();
    
        // Find out what assignment expression triggered the expansion of that function
        StatementNode* pStatementNode = pFuncDecl->GetStatementNode();
    
        // Set the mapping that calls to the function are replaced with the child of this return
        pStatementNode->SetCallReplacement(pFuncDecl->GetCallNode(), GetChild(0));
    
        //printf("Duplicating return node %p, with function %s\n", this, pFuncDecl->GetFunctionName());
        
            // Replace the return statement with a duplicate of this assignment - function
        // calls in this duplication will be replaced with a duplicate of what was
        // returned in the return statement.
        ASTNode* pReplacement = pStatementNode->DuplicateNode(DuplicateType::ExpandFunction);
    
        // Undo the mapping so that debugging is not a nightmare
        pStatementNode->SetCallReplacement(nullptr, nullptr);
    
        return pReplacement;
    }
    else
    {
        if (type != DuplicateType::ExpandGeneric)
        {
            throw "Wat";
        }

        return ASTNode::DuplicateNode(type);
    }
}
