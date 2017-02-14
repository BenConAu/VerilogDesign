#include "SaveRegistersNode.h"
#include "PSLCompilerContext.h"
#include "RegisterWrapper.h"
#include "FunctionDeclaratorNode.h"
#include "ExpressionNode.h"
#include "StatementListNode.h"
#include "../PhaethonObjWriter/ObjWriter.h"

SaveRegistersNode::SaveRegistersNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pCompound) : ASTNode(pContext)
{
    _location = location;

    AddNode(pCompound);
}

void SaveRegistersNode::VerifyNodeImpl()
{
}

void SaveRegistersNode::ProcessNode()
{
    // We are taking over the whole processing, so we have to be careful and
    // replicate everything that the base class does. We just need a specific
    // order.
    StatementListNode *pCompound = dynamic_cast<StatementListNode *>(GetChild(0));

    FunctionDeclaratorNode *pScope = GetTypedParent<FunctionDeclaratorNode>();

    // Save all of the used registers
    for (size_t i = 0; i < pScope->GetRegCollection()->GetUsedCount(); i++)
    {
        Operand regOp(pScope->GetRegCollection()->GetUsedReg(i));

        GetContext()->OutputInstruction(
            OpCodes::PushR,
            regOp);
    }

    // Now the statement list
    pCompound->ProcessNode();

    for (int i = pScope->GetRegCollection()->GetUsedCount() - 1; i >=0 ; i--)
    {
        Operand regOp(pScope->GetRegCollection()->GetUsedReg(i));

        GetContext()->OutputInstruction(
            OpCodes::PopR,
            regOp);
    }
}
