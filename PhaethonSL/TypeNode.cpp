#include "TypeNode.h"
#include "PSLCompilerContext.h"
#include "BasicTypeInfo.h"
#include "StructTypeInfo.h"
#include "FunctionDeclaratorNode.h"
#include <sstream>

TypeNode::TypeNode(PSLCompilerContext *pContext, TypeClass typeClass, int type) : ASTNode(pContext)
{
    _typeClass = typeClass;
    _pBaseTypeNode = nullptr;
    _typeOrSymbol = type;
    _pTypeInfo = nullptr;
}

TypeNode::TypeNode(PSLCompilerContext *pContext, ASTNode *pNode) : ASTNode(pContext)
{
    _typeClass = TypeClass::Pointer;
    _pBaseTypeNode = dynamic_cast<TypeNode *>(pNode);
    _typeOrSymbol = -1;
    _pTypeInfo = nullptr;
}

TypeInfo *TypeNode::GetTypeInfo()
{
    FunctionDeclaratorNode *pScope = GetTypedParent<FunctionDeclaratorNode>();

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

                // Wat
                //std::stringstream sstr;
                //sstr << "Failed to find struct type with name " << GetContext()->_symbols[_typeOrSymbol];
                //static std::string error = sstr.str();

                //throw error.c_str();
            }
            break;

        case TypeClass::Pointer:
            _pTypeInfo = GetContext()->_typeCollection.GetPointerType(_pBaseTypeNode->GetTypeInfo());

            if (_pTypeInfo == nullptr)
            {
                throw "That pointer type was a fail";
            }
            break;

        case TypeClass::Generic:
            _pTypeInfo = GetContext()->_typeCollection.GetGenericType(_typeOrSymbol, pScope);

            if (_pTypeInfo == nullptr)
            {
                throw "That pointer type was a fail";
            }
            break;
        
        }
    }

    return _pTypeInfo;
}

void TypeNode::VerifyNodeImpl()
{
}
