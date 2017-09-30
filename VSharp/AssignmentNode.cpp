#include "AssignmentNode.h"
#include "DriveDefinitionNode.h"
#include "FunctionDeclaratorNode.h"
#include "IdentifierNode.h"
#include "ModuleDefinitionNode.h"
#include "OutputContext.h"
#include "ParserContext.h"
#include "VariableInfo.h"

AssignmentNode::AssignmentNode(
    ParserContext *pContext, 
    const YYLTYPE &location, 
    ASTNode *pLeft, 
    ASTNode *pRight) : StatementNode(pContext, location)
{
    AddNode(pLeft);
    AddNode(pRight);
}

AssignmentNode::AssignmentNode(
    ParserContext *pContext, 
    const YYLTYPE &location) : StatementNode(pContext, location)
{
}

ASTNode* AssignmentNode::DuplicateNodeImpl(DuplicateType type)
{
    return new AssignmentNode(GetContext(), GetLocation());
}

void AssignmentNode::VerifyNodeImpl()
{
    ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));
    ExpressionNode *pRight = dynamic_cast<ExpressionNode *>(GetChild(1));

    if (!ExpressionNode::EqualType(GetChild(0), GetChild(1)))
    {
        printf("Type %s and type %s are not equal\n", pLeft->GetTypeInfo()->DebugPrint().c_str(), pRight->GetTypeInfo()->DebugPrint().c_str());

        GetContext()->ReportError(GetLocation(), "Assignment must have equal types on each side");
    }

    // No assigning to wires, please
    VariableInfo* pVarInfo = pLeft->IsVariableExpression();
    if (pVarInfo == nullptr || pVarInfo->GetModifier() == TypeModifier::Wire)
    {
        GetContext()->ReportError(GetLocation(), "Not a valid LValue for assignment");
    }

    // Must be not an input
    if (pVarInfo->GetLocationType() == VariableLocationType::Input)
    {
        GetContext()->ReportError(GetLocation(), "Inputs are not valid LValue for assignment");
    }
}

ASTNode* AssignmentNode::DuplicateNode(DuplicateType type)
{
    if (type == DuplicateType::ExpandStageInput)
    {
        // For stages, an assignment to an out parameter is equivalent to a return
        // statement and therefore handled in a similar way. So we see if the LHS
        // of the assignment is to that out parameter.
        ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));        

        // See if the LHS is the thing we are replacing - it will be an output of the
        // function that we are expanding.
        VariableInfo* pInfo = pLeft->IsVariableExpression();
        if (pInfo != nullptr && pInfo->GetLocationType() == VariableLocationType::Output)
        {
            // Find out what stage function has this assignment
            FunctionDeclaratorNode *pFuncDecl = GetTypedParent<FunctionDeclaratorNode>();
        
            // Is this the identifer we are expanding?
            if (pFuncDecl->GetStageInput() != nullptr)
            {
                if (pFuncDecl->GetStageInput()->GetSymbolIndex() == pInfo->GetSymbolIndex())
                {
                    // The LHS of this assignment is the out param that was being replaced, so this
                    // is equivalent to a return statement. So we duplicate the same set of steps
                    // here.

                    // Find out what statement triggered the expansion of that stage function
                    StatementNode* pStatementNode = pFuncDecl->GetStatementNode();
                
                    // Set the mapping that calls to the function are replaced with the RHS of this assignment
                    pStatementNode->SetIdentifierReplacement(pFuncDecl->GetStageInput(), GetChild(1));
                
                    // Duplicate the statement that launched this
                    ASTNode* pReplacement = pStatementNode->DuplicateNode(DuplicateType::ExpandStageInput);
                
                    // Undo the mapping so that debugging is not a nightmare
                    pStatementNode->SetIdentifierReplacement(nullptr, nullptr);
                
                    return pReplacement;    
                }
                else
                {
                    // Assignments to things that are not the input we are expanding need to be dropped
                    return nullptr;
                }
            }
        }

        return ASTNode::DuplicateNode(type);
    }
    else
    {
        return ASTNode::DuplicateNode(type);
    }
}

void AssignmentNode::PostProcessNodeImpl(OutputContext* pContext)
{
    ModuleDefinitionNode *pFunc = GetTypedParent<ModuleDefinitionNode>();
    DriveDefinitionNode *pDrive = GetTypedParent<DriveDefinitionNode>();

    ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(GetChild(0));
    ExpressionNode *pRight = dynamic_cast<ExpressionNode *>(GetChild(1));

    std::unique_ptr<ExpressionResult> leftResult(pLeft->TakeResult());
    std::unique_ptr<ExpressionResult> rightResult(pRight->TakeResult());

    //printf("Assignment between these two expressions\n");
    //printf("Left = %s\n", leftResult->DebugPrint().c_str());
    //printf("Right = %s\n", rightResult->DebugPrint().c_str());

    if (leftResult.get() == nullptr || rightResult.get() == nullptr)
    {
        printf("Assignment on node %p between two expressions\n", this);
        GetContext()->DumpTree();
        GetContext()->ReportError(GetLocation(), "Assignment needs a valid expression on each side");
    }

    if (pDrive == nullptr)
    {
        // Regular NBA somewhere
        pContext->OutputLine("%s <= %s;", leftResult->GetString().c_str(), rightResult->GetString().c_str());
    }
    else
    {
        // Part of an initial block, get the timing information
        pContext->OutputLine(
            "# %d %s = %s;", 
            pDrive->GetDelta(),
            leftResult->GetString().c_str(), 
            rightResult->GetString().c_str());
    }
}
