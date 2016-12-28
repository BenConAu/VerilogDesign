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
        if (objArg._memberName.length() != 0)
        {
            // The constant was derived from a variable, use that
            result << "&" << objArg._memberName;
        }
        else if (objArg._label.length() != 0)
        {
            result << "@" << objArg._label;
        }
        else
        {
            // If no symbol is given, then we can just go with the constant
            result << objArg._value;
        }
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
        if (objArg._memberName.length() != 0)
        {
            // C++ syntax for members of things
            result << "r" << objArg._value << "->" << objArg._typeName << "::" << objArg._memberName;
        }
        else
        {
            // Syntax for array lookup
            result << "[r" << objArg._value << ":sizeof(" << objArg._typeName << ")]";
        }
        break;

    default:
        throw "Unknown result type";
    }

    return result.str();
}

void AsmObjWriter::OutputInstruction(
    OpCodes::Enum opCode,
    ObjArgument *args)
{
    for (int i = 0; i < OpCodeData::s_dataCount; i++)
    {
        if (OpCodeData::s_data[i].opCode == opCode)
        {
            // Subtract 1 to account for Unknown
            int index = OpCodeData::s_data[i].instr - 1;

            switch (OpCodeData::s_data[i].OperandCount())
            {
            case 0:
                fprintf(
                    _pOutFile,
                    "%s\n",
                    InstructionData::s_data[index].pszName);
                break;

            case 1:
                fprintf(
                    _pOutFile,
                    "%s %s\n",
                    InstructionData::s_data[index].pszName,
                    GetOpString(args[0]).c_str());
                break;

            case 2:
                fprintf(
                    _pOutFile,
                    "%s %s, %s\n",
                    InstructionData::s_data[index].pszName,
                    GetOpString(args[0]).c_str(),
                    GetOpString(args[1]).c_str());
                break;

            case 3:
                fprintf(
                    _pOutFile,
                    "%s %s, %s, %s\n",
                    InstructionData::s_data[index].pszName,
                    GetOpString(args[0]).c_str(),
                    GetOpString(args[1]).c_str(),
                    GetOpString(args[2]).c_str());
                break;

            default:
                throw "Unsupported arg count";
            }

            return;
        }
    }

    throw "Unknown instruction";
}

void AsmObjWriter::OutputLabel(const char *pszLabel)
{
    fprintf(_pOutFile, "%s:\n", pszLabel);
}