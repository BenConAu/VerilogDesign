#include "FunctionCallNode.h"
#include "VariableInfo.h"
#include "ModuleDefinitionNode.h"
#include "ModuleParameterNode.h"
#include "VSharpCompilerContext.h"
#include "TypeNode.h"
#include "FunctionInfo.h"
#include "FunctionDeclaratorNode.h"
#include "StatementNode.h"
#include "VariableDeclarationNode.h"
#include "VSharp.tab.h"

class FunctionCallSpec
{
public:
    virtual size_t GetParameterCount() = 0;                 // The number of parameters that should be there
    virtual TypeInfo* GetParameterType(size_t index) = 0;   // The type of the given parameter
    virtual bool IsParameterOut(size_t index) = 0;          // Is the given parameter an out param
    virtual TypeInfo* GetReturnType() = 0;                  // The return type of the expression
};

class StructConstructorSpec : public FunctionCallSpec
{
public:
    StructConstructorSpec(StructTypeInfo* pStructInfo)
    {
        _pStructInfo = pStructInfo;
    }

    size_t GetParameterCount() override
    {
        return _pStructInfo->GetMemberCount();
    }

    TypeInfo* GetParameterType(size_t index) override
    {
        StructMember* pMember = _pStructInfo->GetMemberByIndex(index);
        return pMember->GetTypeInfo();
    }

    bool IsParameterOut(size_t index) override
    {
        // Struct constructors never take out parameters
        return false;
    }    

    TypeInfo* GetReturnType() override
    {
        return _pStructInfo;
    }

private:
    StructTypeInfo* _pStructInfo;
};

class DefinedFunctionSpec : public FunctionCallSpec
{
public:
    DefinedFunctionSpec(FunctionInfo* pFunctionInfo)
    {
        _pFunctionInfo = pFunctionInfo;
    }

    size_t GetParameterCount() override
    {
        return _pFunctionInfo->GetParameterCount();
    }

    TypeInfo* GetParameterType(size_t index) override
    {
        FunctionDeclaratorNode* pFuncDecl = _pFunctionInfo->GetFunctionDeclarator();
        FunctionParameterNode* pDefParam = pFuncDecl->GetParameter(index);
        
        return pDefParam->GetTypeNode()->GetTypeInfo();
    }

    bool IsParameterOut(size_t index) override
    {
        FunctionDeclaratorNode* pFuncDecl = _pFunctionInfo->GetFunctionDeclarator();
        FunctionParameterNode* pDefParam = pFuncDecl->GetParameter(index);
        
        return pDefParam->IsOutParam();
    }

    TypeInfo* GetReturnType() override
    {
        return _pFunctionInfo->GetReturnType();
    }

private:
    FunctionInfo* _pFunctionInfo;
};

class DefinedModuleSpec : public FunctionCallSpec
{
public:
    DefinedModuleSpec(ModuleTypeInfo* pModuleTypeInfo)
    {
        _pModuleTypeInfo = pModuleTypeInfo;
    }

    size_t GetParameterCount() override
    {
        return _pModuleTypeInfo->GetParameterCount();
    }

    TypeInfo* GetParameterType(size_t index) override
    {
        ModuleDefinitionNode* pModuleDef = _pModuleTypeInfo->GetModuleDefinition();
        ModuleParameterNode* pDefParam = pModuleDef->GetParameter(index);
        
        return pDefParam->GetTypeNode()->GetTypeInfo();
    }

    bool IsParameterOut(size_t index) override
    {
        ModuleDefinitionNode* pModuleDef = _pModuleTypeInfo->GetModuleDefinition();
        ModuleParameterNode* pDefParam = pModuleDef->GetParameter(index);
        
        return pDefParam->IsOutParam();
    }

    TypeInfo* GetReturnType() override
    {
        return _pModuleTypeInfo;
    }

private:
    ModuleTypeInfo* _pModuleTypeInfo;
};

FunctionCallNode::FunctionCallNode(
    ParserContext *pContext,
    const YYLTYPE &location,
    int symIndex,
    ASTNode *pGenericType,
    ASTNode *pFirstArg) : ExpressionNode(pContext, location)
{
    //printf("Creating function call %s\n", pContext->GetSymbolString(symIndex].c_str());

    AddNode(pGenericType);

    if (pFirstArg != nullptr)
    {
        AddNode(pFirstArg);
    }

    _symIndex = symIndex;
    _functionType = FunctionType::Unknown; // Until we learn otherwise
}

