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

RegIndex VariableInfo::GetRegIndex()
{
    if (_regIndex == 0xFF)
    {
        _regIndex = _pContext->_regCollection.AllocateRegister();
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
