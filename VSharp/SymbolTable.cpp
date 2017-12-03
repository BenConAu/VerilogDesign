#include "SymbolTable.h"
#include "VariableDeclarationNode.h"
#include "VariableInfo.h"
#include "FunctionInfo.h"
#include "StateInfo.h"
#include "VSharp.tab.h"
#include "VSharpCompiler.h"
#include <sstream>

SymbolTable::SymbolTable(VSharpCompiler *pCompiler)
{
    _pCompiler = pCompiler;
}

void SymbolTable::AddBuiltin()
{
    FunctionInfo *pNewInfo = new FunctionInfo(
        _pCompiler, 
        _pCompiler->AddSymbol("__monitor"),
        _pCompiler->GetTypeCollection()->GetVoidType(),
        -1,
        "$monitor");
    _symbols.emplace(std::make_pair(pNewInfo->GetSymbolIndex(), std::unique_ptr<SymbolInfo>(pNewInfo)));

    pNewInfo = new FunctionInfo(
        _pCompiler, 
        _pCompiler->AddSymbol("__display"),
        _pCompiler->GetTypeCollection()->GetVoidType(),
        -1,
        "$display");
    _symbols.emplace(std::make_pair(pNewInfo->GetSymbolIndex(), std::unique_ptr<SymbolInfo>(pNewInfo)));

    pNewInfo = new FunctionInfo(
        _pCompiler, 
        _pCompiler->AddSymbol("__readmemh"),
        _pCompiler->GetTypeCollection()->GetVoidType(),
        -1,
        "$readmemh");
    _symbols.emplace(std::make_pair(pNewInfo->GetSymbolIndex(), std::unique_ptr<SymbolInfo>(pNewInfo)));

    pNewInfo = new FunctionInfo(
        _pCompiler, 
        _pCompiler->AddSymbol("__valueargs"),
        _pCompiler->GetTypeCollection()->GetRegisterType(1),
        -1,
        "$value$plusargs");
    _symbols.emplace(std::make_pair(pNewInfo->GetSymbolIndex(), std::unique_ptr<SymbolInfo>(pNewInfo)));

    VariableInfo *pVarInfo = new VariableInfo(
        _pCompiler,
        nullptr,
        _pCompiler->AddSymbol("__time"),
        VariableLocationType::Member,
        TypeModifier::None,
        _pCompiler->GetTypeCollection()->GetRegisterType(32));
    pVarInfo->SetNameOverride("$time");
    _symbols.emplace(std::make_pair(pVarInfo->GetSymbolIndex(), std::unique_ptr<SymbolInfo>(pVarInfo)));
}

VariableInfo *SymbolTable::AddVariable(
    ASTNode *pScope,
    int symIndex,
    VariableLocationType location,
    TypeModifier modifier,
    TypeInfo *pTypeInfo)
{
    for (auto iter = _symbols.lower_bound(symIndex); iter != _symbols.upper_bound(symIndex); iter++)
    {
        if (iter->second->GetScope() == pScope || iter->second->GetScope() == nullptr)
        {
            // Caller can decide how to report this error
            return nullptr;
        }
    }

    VariableInfo *pNewInfo = new VariableInfo(_pCompiler, pScope, symIndex, location, modifier, pTypeInfo);
    _symbols.emplace(std::make_pair(symIndex, std::unique_ptr<SymbolInfo>(pNewInfo)));
    return pNewInfo;
}

FunctionInfo *SymbolTable::AddFunction(
    FunctionDeclaratorNode *pFuncDecl,
    int symIndex,
    UIntConstant* pConstant)
{
    std::vector<FunctionInfo*> Functions;
    GetSymbols(symIndex, nullptr, Functions);

    // See if we are updating a forward declaration
    for (size_t i = 0; i < Functions.size(); i++)
    {
        if (Functions[i]->GetUIntConstant() == nullptr)
        {
            if (pConstant == nullptr)
            {
                // We are adding a generic version or non-generic function but it was forward declared
                if (Functions[i]->GetFunctionDeclarator() == nullptr)
                {
                    // If somebody forward declares again, then nothing to do
                    if (pFuncDecl != nullptr)
                    {
                        // Fine, update now
                        Functions[i]->UpdateInfo(pFuncDecl);

                        // We are done here
                        return Functions[i];
                    }
                }
                else
                {
                    throw "Cannot define functions twice - this needs to be an error";
                }
            }
        }
        else
        {
            if (pConstant != nullptr && pConstant == Functions[i]->GetUIntConstant())
            {
                // We are adding a specialized version that was forward declared
                throw "Forward declaration of specialized generic functions not supported";
            }
        }
    }

    FunctionInfo *pNewInfo = new FunctionInfo(_pCompiler, pFuncDecl, symIndex, pConstant);
    _symbols.emplace(std::make_pair(symIndex, std::unique_ptr<SymbolInfo>(pNewInfo)));

    // If we are adding a specialized function without adding the generic first, then
    // forward declare the generic version now. Otherwise the function lookup won't
    // work when somebody tries to call the specific version either.
    if (Functions.size() == 0 && pConstant != nullptr)
    {
        pNewInfo = new FunctionInfo(_pCompiler, nullptr, symIndex, nullptr);
        _symbols.emplace(std::make_pair(symIndex, std::unique_ptr<SymbolInfo>(pNewInfo)));
    }

    return pNewInfo;
}

StateInfo *SymbolTable::AddState(
    int symIndex,
    ASTNode *pScope)
{
    for (auto iter = _symbols.lower_bound(symIndex); iter != _symbols.upper_bound(symIndex); iter++)
    {
        // Caller can decide how to report this error
        return nullptr;
    }

    StateInfo *pNewInfo = new StateInfo(_pCompiler, pScope, symIndex);
    _symbols.emplace(std::make_pair(symIndex, std::unique_ptr<SymbolInfo>(pNewInfo)));
    return pNewInfo;
}

void SymbolTable::GetFunctionVariables(
    ASTNode *pScope, 
    std::vector<VariableInfo*> &varList)
{
    for (auto iter = _symbols.begin(); iter != _symbols.end(); iter++)
    {
        VariableInfo *pVarInfo = dynamic_cast<VariableInfo*>(iter->second.get());

        if (pVarInfo != nullptr)
        {
            if ((pVarInfo->GetScope() == pScope || pVarInfo->GetScope() == nullptr) && 
                pVarInfo->GetTypeInfo()->GetTypeClass() == TypeClass::Struct)
            {
                //printf("Adding variable %s with type %d\n", pVarInfo->GetSymbol(), pVarInfo->GetTypeInfo()->GetTypeClass());
                varList.push_back(pVarInfo);
            }
        }
    }
}