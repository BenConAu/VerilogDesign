#include "DriveDefinitionNode.h"
#include "IdentifierNode.h"
#include "VariableInfo.h"
#include "VSharpCompilerContext.h"
#include "ModuleDeclaratorNode.h"
#include "../PhaethonObjWriter/ObjWriter.h"

DriveDefinitionNode::DriveDefinitionNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    int delta,
    ASTNode *pExpr) : ASTNode(pContext)
{
    _location = location;
    _delta = delta;

    AddNode(pExpr);
}

void DriveDefinitionNode::VerifyNodeImpl()
{
}
