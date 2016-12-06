#include "VariablePath.h"
#include "FunctionDeclaratorNode.h"

RegIndex VariablePath::EnsurePathRegister(FunctionDeclaratorNode* pScope)
{
    if (_regIndexMap.find(pScope) == _regIndexMap.end())
    {
        // Upon the first request for a register at a particular scope,
        // allocate the register.
        _regIndexMap[pScope] = pScope->GetRegCollection()->AllocateRegister();

        // If we have a memory variable then it needs to be loaded when first ensured
        if (_pVarInfo->GetLocationType() == LocationType::Memory)
        {
            // An operand that represents the variable
            Operand varOperand(_pVarInfo, pScope->GetContext());
            Operand regOperand(_regIndexMap[pScope]);

            // Spit out the code to load said register
            pScope->GetContext()->OutputMovInstruction(
                regOperand,
                varOperand);
        }
    }

    return _regIndexMap[pScope];
}

void VariablePath::ReserveRegister(FunctionDeclaratorNode* pScope, RegIndex index)
{
    // We are being told which register to use
    pScope->GetRegCollection()->ReserveRegister(index);
    _regIndexMap[pScope] = index;    
}