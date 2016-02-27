PSLcc: lex.yy.c \
	   PSL.tab.c \
	   ASTNode.h \
	   ASTTree.h \
	   ConstantNode.cpp \
	   ConstantNode.h \
	   ExpressionNode.h \
	   RegisterCollection.cpp \
	   RegisterCollection.h \
	   VariableCollection.cpp \
	   VariableDeclarationNode.cpp \
	   VariableDeclarationNode.h \
	   PSLCompilerContext.cpp \
	   PSLCompiler.cpp \
	   TypeCollection.cpp \
	   TypeCollection.h \
	   StructDeclarationNode.cpp \
	   StructSpecifierNode.cpp \
	   TypeNode.cpp \
	   IdentifierNode.cpp \
	   IdentifierNode.h \
	   VariableInfo.cpp \
	   VariableInfo.h \
	   FieldSelectionNode.h
	clang++ -std=c++11 -g lex.yy.c \
	   PSL.tab.c \
	   ConstantNode.cpp \
	   PSLCompiler.cpp \
	   TypeNode.cpp \
	   IdentifierNode.cpp \
	   VariableCollection.cpp \
	   PSLCompilerContext.cpp \
	   RegisterCollection.cpp \
	   TypeCollection.cpp \
	   StructDeclarationNode.cpp \
	   VariableDeclarationNode.cpp \
	   VariableInfo.cpp \
	   StructSpecifierNode.cpp -o PSLcc

lex.yy.c: PSL.l
	flex --header-file=lex.h PSL.l

PSL.tab.c: PSL.y
	bison -d PSL.y
