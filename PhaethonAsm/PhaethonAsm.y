%{
#define YYDEBUG 1
#include <cstdio>
#include <iostream>
using namespace std;

#include "PhaethonAsmTypes.h"
#include "PhaethonAsmLib.h"

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

void yyerror(const char *s);
%}

// Bison fundamentally works by asking flex to get the next token, which it
// returns as an object of type "yystype".  But tokens could be of any
// arbitrary data type!  So we deal with that in Bison by defining a C union
// holding each of the types of tokens that Flex could return, and have Bison
// use that union instead of "int" for the definition of "yystype":
%union {
	int intVal;
	Instructions::Enum instrIndex;
	int regIndex;
	int symIndex;
	Argument arg;
	int structIndex;
}

// define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the union:
%token <intVal> INT_TOKEN
%token <instrIndex> INSTR_TOKEN_1
%token <instrIndex> INSTR_TOKEN_2
%token <instrIndex> INSTR_TOKEN_3
%token <regIndex> REG_TOKEN
%token COMMA_TOKEN
%token ADDR_LEFT
%token ADDR_RIGHT
%token COLON_TOKEN
%token STRUCT_TOKEN
%token ENDS_TOKEN
%token LEFT_PAREN_TOKEN
%token RIGHT_PAREN_TOKEN
%token MEMBEROF_TOKEN
%token DEREF_TOKEN
%token <symIndex> SYMBOL_TOKEN
%type <arg> argument
%type <structIndex> struct_member_list

%%

assembler_unit_list:
      assembler_unit assembler_unit_list
    | assembler_unit
    ;

assembler_unit:
      instruction
    | label
    | struct_definition
    ;

struct_definition:
      STRUCT_TOKEN SYMBOL_TOKEN struct_member_list ENDS_TOKEN          { StructDef::SetStructName($3, $2); }
    ;

struct_member_list:
      SYMBOL_TOKEN struct_member_list                                  { $$ = StructDef::AddMember($2, $1); }
    | SYMBOL_TOKEN                                                     { $$ = StructDef::Construct($1); }
    ;

instruction:
      INSTR_TOKEN_3 argument COMMA_TOKEN argument COMMA_TOKEN argument { OutputInstruction($1, $2, $4, $6); }
	| INSTR_TOKEN_2 argument COMMA_TOKEN argument DEREF_TOKEN argument { OutputInstruction($1, $2, $4, $6); }
	| INSTR_TOKEN_2 argument DEREF_TOKEN argument COMMA_TOKEN argument { OutputInstruction($1, $2, $4, $6); }
    | INSTR_TOKEN_2 argument COMMA_TOKEN argument                      { OutputInstruction($1, $2, $4, Argument::ConstructNone()); }
    | INSTR_TOKEN_1 argument                                           {
    	OutputInstruction($1, $2, Argument::ConstructNone(), Argument::ConstructNone());
    }
    ;

argument:
      REG_TOKEN                                                        { $$ = Argument::Construct(Argument::Register, $1); }
	| ADDR_LEFT INT_TOKEN ADDR_RIGHT                                   { $$ = Argument::Construct(Argument::ConstAddress, $2);  }
	| ADDR_LEFT REG_TOKEN ADDR_RIGHT                                   { $$ = Argument::Construct(Argument::RegAddress, $2);  }
    | INT_TOKEN                                                        { $$ = Argument::Construct(Argument::Constant, $1); }
	| SYMBOL_TOKEN MEMBEROF_TOKEN SYMBOL_TOKEN                         { $$ = Argument::Construct(Argument::Constant, StructDef::CalcOffset($1, $3)); }
    | SYMBOL_TOKEN                                                     { $$ = Argument::Construct(Argument::ConstAddress, GetSymbolAddress($1)); }
    ;

label:
      SYMBOL_TOKEN COLON_TOKEN                                         { AddLabel($1); }

%%

int main(int, char**) {
	//yydebug = 1;
	// open a file handle to a particular file:
	FILE *myfile = fopen("test.asm", "r");
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

}

void yyerror(const char *s) {
	cout << "EEK, parse error!  Message: " << s << endl;
	// might as well halt now:
	exit(-1);
}