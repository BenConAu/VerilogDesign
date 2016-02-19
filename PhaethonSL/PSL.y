%{
#define YYDEBUG 1
#include <cstdio>
#include <iostream>
using namespace std;

#include "PSLGlobal.h"
#include "ASTTree.h"
#include "PSL.tab.h"
#include "lex.h"

void yyerror(void*, const char *s);
%}

%pure-parser
%lex-param {void* scanner}
%parse-param {void* scanner}

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
%token LEFT_PAREN
%token RIGHT_PAREN
%token INT_TOKEN
%token LEFT_BRACE
%token RIGHT_BRACE
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
%type <pNode> function_header
%type <pNode> fully_specified_type
%type <pNode> function_prototype
%type <pNode> function_declarator
%type <pNode> function_definition
%type <pNode> compound_statement
%type <pNode> init_declarator_list
%type <pNode> single_declaration
%type <pNode> declaration
%type <pNode> declaration_statement

%%

translation_unit:
      external_declaration
    | translation_unit external_declaration
    ;

external_declaration:
      function_definition                                           {
        dynamic_cast<FunctionDeclaratorNode*>($1)->VerifyNode();
        dynamic_cast<FunctionDeclaratorNode*>($1)->ProcessNode();
      }
    ;

statement_list:
      statement                                                     { $$ = new StatementListNode($1); }
    | statement_list statement                                      { $$ = $1; $$->AddNode($2); }
    ;

statement:
      expression_statement                                          { $$ = $1; }
    | declaration_statement                                         { $$ = $1; }
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

declaration:
      init_declarator_list SEMICOLON                                { $$ = $1; }
    ;

variable_identifier:
      IDENTIFIER                                                    { $$ = new IdentifierNode($1); }
    ;

function_prototype:
      function_declarator RIGHT_PAREN                               { $$ = $1; }
    ;

function_declarator:
      function_header                                               { $$ = $1; }
    ;

function_header:
      fully_specified_type IDENTIFIER LEFT_PAREN                    { $$ = new FunctionDeclaratorNode($1, $2); }
    ;

fully_specified_type:
      INT_TOKEN                                                     { $$ = new TypeNode(INT_TOKEN); }
    ;

function_definition:
      function_prototype compound_statement                         { $$ = $1; dynamic_cast<FunctionDeclaratorNode*>($$)->SetStatementList($2); }
    ;

init_declarator_list:
      single_declaration                                            { $$ = $1; }
    ;

single_declaration:
      fully_specified_type IDENTIFIER                               { $$ = new VariableDeclarationNode($1, $2); }
    ;

declaration_statement:
      declaration                                                   { $$ = $1; }
    ;

compound_statement:
      LEFT_BRACE RIGHT_BRACE                                        { $$ = nullptr; }
    | LEFT_BRACE statement_list RIGHT_BRACE                         { $$ = $2; }
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

    void* something;
    yylex_init(&something);

    // set flex to read from it instead of defaulting to STDIN:
    yyrestart(myfile, something);

    // parse through the input until there is no more:
	yyparse(something);

    yylex_destroy(something);

}

void yyerror(void *, const char *s) {
	cout << "EEK, parse error!  Message: " << s << endl;
	// might as well halt now:
	exit(-1);
}
