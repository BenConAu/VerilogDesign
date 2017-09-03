#include "FunctionCallNode.h"
#include "VariableInfo.h"
#include "ModuleInfo.h"
#include "ModuleDeclaratorNode.h"
#include "VSharpCompilerContext.h"
#include "TypeNode.h"
#include "FunctionInfo.h"
#include "FunctionDeclaratorNode.h"
#include "AssignmentNode.h"
#include "VSharp.tab.h"

FunctionCallNode::FunctionCallNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    int symIndex,
    ASTNode *pGenericType,
    ASTNode *pFirstArg) : ExpressionNode(pContext, location)
{
    AddNode(pGenericType);

    if (pFirstArg != nullptr)
    {
        AddNode(pFirstArg);
    }

    _symIndex = symIndex;
}

FunctionCallNode::FunctionCallNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    int symIndex) : ExpressionNode(pContext, location)
{
    _symIndex = symIndex;
}

ASTNode* FunctionCallNode::DuplicateNode()
{
    // Find the assignment node that initiated the duplication - it might
    // not be the first one up the tree.
    AssignmentNode* pAssignmentNode = GetTypedParent<AssignmentNode>(); 
    while (pAssignmentNode->GetCallNode() == nullptr)
    {
        pAssignmentNode = GetTypedParent<AssignmentNode>();
    }

    printf("Comparing %p and %p for function calls\n", this, pAssignmentNode->GetCallNode());

    if (this == pAssignmentNode->GetCallNode())
    {
        printf(
            "Duplicating function call %s by replacing with node %s\n", 
            GetFunctionName(), 
            pAssignmentNode->GetReplacementNode()->GetDebugName());

        // Replace the call with the expression we were given from the return statement
        return pAssignmentNode->GetReplacementNode()->DuplicateNode();
    }
    else
    {
        printf("Duplicating function call %s, but not the one being expanded\n", GetFunctionName());

        return ASTNode::DuplicateNode();
    }    
}

ASTNode* FunctionCallNode::DuplicateNodeImpl()
{
    return new FunctionCallNode(GetContext(), GetLocation(), _symIndex);
}

const char* FunctionCallNode::GetFunctionName()
{
    return GetContext()->_symbols[_symIndex].c_str();
}

void FunctionCallNode::VerifyNodeImpl()
{
    if (GetFunctionInfo() == nullptr)
    {
        GetContext()->ReportError(GetLocation(), "Unknown function");
    }

    if (GetFunctionInfo()->GetParameterCount() != -1 && GetParameterCount() != GetFunctionInfo()->GetParameterCount())
    {
        char message[256];
        sprintf(
            message, 
            "Expected %lu arguments but got %lu arguments to function %s",
            GetFunctionInfo()->GetParameterCount(),
            GetParameterCount(),
            GetFunctionName());

        GetContext()->ReportError(GetLocation(), message);    
    }

    SetType(GetFunctionInfo()->GetReturnType());
}

FunctionInfo* FunctionCallNode::GetFunctionInfo()
{
    ModuleDeclaratorNode *pModule = GetTypedParent<ModuleDeclaratorNode>();
    return dynamic_cast<FunctionInfo*>(GetContext()->_symbolTable.GetInfo(_symIndex, pModule));
}

ASTNode* FunctionCallNode::ExpandFunction(AssignmentNode* pOwningExpression)
{
    // We have been given the expression that this function call is inside of,
    // and we will now construct a statement list that represents the work
    // of this function, but where return statements are replaced with copies
    // of the expression provided, subsituting the function call for the expression
    // in the return statement.
    FunctionDeclaratorNode* pFuncDecl = GetFunctionInfo()->GetFunctionDeclarator();
    if (pFuncDecl == nullptr)
    {
        GetContext()->ReportError(GetLocation(), "Internal compiler error - function calls that return values cannot be builtin functions");
    }

    printf("Expanding function %s\n", GetContext()->_symbols[_symIndex].c_str());
    return pFuncDecl->ExpandFunction(this, pOwningExpression);
}

ExpressionResult *FunctionCallNode::CalculateResult()
{
    FunctionDeclaratorNode* pFuncDecl = GetFunctionInfo()->GetFunctionDeclarator();
    if (pFuncDecl != nullptr)
    {
        printf("Old implementation of function call removed\n");
        return nullptr;
    }
    else
    {
        GetContext()->BeginLine();
        GetContext()->OutputString(GetFunctionInfo()->GetVerilogName().c_str());
        GetContext()->OutputString("(");

        for (size_t i = 0; i < GetParameterCount(); i++)
        {
            ExpressionNode* pParam = GetParameter(i);
            std::unique_ptr<ExpressionResult> paramResult(pParam->TakeResult());
            
            GetContext()->OutputString(paramResult->GetString().c_str());
            if (i != GetParameterCount() - 1)
            {
                GetContext()->OutputString(", ");
            }
        }

        GetContext()->OutputString(");");
        GetContext()->EndLine();
        return nullptr;
    }
}
