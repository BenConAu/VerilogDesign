PSLcc: lex.yy.c \
	   PSL.tab.c \
	   ASTNode.h \
	   ASTTree.h \
	   RegisterCollection.h \
	   RegisterCollection.cpp \
	   VariableCollection.cpp \
	   VariableDeclarationNode.h \
	   PSLCompilerContext.cpp \
	   TypeCollection.cpp \
	   StructDeclarationNode.cpp \
	   StructSpecifierNode.cpp \
	   TypeNode.cpp
	clang++ -std=c++11 -g lex.yy.c \
	   PSL.tab.c \
	   TypeNode.cpp \
	   VariableCollection.cpp \
	   PSLCompilerContext.cpp \
	   RegisterCollection.cpp \
	   TypeCollection.cpp \
	   StructDeclarationNode.cpp \
	   StructSpecifierNode.cpp -o PSLcc

lex.yy.c: PSL.l
	flex --header-file=lex.h PSL.l

PSL.tab.c: PSL.y
	bison -d PSL.y
