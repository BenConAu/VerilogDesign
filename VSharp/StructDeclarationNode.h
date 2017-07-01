#pragma once

#include "ASTNode.h"

class PSLCompilerContext;
class TypeInfo;

// Indicates a member of a struct
class StructDeclarationNode : public ASTNode
{
public:
    StructDeclarationNode(
        PSLCompilerContext* pContext, 
        ASTNode* pTypeNode, 
        int symId, 
        int dimension);

    TypeInfo* GetTypeInfo(); // Returns the type on the node, not the type the member eventually gets
    int GetDimension() const { return _dimension; }
    int GetName() { return _symIndex; }
    void PreProcessNodeImpl() override;
    void VerifyNodeImpl() override;
    const char* GetDebugName() override { return "StructDeclarationNode"; }

private:
    int _symIndex;
    int _dimension;
};
