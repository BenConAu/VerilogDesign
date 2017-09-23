#include "VariableDeclarationNode.h"
#include "ModuleDefinitionNode.h"
#include "AssignmentNode.h"
#include "IdentifierNode.h"
#include "TypeNode.h"
#include "VariableLocationType.h"
#include "VariableInfo.h"
#include "OutputContext.h"

VariableDeclarationNode::VariableDeclarationNode(
    ParserContext *pContext,
    const YYLTYPE &location,
    ASTNode *pType,
    int symIndex,
    ASTNode *pArraySizeExpr,
    ASTNode *pInitExpr) : ASTNode(pContext, location)
{
    AddNode(pType);
    AddNode(pArraySizeExpr);
    AddNode(pInitExpr);

    _symIndex = symIndex;

    // We will determine this size when we verify
    _arraySize = -1;
}

void VariableDeclarationNode::VerifyNodeImpl()
{
    //printf("Adding variable %s\n", GetContext()->GetSymbolString(_symIndex).c_str());
    ModuleDefinitionNode *pFunc = GetTypedParent<ModuleDefinitionNode>();

    // Is there an array size?
    ExpressionNode* pArraySize = dynamic_cast<ExpressionNode*>(GetChild(1));
    if (pArraySize != nullptr)
    {
        UIntConstant SizeEval;
        if (!pArraySize->ConstEvaluate(&SizeEval))
        {
            GetContext()->ReportError(GetLocation(), "Array size must be constant expression");
        }

        _arraySize = SizeEval._value;
    }

    // From the type node and array size we can get the type info
    TypeInfo* pInfo = GetTypeNode()->GetTypeInfo();
    if (_arraySize != -1)
    {
        pInfo = GetContext()->GetTypeCollection()->GetArrayType(pInfo, _arraySize);
    }

    // Add variable to collection and mark first usage
    VariableInfo* pVarInfo = GetContext()->GetSymbolTable()->AddVariable(
        pFunc,
        _symIndex,
        VariableLocationType::Member,
        GetTypeNode()->GetModifier(),
        pInfo);

    if (pVarInfo == nullptr)
    {
        GetContext()->ReportError(GetLocation(), "Duplicate variable declaration %s", GetContext()->GetSymbolString(_symIndex).c_str());
    }

    ExpressionNode* pInitExpr = GetInitNode();
    if (pInitExpr != nullptr)
    {
        RegisterTypeInfo* pRegInfo = dynamic_cast<RegisterTypeInfo*>(pInfo);

        // You need to initialize register types to constant expressions
        if (pRegInfo != nullptr)
        {
            UIntConstant InitValue;
            if (!pInitExpr->ConstEvaluate(&InitValue))
            {
                GetContext()->ReportError(GetLocation(), "Init expressions for register types must be constant expressions");
            }

            pVarInfo->SetInitialValue(InitValue);
        }
    }
}

void VariableDeclarationNode::PostProcessNodeImpl(OutputContext* pContext)
{
    ModuleDefinitionNode *pModule = GetTypedParent<ModuleDefinitionNode>();

    // Spit out the preamble
    VariableInfo* pInfo = dynamic_cast<VariableInfo*>(GetContext()->GetSymbolTable()->GetInfo(_symIndex, pModule));

    // We don't emit Verilog for constant variables
    if (pInfo->GetModifier() != TypeModifier::Const)
    {
        // Each type should know how to make a declaration
        std::string decl = pInfo->GetTypeInfo()->GetDeclaration(pInfo, GetInitNode());
    
        // This node owns putting the semicolon on it
        pContext->OutputLine("%s;", decl.c_str());    
    }
}

TypeNode* VariableDeclarationNode::GetTypeNode()
{
    return dynamic_cast<TypeNode *>(GetChild(0));
}

ExpressionNode* VariableDeclarationNode::GetInitNode()
{
    return dynamic_cast<ExpressionNode *>(GetChild(2));
}