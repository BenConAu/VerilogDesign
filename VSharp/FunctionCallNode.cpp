#include "FunctionCallNode.h"
#include "VariableInfo.h"
#include "ModuleInfo.h"
#include "ModuleDeclaratorNode.h"
#include "VSharpCompilerContext.h"
#include "TypeNode.h"
#include "FunctionInfo.h"
#include "FunctionDeclaratorNode.h"
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

void FunctionCallNode::VerifyNodeImpl()
{
    if (GetFunctionInfo() == nullptr)
    {
        GetContext()->ReportError(GetLocation(), "Unknown function");
    }

    if (GetFunctionInfo()->GetParameterCount() != -1 && GetParameterCount() != GetFunctionInfo()->GetParameterCount())
    {
        GetContext()->ReportError(GetLocation(), "Wrong number of arguments to function");
    }

    SetType(GetFunctionInfo()->GetReturnType());
}

FunctionInfo* FunctionCallNode::GetFunctionInfo()
{
    ModuleDeclaratorNode *pModule = GetTypedParent<ModuleDeclaratorNode>();
    return dynamic_cast<FunctionInfo*>(GetContext()->_symbolTable.GetInfo(_symIndex, pModule));
}

ExpressionResult *FunctionCallNode::CalculateResult()
{
    FunctionDeclaratorNode* pFuncDecl = GetFunctionInfo()->GetFunctionDeclarator();
    if (pFuncDecl != nullptr)
    {
        pFuncDecl->SetCall(this);
        pFuncDecl->ProcessNode();
        pFuncDecl->SetCall(nullptr);
    
        if (GetFunctionInfo()->GetReturnType()->GetTypeClass() != TypeClass::Void)
        {
            //printf("Function call getting a result\n");
    
            // If the function is not void then it returns something
            return pFuncDecl->GetResult();        
        }
        else
        {
            //printf("Function call not getting a result\n");
            
            return nullptr;
        }
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
