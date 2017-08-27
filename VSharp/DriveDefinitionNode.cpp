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

void DriveDefinitionNode::PostProcessNodeImpl()
{
    // If there was a null child this indicates a finish
    if (GetChild(0) == nullptr)
    {
        // Part of an initial block, get the timing information
        GetContext()->OutputLine(
            "# %d $finish;", 
            GetDelta());
    }
}