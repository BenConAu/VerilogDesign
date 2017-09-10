#include "FunctionCallNode.h"
#include "VariableInfo.h"
#include "ModuleInfo.h"
#include "ModuleDefinitionNode.h"
#include "VSharpCompilerContext.h"
#include "TypeNode.h"
#include "FunctionInfo.h"
#include "FunctionDeclaratorNode.h"
#include "StatementNode.h"
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
    _functionType = FunctionType::Defined; // Until we learn otherwise
}

FunctionCallNode::FunctionCallNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    int symIndex,
    FunctionType type) : ExpressionNode(pContext, location)
{
    _symIndex = symIndex;
    _functionType = type;
}

void FunctionCallNode::DumpNodeImpl()
{
    printf(
        "%s node %p :\t%s\n", 
        GetDebugName(),
        this,
        GetFunctionName()
    );    
}

ASTNode* FunctionCallNode::DuplicateNode()
{
    // Find the statement that initiated the duplication - it might
    // not be the first one up the tree.
    //printf("Starting function call node duplication of %s %p\n", GetFunctionName(), this);
    //GetContext()->DumpTree();
    StatementNode* pStatementNode = GetTypedParent<StatementNode>(); 
    while (pStatementNode != nullptr && pStatementNode->GetCallNode() == nullptr)
    {
        pStatementNode = pStatementNode->GetTypedParent<StatementNode>();
    }

    if (pStatementNode != nullptr && this == pStatementNode->GetCallNode())
    {
        //printf(
            //"Duplicating function call %s by replacing with node %s\n", 
            //GetFunctionName(), 
            //pStatementNode->GetReplacementNode()->GetDebugName());

        // Replace the call with the expression we were given from the return statement
        return pStatementNode->GetReplacementNode()->DuplicateNode();
    }
    else
    {
        //printf("Duplicating function call %s, but not the one being expanded\n", GetFunctionName());

        return ASTNode::DuplicateNode();
    }    
}

ASTNode* FunctionCallNode::DuplicateNodeImpl()
{
    return new FunctionCallNode(GetContext(), GetLocation(), _symIndex, _functionType);
}

const char* FunctionCallNode::GetFunctionName()
{
    return GetContext()->_symbols[_symIndex].c_str();
}

void FunctionCallNode::VerifyNodeImpl()
{
    if (GetFunctionInfo() == nullptr)
    {
        // If there is no function info, then it could be a constructor of a struct
        StructTypeInfo* pStructInfo = GetContext()->_typeCollection.GetStructType(_symIndex);
        if (pStructInfo == nullptr)
        {
            char message[256];
            sprintf(
                message, 
                "Unknown function or struct type %s", 
                GetFunctionName());
            GetContext()->ReportError(GetLocation(), message);
        }

        _functionType = FunctionType::Constructor;

        if (GetParameterCount() != pStructInfo->GetMemberCount())
        {
            char message[256];
            sprintf(
                message, 
                "Expected %lu arguments but got %lu arguments to constructor for %s",
                pStructInfo->GetMemberCount(),
                GetParameterCount(),
                GetFunctionName());

            GetContext()->ReportError(GetLocation(), message);    
        }

        for (size_t i = 0; i < GetParameterCount(); i++)
        {
            FunctionCallParamNode* pCallParam = GetParameter(i);
            StructMember* pMember = pStructInfo->GetMemberByIndex(i);

            ExpressionNode* pParamExpr = pCallParam->GetParamExpr();
            if (!pParamExpr->GetTypeInfo()->EqualType(pMember->GetTypeInfo()))
            {
                char message[256];
                sprintf(
                    message, 
                    "Expected type %s for argument %lu but got type %s",
                    pMember->GetTypeInfo()->GetTypeName().c_str(),
                    i,
                    pParamExpr->GetTypeInfo()->GetTypeName().c_str());
    
                GetContext()->ReportError(GetLocation(), message);    
    

                GetContext()->ReportError(GetLocation(), "Mismatch in param type");
            }
        }

        SetType(pStructInfo);
    }
    else
    {
        if (GetFunctionInfo()->GetParameterCount() == -1)
        {
            // Builtin functions have no parameters to key off right now
            _functionType = FunctionType::BuiltIn;
        }
        else
        {
            _functionType = FunctionType::Defined;

            if (GetParameterCount() != GetFunctionInfo()->GetParameterCount())
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
    
            for (size_t i = 0; i < GetParameterCount(); i++)
            {
                FunctionDeclaratorNode* pFuncDecl = GetFunctionInfo()->GetFunctionDeclarator();
                FunctionCallParamNode* pCallParam = GetParameter(i);
                FunctionParameterNode* pDefParam = pFuncDecl->GetParameter(i);
    
                // Out params need to be passed correctly
                if (pCallParam->IsOutParam() != pDefParam->IsOutParam())
                {
                    GetContext()->ReportError(GetLocation(), "Mismatch in param in / out definition");
                }
    
                ExpressionNode* pParamExpr = pCallParam->GetParamExpr();
                if (!pParamExpr->GetTypeInfo()->EqualType(pDefParam->GetTypeNode()->GetTypeInfo()))
                {
                    GetContext()->ReportError(GetLocation(), "Mismatch in param type");
                }
            }
        }

        SetType(GetFunctionInfo()->GetReturnType());
    }
}

FunctionInfo* FunctionCallNode::GetFunctionInfo()
{
    ModuleDefinitionNode *pModule = GetTypedParent<ModuleDefinitionNode>();
    return dynamic_cast<FunctionInfo*>(GetContext()->_symbolTable.GetInfo(_symIndex, pModule));
}

ASTNode* FunctionCallNode::ExpandFunction(StatementNode* pOwningStatement)
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

    //printf("Expanding function %s\n", GetContext()->_symbols[_symIndex].c_str());
    return pFuncDecl->ExpandFunction(this, pOwningStatement);
}

ExpressionResult *FunctionCallNode::CalculateResult()
{
    switch(_functionType)
    {
        case FunctionType::BuiltIn:
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

        case FunctionType::Constructor:
        {
            StructTypeInfo* pStructInfo = GetContext()->_typeCollection.GetStructType(_symIndex);            
            std::string resultString = "{ ";
            
            for (size_t i = 0; i < GetParameterCount(); i++)
            {
                ExpressionNode* pParam = GetParameter(i);
                std::unique_ptr<ExpressionResult> paramResult(pParam->TakeResult());
                
                if (i != 0)
                {
                    resultString.append(", ");
                }
        
                resultString.append(paramResult->GetString());
                _parameterResults.push_back(paramResult->GetString());
            }
        
            resultString.append(" }");               

            // Make a magical expression result that can come back here and extract stuff if need be
            return new ExpressionResult(resultString, this);
        }

        case FunctionType::Defined:
            printf("Unexpected function call %p named %s\n", this, GetFunctionName());
            //GetContext()->DumpTree();
            return nullptr;
    }
}

ExpressionResult* FunctionCallNode::CreateMemberResult(int fieldSymIndex)
{
    StructTypeInfo* pStructInfo = GetContext()->_typeCollection.GetStructType(_symIndex);            
    
    size_t memberIndex;
    if (!pStructInfo->GetMemberIndex(fieldSymIndex, &memberIndex))
    {
        throw "That is not a member";
    }
    
    return new ExpressionResult(_parameterResults[memberIndex]);
}