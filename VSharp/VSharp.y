%{
#define YYDEBUG 1

#include "VSharpCompilerContext.h"
#include "ASTTree.h"
#include "VSharp.tab.h"

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
    int symIndex;
    ASTNode* pNode;
}

%locations

%token MODULE_TOKEN
%token OUT_TOKEN
%token STATE_TOKEN
%token UINT_TOKEN
%token UINT32_TOKEN
%token UINT16_TOKEN
%token UINT8_TOKEN
%token VOID_TOKEN
%token INITIAL_TOKEN
%token RETURN_TOKEN
%token AND_OP

%token <intVal> INTCONSTANT
%token <intVal> BOOLCONSTANT
%token AT
%token SEMICOLON
%token COLON
%token EQUAL
%token STAR
%token PLUS
%token MINUS
%token LEFT_PAREN
%token RIGHT_PAREN
%token LT
%token GT
%token LT_OP
%token GT_OP
%token SHIFTLEFT
%token SHIFTRIGHT
%token ARROW
%token DOT
%token COMMA
%token AMPERSAND
%token EQUAL_OP
%token NOTEQUAL_OP
%token BOOL_TOKEN
%token STRUCT_TOKEN
%token TRANSITION_TOKEN
%token LEFT_BRACE
%token RIGHT_BRACE
%token LEFT_BRACKET
%token RIGHT_BRACKET
%token IF_TOKEN
%token ELSE_TOKEN
%token WHILE_TOKEN
%token SIZEOF_TOKEN
%token PACKBYTE_TOKEN
%token RSP_TOKEN
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
%type <pNode> module_header
%type <pNode> fully_specified_type
%type <pNode> module_prototype
%type <pNode> module_definition
%type <pNode> compound_statement
%type <pNode> init_declarator_list
%type <pNode> single_declaration
%type <pNode> declaration
%type <pNode> declaration_statement
%type <pNode> struct_specifier
%type <pNode> struct_declaration_list
%type <pNode> struct_declaration
%type <pNode> external_declaration
%type <pNode> module_param_decl
%type <pNode> module_header_with_parameters
%type <pNode> packbyte_statement
%type <pNode> function_call_header
%type <pNode> function_call_header_no_param
%type <pNode> function_call
%type <pNode> fn_call_arg
%type <pNode> transition_statement
%type <pNode> jump_statement
%type <pNode> selection_statement
%type <pNode> selection_rest_statement
%type <pNode> equality_expression
%type <pNode> shift_expression
%type <pNode> relational_expression
%type <pNode> unary_expression
%type <pNode> module_states
%type <pNode> module_member
%type <pNode> module_state
%type <pNode> state_list
%type <pNode> function_prototype
%type <pNode> function_header
%type <pNode> function_header_with_parameters
%type <pNode> function_definition
%type <pNode> function_param_decl
%type <pNode> return_statement
%type <pNode> logical_and_expression

%%

translation_unit:
      external_declaration
    | translation_unit external_declaration
    ;

external_declaration:
      module_definition                                             { $$ = $1; pContext->AddModuleDef($$); }
	| struct_specifier SEMICOLON                                    { $$ = $1; pContext->AddStructDef($$); }
	| declaration                                                   { $$ = $1; pContext->AddGlobal($$); }
    ;

statement_list:
      statement                                                     { $$ = new ListNode(pContext, $1); }
    | statement_list statement                                      { $$ = $1; $$->AddNode($2); }
    ;

statement:
      expression_statement                                          { $$ = $1; }
    | selection_statement                                           { $$ = $1; }
    | declaration_statement                                         { $$ = $1; }
    | jump_statement                                                { $$ = $1; }
    | packbyte_statement                                            { $$ = $1; }
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

unary_expression:
      postfix_expression                                            { $$ = $1; }
    | MINUS postfix_expression                                      { $$ = new UnaryOperatorNode(pContext, $2, Operator::Negate); }
    ;

multiplicative_expression:
      unary_expression                                              { $$ = $1; }
    | multiplicative_expression STAR unary_expression               { $$ = new OperatorNode(pContext, @$, $1, $3, Operator::Multiply); }
    ;

additive_expression:
      multiplicative_expression                                     { $$ = $1; }
    | additive_expression PLUS multiplicative_expression            { $$ = new OperatorNode(pContext, @$, $1, $3, Operator::Add); }
    | additive_expression MINUS multiplicative_expression           { $$ = new OperatorNode(pContext, @$, $1, $3, Operator::Subtract); }
    ;

shift_expression:
      additive_expression                                           { $$ = $1; }
    | shift_expression SHIFTLEFT additive_expression                { $$ = new OperatorNode(pContext, @$, $1, $3, Operator::ShiftLeft); }
    | shift_expression SHIFTRIGHT additive_expression               { $$ = new OperatorNode(pContext, @$, $1, $3, Operator::ShiftRight); }
    ;

