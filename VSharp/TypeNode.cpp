#include "TypeNode.h"
#include "VSharpCompilerContext.h"
#include "RegisterTypeInfo.h"
#include "StructTypeInfo.h"
#include "ModuleDefinitionNode.h"
#include <sstream>

TypeNode::TypeNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    TypeClass typeClass,
    int type) : ASTNode(pContext, location)
{
    _typeClass = typeClass;
    _extra = type;
    _pTypeInfo = nullptr;
    _IsWire = false;
}

TypeNode::TypeNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    TypeClass typeClass) : ASTNode(pContext, location)
{
    _typeClass = typeClass;
    _extra = 0;
    _pTypeInfo = nullptr;
    _IsWire = false;
}

TypeNode::TypeNode(
    PSLCompilerContext *pContext, 
    const YYLTYPE &location,
    const UIntConstant &bitLength) : ASTNode(pContext, location)
{
    _typeClass = TypeClass::Register;
    _extra = bitLength._value;
    _pTypeInfo = nullptr;
    _IsWire = false;
}

void TypeNode::SetModifier(int symIndex)
{
    if (symIndex != WIRE_TOKEN)
    {
        throw "Unexpected modifier";
    }

    _IsWire = true;
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
