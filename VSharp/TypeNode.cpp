#include "TypeNode.h"
#include "ParserContext.h"
#include "RegisterTypeInfo.h"
#include "StructTypeInfo.h"
#include "ModuleDefinitionNode.h"
#include "ConstantNode.h"
#include "IdentifierNode.h"
#include <sstream>

TypeNode::TypeNode(
    ParserContext *pContext,
    const YYLTYPE &location,
    TypeClass typeClass,
    int type) : ASTNode(pContext, location)
{
    _typeClass = typeClass;
    _extra = type;
    _pTypeInfo = nullptr;
    _TypeModifier = TypeModifier::None;
}

TypeNode::TypeNode(
    ParserContext *pContext,
    const YYLTYPE &location,
    TypeClass typeClass) : ASTNode(pContext, location)
{
    _typeClass = typeClass;
    _extra = 0;
    _pTypeInfo = nullptr;
    _TypeModifier = TypeModifier::None;
}

TypeNode::TypeNode(
    ParserContext *pContext, 
    const YYLTYPE &location,
    ASTNode* pExpr) : ASTNode(pContext, location)
{
    AddNode(pExpr);

    _typeClass = TypeClass::Unknown;
    _extra = 0;
    _pTypeInfo = nullptr;
    _TypeModifier = TypeModifier::None;
}

TypeNode::TypeNode(
    ParserContext *pContext, 
    const YYLTYPE &location,
    TypeClass typeClass,
    TypeModifier TypeModifier,
    int extra,
    TypeInfo* pTypeInfo) : ASTNode(pContext, location)
{
    _typeClass = typeClass;
    _TypeModifier = TypeModifier;
    _extra = extra;
    _pTypeInfo = pTypeInfo;
}

ASTNode* TypeNode::DuplicateNodeImpl(FunctionExpandType type)
{
    return new TypeNode(GetContext(), GetLocation(), _typeClass, _TypeModifier, _extra, _pTypeInfo);
}

void TypeNode::SetModifier(TypeModifier modifier)
{
    _TypeModifier = modifier;
}

TypeInfo *TypeNode::GetTypeInfo()
{
    ModuleDefinitionNode *pScope = GetTypedParent<ModuleDefinitionNode>();
    //printf("Scope for typeNode is %p\n", pScope);

    if (_pTypeInfo == nullptr)
    {
        switch (_typeClass)
        {
        case TypeClass::Register:
            _pTypeInfo = GetContext()->GetTypeCollection()->GetRegisterType(_extra);
            break;

        case TypeClass::Void:
            _pTypeInfo = GetContext()->GetTypeCollection()->GetVoidType();
            break;

        case TypeClass::Clock:
            _pTypeInfo = GetContext()->GetTypeCollection()->GetClockType();
            break;

        case TypeClass::Unknown:
        {
            if (GetChildCount() == 1)
            {
                ConstantNode* pConstantNode = dynamic_cast<ConstantNode*>(GetChild(0));
                if (pConstantNode != nullptr)
                {
                    _pTypeInfo = GetContext()->GetTypeCollection()->GetRegisterType(pConstantNode->GetUInt());
                }
                else
                {
                    IdentifierNode* pIdentifierNode = dynamic_cast<IdentifierNode*>(GetChild(0));
                    int symIndex = pIdentifierNode->GetSymbolIndex();
                    if (pIdentifierNode != nullptr)
                    {
                        _pTypeInfo = GetContext()->GetTypeCollection()->GetGenericType(symIndex, pScope);
                    }
                    else
                    {
                        throw "Generic type needs to be based on constant or identifier";
                    }
                }
            }
            else
            {
                _pTypeInfo = GetContext()->GetTypeCollection()->GetEnumType(_extra);
                if (_pTypeInfo == nullptr)
                {
                    _pTypeInfo = GetContext()->GetTypeCollection()->GetStructType(_extra);
                    if (_pTypeInfo == nullptr)
                    {
                        _pTypeInfo = GetContext()->GetTypeCollection()->GetGenericType(_extra, pScope);    
                        if (_pTypeInfo == nullptr)
                        {
                            _pTypeInfo = GetContext()->GetTypeCollection()->GetModuleType(_extra);
                            if (_pTypeInfo == nullptr)
                            {
                                std::stringstream sstr;
                                sstr << "Failed to find struct, enum, or generic type with name " << GetContext()->GetSymbolString(_extra);
                                static std::string error = sstr.str();
            
                                GetContext()->ReportError(GetLocation(), sstr.str().c_str());    
                            }
                            else
                            {
                                _typeClass = TypeClass::Module;
                            }
                        }
                        else
                        {
                            _typeClass = TypeClass::Generic;
                        }
                    }
                    else
                    {
                        _typeClass = TypeClass::Struct;
                    }
                }
                else
                {
                    _typeClass = TypeClass::Enum;
                }
            }

            break;
        }

        case TypeClass::Enum:
        case TypeClass::Generic:
        case TypeClass::Array:
        case TypeClass::Static:
        case TypeClass::Struct:
        case TypeClass::Module:
            throw "Not expected here";
            break;
        }
    }

    return _pTypeInfo;
}

void TypeNode::VerifyNodeImpl()
{
}
