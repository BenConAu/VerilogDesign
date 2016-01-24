PACodeGen: lex.yy.c PACodeGen.tab.c PACodeGenLib.cpp ../Argument.cpp
	clang++ -std=c++11 lex.yy.c PACodeGen.tab.c PACodeGenLib.cpp ../Argument.cpp -o PACodeGen

lex.yy.c: PACodeGen.l
	flex PACodeGen.l

PACodeGen.tab.c: PACodeGen.y
	bison -d PACodeGen.y
