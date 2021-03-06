#include "ExpressionNode.h"
#include "ParserContext.h"
#include "FunctionCallNode.h"

ExpressionNode::ExpressionNode(ParserContext* pContext, const YYLTYPE &location) : ASTNode(pContext, location)
{
    _pType = nullptr;
    _pResult = nullptr;
    _fResultCalculated = false;
    _fResultTaken = false;
}

TypeInfo *ExpressionNode::GetTypeInfo()
{
    if (_pType == nullptr)
    {
        //GetContext()->ReportError(_location, "Internal compiler error: Unset type on expression");
        //throw "Unset type on expression";
    }

    return _pType;
}

void ExpressionNode::SetType(TypeInfo *pInfo)
{
    if (pInfo == nullptr)
    {
        throw "Should not set type to null";
    }

    _pType = pInfo;
}

void ExpressionNode::PostProcessNodeImpl(OutputContext* pContext)
{
    // Maybe we can make a constant out of this
    UIntConstant Eval;
    if (ConstEvaluate(&Eval))
    {
        _pResult = new ExpressionResult(Eval);
    }
    else
    {
        _pResult = CalculateResult();
    }

    // Calculate our result using the result of the children
    _fResultCalculated = true;
}

bool ExpressionNode::EqualType(ASTNode *pA, ASTNode *pB)
{
    ExpressionNode *pLeft = dynamic_cast<ExpressionNode *>(pA);
    ExpressionNode *pRight = dynamic_cast<ExpressionNode *>(pB);

    TypeInfo *pLeftType = pLeft->GetTypeInfo();
    TypeInfo *pRightType = pRight->GetTypeInfo();

    return pLeftType->EqualType(pRightType);
}

void ExpressionNode::DumpNodeImpl()
{
    printf(
        "%s node %p :\t%s :\t%s\n", 
        GetDebugName(),
        this,
        _fResultCalculated ? "Calculated" : "Uncalculated",
        _fResultTaken ? "ResultTaken" : "ResultNotTaken"
    );    
}

ExpressionResult* ExpressionNode::TakeResult() 
{
    if (!_fResultTaken)
    {
        if (_fResultCalculated)
        {
            ExpressionResult* pRet = _pResult; 
            _pResult = nullptr;
            _fResultTaken = true;
            return pRet; 
        }
        else
        {
            throw "Trying to take result when not done";
        }
    }
    else
    {
        throw "Result already taken";
    }
}

bool ExpressionNode::ConstEvaluate(UIntConstant* pVal)
{
    return false;
}