#include "ReturnNode.h"
#include "FunctionDeclaratorNode.h"
#include "StatementNode.h"
#include "VSharp.tab.h"

ASTNode* ReturnNode::DuplicateNodeImpl(FunctionExpandType type)
{
    if (type == FunctionExpandType::Function)
    {
        throw "You should not be duplicating return statements";
    }

    return new ReturnNode(GetContext(), GetLocation());
}

ASTNode* ReturnNode::DuplicateNode(FunctionExpandType type)
{
    if (type == FunctionExpandType::Function)
    {
        // Find out what function declared this return statement
        FunctionDeclaratorNode *pFuncDecl = GetTypedParent<FunctionDeclaratorNode>();
    
        // Find out what statement triggered the expansion of that function
        StatementNode* pStatementNode = pFuncDecl->GetStatementNode();
    
        // We are going to duplicate that statement now, replacing the function call
        // part of the statement with the value that this return statement has. So
        // tell the statement what to use instead of the function call.
        pStatementNode->SetCallReplacement(pFuncDecl->GetCallNode(), GetChild(0));
    
        //printf("Duplicating return node %p, with function %s\n", this, pFuncDecl->GetFunctionName());
        
        // Now duplicate this original statement. It will replace function calls
        // with the child of the return statement.
        ASTNode* pReplacement = pStatementNode->DuplicateNode(FunctionExpandType::Function);
    
        // Undo the mapping so that debugging is not a nightmare for the next thing
        // that needs to do this to the statement.
        pStatementNode->SetCallReplacement(nullptr, nullptr);
    
        return pReplacement;
    }
    else
    {
        if (type != FunctionExpandType::Generic)
        {
            throw "Wat";
        }

        return ASTNode::DuplicateNode(type);
    }
}
