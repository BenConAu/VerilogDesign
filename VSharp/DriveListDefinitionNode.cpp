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

bool DriveListDefinitionNode::PreProcessNodeImpl()
{
    GetContext()->OutputLine("initial");
    GetContext()->OutputLine("begin");
    GetContext()->IncreaseIndent();

    return true;
}

void DriveListDefinitionNode::PostProcessNodeImpl()
{
    GetContext()->DecreaseIndent();
    GetContext()->OutputLine("end");
}
