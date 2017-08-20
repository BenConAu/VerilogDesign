#include "DriveListDefinitionNode.h"
#include "IdentifierNode.h"
#include "VariableInfo.h"
#include "VSharpCompilerContext.h"
#include "ModuleDeclaratorNode.h"
#include "../PhaethonObjWriter/ObjWriter.h"

DriveListDefinitionNode::DriveListDefinitionNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pList) : ASTNode(pContext)
{
    _location = location;

    AddNode(pList);
}

void DriveListDefinitionNode::VerifyNodeImpl()
{
}

void DriveListDefinitionNode::PreProcessNodeImpl()
{
    GetContext()->OutputLine("initial");
    GetContext()->OutputLine("begin");
    GetContext()->IncreaseIndent();
    
}

void DriveListDefinitionNode::PostProcessNodeImpl()
{
    GetContext()->DecreaseIndent();
    GetContext()->OutputLine("end");
}
