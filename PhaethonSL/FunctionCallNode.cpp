#include "FunctionCallNode.h"
#include "VariableInfo.h"
#include "FunctionInfo.h"
#include "FunctionDeclaratorNode.h"

FunctionCallNode::FunctionCallNode(
    PSLCompilerContext *pContext,
    int symIndex,
    ASTNode *pFirstArg) : ExpressionNode(pContext)
{
    if (pFirstArg != nullptr)
    {
        AddNode(pFirstArg);
    }

    _symIndex = symIndex;
}

void FunctionCallNode::VerifyNodeImpl()
{
    // Function needs to be defined
    FunctionInfo *pInfo = GetFunctionInfo();

    SetType(pInfo->GetReturnTypeInfo());
}

ExpressionResult *FunctionCallNode::CalculateResult()
{
    //printf("CalculateResult for FunctionCall\n");
    FunctionDeclaratorNode *pScope = GetTypedParent<FunctionDeclaratorNode>();

    // We need a register to load our function address
    RegIndex callIndex = pScope->GetRegCollection()->AllocateRegister();
    Operand addrOperand(callIndex);
    Operand labelOperand(GetContext()->_symbols[_symIndex]);

    GetContext()->OutputMovInstruction(
        addrOperand,
        labelOperand);

    // Figure out how many registers are in use in our scope
    RegIndex firstAvail = pScope->GetRegCollection()->FirstUnused();
    RegIndex firstArg = firstAvail + 2;

    // Find the results of the children
    std::vector<std::unique_ptr<ExpressionResult>> paramResults;

    // We need to move all of the arguments into the registers
    for (size_t i = 0; i < GetChildCount(); i++)
    {
        ExpressionNode *pExprChild = dynamic_cast<ExpressionNode *>(GetChild(i));
        paramResults.emplace_back(pExprChild->TakeResult());

        // No matter where it is, we need to move into the correct register
        RegIndex argIndex = firstArg + i;
        pScope->GetRegCollection()->ReserveRegister(argIndex);

        // Put out the instruction for this
        // Push the wrapped register into the memory
        GetContext()->OutputMovInstruction(
            Operand(argIndex),
            paramResults[i]->_operand);
    }

    // Now output call
    GetContext()->OutputInstruction(
        OpCodes::RCallRC,
        addrOperand,
        Operand((int)firstAvail));

    return nullptr;
}

FunctionInfo *FunctionCallNode::GetFunctionInfo()
{
    return dynamic_cast<FunctionInfo *>(GetContext()->_varCollection.GetInfo(_symIndex));
}