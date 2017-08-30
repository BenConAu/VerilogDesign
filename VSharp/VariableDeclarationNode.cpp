#include "VariableDeclarationNode.h"
#include "ModuleDeclaratorNode.h"
#include "AssignmentNode.h"
#include "IdentifierNode.h"
#include "TypeNode.h"
#include "VariableLocationType.h"
#include "VariableInfo.h"

VariableDeclarationNode::VariableDeclarationNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pType,
    int symIndex,
    const UIntConstant& arraySize,
    ASTNode *pInitExpr) : ASTNode(pContext)
{
    AddNode(pType);

    if (pInitExpr != nullptr)
    {
        IdentifierNode *pLeft = new IdentifierNode(pContext, location, symIndex);
        AssignmentNode *pAssignment = new AssignmentNode(pContext, location, pLeft, pInitExpr);

        AddNode(pAssignment);
    }

    _symIndex = symIndex;
    _arraySize = arraySize._value;
}

VariableDeclarationNode::VariableDeclarationNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    ASTNode *pType,
    int symIndex,
    ASTNode *pInitExpr) : ASTNode(pContext)
{
    AddNode(pType);

    if (pInitExpr != nullptr)
    {
        IdentifierNode *pLeft = new IdentifierNode(pContext, location, symIndex);
        AssignmentNode *pAssignment = new AssignmentNode(pContext, location, pLeft, pInitExpr);

        AddNode(pAssignment);
    }

    _symIndex = symIndex;
    _arraySize = -1;
}

void VariableDeclarationNode::PreVerifyNodeImpl()
{
    //printf("Adding variable %s\n", GetContext()->_symbols[_symIndex].c_str());
    ModuleDeclaratorNode *pFunc = GetTypedParent<ModuleDeclaratorNode>();

    TypeInfo* pInfo = dynamic_cast<TypeNode *>(GetChild(0))->GetTypeInfo();
    if (_arraySize != -1)
    {
        pInfo = GetContext()->_typeCollection.GetArrayType(pInfo);
    }

    // Add variable to collection and mark first usage
    GetContext()->_symbolTable.AddVariable(
        pFunc,
        _symIndex,
        VariableLocationType::Member,
        pInfo);
}

void VariableDeclarationNode::PreProcessNodeImpl()
{
    ModuleDeclaratorNode *pModule = GetTypedParent<ModuleDeclaratorNode>();

    // Spit out the preamble
    VariableInfo* pInfo = dynamic_cast<VariableInfo*>(GetContext()->_symbolTable.GetInfo(_symIndex, pModule));

    // Find out the bit width
    if (_arraySize == -1)
    {
        RegisterTypeInfo* pRegInfo = dynamic_cast<RegisterTypeInfo*>(pInfo->GetTypeInfo());
        if (pRegInfo != nullptr)
        {
            GetContext()->OutputLine("reg[%d:0] %s;", pRegInfo->GetBitLength() - 1, pInfo->GetSymbol());
        }
        else
        {
            ClockTypeInfo* pClockInfo = dynamic_cast<ClockTypeInfo*>(pInfo->GetTypeInfo());
            if (pClockInfo != nullptr)
            {
                GetContext()->OutputLine("reg %s = 0; always #5 %s = !%s;", pInfo->GetSymbol(), pInfo->GetSymbol(), pInfo->GetSymbol());
            }
            else
            {
                StructTypeInfo* pStructInfo = dynamic_cast<StructTypeInfo*>(pInfo->GetTypeInfo());
                if (pStructInfo != nullptr)
                {
                    GetContext()->OutputLine("reg[%d:0] %s;", pStructInfo->GetBitLength() - 1, pInfo->GetSymbol());                    
                }
                else
                {
                    throw "Bad type, fix verify";
                }
            }
        }
    }
    else
    {
        ArrayTypeInfo* pArrayInfo = dynamic_cast<ArrayTypeInfo*>(pInfo->GetTypeInfo());
        RegisterTypeInfo* pRegInfo = dynamic_cast<RegisterTypeInfo*>(pArrayInfo->GetBaseType());
        GetContext()->OutputLine("reg[%d:0] %s[%d:0];", pRegInfo->GetBitLength() - 1, pInfo->GetSymbol(), _arraySize - 1);
    }
}