FunctionCallNode::FunctionCallNode(
    ParserContext *pContext,
    const YYLTYPE &location,
    int symIndex,
    FunctionType type) : ExpressionNode(pContext, location)
{
    _symIndex = symIndex;
    _functionType = type;
}

void FunctionCallNode::DumpNodeImpl()
{
    printf(
        "%s node %p :\t%s\n", 
        GetDebugName(),
        this,
        GetFunctionName()
    );    
}

ASTNode* FunctionCallNode::DuplicateNode()
{
    // Find the statement that initiated the duplication - it might
    // not be the first one up the tree.
    //printf("Starting function call node duplication of %s %p\n", GetFunctionName(), this);
    //GetContext()->DumpTree();
    StatementNode* pStatementNode = GetTypedParent<StatementNode>(); 
    while (pStatementNode != nullptr && pStatementNode->GetCallNode() == nullptr)
    {
        pStatementNode = pStatementNode->GetTypedParent<StatementNode>();
    }

    if (pStatementNode != nullptr && this == pStatementNode->GetCallNode())
    {
        //printf(
            //"Duplicating function call %s by replacing with node %s\n", 
            //GetFunctionName(), 
            //pStatementNode->GetReplacementNode()->GetDebugName());

        // Replace the call with the expression we were given from the return statement
        return pStatementNode->GetReplacementNode()->DuplicateNode();
    }
    else
    {
        //printf("Duplicating function call %s, but not the one being expanded\n", GetFunctionName());

        return ASTNode::DuplicateNode();
    }    
}

ASTNode* FunctionCallNode::DuplicateNodeImpl()
{
    return new FunctionCallNode(GetContext(), GetLocation(), _symIndex, _functionType);
}

const char* FunctionCallNode::GetFunctionName()
{
    return GetContext()->GetSymbolString(_symIndex).c_str();
}

void FunctionCallNode::VerifyNodeImpl()
{
    std::unique_ptr<FunctionCallSpec> CallSpec;

    if (GetFunctionInfo() == nullptr)
    {
        VariableDeclarationNode* pVarDecl = dynamic_cast<VariableDeclarationNode*>(GetParent());

        // If there is no function info, then it could be a constructor of a struct or a declaration
        // of a module (which also looks just like a function call from the parser perspective).
        if (pVarDecl != nullptr)
        {
            _functionType = FunctionType::ModuleDecl;

            // Find the type of the declaration
            TypeNode* pTypeNode = pVarDecl->GetTypeNode();
            if (pTypeNode->GetTypeClass() != TypeClass::Module)
            {
                GetContext()->ReportError(GetLocation(), "Not a module type");
            }

            // Should be a module type info
            ModuleTypeInfo* pModuleInfo = dynamic_cast<ModuleTypeInfo*>(pTypeNode->GetTypeInfo());

            // The function name should be the same symbol as the type name
            if (pModuleInfo->GetSymbolIndex() != _symIndex)
            {
                GetContext()->ReportError(GetLocation(), "Module constructor needs same name as module type");
            }

            CallSpec.reset(new DefinedModuleSpec(pModuleInfo));
        }
        else
        {
            _functionType = FunctionType::Constructor;

            StructTypeInfo* pStructInfo = GetContext()->GetTypeCollection()->GetStructType(_symIndex);
            if (pStructInfo == nullptr)
            {
                char message[256];
                sprintf(
                    message, 
                    "Unknown function or struct type %s", 
                    GetFunctionName());
                GetContext()->ReportError(GetLocation(), message);
            }
    
            CallSpec.reset(new StructConstructorSpec(pStructInfo));
        }
    }
    else
    {
        if (GetFunctionInfo()->GetParameterCount() == -1)
        {
            // Builtin functions have no parameters to key off right now
            _functionType = FunctionType::BuiltIn;
        }
        else
        {
            _functionType = FunctionType::Defined;

            if (GetParameterCount() != GetFunctionInfo()->GetParameterCount())
            {
                char message[256];
                sprintf(
                    message, 
                    "Expected %lu arguments but got %lu arguments to function %s",
                    GetFunctionInfo()->GetParameterCount(),
                    GetParameterCount(),
                    GetFunctionName());
    
                GetContext()->ReportError(GetLocation(), message);    
            }

            CallSpec.reset(new DefinedFunctionSpec(GetFunctionInfo()));
        }
    }

    if (CallSpec.get() != nullptr)
    {
        if (GetParameterCount() != CallSpec->GetParameterCount())
        {
            char message[256];
            sprintf(
                message, 
                "Expected %lu arguments but got %lu arguments when invoking %s",
                CallSpec->GetParameterCount(),
                GetParameterCount(),
                GetFunctionName());
    
            GetContext()->ReportError(GetLocation(), message);    
        }
    
        for (size_t i = 0; i < GetParameterCount(); i++)
        {
            FunctionCallParamNode* pCallParam = GetParameter(i);
            ExpressionNode* pParamExpr = pCallParam->GetParamExpr();
    
            TypeInfo* pSpecInfo = CallSpec->GetParameterType(i);
    
            // Out params need to be passed correctly
            if (pCallParam->IsOutParam() != CallSpec->IsParameterOut(i))
            {
                GetContext()->ReportError(GetLocation(), "Mismatch in param in / out definition");
            }
    
            // Types should match
            if (!pParamExpr->GetTypeInfo()->EqualType(pSpecInfo))
            {
                char message[256];
                sprintf(
                    message, 
                    "Expected type %s for argument %lu but got type %s",
                    pSpecInfo->GetTypeName().c_str(),
                    i,
                    pParamExpr->GetTypeInfo()->GetTypeName().c_str());
    
                GetContext()->ReportError(GetLocation(), message);    
            }
        }
    
        SetType(CallSpec->GetReturnType());
    }
}

