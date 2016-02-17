%{
#define YYDEBUG 1
#include <cstdio>
#include <iostream>
using namespace std;

#include "PSLGlobal.h"
#include "ASTNode.h"

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

void yyerror(const char *s);
%}

%union {
	int intVal;
    float floatVal;
	int symIndex;
    ASTNode* pNode;
}

%token <intVal> INTCONSTANT
%token <floatVal> FLOATCONSTANT
%token SEMICOLON
%token EQUAL
%token STAR
%token <symIndex> IDENTIFIER
%type <pNode> variable_identifier
%type <pNode> primary_expression
%type <pNode> postfix_expression
%type <pNode> multiplicative_expression
%type <pNode> unary_expression
%type <pNode> assignment_expression
%type <pNode> expression_statement
%type <pNode> expression
%type <pNode> statement
%type <pNode> statement_list

%%

translation_unit:
      statement_list                                                { ProcessStatementList($1); }
    ;

statement_list:
      statement                                                     { $$ = new StatementListNode($1); }
    | statement_list statement                                      { $$ = $1; $$->AddNode($2); }
    ;

statement:
      expression_statement                                          { $$ = $1; }
    ;

expression_statement:
      expression SEMICOLON                                          { $$ = $1; }
    ;

expression:
      assignment_expression                                         { $$ = $1; }
    ;

assignment_expression:
      multiplicative_expression                                     { $$ = $1; }
    | unary_expression assignment_operator assignment_expression    { $$ = new AssignmentNode($1, $3); }
    ;

multiplicative_expression:
      unary_expression                                              { $$ = $1; }
    | multiplicative_expression STAR unary_expression               { $$ = new MultiplyNode($1, $3); }
    ;

unary_expression:
      postfix_expression                                            { $$ = $1; }
    ;

assignment_operator:
      EQUAL
    ;

postfix_expression:
      primary_expression                                            { $$ = $1; }
    ;

primary_expression:
      variable_identifier                                           { $$ = $1; }
    | INTCONSTANT                                                   { $$ = new ConstantNode($1); }
    | FLOATCONSTANT                                                 { $$ = new ConstantNode($1); }
    ;

variable_identifier:
      IDENTIFIER                                                    { $$ = new IdentifierNode($1); }
    ;

%%

int main(int, char**) {
	//yydebug = 1;
	// open a file handle to a particular file:
	FILE *myfile = fopen("test.psl", "r");
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
