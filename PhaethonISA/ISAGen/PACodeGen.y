%{
#define YYDEBUG 1
#include <cstdio>
#include <iostream>
#include "PACodeGenLib.h"
#include "../ISAOperand.h"

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
    OperandType opType;
    ISAOperand argType;
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
      operandType                                                   { $$ = ISAOperand::Construct($1, false); }
    | DEREF_TOKEN COLON_TOKEN operandType                           { $$ = ISAOperand::Construct($3, true); }
    | DEREF_TOKEN COLON_TOKEN REGISTER_TOKEN COLON_TOKEN OFFSET_TOKEN { $$ = ISAOperand::DerefRegisterOffset(); }
    ;

operandType:
      REGISTER_TOKEN                                                { $$ = OperandType::Register; }
    | CONSTANT_TOKEN                                                { $$ = OperandType::Constant; }
    | NONE_TOKEN                                                    { $$ = OperandType::None; }
    ;

%%
int main(int, char**) {
	//yydebug = 1;
	// open a file handle to a particular file:
	FILE *myfile = fopen("InstructionSet.def", "r");
	// make sure it is valid:
	if (!myfile) 
    {
		cout << "I can't open InstructionSet.def!" << endl;
		return -1;
	}
	// set flex to read from it instead of defaulting to STDIN:
	yyin = myfile;

	// parse through the input until there is no more:
	do 
    {
		yyparse();
	} while (!feof(yyin));

    OutputInstructions();

}
void yyerror(const char *s) {
	cout << "EEK, parse error!  Message: " << s << endl;
	// might as well halt now:
	exit(-1);
}
