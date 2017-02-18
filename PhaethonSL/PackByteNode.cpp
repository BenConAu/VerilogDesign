#include "PackByteNode.h"
#include "IdentifierNode.h"
#include "VariableInfo.h"
#include "PSLCompilerContext.h"
#include "RegisterWrapper.h"
#include "FunctionDeclaratorNode.h"
#include "../PhaethonObjWriter/ObjWriter.h"

PackByteNode::PackByteNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pDest,
    ASTNode *pSrc,
    ASTNode *pIndex) : ASTNode(pContext)
{
    _location = location;

    AddNode(pDest);
    AddNode(pSrc);
    AddNode(pIndex);
}

void PackByteNode::VerifyNodeImpl()
{
}

void PackByteNode::PostProcessNodeImpl()
{
    FunctionDeclaratorNode *pFunc = GetTypedParent<FunctionDeclaratorNode>();

    ExpressionNode *pDest = dynamic_cast<ExpressionNode *>(GetChild(0));
    ExpressionNode *pSrc = dynamic_cast<ExpressionNode *>(GetChild(1));
    ExpressionNode *pIndex = dynamic_cast<ExpressionNode *>(GetChild(2));

    std::unique_ptr<ExpressionResult> destResult(pDest->TakeResult());
    std::unique_ptr<ExpressionResult> srcResult(pSrc->TakeResult());
    std::unique_ptr<ExpressionResult> indexResult(pIndex->TakeResult());

    RegisterWrapper srcWrap(GetContext(), pFunc->GetRegCollection(), srcResult.get());
    RegisterWrapper indexWrap(GetContext(), pFunc->GetRegCollection(), indexResult.get());

    IdentifierNode *pDestIdentifier = dynamic_cast<IdentifierNode *>(pDest);
    if (pDestIdentifier != nullptr)
    {
        VariableInfo *pVarInfo = pDestIdentifier->GetVariableInfo();
        RegIndex destIndex = pVarInfo->EnsureRegister(pFunc);

        GetContext()->OutputInstruction(
            OpCode::PackRRR,
            Operand(destIndex),
            srcWrap.GetWrapped(),
            indexWrap.GetWrapped());
    }
    else
    {
        throw "Not supported yet";
    }
}
