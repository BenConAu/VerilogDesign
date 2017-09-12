#include "DriveDefinitionNode.h"
#include "IdentifierNode.h"
#include "VariableInfo.h"
#include "VSharpCompilerContext.h"
#include "ModuleDefinitionNode.h"
#include "OutputContext.h"

DriveDefinitionNode::DriveDefinitionNode(
    ParserContext *pContext,
    const YYLTYPE &location,
    const UIntConstant &delta,
    ASTNode *pExpr) : ASTNode(pContext, location)
{
    _delta = delta._value;

    AddNode(pExpr);
}

void DriveDefinitionNode::VerifyNodeImpl()
{
}

void DriveDefinitionNode::PostProcessNodeImpl(OutputContext* pContext)
{
    // If there was a null child this indicates a finish
    if (GetChild(0) == nullptr)
    {
        // Part of an initial block, get the timing information
        pContext->OutputLine(
            "# %u $finish;", 
            GetDelta());
    }
}