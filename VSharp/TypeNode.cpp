#include "TypeNode.h"
#include "PSLCompilerContext.h"
#include "BasicTypeInfo.h"
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
    _typeOrSymbol = type;
    _location = location;
    _pTypeInfo = nullptr;
}

TypeNode::TypeNode(
    PSLCompilerContext *pContext, 
    const YYLTYPE &location,
    ASTNode *pNode) : ASTNode(pContext)
{
    _typeClass = TypeClass::Pointer;
    _typeOrSymbol = -1;
    _location = location;
    _pTypeInfo = nullptr;
    
    AddNode(pNode);
}

TypeInfo *TypeNode::GetTypeInfo()
{
    ModuleDeclaratorNode *pScope = GetTypedParent<ModuleDeclaratorNode>();
    //printf("Scope for typeNode is %p\n", pScope);

    if (_pTypeInfo == nullptr)
    {
        switch (_typeClass)
        {
        case TypeClass::Basic:
            _pTypeInfo = GetContext()->_typeCollection.GetBasicType(_typeOrSymbol);

            if (_pTypeInfo == nullptr)
            {
                throw "That basic type was a fail";
            }
            break;

        case TypeClass::Struct:
            _pTypeInfo = GetContext()->_typeCollection.GetStructType(_typeOrSymbol);

            if (_pTypeInfo == nullptr)
            {
                // It was a good guess - perhaps it was a generic?
                _pTypeInfo = GetContext()->_typeCollection.GetGenericType(_typeOrSymbol, pScope);
                _typeClass = TypeClass::Generic;

                if (_pTypeInfo == nullptr)
                {
                    std::stringstream sstr;
                    sstr << "Failed to find struct or generic type with name " << GetContext()->_symbols[_typeOrSymbol];
                    static std::string error = sstr.str();

                    GetContext()->ReportError(_location, sstr.str().c_str());
                }
            }
            break;

        case TypeClass::Pointer:
            _pTypeInfo = GetContext()->_typeCollection.GetPointerType(dynamic_cast<TypeNode *>(GetChild(0))->GetTypeInfo());

            if (_pTypeInfo == nullptr)
            {
                throw "That pointer type was a fail";
            }
            break;

        case TypeClass::Generic:
        case TypeClass::Array:
            throw "Not expected here";
            break;
        }
    }

    return _pTypeInfo;
}

void TypeNode::VerifyNodeImpl()
{
}
