#include "FunctionCallNode.h"
#include "VariableInfo.h"
#include "ModuleDefinitionNode.h"
#include "ModuleParameterNode.h"
#include "ParserContext.h"
#include "TypeNode.h"
#include "FunctionInfo.h"
#include "FunctionDeclaratorNode.h"
#include "StatementNode.h"
#include "VariableDeclarationNode.h"
#include "IdentifierNode.h"
#include "EnumTypeInfo.h"
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

class EnumConstructorSpec : public FunctionCallSpec
{
public:
    EnumConstructorSpec(EnumTypeInfo* pInfo)
    {
        _pEnumInfo = pInfo;
    }

    size_t GetParameterCount() override
    {
        return 1;
    }

    TypeInfo* GetParameterType(size_t index) override
    {
        // Provide a way to make from uint
        return _pEnumInfo->GetContext()->GetTypeCollection()->GetRegisterType(_pEnumInfo->GetBitLength());
    }

    bool IsParameterOut(size_t index) override
    {
        // Enum constructors never take out parameters
        return false;
    }    

    TypeInfo* GetReturnType() override
    {
        return _pEnumInfo;
    }

private:
    EnumTypeInfo* _pEnumInfo;
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
    ASTNode *pGenericValue,
    ASTNode *pFirstArg) : ExpressionNode(pContext, location)
{
    //printf("Creating function call %s\n", pContext->GetSymbolString(symIndex].c_str());

    AddNode(pGenericValue);

    if (pFirstArg != nullptr)
    {
        AddNode(pFirstArg);
    }

    _pFunctionInfo = nullptr;
    _symIndex = symIndex;
    _FunctionCallType = FunctionCallType::Unknown; // Until we learn otherwise
}

FunctionCallNode::FunctionCallNode(
    ParserContext *pContext,
    const YYLTYPE &location,
    int symIndex,
    FunctionCallType type,
    FunctionInfo* pInfo,
    UIntConstant GenericParam) : ExpressionNode(pContext, location)
{
    _pFunctionInfo = pInfo;
    _symIndex = symIndex;
    _FunctionCallType = type;
    _GenericParam = GenericParam;
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

ASTNode* FunctionCallNode::DuplicateNode(DuplicateType type)
{
    if (type == DuplicateType::ExpandFunction)
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
            return pStatementNode->GetReplacementNode()->DuplicateNode(type);
        }
        else
        {
            //printf("Duplicating function call %s, but not the one being expanded\n", GetFunctionName());

            return ASTNode::DuplicateNode(type);
        }    
    }
    else
    {
        if (type != DuplicateType::ExpandGeneric)
        {
            throw "Wat";
        }

        return ASTNode::DuplicateNode(type);
    }
}

ASTNode* FunctionCallNode::DuplicateNodeImpl(DuplicateType type)
{
    return new FunctionCallNode(GetContext(), GetLocation(), _symIndex, _FunctionCallType, _pFunctionInfo, _GenericParam);
}

const char* FunctionCallNode::GetFunctionName()
{
    return GetContext()->GetSymbolString(_symIndex).c_str();
}

void FunctionCallNode::SearchFunctionInfo(
    FunctionInfo** ppFunctionInfo,
    FunctionInfo** ppGenericInfo
    )
{
    ModuleDefinitionNode *pModule = GetTypedParent<ModuleDefinitionNode>();
        
    std::vector<FunctionInfo*> Functions;
    GetContext()->GetSymbolTable()->GetSymbols(_symIndex, pModule, Functions);

    // Find the one that matches
    for (size_t i = 0; i < Functions.size(); i++)
    {
        if (GetChild(0) == nullptr)
        {
            if (Functions[i]->GetUIntConstant() == nullptr)
            {
                // We need a non-generic function and we found one
                (*ppFunctionInfo) = Functions[i];
            }
            else
            {
                GetContext()->ReportError(GetLocation(), "Calling generic function without argument");
            }
        }
        else
        {
            // Grab the expression that was the generic argument
            ExpressionNode* pExpr = dynamic_cast<ExpressionNode*>(GetChild(0));
            
            // Evaluate the constant
            if (!pExpr->ConstEvaluate(&_GenericParam))
            {
                GetContext()->ReportError(GetLocation(), "Non - constant expression not valid for generic expansion");
            }

            // If somebody passed a constant generic parameter, find the match
            UIntConstant* pFunctionConstant = Functions[i]->GetUIntConstant();
            if (pFunctionConstant == nullptr)
            {
                // Remember this in case we can't find it
                (*ppGenericInfo) = Functions[i];
            }
            else
            {
                if (*pFunctionConstant == _GenericParam)
                {
                    // We have found a match
                    (*ppFunctionInfo) = Functions[i];
                }
            }
        }
    }    
}

