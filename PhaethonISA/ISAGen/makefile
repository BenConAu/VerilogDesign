ISAGen: \
	lex.yy.c \
	PACodeGen.tab.c \
	PACodeGenLib.cpp \
	../ISAOperand.cpp \
	../ISAOperand.h
	clang++ -std=c++11 -Wno-deprecated-register \
	lex.yy.c \
	PACodeGen.tab.c \
	PACodeGenLib.cpp \
	../ISAOperand.cpp \
	-o ISAGen

lex.yy.c: PACodeGen.l
	flex PACodeGen.l

PACodeGen.tab.c: PACodeGen.y
	bison -d PACodeGen.y
