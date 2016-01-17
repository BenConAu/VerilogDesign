PhaethonAsm: lex.yy.c PhaethonAsm.tab.c PhaethonAsmLib.cpp PhaethonAsmTypes.h
	g++ lex.yy.c PhaethonAsm.tab.c PhaethonAsmLib.cpp -o PhaethonAsm

lex.yy.c: PhaethonAsm.l
	flex PhaethonAsm.l

PhaethonAsm.tab.c: PhaethonAsm.y
	bison -d PhaethonAsm.y
