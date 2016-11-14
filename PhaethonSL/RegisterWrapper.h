#pragma once

#include "ExpressionResult.h"

class PSLCompilerContext;
class RegisterCollection;

class RegisterWrapper
{
public:
    RegisterWrapper(
        PSLCompilerContext* pContext,
        RegisterCollection* pCollection, 
        ExpressionResult result
        );

    const ExpressionResult& GetWrapped();

    ~RegisterWrapper();

private:
    bool _fAllocated;
    ExpressionResult _converted;
    PSLCompilerContext* _pContext;
    RegisterCollection* _pCollection;
};
