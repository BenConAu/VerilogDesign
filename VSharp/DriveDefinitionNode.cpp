#include "DriveDefinitionNode.h"
#include "IdentifierNode.h"
#include "VariableInfo.h"
#include "VSharpCompilerContext.h"
#include "ModuleDefinitionNode.h"
#include "../PhaethonObjWriter/ObjWriter.h"

DriveDefinitionNode::DriveDefinitionNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    const UIntConstant &delta,
    ASTNode *pExpr) : ASTNode(pContext)
{
    _location = location;
    _delta = delta._value;

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
            "# %u $finish;", 
            GetDelta());
    }
}