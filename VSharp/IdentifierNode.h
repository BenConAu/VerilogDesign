#pragma once

#include "ExpressionNode.h"
#include "VSharp.tab.h"

class VariableInfo;

class IdentifierNode : public ExpressionNode
{
public:
    IdentifierNode(
        ParserContext* pContext, 
        const YYLTYPE& location, 
        int symIndex);

    IdentifierNode(
        ParserContext *pContext, 
        const YYLTYPE &location, 
        int symIndex, 
        VariableInfo* pVarInfo,
        TypeInfo* pTypeInfo);
    
    void VerifyNodeImpl() override;
    int GetSymbolIndex() const { return _symIndex; }
    VariableInfo* GetVariableInfo();
    ExpressionResult* CalculateResult() override;
    ASTNode* DuplicateNodeImpl(FunctionExpandType type) override;
    const char* GetDebugName() override { return "IdentifierNode"; }
    const char* GetIdentifierName();
    VariableInfo* IsVariableExpression() override;
    bool ConstEvaluate(UIntConstant* pVal) override;
    
private:
    int _symIndex;
    VariableInfo* _pVarInfo;
    TypeInfo* _pTypeInfo;
};
