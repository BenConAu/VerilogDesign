#include "PhaethonAsmLib.h"
#include "PhaethonAsm.tab.h"
#include <iostream>

void OutputBytes(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4)
{
	printf("%02x %02x %02x %02x\n", b1, b2, b3, b4);
}

void OutputInstruction(Instructions::Enum instr, Argument a1, Argument a2)
{
	switch(instr)
	{
		case Instructions::Mov:
			unsigned char opCode;
			if (a1._type == Argument::Register && a2._type == Argument::Constant)
			{
				opCode = 1;
			}
			else if (a1._type == Argument::Register && a2._type == Argument::Address)
			{
				opCode = 2;
			}
			else if (a1._type == Argument::Register && a2._type == Argument::Register)
			{
				opCode = 3;
			}
			else if (a1._type == Argument::Address && a2._type == Argument::Register)
			{
				opCode = 4;
				Argument t = a1;
				a1 = a2;
				a2 = t;
			}

			OutputBytes(opCode, a1._value, a2._value, 0);				
			break;

		case Instructions::Fadd:
        	if (a1._type != Argument::Register && a2._type != Argument::Register)
        	{
        		std::cout << "Invalid argument for fconv" << std::endl;
        	}

        	OutputBytes(20, a1._value, a2._value, 0);
        	break;

		default:
			std::cout << "Unknown instruction" << std::endl;
	}
}

void OutputInstruction(Instructions::Enum instr, Argument a1)
{
	switch(instr)
	{
        case Instructions::Fconv:
        	if (a1._type != Argument::Register)
        	{
        		std::cout << "Invalid argument for fconv" << std::endl;
        	}

        	OutputBytes(22, a1._value, 0, 0);
        	break;

		default:
			std::cout << "Unknown instruction" << std::endl;
	}
}
