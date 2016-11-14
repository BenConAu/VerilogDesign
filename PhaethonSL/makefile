PSLcc: lex.yy.c \
	   PSL.tab.c \
	   ASTNode.h \
	   ASTTree.h \
	   AssignmentNode.cpp \
	   AssignmentNode.h \
	   ConstantNode.cpp \
	   ConstantNode.h \
	   ExpressionNode.h \
	   RegisterCollection.cpp \
	   RegisterCollection.h \
	   VariableCollection.cpp \
	   VariableDeclarationNode.cpp \
	   VariableDeclarationNode.h \
	   PSLCompilerContext.cpp \
	   PSLCompilerContext.h \
	   PSLCompiler.cpp \
	   TypeCollection.cpp \
	   TypeCollection.h \
	   StructDeclarationNode.cpp \
	   StructSpecifierNode.cpp \
	   TypeNode.cpp \
	   IdentifierNode.cpp \
	   IdentifierNode.h \
	   ExpressionResult.cpp \
	   ExpressionResult.h \
	   RegisterWrapper.cpp \
	   RegisterWrapper.h \
	   VariableInfo.cpp \
	   VariableInfo.h \
	   StructMember.h \
	   FunctionDeclaratorNode.cpp \
	   FunctionDeclaratorNode.h \
	   FunctionParameterNode.cpp \
	   FunctionParameterNode.h \
	   FieldSelectionNode.cpp \
	   FieldSelectionNode.h \
	   MultiplyNode.h \
	   MultiplyNode.cpp
	clang++ -std=c++11 -g lex.yy.c \
	   PSL.tab.c \
	   ConstantNode.cpp \
	   AssignmentNode.cpp \
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
	   ExpressionResult.cpp \
	   RegisterWrapper.cpp \
	   FieldSelectionNode.cpp \
	   FunctionParameterNode.cpp \
	   MultiplyNode.cpp \
	   FunctionDeclaratorNode.cpp \
	   StructSpecifierNode.cpp -o PSLcc

lex.yy.c: PSL.l
	flex --header-file=lex.h PSL.l

PSL.tab.c: PSL.y
	bison -d PSL.y
