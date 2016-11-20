%{
#define YYDEBUG 1
#include <cstdio>
#include <iostream>
#include "PACodeGenLib.h"
#include "../PhaethonAsm/Operand.h"

using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

void yyerror(const char *s);
%}

%union
{
    int symIndex;
    int flags;
    OperandType::Enum opType;
    OperandModifier::Enum modType;
    Operand argType;
}

%token <symIndex> SYMBOL_TOKEN
%token <opType> REGISTER_TOKEN
%token <opType> CONSTANT_TOKEN
%token <opType> NONE_TOKEN
%token OFFSET_TOKEN
%token DEREF_TOKEN
%token ADDRESSOF_TOKEN
%token COLON_TOKEN
%token <flags> RAM_TOKEN
%token <flags> NOFLAGS_TOKEN
%type <argType> argument
%type <opType> operandType
%type <modType> modifierType
%type <flags> flag

%%

instruction_set:
      instruction instruction_set
    | instruction
    ;

instruction:
      SYMBOL_TOKEN argument argument argument flag                  { StoreInstruction($1, $2, $3, $4, $5); }
    ;

flag:
      NOFLAGS_TOKEN                                                 { $$ = 0; }
    | RAM_TOKEN                                                     { $$ = 1; }
    ;

argument:
      operandType                                                   { $$ = Operand::Construct($1, OperandModifier::None, false); }
    | operandType COLON_TOKEN OFFSET_TOKEN                          { $$ = Operand::Construct($1, OperandModifier::None, true); }
    | modifierType COLON_TOKEN operandType                          { $$ = Operand::Construct($3, $1, false); }
    | modifierType COLON_TOKEN operandType COLON_TOKEN OFFSET_TOKEN { $$ = Operand::Construct($3, $1, true); }
    ;

operandType:
      REGISTER_TOKEN                                                { $$ = OperandType::Register; }
    | CONSTANT_TOKEN                                                { $$ = OperandType::Constant; }
    | NONE_TOKEN                                                    { $$ = OperandType::None; }
    ;

modifierType:
      DEREF_TOKEN                                                   { $$ = OperandModifier::Deref; }
    | ADDRESSOF_TOKEN                                               { $$ = OperandModifier::AddressOf; }
    ;

%%
int main(int, char**) {
	//yydebug = 1;
	// open a file handle to a particular file:
	FILE *myfile = fopen("InstructionSet.def", "r");
	// make sure it is valid:
	if (!myfile) {
		cout << "I can't open a.snazzle.file!" << endl;
		return -1;
	}
	// set flex to read from it instead of defaulting to STDIN:
	yyin = myfile;

	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));

    OutputInstructions();

}
void yyerror(const char *s) {
	cout << "EEK, parse error!  Message: " << s << endl;
	// might as well halt now:
	exit(-1);
}
