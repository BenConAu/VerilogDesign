#include "FunctionCallNode.h"
#include "VariableInfo.h"
#include "FunctionInfo.h"
#include "FunctionDeclaratorNode.h"
#include "PSLCompilerContext.h"
#include "TypeNode.h"
#include "VSharp.tab.h"

FunctionCallNode::FunctionCallNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    int symIndex,
    ASTNode *pGenericType,
    ASTNode *pFirstArg) : ExpressionNode(pContext)
{
    AddNode(pGenericType);

    if (pFirstArg != nullptr)
    {
        AddNode(pFirstArg);
    }

    _symIndex = symIndex;
    _location = location;
}

void FunctionCallNode::VerifyNodeImpl()
{
    // Function needs to be defined
    FunctionInfo *pInfo = GetFunctionInfo();
    if (pInfo == nullptr)
    {
        GetContext()->ReportError(_location, "Unknown function called");
    }

    GenericTypeInfo *pGenericTypeInfo = pInfo->GetGenericTypeInfo();

    if (GetChild(0) != nullptr)
    {
        if (pGenericTypeInfo == nullptr)
        {
            GetContext()->ReportError(_location, "Generic function called with no generic type argument");
        }

        // Called with template syntax so we need to replace the type
        TypeNode *pReplaceTypeNode = dynamic_cast<TypeNode *>(GetChild(0));
        TypeInfo *pReplaceType = pReplaceTypeNode->GetTypeInfo();

        SetType(pInfo->GetReturnTypeInfo()->MakeSpecificType(pReplaceType, &(GetContext()->_typeCollection)));
    }
    else
    {
        if (pGenericTypeInfo != nullptr)
        {
            GetContext()->ReportError(_location, "Non-generic function called with generic type argument");
        }

        SetType(pInfo->GetReturnTypeInfo());
    }
}

ExpressionResult *FunctionCallNode::CalculateResult()
{
    //printf("CalculateResult for FunctionCall\n");
/*    FunctionDeclaratorNode *pScope = GetTypedParent<FunctionDeclaratorNode>();

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
    for (size_t i = 0; i < GetChildCount() - 1; i++)
    {
        // First child is generic type node, so we skip it
        ExpressionNode *pExprChild = dynamic_cast<ExpressionNode *>(GetChild(i + 1));
        paramResults.emplace_back(pExprChild->TakeResult());

        // No matter where it is, we need to move into the correct register
        RegIndex argIndex = firstArg + i;

        // Put out the instruction for this
        // Push the wrapped register into the memory
        GetContext()->OutputMovInstruction(
            Operand(argIndex),
            *paramResults[i].get());
    }

    // Now output call
    GetContext()->OutputInstruction(
        OpCode::RCallRC,
        addrOperand,
        Operand((int)firstAvail));

    FunctionInfo *pInfo = GetFunctionInfo();
    if (pInfo->GetReturnTypeInfo()->GetTypeClass() == TypeClass::Basic && dynamic_cast<BasicTypeInfo *>(pInfo->GetReturnTypeInfo())->GetTypeToken() == VOID_TOKEN)
    {
        return nullptr;
    }
    else
    {
        // The register we return stuff with needs to be reserved
        pScope->GetRegCollection()->ReserveRegister(firstArg);

        return new ExpressionResult(Operand(firstArg), pScope->GetRegCollection());
    }*/
    return nullptr;
}

FunctionInfo *FunctionCallNode::GetFunctionInfo()
{
    return dynamic_cast<FunctionInfo *>(GetContext()->_symbolTable.GetInfo(_symIndex, nullptr));
}
