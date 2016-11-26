#include "AsmObjWriter.h"
#include "ObjArgument.h"
#include "../PhaethonISA/InstructionData.h"
#include <stdio.h>
#include <sstream>

std::string AsmObjWriter::GetOpString(const ObjArgument &objArg) const
{
    std::stringstream result;

    switch (objArg._argType)
    {
    case OperandType::Constant:
        // PASM just uses the constant simply
        result << objArg._value;
        break;

    case OperandType::Register:
        // Return the register syntax
        result << "r" << objArg._value;
        break;

    case OperandType::DerefConstant:
        // The assembler uses C-like syntax for getting addresses of things
        result << "&" << objArg._memberName;
        break;

    case OperandType::DerefRegisterOffset:
        // C++ syntax for members of things
        result << "r" << objArg._value << "->" << objArg._typeName << "::" << objArg._memberName;
        break;

    default:
        throw "Unknown result type";
    }

    return result.str();
}

void AsmObjWriter::OutputInstruction(
    OpCodes::Enum opCode,
    ObjArgument *args
    )
{
    for (int i = 0; i < OpCodeData::s_dataCount; i++)
    {
        if (OpCodeData::s_data[i].opCode == opCode)
        {
            // Subtract 1 to account for Unknown
            int index = OpCodeData::s_data[i].instr - 1;

            printf(
                "%s %s, %s\n",
                InstructionData::s_data[index].pszName,
                GetOpString(args[0]).c_str(),
                GetOpString(args[1]).c_str()
                );
            
            return;
        }
    }

    throw "Unknown instruction";
}
