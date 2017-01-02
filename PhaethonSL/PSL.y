%{
#define YYDEBUG 1

#include "PSLCompilerContext.h"
#include "ASTTree.h"
#include "PSL.tab.h"

#define YY_EXTRA_TYPE PSLCompilerContext*
#include "lex.h"

void yyerror(YYLTYPE*, void*, const char *s);

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

%locations

%token <intVal> INTCONSTANT
%token <floatVal> FLOATCONSTANT
%token <intVal> BOOLCONSTANT
%token SEMICOLON
%token EQUAL
%token STAR
%token PLUS
%token MINUS
%token LEFT_PAREN
%token RIGHT_PAREN
%token LT
%token GT
%token SHIFTLEFT
%token SHIFTRIGHT
%token ARROW
%token DOT
%token COMMA
%token AMPERSAND
%token EQUAL_OP
%token NOTEQUAL_OP
%token PTR_TOKEN
%token WORD_TOKEN
%token BOOL_TOKEN
%token FLOAT_TOKEN
%token VOID_TOKEN
%token STRUCT_TOKEN
%token RETURN_TOKEN
%token LEFT_BRACE
%token RIGHT_BRACE
%token LEFT_BRACKET
%token RIGHT_BRACKET
%token IF_TOKEN
%token ELSE_TOKEN
%token WHILE_TOKEN
%token NULLPTR_TOKEN
%token DEBUGOUT_TOKEN
%token SIZEOF_TOKEN
%token OFFSETPTR_TOKEN
%token CASTPTR_TOKEN
%token DATASEGEND_TOKEN
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
%type <pNode> parameter_declaration
%type <pNode> function_header_with_parameters
%type <pNode> debugout_statement
%type <pNode> sizeof_expression
%type <pNode> offset_expression
%type <pNode> function_call_header
%type <pNode> function_call
%type <pNode> return_statement
%type <pNode> jump_statement
%type <pNode> cast_expression
%type <pNode> selection_statement
%type <pNode> selection_rest_statement
%type <pNode> equality_expression
%type <pNode> shift_expression
%type <pNode> relational_expression
%type <pNode> unary_expression

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
    | selection_statement                                           { $$ = $1; }
    | declaration_statement                                         { $$ = $1; }
    | jump_statement                                                { $$ = $1; }
    | debugout_statement                                            { $$ = $1; }
    ;

expression_statement:
      expression SEMICOLON                                          { $$ = $1; }
    ;

selection_statement:
      IF_TOKEN LEFT_PAREN expression RIGHT_PAREN selection_rest_statement 
                                                                    { $$ = $5; dynamic_cast<IfStatementNode*>($$)->SetStatementList($3); }
    | WHILE_TOKEN LEFT_PAREN expression RIGHT_PAREN compound_statement
                                                                    { $$ = new WhileStatementNode(pContext, $3, $5); }
    ;

selection_rest_statement:
      compound_statement ELSE_TOKEN compound_statement              { $$ = new IfStatementNode(pContext, $1, $3); }
    | compound_statement                                            { $$ = new IfStatementNode(pContext, $1, nullptr); }
    ;

expression:
      assignment_expression                                         { $$ = $1; }
    ;

assignment_expression:
      equality_expression                                           { $$ = $1; }
    | postfix_expression assignment_operator equality_expression    { $$ = new AssignmentNode(pContext, @$, $1, $3); }
    ;

equality_expression:
      relational_expression                                         { $$ = $1; }
    | equality_expression EQUAL_OP relational_expression            { $$ = new OperatorNode(pContext, $1, $3, Operator::Equal); }
    | equality_expression NOTEQUAL_OP relational_expression         { $$ = new OperatorNode(pContext, $1, $3, Operator::NotEqual); }
    ;

relational_expression:
      shift_expression                                              { $$ = $1; }
    | relational_expression LT shift_expression                     { $$ = new OperatorNode(pContext, $1, $3, Operator::LessThan); }
    | relational_expression GT shift_expression                     { $$ = new OperatorNode(pContext, $1, $3, Operator::GreaterThan); }
    ;

shift_expression:
      additive_expression                                           { $$ = $1; }
    | shift_expression SHIFTLEFT additive_expression                { $$ = new OperatorNode(pContext, $1, $3, Operator::ShiftLeft); }
    | shift_expression SHIFTRIGHT additive_expression               { $$ = new OperatorNode(pContext, $1, $3, Operator::ShiftRight); }
    ;

additive_expression:
      multiplicative_expression                                     { $$ = $1; }
    | additive_expression PLUS multiplicative_expression            { $$ = new OperatorNode(pContext, $1, $3, Operator::Add); }
    | additive_expression MINUS multiplicative_expression           { $$ = new OperatorNode(pContext, $1, $3, Operator::Subtract); }
    ;

multiplicative_expression:
      unary_expression                                              { $$ = $1; }
    | multiplicative_expression STAR unary_expression               { $$ = new OperatorNode(pContext, $1, $3, Operator::Multiply); }
    ;

unary_expression:
      postfix_expression                                            { $$ = $1; }
    | MINUS postfix_expression                                      { $$ = new UnaryOperatorNode(pContext, $2, Operator::Negate); }
    ;

assignment_operator:
      EQUAL
    ;

postfix_expression:
      primary_expression                                            { $$ = $1; }
    | postfix_expression LEFT_BRACKET expression RIGHT_BRACKET      { $$ = new IndexSelectionNode(pContext, @$, $1, $3); }
    | function_call                                                 { $$ = $1; }
	| postfix_expression DOT IDENTIFIER								{ $$ = new FieldSelectionNode(pContext, $1, false, $3); }
	| postfix_expression ARROW IDENTIFIER							{ $$ = new FieldSelectionNode(pContext, $1, true, $3); }
    ;

primary_expression:
      variable_identifier                                           { $$ = $1; }
    | AMPERSAND variable_identifier                                 { $$ = new AddressOfNode(pContext, $2); }
    | INTCONSTANT                                                   { $$ = new ConstantNode(pContext, ConstantNode::Word, $1); }
    | BOOLCONSTANT                                                  { $$ = new ConstantNode(pContext, ConstantNode::Bool, $1); }
    | FLOATCONSTANT                                                 { $$ = new ConstantNode(pContext, $1); }
	| NULLPTR_TOKEN                                                 { $$ = new ConstantNode(pContext, ConstantNode::Pointer); }
    | DATASEGEND_TOKEN                                              { $$ = new KnownConstantNode(pContext, KnownConstants::DataSegmentEnd); }
    | sizeof_expression                                             { $$ = $1; }
    | offset_expression                                             { $$ = $1; }
    | cast_expression                                               { $$ = $1; }
    ;

sizeof_expression:
      SIZEOF_TOKEN LEFT_PAREN fully_specified_type RIGHT_PAREN      { $$ = new SizeOfNode(pContext, $3); }
    ;

offset_expression:
      OFFSETPTR_TOKEN LT fully_specified_type GT LEFT_PAREN expression COMMA expression RIGHT_PAREN
                                                                    { $$ = new OffsetNode(pContext, @$, $3, $6, $8); }
    ;

cast_expression:
      CASTPTR_TOKEN LT fully_specified_type GT LEFT_PAREN expression RIGHT_PAREN
                                                                    { $$ = new CastNode(pContext, @$, $3, $6); }
    ;

declaration:
      init_declarator_list SEMICOLON                                { $$ = $1; }
    ;

variable_identifier:
      IDENTIFIER                                                    { $$ = new IdentifierNode(pContext, @$, $1); }
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
      fully_specified_type IDENTIFIER LEFT_PAREN                    { $$ = new FunctionDeclaratorNode(pContext, $1, $2, -1); }
    | fully_specified_type IDENTIFIER LT IDENTIFIER GT LEFT_PAREN   { $$ = new FunctionDeclaratorNode(pContext, $1, $2, $4); } 
    ;

parameter_declaration:
      fully_specified_type IDENTIFIER                               { $$ = new FunctionParameterNode(pContext, $1, $2); }
	;

fully_specified_type:
      WORD_TOKEN                                                    { $$ = new TypeNode(pContext, TypeClass::Basic, WORD_TOKEN); }
    | FLOAT_TOKEN                                                   { $$ = new TypeNode(pContext, TypeClass::Basic, FLOAT_TOKEN); }
	| VOID_TOKEN                                                    { $$ = new TypeNode(pContext, TypeClass::Basic, VOID_TOKEN); }
	| BOOL_TOKEN                                                    { $$ = new TypeNode(pContext, TypeClass::Basic, BOOL_TOKEN); }
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
      fully_specified_type IDENTIFIER SEMICOLON						{ $$ = new StructDeclarationNode(pContext, $1, $2, -1); }
    | fully_specified_type IDENTIFIER LEFT_BRACKET INTCONSTANT RIGHT_BRACKET SEMICOLON
                                                                    { $$ = new StructDeclarationNode(pContext, $1, $2, $4); }
    ;

function_definition:
      function_prototype compound_statement                         { $$ = $1; dynamic_cast<FunctionDeclaratorNode*>($$)->SetStatementList($2); }
    ;

init_declarator_list:
      single_declaration                                            { $$ = $1; }
    ;

single_declaration:
      fully_specified_type IDENTIFIER                               { $$ = new VariableDeclarationNode(pContext, @$, $1, $2, nullptr); }
    | fully_specified_type IDENTIFIER EQUAL expression              { $$ = new VariableDeclarationNode(pContext, @$, $1, $2, $4); }
    ;

declaration_statement:
      declaration                                                   { $$ = $1; }
    ;

compound_statement:
      LEFT_BRACE RIGHT_BRACE                                        { $$ = new StatementListNode(pContext, nullptr); }
    | LEFT_BRACE statement_list RIGHT_BRACE                         { $$ = $2; }
    ;

function_call:
      function_call_header RIGHT_PAREN                              { $$ = $1; }
    ;

function_call_header:
      IDENTIFIER LEFT_PAREN                                         { $$ = new FunctionCallNode(pContext, @$, $1, nullptr, nullptr); }
    | IDENTIFIER LT fully_specified_type GT LEFT_PAREN              { $$ = new FunctionCallNode(pContext, @$, $1, $3, nullptr); }
    | IDENTIFIER LEFT_PAREN assignment_expression                   { $$ = new FunctionCallNode(pContext, @$, $1, nullptr, $3); }
    | IDENTIFIER LT fully_specified_type GT LEFT_PAREN assignment_expression  
                                                                    { $$ = new FunctionCallNode(pContext, @$, $1, $3, $6); }
    | function_call_header COMMA assignment_expression              { $$ = $1; $$->AddNode($3); }
    ;

jump_statement:
      return_statement                                              { $$ = $1; }
    ;

return_statement:
      RETURN_TOKEN assignment_expression SEMICOLON                  { $$ = new ReturnNode(pContext, $2); }
    ;

debugout_statement:
      DEBUGOUT_TOKEN LEFT_PAREN postfix_expression RIGHT_PAREN SEMICOLON      
                                                                    { $$ = new DebugOutNode(pContext, $3); }
    ;

%%
