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
	Argument arg;
}

// define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the union:
%token <intVal> INT_TOKEN
%token <instrIndex> INSTR_TOKEN_1
%token <instrIndex> INSTR_TOKEN_2
%token <regIndex> REG_TOKEN
%token COMMA_TOKEN
%token ADDR_LEFT
%token ADDR_RIGHT
%type <arg> argument

%%

instruction_list:
      instruction instruction_list
    | instruction
    ;

  instruction:
      INSTR_TOKEN_2 argument COMMA_TOKEN argument   { OutputInstruction($1, $2, $4); }
    | INSTR_TOKEN_1 argument                        { cout << "1 reg instruction" << endl; }
    ;

  argument:
      REG_TOKEN                                     { $$ = Argument::Construct(Argument::Register, $1); }
    | ADDR_LEFT INT_TOKEN ADDR_RIGHT                { $$ = Argument::Construct(Argument::Address, $2);  }
    | INT_TOKEN                                     { $$ = Argument::Construct(Argument::Constant, $1); }
    ;

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