#include "TypeNode.h"
#include "VSharpCompilerContext.h"
#include "RegisterTypeInfo.h"
#include "StructTypeInfo.h"
#include "ModuleDeclaratorNode.h"
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
}

TypeNode::TypeNode(
    PSLCompilerContext *pContext,
    const YYLTYPE &location) : ASTNode(pContext)
{
    _typeClass = TypeClass::Void;
    _extra = 0;
    _location = location;
    _pTypeInfo = nullptr;
}

TypeNode::TypeNode(
    PSLCompilerContext *pContext, 
    const YYLTYPE &location,
    int bitLength) : ASTNode(pContext)
{
    _typeClass = TypeClass::Register;
    _extra = bitLength;
    _location = location;
    _pTypeInfo = nullptr;
}

TypeInfo *TypeNode::GetTypeInfo()
{
    ModuleDeclaratorNode *pScope = GetTypedParent<ModuleDeclaratorNode>();
    //printf("Scope for typeNode is %p\n", pScope);

    if (_pTypeInfo == nullptr)
    {
        switch (_typeClass)
        {
        case TypeClass::Register:
            _pTypeInfo = GetContext()->_typeCollection.GetRegisterType(_extra);
            break;

        case TypeClass::Struct:
            _pTypeInfo = GetContext()->_typeCollection.GetStructType(_extra);

            if (_pTypeInfo == nullptr)
            {
                // It was a good guess - perhaps it was a generic?
                _pTypeInfo = GetContext()->_typeCollection.GetGenericType(_extra, pScope);
                _typeClass = TypeClass::Generic;

                if (_pTypeInfo == nullptr)
                {
                    std::stringstream sstr;
                    sstr << "Failed to find struct or generic type with name " << GetContext()->_symbols[_extra];
                    static std::string error = sstr.str();

                    GetContext()->ReportError(_location, sstr.str().c_str());
                }
            }
            break;

        case TypeClass::Void:
            _pTypeInfo = GetContext()->_typeCollection.GetVoidType();
            break;

        case TypeClass::Unknown:
        {
            _pTypeInfo = GetContext()->_typeCollection.GetEnumType(_extra);
            if (_pTypeInfo == nullptr)
            {
                std::stringstream sstr;
                sstr << "Failed to find enum type with name " << GetContext()->_symbols[_extra];
                static std::string error = sstr.str();

                GetContext()->ReportError(_location, sstr.str().c_str());
            }
            break;
        }

        case TypeClass::Enum:
        case TypeClass::Generic:
        case TypeClass::Array:
        case TypeClass::Static:
            throw "Not expected here";
            break;
        }
    }

    return _pTypeInfo;
}

void TypeNode::VerifyNodeImpl()
{
}
