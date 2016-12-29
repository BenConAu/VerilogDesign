#include "AddressOfNode.h"
#include "IdentifierNode.h"
#include "VariableInfo.h"

void AddressOfNode::VerifyNodeImpl()
{
    // We are getting the address of an identifier
    IdentifierNode *pIdentifierNode = dynamic_cast<IdentifierNode *>(GetChild(0));
    if (pIdentifierNode == nullptr)
    {
        throw "Need an identifier to take address";
    }

    // We are only allowed to get addresses of structs
    VariableInfo *pVariableInfo = pIdentifierNode->GetVariableInfo();
    StructTypeInfo *pStructInfo = dynamic_cast<StructTypeInfo *>(pVariableInfo->GetTypeInfo());
    if (pStructInfo == nullptr)
    {
        throw "Can only take address of structs";
    }

    // Our expression type is pointer to the other expression type
    TypeInfo *pNewTypeInfo = GetContext()->_typeCollection.GetPointerType(pVariableInfo->GetTypeInfo());
    SetType(pNewTypeInfo);
}

ExpressionResult *AddressOfNode::CalculateResult()
{
    // Find the result of the child
    IdentifierNode *pIdentifierNode = dynamic_cast<IdentifierNode *>(GetChild(0));
    std::unique_ptr<ExpressionResult> childResult(pIdentifierNode->CalculateResult());

    // Change its type
    childResult->SetTypeInfo(GetTypeInfo());

    // The result has the new type but same path and same operand
    return childResult.release();
}