relational_expression:
      shift_expression                                              { $$ = $1; }
    | relational_expression LT_OP shift_expression                  { $$ = new OperatorNode(pContext, @$, $1, $3, Operator::LessThan); }
    | relational_expression GT_OP shift_expression                  { $$ = new OperatorNode(pContext, @$, $1, $3, Operator::GreaterThan); }
    ;

equality_expression:
      relational_expression                                         { $$ = $1; }
    | equality_expression EQUAL_OP relational_expression            { $$ = new OperatorNode(pContext, @$, $1, $3, Operator::Equal); }
    | equality_expression NOTEQUAL_OP relational_expression         { $$ = new OperatorNode(pContext, @$, $1, $3, Operator::NotEqual); }
    ;

logical_and_expression:
      equality_expression                                           { $$ = $1; }
    | logical_and_expression AND_OP equality_expression             { $$ = new OperatorNode(pContext, @$, $1, $3, Operator::LogicalAnd); } 
    ;

assignment_expression:
      logical_and_expression                                        { $$ = $1; }
    | postfix_expression assignment_operator logical_and_expression { $$ = new AssignmentNode(pContext, @$, $1, $3); }
    ;

assignment_operator:
      EQUAL
    ;

postfix_expression:
      primary_expression                                            { $$ = $1; }
    | postfix_expression LEFT_BRACKET expression RIGHT_BRACKET      { $$ = new IndexSelectionNode(pContext, @$, $1, $3); }
    | postfix_expression LEFT_BRACKET INTCONSTANT COLON INTCONSTANT RIGHT_BRACKET      
                                                                    { $$ = new BitSelectionNode(pContext, @$, $1, $3, $5); }
    | function_call                                                 { $$ = $1; }
	| postfix_expression DOT IDENTIFIER								{ $$ = new FieldSelectionNode(pContext, @$, $1, false, $3); }
	| postfix_expression ARROW IDENTIFIER							{ $$ = new FieldSelectionNode(pContext, @$, $1, true, $3); }
    ;

primary_expression:
      variable_identifier                                           { $$ = $1; }
    | INTCONSTANT                                                   { $$ = new ConstantNode(pContext, ConstantNode::Word, $1); }
    | BOOLCONSTANT                                                  { $$ = new ConstantNode(pContext, ConstantNode::Bool, $1); }
    ;

declaration:
      init_declarator_list SEMICOLON                                { $$ = $1; }
    ;

variable_identifier:
      IDENTIFIER                                                    { $$ = new IdentifierNode(pContext, @$, $1); }
    ;

module_prototype:
      module_header_with_parameters RIGHT_PAREN                     { $$ = $1; }
    ;

module_header_with_parameters:
	  module_header module_param_decl						        { $$ = $1; dynamic_cast<ModuleDeclaratorNode*>($$)->AddParameter($2); }
	| module_header_with_parameters COMMA module_param_decl         { $$ = $1; dynamic_cast<ModuleDeclaratorNode*>($$)->AddParameter($3); }
	;

module_header:
      MODULE_TOKEN IDENTIFIER LEFT_PAREN                            { $$ = new ModuleDeclaratorNode(pContext, $2, -1); }
    | MODULE_TOKEN IDENTIFIER LT IDENTIFIER GT LEFT_PAREN           { $$ = new ModuleDeclaratorNode(pContext, $2, $4); } 
    ;

module_param_decl:
      fully_specified_type IDENTIFIER                               { $$ = new ModuleParameterNode(pContext, $1, $2, false); }
    | OUT_TOKEN fully_specified_type IDENTIFIER                     { $$ = new ModuleParameterNode(pContext, $2, $3, true); }
	;

function_definition:
      function_prototype compound_statement                         { $$ = $1; dynamic_cast<FunctionDeclaratorNode*>($$)->SetStatementList($2); }
    | function_prototype LEFT_BRACE return_statement RIGHT_BRACE    { $$ = $1; dynamic_cast<FunctionDeclaratorNode*>($$)->SetStatementList($3); }
    ;

function_prototype:
      function_header_with_parameters RIGHT_PAREN                   { $$ = $1; }

function_header_with_parameters:
	  function_header function_param_decl							{ $$ = $1; dynamic_cast<FunctionDeclaratorNode*>($$)->AddParameter($2); }
	| function_header_with_parameters COMMA function_param_decl     { $$ = $1; dynamic_cast<FunctionDeclaratorNode*>($$)->AddParameter($3); }
	;

function_header:
      fully_specified_type IDENTIFIER LEFT_PAREN                    { $$ = new FunctionDeclaratorNode(pContext, $1, $2, -1); }
    | fully_specified_type IDENTIFIER LT IDENTIFIER GT LEFT_PAREN   { $$ = new FunctionDeclaratorNode(pContext, $1, $2, $4); } 
    ;

