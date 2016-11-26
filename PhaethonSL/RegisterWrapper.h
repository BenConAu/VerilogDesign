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
        Operand result
        );

    const Operand &GetWrapped();

    ~RegisterWrapper();

  private:
    bool _fAllocated;
    Operand _converted;
    PSLCompilerContext *_pContext;
    RegisterCollection *_pCollection;
};
