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
    int type) : ASTNode(pContext)
{
    _typeClass = typeClass;
    _extra = type;
    _location = location;
    _pTypeInfo = nullptr;
    _IsWire = false;
}

TypeNode::TypeNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location,
    TypeClass typeClass) : ASTNode(pContext)
{
    _typeClass = typeClass;
    _extra = 0;
    _location = location;
    _pTypeInfo = nullptr;
    _IsWire = false;
}

TypeNode::TypeNode(
    PSLCompilerContext *pContext, 
    const YYLTYPE &location,
    const UIntConstant &bitLength) : ASTNode(pContext)
{
    _typeClass = TypeClass::Register;
    _extra = bitLength._value;
    _location = location;
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
            _pTypeInfo = GetContext()->_typeCollection.GetRegisterType(_extra);
            break;

        case TypeClass::Void:
            _pTypeInfo = GetContext()->_typeCollection.GetVoidType();
            break;

        case TypeClass::Clock:
            _pTypeInfo = GetContext()->_typeCollection.GetClockType();
            break;

        case TypeClass::Unknown:
        {
            _pTypeInfo = GetContext()->_typeCollection.GetEnumType(_extra);
            if (_pTypeInfo == nullptr)
            {
                _pTypeInfo = GetContext()->_typeCollection.GetStructType(_extra);
                if (_pTypeInfo == nullptr)
                {
                    // It was a good guess - perhaps it was a generic?
                    _pTypeInfo = GetContext()->_typeCollection.GetGenericType(_extra, pScope);
                    _typeClass = TypeClass::Generic;
    
                    if (_pTypeInfo == nullptr)
                    {
                        std::stringstream sstr;
                        sstr << "Failed to find struct, enum, or generic type with name " << GetContext()->_symbols[_extra];
                        static std::string error = sstr.str();
    
                        GetContext()->ReportError(_location, sstr.str().c_str());
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
            throw "Not expected here";
            break;
        }
    }

    return _pTypeInfo;
}

void TypeNode::VerifyNodeImpl()
{
}
