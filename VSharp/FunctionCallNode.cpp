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
    if (GetParameterCount() != GetDeclarator()->GetParameterCount())
    {
        GetContext()->ReportError(GetLocation(), "Wrong number of arguments to function");
    }

    TypeNode* pTypeNode = GetDeclarator()->GetReturnType();
    SetType(pTypeNode->GetTypeInfo());
}

FunctionDeclaratorNode* FunctionCallNode::GetDeclarator()
{
    ModuleDeclaratorNode *pModule = GetTypedParent<ModuleDeclaratorNode>();
    FunctionInfo* pInfo = dynamic_cast<FunctionInfo*>(GetContext()->_symbolTable.GetInfo(_symIndex, pModule));
    return pInfo->GetFunctionDeclarator();
}

ExpressionResult *FunctionCallNode::CalculateResult()
{
    GetDeclarator()->SetCall(this);
    GetDeclarator()->ProcessNode();
    GetDeclarator()->SetCall(nullptr);

    if (GetDeclarator()->GetReturnType()->GetTypeInfo()->GetTypeClass() != TypeClass::Void)
    {
        printf("Function call getting a result\n");

        // If the function is not void then it returns something
        return GetDeclarator()->GetResult();        
    }
    else
    {
        printf("Function call not getting a result\n");
        
        return nullptr;
    }
}

ModuleInfo *FunctionCallNode::GetModuleInfo()
{
    return dynamic_cast<ModuleInfo *>(GetContext()->_symbolTable.GetInfo(_symIndex, nullptr));
}
