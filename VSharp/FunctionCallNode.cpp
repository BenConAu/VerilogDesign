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
    ASTNode *pFirstArg) : ExpressionNode(pContext)
{
    AddNode(pGenericType);

    if (pFirstArg != nullptr)
    {
        AddNode(pFirstArg);
    }

    _symIndex = symIndex;
    _location = location;
}

void FunctionCallNode::VerifyNodeImpl()
{
}

ExpressionResult *FunctionCallNode::CalculateResult()
{
    // Find the info for the function
    ModuleDeclaratorNode *pModule = GetTypedParent<ModuleDeclaratorNode>();
    FunctionInfo* pInfo = dynamic_cast<FunctionInfo*>(GetContext()->_symbolTable.GetInfo(_symIndex, pModule));
    FunctionDeclaratorNode* pFuncDecl = pInfo->GetFunctionDeclarator();

    GetContext()->PushCall(this);
    pFuncDecl->ProcessNode();
    GetContext()->PopCall();

    return nullptr;
}

ModuleInfo *FunctionCallNode::GetModuleInfo()
{
    return dynamic_cast<ModuleInfo *>(GetContext()->_symbolTable.GetInfo(_symIndex, nullptr));
}