FunctionInfo* FunctionCallNode::GetFunctionInfo()
{
    ModuleDefinitionNode *pModule = GetTypedParent<ModuleDefinitionNode>();
    return dynamic_cast<FunctionInfo*>(GetContext()->GetSymbolTable()->GetInfo(_symIndex, pModule));
}

ASTNode* FunctionCallNode::ExpandFunction(StatementNode* pOwningStatement)
{
    // We have been given the expression that this function call is inside of,
    // and we will now construct a statement list that represents the work
    // of this function, but where return statements are replaced with copies
    // of the expression provided, subsituting the function call for the expression
    // in the return statement.
    FunctionDeclaratorNode* pFuncDecl = GetFunctionInfo()->GetFunctionDeclarator();
    if (pFuncDecl == nullptr)
    {
        GetContext()->ReportError(GetLocation(), "Internal compiler error - function calls that return values cannot be builtin functions");
    }

    //printf("Expanding function %s\n", GetContext()->GetSymbolString(_symIndex).c_str());
    return pFuncDecl->ExpandFunction(this, pOwningStatement);
}

ExpressionResult *FunctionCallNode::CalculateResult()
{
    switch(_functionType)
    {
        case FunctionType::Unknown:
            throw "Unexpected unknown function type during processing";

        case FunctionType::ModuleDecl:
        {
            std::string resultString = "(";
            AppendParameterList(resultString);
            resultString.append(")");               

            // Make a magical expression result that can come back here and extract stuff if need be
            return new ExpressionResult(resultString, this);
        }

        case FunctionType::BuiltIn:
        {
            std::string resultString;

            resultString.append(GetFunctionInfo()->GetVerilogName());
            resultString.append("(");
            AppendParameterList(resultString);
            resultString.append(")");

            return new ExpressionResult(resultString);
        }

        case FunctionType::Constructor:
        {
            std::string resultString = "{ ";
            AppendParameterList(resultString);
            resultString.append(" }");               

            // Make a magical expression result that can come back here and extract stuff if need be
            return new ExpressionResult(resultString, this);
        }

        case FunctionType::Defined:
            printf("Unexpected function call %p named %s\n", this, GetFunctionName());
            //GetContext()->DumpTree();
            return nullptr;
    }
}

ExpressionResult* FunctionCallNode::CreateMemberResult(int fieldSymIndex)
{
    StructTypeInfo* pStructInfo = GetContext()->GetTypeCollection()->GetStructType(_symIndex);            
    
    size_t memberIndex;
    if (!pStructInfo->GetMemberIndex(fieldSymIndex, &memberIndex))
    {
        throw "That is not a member";
    }
    
    return new ExpressionResult(_parameterResults[memberIndex]);
}

size_t FunctionCallNode::GetParameterCount() const 
{ 
    return (GetChildCount() - 1); 
}

void FunctionCallNode::AppendParameterList(std::string& str)
{
    for (size_t i = 0; i < GetParameterCount(); i++)
    {
        ExpressionNode* pParam = GetParameter(i);
        std::unique_ptr<ExpressionResult> paramResult(pParam->TakeResult());
        
        if (i != 0)
        {
            str.append(", ");
        }

        str.append(paramResult->GetString());
        _parameterResults.push_back(paramResult->GetString());
    }
}