PhaethonAsm: lex.yy.c PhaethonAsm.tab.c PhaethonAsmLib.cpp InstructionNode.h InstructionNode.cpp CodeGen/PhaethonOpCode.h CodeGen/PhaethonOpCode.cpp AssemblerNode.h AssemblerListNode.h StructDef.h DataSegmentDef.h Argument.cpp
	clang++ -std=c++11 lex.yy.c PhaethonAsm.tab.c PhaethonAsmLib.cpp Argument.cpp InstructionNode.cpp CodeGen/PhaethonOpCode.cpp -o PhaethonAsm

lex.yy.c: PhaethonAsm.l
	flex PhaethonAsm.l

PhaethonAsm.tab.c: PhaethonAsm.y
	bison -d PhaethonAsm.y
