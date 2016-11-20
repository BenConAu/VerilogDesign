PhaethonAsm: 			\
	lex.yy.c 			\
	PhaethonAsm.tab.c 	\
	PhaethonAsmLib.cpp	\
	InstructionNode.h 	\
	InstructionNode.cpp \
	AssemblerNode.h 	\
	AssemblerListNode.h \
	StructDef.h 		\
	DataSegmentDef.h 	\
	Argument.h 			\
	Argument.cpp 		\
	../PhaethonISA/Generated/PhaethonOpCode.h 	\
	../PhaethonISA/Generated/PhaethonOpCode.cpp 	\
	../PhaethonISA/Operand.cpp 			\
	../PhaethonISA/Operand.h            \
	../PhaethonISA/InstructionData.h
	clang++ -std=c++11 -Wno-deprecated-register \
	lex.yy.c 			\
	PhaethonAsm.tab.c 	\
	PhaethonAsmLib.cpp 	\
	Argument.cpp 		\
	InstructionNode.cpp \
	../PhaethonISA/Operand.cpp 			\
	../PhaethonISA/Generated/PhaethonOpCode.cpp 	\
	-o PhaethonAsm

lex.yy.c: PhaethonAsm.l
	flex PhaethonAsm.l

PhaethonAsm.tab.c: PhaethonAsm.y
	bison -d PhaethonAsm.y