void FunctionCallNode::VerifyNodeImpl()
{
    // If we find the non-specialized version of the function anywhere, remember it
    FunctionInfo* pGenericInfo = nullptr;
    SearchFunctionInfo(&_pFunctionInfo, &pGenericInfo);

    // If we have only found the function in generic form, then specialize it and use the specialization
    if (_pFunctionInfo == nullptr && pGenericInfo != nullptr)
    {
        FunctionDeclaratorNode* pGenericFuncDecl = pGenericInfo->GetFunctionDeclarator();
        
        // First duplicate
        ASTNode* pSpecificDecl = pGenericFuncDecl->ExpandFunction(this, _GenericParam);
        
        // Insert the specialization after the original
        GetContext()->AddFunction(pSpecificDecl);

        // Since it was a generic, it was not verified before. Now we can do so.
        pSpecificDecl->VerifyNode(nullptr);

        SearchFunctionInfo(&_pFunctionInfo, &pGenericInfo);
    }

    // The common logic for verifying things like functions is in a spec
    std::unique_ptr<FunctionCallSpec> CallSpec;

    if (GetFunctionInfo() == nullptr)
    {
        VariableDeclarationNode* pVarDecl = dynamic_cast<VariableDeclarationNode*>(GetParent());

        // If there is no function info, then it could be a constructor of a struct or a declaration
        // of a module (which also looks just like a function call from the parser perspective).
        if (pVarDecl != nullptr)
        {
            _FunctionCallType = FunctionCallType::ModuleDecl;

            // Should be a module type info
            TypeNode* pTypeNode = pVarDecl->GetTypeNode();
            ModuleTypeInfo* pModuleInfo = dynamic_cast<ModuleTypeInfo*>(pTypeNode->GetTypeInfo());
            if (pModuleInfo == nullptr)
            {
                GetContext()->ReportError(GetLocation(), "Not a module type");
            }

            // The function name should be the same symbol as the type name
            if (pModuleInfo->GetSymbolIndex() != _symIndex)
            {
                GetContext()->ReportError(GetLocation(), "Module constructor needs same name as module type");
            }

            CallSpec.reset(new DefinedModuleSpec(pModuleInfo));
        }
        else
        {
            _FunctionCallType = FunctionCallType::Constructor;

            StructTypeInfo* pStructInfo = GetContext()->GetTypeCollection()->GetStructType(_symIndex);
            if (pStructInfo == nullptr)
            {
                EnumTypeInfo* pEnumInfo = GetContext()->GetTypeCollection()->GetEnumType(_symIndex);
                if (pEnumInfo == nullptr)
                {
                    char message[256];
                    sprintf(
                        message, 
                        "Unknown function, struct, or enum type %s", 
                        GetFunctionName());
                    GetContext()->ReportError(GetLocation(), message);
                }

                CallSpec.reset(new EnumConstructorSpec(pEnumInfo));
            }
            else
            {
                CallSpec.reset(new StructConstructorSpec(pStructInfo));
            }
        }
    }
    else
    {
        if (GetFunctionInfo()->GetParameterCount() == -1)
        {
            // Builtin functions have no parameters to key off right now
            _FunctionCallType = FunctionCallType::BuiltIn;
        }
        else
        {
            _FunctionCallType = FunctionCallType::Defined;

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
                GetContext()->ReportError(GetLocation(), "Mismatch with in / out definition for param %d", i);                    
            }            

            if (CallSpec->IsParameterOut(i))
            {
                // Modules need to be called with wires for out
                if (_FunctionCallType == FunctionCallType::ModuleDecl)
                {
                    VariableInfo* pVarInfo = pParamExpr->IsVariableExpression();
                    if (pVarInfo == nullptr)
                    {
                        GetContext()->ReportError(GetLocation(), "Param %d of module out parameters must be identifier expressions to be wires", i);
                    }

                    if (pVarInfo->GetModifier() != TypeModifier::Wire && pVarInfo->GetLocationType() != VariableLocationType::Output)
                    {
                        GetContext()->ReportError(GetLocation(), "Module out parameter %d must be a wire", i);
                    }
                }
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
    switch(_FunctionCallType)
    {
        case FunctionCallType::Unknown:
            throw "Unexpected unknown function type during processing";

        case FunctionCallType::ModuleDecl:
        {
            std::string resultString = "(";
            AppendParameterList(resultString);
            resultString.append(")");               

            // Make a magical expression result that can come back here and extract stuff if need be
            return new ExpressionResult(resultString, this);
        }

        case FunctionCallType::BuiltIn:
        {
            std::string resultString;

            resultString.append(GetFunctionInfo()->GetVerilogName());
            resultString.append("(");
            AppendParameterList(resultString);
            resultString.append(")");

            return new ExpressionResult(resultString);
        }

        case FunctionCallType::Constructor:
        {
            // This should work even for enums, because a single thing in a concat list
            // is just that single thing.
            std::string resultString = "{ ";
            AppendParameterList(resultString);
            resultString.append(" }");               

            // Make a magical expression result that can come back here and extract stuff if need be
            return new ExpressionResult(resultString, this);
        }

        case FunctionCallType::Defined:
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

UIntConstant* FunctionCallNode::GetGenericValue()
{
    if (GetChild(0) == nullptr)
    {
        return nullptr;
    }
    else
    {
        return &_GenericParam;
    }
}
