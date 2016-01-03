#include "PhaethonAsmLib.h"
#include "PhaethonAsm.tab.h"
#include <iostream>

void OutputInstruction(Instructions::Enum instr, Argument a1, Argument a2)
{
	switch(instr)
	{
		case Instructions::Mov:
			if (a1._type == Argument::Register && a2._type == Argument::Constant)
			{
				std::cout << 1 << ", " << a1._value << ", " << a2._value << ", 0" << std::endl;				
			}
			else if (a1._type == Argument::Register && a2._type == Argument::Address)
			{
				std::cout << 2 << ", " << a1._value << ", " << a2._value << ", 0" << std::endl;				
			}
			else if (a1._type == Argument::Register && a2._type == Argument::Register)
			{
				std::cout << 3 << ", " << a1._value << ", " << a2._value << ", 0" << std::endl;				
			}

			break;

		default:
			std::cout << "Unknown instruction" << std::endl;
	}
}
