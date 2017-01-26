#include "ReadPortNode.h"
#include "PSLCompilerContext.h"
#include "RegisterWrapper.h"
#include "FunctionDeclaratorNode.h"
#include "../PhaethonObjWriter/ObjWriter.h"

ReadPortNode::ReadPortNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pPort) : ExpressionNode(pContext)
{
    _location = location;

    AddNode(pPort);
}

void ReadPortNode::VerifyNodeImpl()
{
    ExpressionNode *pPort = dynamic_cast<ExpressionNode *>(GetChild(0));
    BasicTypeInfo *pPortType = dynamic_cast<BasicTypeInfo *>(pPort->GetTypeInfo());

    if (pPortType == nullptr ||
        pPortType->GetTypeToken() != WORD_TOKEN)
    {
        GetContext()->ReportError(_location, "readport requires word for input");
    }

    SetType(pPortType);    
}

ExpressionResult* ReadPortNode::CalculateResult()
{
    FunctionDeclaratorNode *pFunc = GetTypedParent<FunctionDeclaratorNode>();
    ExpressionNode *pPort = dynamic_cast<ExpressionNode *>(GetChild(0));
    BasicTypeInfo *pPortType = dynamic_cast<BasicTypeInfo *>(pPort->GetTypeInfo());

    std::unique_ptr<ExpressionResult> portResult(pPort->TakeResult());

    RegisterWrapper portWrap(GetContext(), pFunc->GetRegCollection(), portResult.get());

    // Get register for our result
    RegIndex resultIndex = pFunc->GetRegCollection()->AllocateRegister();
    Operand resultOperand(resultIndex);

    GetContext()->OutputInstruction(
        OpCodes::ReadPortRR,
        resultOperand,
        portWrap.GetWrapped());

    return new ExpressionResult(resultOperand, pFunc->GetRegCollection());
}
