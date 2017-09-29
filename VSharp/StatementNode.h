#pragma once

#include "ASTNode.h"
#include "VSharp.tab.h"

class FunctionCallNode;
class IdentifierNode;

class StatementNode : public ASTNode
{
public:
    StatementNode(ParserContext* pContext, const YYLTYPE &location);

    bool PreProcessNodeImpl(OutputContext* pContext) override;
    void DumpNodeImpl() override;
    
    void SetCallReplacement(FunctionCallNode* pCallNode, ASTNode* pReplacement);
    FunctionCallNode* GetCallNode() { return _pCallNode; }
    ASTNode* GetReplacementNode() { return _pReplacement; }
    
private:
    // Function call replacement
    FunctionCallNode* GetFirstFunctionCall();
    FunctionCallNode* GetFunctionCall(ASTNode* pNode);
    bool IsReplaceableFunctionCall(ASTNode* pNode);

    // Stage output replacement
    IdentifierNode* GetFirstStageOutput();
    IdentifierNode* GetStageOutput(ASTNode* pNode);
    bool IsReplaceableIdentifier(ASTNode* pNode);
    
private:
    bool _fProcessed;
    FunctionCallNode* _pCallNode;   // When duplicating, the call node to replace
    ASTNode* _pReplacement;         // When duplicating, the thing to replace with
  };
