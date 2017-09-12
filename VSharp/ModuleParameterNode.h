#pragma once

#include "ASTNode.h"
#include "TypeNode.h"

class ModuleParameterNode : public ASTNode
{
public:
    ModuleParameterNode(
        PSLCompilerContext* pContext,
        const YYLTYPE &location,
        ASTNode* pType, 
        int symIndex, 
        bool fOut) : ASTNode(pContext, location)
    {
        AddNode(pType);
        _symIndex = symIndex;
        _fOut = fOut;
    }

    void VerifyNodeImpl() override;
    void PostProcessNodeImpl(OutputContext* pContext) override;
    const char* GetDebugName() override { return "ModuleParameterNode"; }
    int GetSymbolIndex() const { return _symIndex; }
    bool IsOutParam() const { return _fOut; }
    TypeNode* GetTypeNode() { return dynamic_cast<TypeNode*>(GetChild(0)); }
    
private:
    int _symIndex;
    bool _fOut;
};
