#include "ASTNode.h"
#include "PSLCompilerContext.h"

void ASTNode::VerifyNode()
{
//    _pContext->PrintIndent();
//    printf("Begin verifying %s node %p\n", GetDebugName(), this);
    _pContext->_indent++;

    for (size_t i = 0; i < _children.size(); i++)
    {
        if (_children[i] != nullptr)
        {
            _children[i]->VerifyNode();
        }
    }

    VerifyNodeImpl();

    _pContext->_indent--;
//    _pContext->PrintIndent();
//    printf("End verifying %s node %p\n", GetDebugName(), this);
}
