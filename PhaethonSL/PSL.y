%{
#define YYDEBUG 1

#include "PSLCompilerContext.h"
#include "ASTTree.h"
#include "PSL.tab.h"

#define YY_EXTRA_TYPE PSLCompilerContext*
#include "lex.h"

void yyerror(void*, const char *s);

#define scanner pContext->pScanner

%}

%pure-parser
%define parse.error verbose
%lex-param {void* scanner}
%parse-param {PSLCompilerContext* pContext}

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
%token PLUS
%token LEFT_PAREN
%token RIGHT_PAREN
%token LT
%token GT
%token ARROW
%token PTR_TOKEN
%token WORD_TOKEN
%token FLOAT_TOKEN
%token VOID_TOKEN
%token STRUCT_TOKEN
%token LEFT_BRACE
%token RIGHT_BRACE
%token DOT
%token COMMA
%token NULLPTR_TOKEN
%token DEBUGOUT_TOKEN
%token SIZEOF_TOKEN
%token <symIndex> IDENTIFIER
%type <pNode> variable_identifier
%type <pNode> primary_expression
%type <pNode> postfix_expression
%type <pNode> multiplicative_expression
%type <pNode> additive_expression
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
%type <pNode> struct_specifier
%type <pNode> struct_declaration_list
%type <pNode> struct_declaration
%type <pNode> external_declaration
%type <pNode> read_expression
%type <pNode> write_expression
%type <pNode> parameter_declaration
%type <pNode> function_header_with_parameters
%type <pNode> debugout_expression
%type <pNode> sizeof_expression

%%

translation_unit:
      external_declaration
    | translation_unit external_declaration
    ;

external_declaration:
      function_definition                                           { $$ = $1; pContext->AddFuncDef($$); }
	| struct_specifier SEMICOLON                                    { $$ = $1; pContext->AddStructDef($$); }
	| declaration                                                   { $$ = $1; pContext->AddGlobal($$); }
    ;

statement_list:
      statement                                                     { $$ = new StatementListNode(pContext, $1); }
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
    | debugout_expression                                           { $$ = $1; }
    ;

debugout_expression:
      DEBUGOUT_TOKEN LEFT_PAREN postfix_expression RIGHT_PAREN      { $$ = new DebugOutNode(pContext, $3); }
    ;

assignment_expression:
      write_expression assignment_operator additive_expression      { $$ = new AssignmentNode(pContext, $1, $3); }
    ;

additive_expression:
      multiplicative_expression                                     { $$ = $1; }
    | additive_expression PLUS multiplicative_expression            { $$ = new OperatorNode(pContext, $1, $3, Operator::Add); }
    ;

multiplicative_expression:
      read_expression                                               { $$ = $1; }
    | multiplicative_expression STAR read_expression                { $$ = new OperatorNode(pContext, $1, $3, Operator::Multiply); }
    ;

write_expression:
      postfix_expression                                            { $$ = $1; dynamic_cast<ExpressionNode*>($$)->SetExpressionType(ExpressionType::Write); }
    ;

read_expression:
      postfix_expression                                            { $$ = $1; dynamic_cast<ExpressionNode*>($$)->SetExpressionType(ExpressionType::Read); }
	;

assignment_operator:
      EQUAL
    ;

postfix_expression:
      primary_expression                                            { $$ = $1; }
	| postfix_expression DOT IDENTIFIER								{ $$ = new FieldSelectionNode(pContext, $1, false, $3); }
	| postfix_expression ARROW IDENTIFIER							{ $$ = new FieldSelectionNode(pContext, $1, true, $3); }
    ;

primary_expression:
      variable_identifier                                           { $$ = $1; }
    | INTCONSTANT                                                   { $$ = new ConstantNode(pContext, $1); }
    | FLOATCONSTANT                                                 { $$ = new ConstantNode(pContext, $1); }
	| NULLPTR_TOKEN                                                 { $$ = new ConstantNode(pContext, ConstantNode::Pointer); }
    | sizeof_expression                                             { $$ = $1; }
    ;

sizeof_expression:
      SIZEOF_TOKEN LEFT_PAREN variable_identifier RIGHT_PAREN       { $$ = new SizeOfNode(pContext, $3); }
    ;

declaration:
      init_declarator_list SEMICOLON                                { $$ = $1; }
    ;

variable_identifier:
      IDENTIFIER                                                    { $$ = new IdentifierNode(pContext, $1); }
    ;

function_prototype:
      function_declarator RIGHT_PAREN                               { $$ = $1; }
    ;

function_declarator:
      function_header                                               { $$ = $1; }
	| function_header_with_parameters								{ $$ = $1; }
    ;

function_header_with_parameters:
	  function_header parameter_declaration							{ $$ = $1; dynamic_cast<FunctionDeclaratorNode*>($$)->AddParameter($2); }
	| function_header_with_parameters COMMA parameter_declaration   { $$ = $1; dynamic_cast<FunctionDeclaratorNode*>($$)->AddParameter($3); }
	;

function_header:
      fully_specified_type IDENTIFIER LEFT_PAREN                    { $$ = new FunctionDeclaratorNode(pContext, $1, $2); }
    ;

parameter_declaration:
      fully_specified_type IDENTIFIER                               { $$ = new FunctionParameterNode(pContext, $1, $2); }
	;

fully_specified_type:
      WORD_TOKEN                                                    { $$ = new TypeNode(pContext, TypeClass::Basic, WORD_TOKEN); }
    | FLOAT_TOKEN                                                   { $$ = new TypeNode(pContext, TypeClass::Basic, FLOAT_TOKEN); }
	| VOID_TOKEN                                                    { $$ = new TypeNode(pContext, TypeClass::Basic, VOID_TOKEN); }
	| IDENTIFIER                                                    { $$ = new TypeNode(pContext, TypeClass::Struct, $1); }
    | PTR_TOKEN LT fully_specified_type GT                          { $$ = new TypeNode(pContext, $3); }
    ;

struct_specifier:
      STRUCT_TOKEN IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE {
	                                    							  $$ = $4; dynamic_cast<StructSpecifierNode*>($$)->SetName($2); }
    ;

struct_declaration_list:
      struct_declaration											{ $$ = new StructSpecifierNode(pContext, $1); }
    | struct_declaration_list struct_declaration					{ $$ = $1; $$->AddNode($2); }
    ;

struct_declaration:
      fully_specified_type IDENTIFIER SEMICOLON						{ $$ = new StructDeclarationNode(pContext, $1, $2); }
    ;

function_definition:
      function_prototype compound_statement                         { $$ = $1; dynamic_cast<FunctionDeclaratorNode*>($$)->SetStatementList($2); }
    ;

init_declarator_list:
      single_declaration                                            { $$ = $1; }
    ;

single_declaration:
      fully_specified_type IDENTIFIER                               { $$ = new VariableDeclarationNode(pContext, $1, $2); }
    ;

declaration_statement:
      declaration                                                   { $$ = $1; }
    ;

compound_statement:
      LEFT_BRACE RIGHT_BRACE                                        { $$ = nullptr; }
    | LEFT_BRACE statement_list RIGHT_BRACE                         { $$ = $2; }
    ;

%%
