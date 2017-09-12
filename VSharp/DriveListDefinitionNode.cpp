#include "DriveListDefinitionNode.h"
#include "IdentifierNode.h"
#include "VariableInfo.h"
#include "ParserContext.h"
#include "ModuleDefinitionNode.h"
#include "OutputContext.h"

DriveListDefinitionNode::DriveListDefinitionNode(
    ParserContext *pContext,
    const YYLTYPE &location,
    ASTNode *pList) : ASTNode(pContext, location)
{
    AddNode(pList);
}

void DriveListDefinitionNode::VerifyNodeImpl()
{
}

bool DriveListDefinitionNode::PreProcessNodeImpl(OutputContext* pContext)
{
    pContext->OutputLine("initial");
    pContext->OutputLine("begin");
    pContext->IncreaseIndent();

    return true;
}

void DriveListDefinitionNode::PostProcessNodeImpl(OutputContext* pContext)
{
    pContext->DecreaseIndent();
    pContext->OutputLine("end");
}
