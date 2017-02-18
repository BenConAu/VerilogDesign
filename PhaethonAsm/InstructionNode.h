#pragma once

#include "AssemblerNode.h"
#include "../PhaethonISA/InstructionData.h"
#include "../PhaethonObjWriter/ObjWriter.h"
#include "PhaethonAsmLib.h"
#include <iostream>
#include <vector>

class InstructionNode : public AssemblerNode
{
public:
    static int GetCodeSize() { return s_codeSize; }

    void StoreInstruction(Instructions::Enum instr, Argument a1, Argument a2, Argument a3);
    void ResolveSymbols();
    void OutputInstruction();

public:
    static int s_codeSize;

private:
    OpCode _opCode;
    Argument _args[3];
};
