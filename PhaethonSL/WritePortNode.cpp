#include "WritePortNode.h"
#include "PSLCompilerContext.h"
#include "RegisterWrapper.h"
#include "FunctionDeclaratorNode.h"
#include "../PhaethonObjWriter/ObjWriter.h"

WritePortNode::WritePortNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pPort,
    ASTNode *pData) : ASTNode(pContext)
{
    _location = location;

    AddNode(pPort);
    AddNode(pData);
}

void WritePortNode::VerifyNodeImpl()
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

void WritePortNode::PostProcessNodeImpl()
{
    FunctionDeclaratorNode *pFunc = GetTypedParent<FunctionDeclaratorNode>();

    ExpressionNode *pPort = dynamic_cast<ExpressionNode *>(GetChild(0));
    ExpressionNode *pData = dynamic_cast<ExpressionNode *>(GetChild(1));

    BasicTypeInfo *pPortType = dynamic_cast<BasicTypeInfo *>(pPort->GetTypeInfo());
    BasicTypeInfo *pDataType = dynamic_cast<BasicTypeInfo *>(pData->GetTypeInfo());

    std::unique_ptr<ExpressionResult> portResult(pPort->TakeResult());
    std::unique_ptr<ExpressionResult> dataResult(pData->TakeResult());

    RegisterWrapper portWrap(GetContext(), pFunc->GetRegCollection(), portResult.get());
    RegisterWrapper dataWrap(GetContext(), pFunc->GetRegCollection(), dataResult.get());

    GetContext()->OutputInstruction(
        OpCodes::WritePortRR,
        portWrap.GetWrapped(),
        dataWrap.GetWrapped());
}
