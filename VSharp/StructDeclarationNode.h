#pragma once

#include "ASTNode.h"
#include "UIntConstant.h"

class ParserContext;
class TypeInfo;

// Indicates a member of a struct
class StructDeclarationNode : public ASTNode
{
public:
    StructDeclarationNode(
        ParserContext* pContext,
        const YYLTYPE &location,
        ASTNode* pTypeNode, 
        int symId, 
        const UIntConstant &dimension);

    StructDeclarationNode(
        ParserContext* pContext,
        const YYLTYPE &location, 
        ASTNode* pTypeNode, 
        int symId);

    TypeInfo* GetTypeInfo(); // Returns the type on the node, not the type the member eventually gets
    int GetDimension() const { return _dimension; }
    int GetName() { return _symIndex; }
    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "StructDeclarationNode"; }

private:
    int _symIndex;
    int _dimension;
};
