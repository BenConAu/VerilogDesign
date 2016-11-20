PhaethonAsm: 			\
	lex.yy.c 			\
	PhaethonAsm.tab.c 	\
	PhaethonAsmLib.cpp	\
	InstructionNode.h 	\
	InstructionNode.cpp \
	../PhaethonISA/PhaethonOpCode.h \
	../PhaethonISA/PhaethonOpCode.cpp \
	AssemblerNode.h 	\
	AssemblerListNode.h \
	StructDef.h 		\
	DataSegmentDef.h 	\
	Argument.h 			\
	Argument.cpp 		\
	ArgumentBase.cpp 	\
	ArgumentBase.h
	clang++ -std=c++11 -Wno-deprecated-register \
	lex.yy.c \
	PhaethonAsm.tab.c \
	PhaethonAsmLib.cpp \
	Argument.cpp \
	ArgumentBase.cpp \
	InstructionNode.cpp \
	../PhaethonISA/PhaethonOpCode.cpp \
	-o PhaethonAsm

lex.yy.c: PhaethonAsm.l
	flex PhaethonAsm.l

PhaethonAsm.tab.c: PhaethonAsm.y
	bison -d PhaethonAsm.y
