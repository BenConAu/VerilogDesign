PACodeGen: lex.yy.c PACodeGen.tab.c PACodeGenLib.cpp Operand.cpp Operand.h
	clang++ -std=c++11 lex.yy.c PACodeGen.tab.c PACodeGenLib.cpp Operand.cpp -o PACodeGen

lex.yy.c: PACodeGen.l
	flex PACodeGen.l

PACodeGen.tab.c: PACodeGen.y
	bison -d PACodeGen.y
