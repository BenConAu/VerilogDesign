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
	DataSegmentDef.cpp  \
	Argument.h 			\
	Argument.cpp 		\
	../PhaethonObjWriter/ObjArgument.h       	\
	../PhaethonObjWriter/ObjWriter.h         	\
	../PhaethonObjWriter/ObjWriter.cpp       	\
	../PhaethonISA/Generated/PhaethonOpCode.h 	\
	../PhaethonISA/Generated/PhaethonOpCode.cpp \
	../PhaethonISA/OperandType.h 				\
	../PhaethonISA/OperandType.cpp 				\
	../PhaethonISA/InstructionData.h
	clang++ -std=c++11 -Wno-deprecated-register \
	lex.yy.c 			\
	PhaethonAsm.tab.c 	\
	PhaethonAsmLib.cpp 	\
	Argument.cpp 		\
	DataSegmentDef.cpp  \
	InstructionNode.cpp \
	../PhaethonObjWriter/ObjWriter.cpp       	\
	../PhaethonISA/OperandType.cpp 				\
	../PhaethonISA/Generated/PhaethonOpCode.cpp \
	-o PhaethonAsm

lex.yy.c: PhaethonAsm.l
	flex PhaethonAsm.l

PhaethonAsm.tab.c: PhaethonAsm.y
	bison -d PhaethonAsm.y
