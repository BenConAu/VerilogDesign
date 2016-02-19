PSLcc: lex.yy.c PSL.tab.c PSLGlobal.cpp ASTNode.h ASTTree.h RegisterCollection.h VariableCollection.cpp VariableDeclarationNode.h
	clang++ -std=c++11 lex.yy.c PSL.tab.c PSLGlobal.cpp VariableCollection.cpp -o PSLcc

lex.yy.c: PSL.l
	flex --header-file=lex.h PSL.l

PSL.tab.c: PSL.y
	bison -d PSL.y
