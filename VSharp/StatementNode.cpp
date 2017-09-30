#include "FunctionCallNode.h"
#include "FunctionDeclaratorNode.h"
#include "FunctionInfo.h"
#include "IdentifierNode.h"
#include "ModuleDefinitionNode.h"
#include "ParserContext.h"
#include "StatementNode.h"
#include "VariableInfo.h"

StatementNode::StatementNode(ParserContext* pContext, const YYLTYPE &location) : ASTNode(pContext, location)
{
    _fProcessed = false;
    _pCallNode = nullptr;
    _pReplacement = nullptr;
    _pIdentifier = nullptr;
}

void StatementNode::DumpNodeImpl()
{
    printf(
        "%s node %p :\t%s\n", 
        GetDebugName(),
        this,
        _fProcessed ? "Processed" : "Unprocessed"
    );    
}

bool StatementNode::PreProcessNodeImpl(OutputContext* pContext)
{
    //printf("PreProcess for %p : %s\n", this, GetDebugName());
    
    //GetContext()->DumpTree();
    
    // We expand functions during pre-process so that we don't process until expansion is complete
    FunctionCallNode* pFunctionCallNode = GetFirstFunctionCall();
    if (pFunctionCallNode != nullptr)
    {
        // No declarator means that it is not a function that we defined, so we cannot expand it either
        // Note that this should not be neccessary based on the GetFirstFunctionCall implementation.
        FunctionDeclaratorNode* pDeclarator = pFunctionCallNode->GetFunctionInfo()->GetFunctionDeclarator();
        if (pDeclarator != nullptr)
        {
            //printf("Found function call %p inside statement %p\n", pFunctionCallNode, this);
            //printf("Function call %p is owned by statement %p\n", pFunctionCallNode, this);
            
            // Create the tree that will replace the expression
            ASTNode* pReplacement = pFunctionCallNode->ExpandFunction(this);
    
            //printf("Created replacement node for function call %p\n", pFunctionCallNode);
            //pReplacement->DumpNode();
    
            // Insert the node after this one
            GetParent()->InsertChild(GetParent()->GetChildIndex(this) + 1, pReplacement);
    
            //printf("Attached replacement node\n");
            //GetParent()->DumpNode();
            
            // Mark this node as replaced so that it won't do anything further
            return false;
        }        
    }

    // Outputs of stages are basically like function calls, so process them the same way
    IdentifierNode* pStageOutput = GetFirstStageOutput();
    if (pStageOutput != nullptr)
    {
        //printf("Found stage output %s to replace\n", pStageOutput->GetIdentifierName());
        //DumpNode(GetContext()->GetDebugContext());

        ModuleDefinitionNode* pModule = GetTypedParent<ModuleDefinitionNode>();

        VariableInfo* pVarInfo = pStageOutput->GetVariableInfo();
        FunctionDeclaratorNode* pScope = dynamic_cast<FunctionDeclaratorNode*>(pVarInfo->GetScope());

        // We need to find the stage that outputs the given identifier so that we can make
        // the appropriate replacement. Search backwards from the given one.
        size_t CurrentIndex = pModule->GetStageIndex(pScope);
        FunctionDeclaratorNode* pReplaceStage = nullptr;

        if (CurrentIndex != 0)
        {
            for (size_t i = CurrentIndex - 1; ; i--)
            {
                FunctionDeclaratorNode* pCandidate = pModule->GetStage(i);
                if (pCandidate->IsParameter(pVarInfo->GetSymbolIndex()))
                {
                    pReplaceStage = pCandidate;
                    break;
                }

                if (i == 0)
                {
                    break;
                }
            }
        }

        if (pReplaceStage == nullptr)
        {
            GetContext()->ReportError(GetLocation(), "Cannot find stage that generates %s", pVarInfo->GetSymbol());
        }

        // Expand the function to replace the identifier
        ASTNode* pReplacement = pReplaceStage->ExpandFunction(pStageOutput, this);

        // Insert the node after this one
        GetParent()->InsertChild(GetParent()->GetChildIndex(this) + 1, pReplacement);

        // Mark this node as replaced so that it won't do anything further
        return false;
    }

    _fProcessed = true;

    return true;
}

