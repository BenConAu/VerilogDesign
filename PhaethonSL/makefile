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
	   SmartRegister.cpp \
	   SmartRegister.h \
	   StructMember.h \
	   Operand.cpp \
	   Operand.h \
	   ../PhaethonObjWriter/ObjWriter.h \
	   ../PhaethonObjWriter/AsmObjWriter.cpp \
	   ../PhaethonObjWriter/AsmObjWriter.h \
	   ../PhaethonObjWriter/BinaryObjWriter.cpp \
	   ../PhaethonObjWriter/BinaryObjWriter.h \
  	   ../PhaethonISA/Generated/PhaethonOpCode.cpp \
  	   ../PhaethonISA/Generated/PhaethonOpCode.h \
	   FunctionDeclaratorNode.cpp \
	   FunctionDeclaratorNode.h \
	   FunctionParameterNode.cpp \
	   FunctionParameterNode.h \
	   FieldSelectionNode.cpp \
	   FieldSelectionNode.h \
	   MultiplyNode.h \
	   MultiplyNode.cpp
	clang++ -std=c++11 -g lex.yy.c \
	   ../PhaethonObjWriter/AsmObjWriter.cpp \
	   ../PhaethonObjWriter/BinaryObjWriter.cpp \
	   ../PhaethonISA/Generated/PhaethonOpCode.cpp \
	   PSL.tab.c \
	   AssignmentNode.cpp \
	   ConstantNode.cpp \
	   ExpressionResult.cpp \
	   FieldSelectionNode.cpp \
	   FunctionDeclaratorNode.cpp \
	   FunctionParameterNode.cpp \
	   IdentifierNode.cpp \
	   MultiplyNode.cpp \
	   Operand.cpp \
	   PSLCompiler.cpp \
	   PSLCompilerContext.cpp \
	   RegisterCollection.cpp \
	   RegisterWrapper.cpp \
	   SmartRegister.cpp \
	   StructDeclarationNode.cpp \
	   TypeNode.cpp \
	   TypeCollection.cpp \
	   VariableCollection.cpp \
	   VariableDeclarationNode.cpp \
	   VariableInfo.cpp \
	   StructSpecifierNode.cpp -o PSLcc

lex.yy.c: PSL.l
	flex --header-file=lex.h PSL.l

PSL.tab.c: PSL.y
	bison -d PSL.y
