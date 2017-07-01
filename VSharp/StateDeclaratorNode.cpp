#include "StateDeclaratorNode.h"
#include "PSLCompilerContext.h"
#include "ModuleDeclaratorNode.h"
#include "../PhaethonObjWriter/ObjWriter.h"

StateDeclaratorNode::StateDeclaratorNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    int ident,
    ASTNode *pStatementList) : ASTNode(pContext)
{
    _location = location;
    _identifier = ident;

    AddNode(pStatementList);
}

void StateDeclaratorNode::VerifyNodeImpl()
{
    ExpressionNode *pPort = dynamic_cast<ExpressionNode *>(GetChild(0));
    ExpressionNode *pData = dynamic_cast<ExpressionNode *>(GetChild(1));

    BasicTypeInfo *pPortType = dynamic_cast<BasicTypeInfo *>(pPort->GetTypeInfo());
    BasicTypeInfo *pDataType = dynamic_cast<BasicTypeInfo *>(pData->GetTypeInfo());

    if (pPortType == nullptr ||
        pPortType->GetTypeToken() != WORD_TOKEN)
    {
        GetContext()->ReportError(_location, "writeport requires word for input");
    }

    if (pDataType == nullptr ||
        pDataType->GetTypeToken() != WORD_TOKEN)
    {
        GetContext()->ReportError(_location, "writeport requires word for data");
    }
}

void StateDeclaratorNode::PostProcessNodeImpl()
{
/*    FunctionDeclaratorNode *pFunc = GetTypedParent<FunctionDeclaratorNode>();

    ExpressionNode *pPort = dynamic_cast<ExpressionNode *>(GetChild(0));
    ExpressionNode *pData = dynamic_cast<ExpressionNode *>(GetChild(1));

    BasicTypeInfo *pPortType = dynamic_cast<BasicTypeInfo *>(pPort->GetTypeInfo());
    BasicTypeInfo *pDataType = dynamic_cast<BasicTypeInfo *>(pData->GetTypeInfo());

    std::unique_ptr<ExpressionResult> portResult(pPort->TakeResult());
    std::unique_ptr<ExpressionResult> dataResult(pData->TakeResult());

    RegisterWrapper portWrap(GetContext(), pFunc->GetRegCollection(), portResult.get());
    RegisterWrapper dataWrap(GetContext(), pFunc->GetRegCollection(), dataResult.get());

    GetContext()->OutputInstruction(
        OpCode::WritePortRR,
        portWrap.GetWrapped(),
        dataWrap.GetWrapped());*/
}