void StatementNode::SetCallReplacement(FunctionCallNode* pCallNode, ASTNode* pReplacement)
{
    if (pCallNode != nullptr && _pCallNode != nullptr)
    {
        printf("Callnode is %p and replacementnode is %p\n", _pCallNode, _pReplacement);
        throw "Statement node should only be expanding with a single replacement at a time";
    }

    _pCallNode = pCallNode;
    _pReplacement = pReplacement;
}

void StatementNode::SetIdentifierReplacement(IdentifierNode* pIdent, ASTNode* pReplacement)
{
    if (pIdent != nullptr && _pIdentifier != nullptr)
    {
        printf("Identifier is %p and replacementnode is %p\n", _pIdentifier, _pReplacement);
        throw "Statement node should only be expanding with a single replacement at a time";
    }

    _pIdentifier = pIdent;
    _pReplacement = pReplacement;
}

bool StatementNode::IsReplaceableFunctionCall(ASTNode* pNode)
{
    // Needs to be a function call
    FunctionCallNode* pFunctionCallNode = dynamic_cast<FunctionCallNode*>(pNode);
    if (pFunctionCallNode == nullptr)
    {
        return false;
    }

    // Needs to have function info with a declarator
    FunctionInfo* pFunctionInfo = pFunctionCallNode->GetFunctionInfo();
    if (pFunctionInfo == nullptr)
    {
        return false;
    }

    // Needs to have a declarator for us to expand it
    FunctionDeclaratorNode* pDeclarator = pFunctionInfo->GetFunctionDeclarator();
    if (pDeclarator == nullptr)
    {
        return false;
    }

    // Check that this statement is the actual owning statement
    StatementNode* pOwningStatement = pFunctionCallNode->GetTypedParent<StatementNode>();
    if (pOwningStatement == this)
    {
        return true;
    }

    return false;
}

bool StatementNode::IsReplaceableIdentifier(ASTNode* pNode)
{
    // Needs to be an identifier
    IdentifierNode* pIdentifier = dynamic_cast<IdentifierNode*>(pNode);
    if (pIdentifier == nullptr)
    {
        return false;
    }

    // Needs to have variable info and be an input
    VariableInfo* pVarInfo = pIdentifier->GetVariableInfo();
    if (pVarInfo == nullptr || pVarInfo->GetLocationType() != VariableLocationType::Input)
    {
        return false;
    }

    // Check that the owning scope is a stage declaration
    FunctionDeclaratorNode* pScope = dynamic_cast<FunctionDeclaratorNode*>(pVarInfo->GetScope());
    if (pScope == nullptr || pScope->GetFunctionType() != FunctionType::Stage)
    {
        return false;
    }

    // Check that this statement is the actual owning statement
    StatementNode* pOwningStatement = pIdentifier->GetTypedParent<StatementNode>();
    if (pOwningStatement == this)
    {
        return true;
    }

    return false;
}

FunctionCallNode* StatementNode::GetFunctionCall(ASTNode* pNode)
{
    if (pNode == nullptr)
    {
        return nullptr;
    }

    if (IsReplaceableFunctionCall(pNode))
    {
        return dynamic_cast<FunctionCallNode*>(pNode);
    }

    for (size_t i = 0; i < pNode->GetChildCount(); i++)
    {
        // Do we have a child that is a function call?
        FunctionCallNode* pCallNode = GetFunctionCall(pNode->GetChild(i));
        if (pCallNode != nullptr)
        {
            return pCallNode;
        }
    }

    //printf("GetFunctionCall failed on all children and this node is not a function call\n");
    return nullptr;
}

IdentifierNode* StatementNode::GetStageOutput(ASTNode* pNode)
{
    if (pNode == nullptr)
    {
        return nullptr;
    }

    if (IsReplaceableIdentifier(pNode))
    {
        return dynamic_cast<IdentifierNode*>(pNode);
    }

    for (size_t i = 0; i < pNode->GetChildCount(); i++)
    {
        // Do we have a child that is a stage output?
        IdentifierNode* pStageOutput = GetStageOutput(pNode->GetChild(i));
        if (pStageOutput != nullptr)
        {
            return pStageOutput;
        }
    }

    //printf("GetFunctionCall failed on all children and this node is not a function call\n");
    return nullptr;
}

FunctionCallNode* StatementNode::GetFirstFunctionCall()
{
    return GetFunctionCall(this);
}

IdentifierNode* StatementNode::GetFirstStageOutput()
{
    return GetStageOutput(this);
}