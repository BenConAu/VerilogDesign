#include "DriveListDefinitionNode.h"
#include "IdentifierNode.h"
#include "VariableInfo.h"
#include "VSharpCompilerContext.h"
#include "ModuleDefinitionNode.h"
#include "../PhaethonObjWriter/ObjWriter.h"

DriveListDefinitionNode::DriveListDefinitionNode(
    PSLCompilerContext *pContext,
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
