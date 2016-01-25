%{
#define YYDEBUG 1
#include <cstdio>
#include <iostream>
#include "PACodeGenLib.h"
#include "../ArgumentBase.h"

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
    int argIndex;
    int flags;
}

%token <symIndex> SYMBOL_TOKEN
%token <argIndex> REGISTER_TOKEN
%token <argIndex> REGADDRESS_TOKEN
%token <argIndex> CONSTANT_TOKEN
%token <argIndex> CONSTADDRESS_TOKEN
%token <argIndex> NONE_TOKEN
%token <flags> RAM_TOKEN
%token <flags> NOFLAGS_TOKEN
%type <argIndex> argument
%type <flags> flag

%%

instruction_set:
      instruction instruction_set
    | instruction
    ;

  instruction:
      SYMBOL_TOKEN argument argument argument flag  { StoreInstruction($1, $2, $3, $4, $5); }
    ;

  flag:
      NOFLAGS_TOKEN                                 { $$ = 0; }
    | RAM_TOKEN                                     { $$ = 1; }
    ;

  argument:
      REGISTER_TOKEN                                { $$ = ArgumentBase::Register; }
    | REGADDRESS_TOKEN                              { $$ = ArgumentBase::RegAddress; }
    | CONSTANT_TOKEN                                { $$ = ArgumentBase::Constant; }
    | CONSTADDRESS_TOKEN                            { $$ = ArgumentBase::ConstAddress; }
    | NONE_TOKEN                                    { $$ = ArgumentBase::None; }
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
