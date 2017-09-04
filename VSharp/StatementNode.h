#pragma once

#include "ASTNode.h"
#include "VSharp.tab.h"

class FunctionCallNode;

class StatementNode : public ASTNode
{
public:
    StatementNode(PSLCompilerContext* pContext, const YYLTYPE &location);

    bool PreProcessNodeImpl() override;
    void DumpNodeImpl() override;
    
    void SetCallReplacement(FunctionCallNode* pCallNode, ASTNode* pReplacement);
    FunctionCallNode* GetCallNode() { return _pCallNode; }
    ASTNode* GetReplacementNode() { return _pReplacement; }
    FunctionCallNode* GetFirstFunctionCall();
    
protected:
    const YYLTYPE& GetLocation() { return _location; }

private:
    static FunctionCallNode* GetFunctionCall(ASTNode* pNode);

private:
    YYLTYPE _location;
    bool _fProcessed;
    FunctionCallNode* _pCallNode;   // When duplicating, the call node to replace
    ASTNode* _pReplacement;         // When duplicating, the thing to replace with
  };