function_param_decl:
      fully_specified_type IDENTIFIER                               { $$ = new FunctionParameterNode(pContext, $1, $2, false); }
    | OUT_TOKEN fully_specified_type IDENTIFIER                     { $$ = new FunctionParameterNode(pContext, $2, $3, true); }
	;

fully_specified_type:
      UINT32_TOKEN                                                  { $$ = new TypeNode(pContext, @$, TypeClass::Register, 32); }
    | UINT16_TOKEN                                                  { $$ = new TypeNode(pContext, @$, TypeClass::Register, 16); }
    | UINT8_TOKEN                                                   { $$ = new TypeNode(pContext, @$, TypeClass::Register, 8); }
	| VOID_TOKEN                                                    { $$ = new TypeNode(pContext, @$); }
    | BOOL_TOKEN                                                    { $$ = new TypeNode(pContext, @$, TypeClass::Register, 1); }
	| IDENTIFIER                                                    { $$ = new TypeNode(pContext, @$, TypeClass::Struct, $1); }
    | UINT_TOKEN LT INTCONSTANT GT                                  { $$ = new TypeNode(pContext, @$, $3); }
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

module_definition:
      module_prototype module_states                                { $$ = $1; dynamic_cast<ModuleDeclaratorNode*>($$)->SetStatementList($2); }
    ;

module_states:
      LEFT_BRACE RIGHT_BRACE                                        { $$ = new ListNode(pContext, nullptr); }
    | LEFT_BRACE state_list RIGHT_BRACE                             { $$ = $2; }
    ;

state_list:
      module_member                                                 { $$ = new ListNode(pContext, $1); }
    | state_list module_member                                      { $$ = $1; $$->AddNode($2); }
    ;

module_member:
      module_state                                                  { $$ = $1; }
    | declaration_statement                                         { $$ = $1; }
    | function_definition                                           { $$ = $1; }
    ;

module_state:
      STATE_TOKEN IDENTIFIER compound_statement                     { $$ = new StateDeclaratorNode(pContext, @$, $2, $3); }
    | STATE_TOKEN INITIAL_TOKEN compound_statement                  { $$ = new StateDeclaratorNode(pContext, @$, -1, $3); }
    ;

init_declarator_list:
      single_declaration                                            { $$ = $1; }
    ;

single_declaration:
      fully_specified_type IDENTIFIER                               { $$ = new VariableDeclarationNode(pContext, @$, $1, $2, -1, nullptr); }
    | fully_specified_type IDENTIFIER LEFT_BRACKET INTCONSTANT RIGHT_BRACKET
                                                                    { $$ = new VariableDeclarationNode(pContext, @$, $1, $2, $4, nullptr); }
    | fully_specified_type IDENTIFIER EQUAL expression              { $$ = new VariableDeclarationNode(pContext, @$, $1, $2, -1, $4); }
    ;

declaration_statement:
      declaration                                                   { $$ = $1; }
    ;

compound_statement:
      LEFT_BRACE RIGHT_BRACE                                        { $$ = new ListNode(pContext, nullptr); }
    | LEFT_BRACE statement_list RIGHT_BRACE                         { $$ = $2; }
    ;

function_call:
      function_call_header RIGHT_PAREN                              { $$ = $1; }
    | function_call_header_no_param RIGHT_PAREN                     { $$ = $1; }
    ;

function_call_header_no_param:
      IDENTIFIER LEFT_PAREN                                         { $$ = new FunctionCallNode(pContext, @$, $1, nullptr, nullptr); }
    | IDENTIFIER LT fully_specified_type GT LEFT_PAREN              { $$ = new FunctionCallNode(pContext, @$, $1, $3, nullptr); }
    ;

function_call_header:
      IDENTIFIER LEFT_PAREN fn_call_arg                             { $$ = new FunctionCallNode(pContext, @$, $1, nullptr, $3); }
    | IDENTIFIER LT fully_specified_type GT LEFT_PAREN fn_call_arg  { $$ = new FunctionCallNode(pContext, @$, $1, $3, $6); }
    | function_call_header COMMA fn_call_arg                        { $$ = $1; $$->AddNode($3); }
    ;

fn_call_arg:
      assignment_expression                                         { $$ = new FunctionCallParamNode(pContext, @$, false, $1); }
    | OUT_TOKEN variable_identifier                                 { $$ = new FunctionCallParamNode(pContext, @$, true, $2); }
    ;

jump_statement:
      transition_statement                                          { $$ = $1; }
    ;

return_statement:
      RETURN_TOKEN expression SEMICOLON                             { $$ = $2; }

transition_statement:
      TRANSITION_TOKEN IDENTIFIER SEMICOLON                         { $$ = new TransitionNode(pContext, $2); }
    ;

packbyte_statement:
      PACKBYTE_TOKEN LEFT_PAREN expression COMMA expression COMMA expression RIGHT_PAREN SEMICOLON
                                                                    { $$ = new PackByteNode(pContext, @$, $3, $5, $7); }
    ;

%%
