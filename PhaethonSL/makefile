PSLcc: lex.yy.c PSL.tab.c PSLGlobal.cpp ASTNode.h ASTTree.h
	clang++ -std=c++11 lex.yy.c PSL.tab.c PSLGlobal.cpp -o PSLcc

lex.yy.c: PSL.l
	flex PSL.l

PSL.tab.c: PSL.y
	bison -d PSL.y
