#include "VariableInfo.h"
#include "PSLCompilerContext.h"

VariableInfo::VariableInfo(PSLCompilerContext* pContext, int symIndex, ASTNode* pNode, TypeInfo* pInfo)
{
    _pContext = pContext;
    _pType = pInfo;
    symIndex = symIndex;
    pDecl = pNode;
    pLastRef = pNode;
    _regIndex = 0xFF;
    fLastProcessed = false;
}

void VariableInfo::Allocate()
{
    _regIndex = _pContext->_regCollection.AllocateRegister();
}

RegIndex VariableInfo::GetRegIndex()
{
    if (_regIndex == 0xFF)
    {
        throw "Register not allocated for this variable";
    }

    return _regIndex;
}

void VariableInfo::NotifyNodeProcessed(ASTNode *pNode)
{
    if (pNode == pLastRef)
    {
        _pContext->_regCollection.DeallocateRegister(_regIndex);
        _regIndex = 0xFF;
        fLastProcessed = true;
    }
}
