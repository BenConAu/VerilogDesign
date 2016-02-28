#pragma once

#include "ASTNode.h"

class PSLCompilerContext;
class TypeInfo;

// Indicates a member of a struct
class StructDeclarationNode : public ASTNode
{
public:
    StructDeclarationNode(PSLCompilerContext* pContext, ASTNode* pTypeNode, int symId);

    TypeInfo* GetTypeInfo();
    int GetName() { return _symIndex; }
    void PreProcessNodeImpl() override;
    void VerifyNodeImpl() override;

private:
    int _symIndex;
};
