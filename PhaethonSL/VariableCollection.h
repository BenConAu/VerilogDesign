#pragma once

#include <map>

class VariableDeclarationNode;
class ASTNode;

struct VariableInfo
{
    int symIndex;
    ASTNode* pDecl;
    ASTNode* pLastRef;
    bool fLastProcessed;
};

class VariableCollection
{
public:
    void AddVariable(int symIndex, VariableDeclarationNode* pNode);
    void AddReference(int symIndex, ASTNode* pNode);
    void ProcessReference(int symIndex, ASTNode *pNode);

private:
    std::map<int, VariableInfo> _variables;
};
