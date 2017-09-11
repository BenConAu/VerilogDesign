#pragma once

#include "VSharpCompilerContext.h"
#include "ASTNode.h"

class StateDeclaratorNode;
class ModuleParameterNode;

class ModuleDefinitionNode : public ASTNode
{
public:
    ModuleDefinitionNode(
        PSLCompilerContext* pContext, 
        const YYLTYPE &location,
        int symIndex,
        int genericSym
        );

    void AddParameter(ASTNode* pNode)
    {
        AddNode(pNode);
    }

    void SetStatementList(ASTNode* pList)
    {
        AddNode(pList);
    }

    void PreVerifyNodeImpl() override;
    void VerifyNodeImpl() override;
    bool PreProcessNodeImpl() override;
    void ProcessNodeImpl() override;
    void PostProcessNodeImpl() override;
    const char* GetDebugName() override { return "ModuleDefinitionNode"; }

    size_t GetParameterCount() { return _paramList.size(); }
    ModuleParameterNode* GetParameter(size_t index) { return _paramList[index]; }

private:
    template<typename T>
    void MoveListChildren(ASTNode* pModuleChildList, size_t InsertPoint)
    {
        //printf("Moving children from list of length %d\n", (int)pModuleChildList->GetChildCount());

        size_t RemovePoint = 0;
        size_t ListCount = pModuleChildList->GetChildCount();
        for (size_t i = 0; i < ListCount; i++)
        {
            //printf("Iteration %d with Remove Point %d and child count %d\n", (int)i, (int)RemovePoint, (int)pModuleChildList->GetChildCount());
            //printf("-- %s\n", pModuleChildList->GetChild(RemovePoint)->GetDebugName());

            T* pDecl = dynamic_cast<T*>(pModuleChildList->GetChild(RemovePoint));
            if (pDecl != nullptr)
            {
                //printf("-- Removing from position %d\n", (int)RemovePoint);
                //printf("-- List is %d long before \n", (int)pModuleChildList->GetChildCount());

                // Extract from list
                pModuleChildList->ExtractChild(RemovePoint);

                //printf("-- List is %d long after \n", (int)pModuleChildList->GetChildCount());

                // Insert into module
                InsertChild(InsertPoint, pDecl);
                InsertPoint++;
            }
            else
            {
                //printf("-- Advancing remove point to %d\n", (int)RemovePoint + 1);
                RemovePoint++;
            }
        }
    }

private:
    // The symbol index of the function identifier
    int _symIndex;

    // The symbol index of the generic type
    int _genericIndex;

    std::vector<StateDeclaratorNode*> _stateList;
    std::vector<ModuleParameterNode*> _paramList;
};