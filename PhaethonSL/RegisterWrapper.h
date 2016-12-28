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
        ExpressionResult* pResult
        );

    const Operand &GetWrapped() { return _converted; }

    ~RegisterWrapper();

  private:
    bool _fAllocated;
    Operand _converted;
    PSLCompilerContext *_pContext;
    RegisterCollection *_pCollection;
};
