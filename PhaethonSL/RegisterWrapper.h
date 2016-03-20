#pragma once

#include "ExpressionResult.h"

class PSLCompilerContext;

class RegisterWrapper
{
public:
    RegisterWrapper(PSLCompilerContext* pContext, ExpressionResult result);

    const ExpressionResult& GetWrapped();

    ~RegisterWrapper();

private:
    bool _fAllocated;
    ExpressionResult _converted;
    PSLCompilerContext* _pContext;
};
