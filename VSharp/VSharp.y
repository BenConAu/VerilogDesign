%{
#define YYDEBUG 1

#include "ParserContext.h"
#include "ASTTree.h"
#include "VSharp.tab.h"

#define YY_EXTRA_TYPE ParserContext*
#include "lex.h"

void yyerror(YYLTYPE*, void*, const char *s);

#define scanner pContext->pScanner

%}

%pure-parser
%define parse.error verbose
%lex-param {void* scanner}
%parse-param {ParserContext* pContext}

%code requires 
{
#include "UIntConstant.h"
#include "EnumItem.h"
#include "FunctionExpandType.h"

class ASTNode;
class ParserContext;
}

%union 
{
    UIntConstant constVal;
    int symIndex;
    ASTNode* pNode;
    EnumItem _EnumItem;
    FunctionExpandType _FunctionExpandType;
}

%locations

%token MODULE_TOKEN
%token OUT_TOKEN
%token STATE_TOKEN
%token UINT_TOKEN
%token UINT64_TOKEN
%token UINT32_TOKEN
%token UINT16_TOKEN
%token UINT8_TOKEN
%token VOID_TOKEN
%token INITIAL_TOKEN
%token ALWAYS_TOKEN
%token RETURN_TOKEN
%token AND_OP
%token OR_OP
%token ENUM_TOKEN
%token DRIVE_TOKEN
%token CLOCK_TOKEN
%token FINISH_TOKEN
%token CASE_TOKEN
%token SWITCH_TOKEN
%token DEFAULT_TOKEN
%token STAGE_TOKEN

%token <constVal> INTCONSTANT
%token <constVal> BOOLCONSTANT
%token STRINGLITERAL
%token AT
%token SEMICOLON
%token COLON
%token EQUAL
%token STAR
%token SLASH
%token PLUS
%token MINUS
%token LEFT_PAREN
%token RIGHT_PAREN
%token LT
%token GT
%token LT_OP
%token GT_OP
%token LT_EQUAL_OP
%token GT_EQUAL_OP
%token SHIFTLEFT
%token SHIFTRIGHT
%token ARROW
%token DOT
%token COMMA
%token HAT
%token BANG
%token BAR
%token AMPERSAND
%token QUESTION
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
%token IMPORT_TOKEN
%token WIRE_TOKEN
%token CONST_TOKEN
%token BLOCKING_TOKEN
%token NONBLOCKING_TOKEN
%token <symIndex> IDENTIFIER
%type <pNode> variable_identifier
%type <pNode> primary_expression
%type <pNode> postfix_expression
%type <pNode> multiplicative_expression
%type <pNode> additive_expression
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
%type <pNode> function_call_header
%type <pNode> function_call_header_no_param
%type <pNode> function_call
%type <pNode> fn_call_arg
%type <pNode> transition_statement
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
%type <pNode> logical_or_expression
%type <pNode> exclusive_or_expression
%type <pNode> inclusive_or_expression
%type <pNode> glom_expression
%type <pNode> glom_list
%type <pNode> enum_definition
%type <pNode> enum_list
%type <pNode> drive_list_definition
%type <pNode> drive_statement_list
%type <pNode> drive_definition
%type <pNode> type_name_specifier
%type <pNode> import_statement
%type <pNode> assignment_statement
%type <pNode> conditional_expression
%type <pNode> switch_statement
%type <pNode> case_statement
%type <pNode> case_list
%type <_EnumItem> enum_item
%type <_FunctionExpandType> duplicate_type

%%

translation_unit:
      external_declaration
    | translation_unit external_declaration
    ;

external_declaration:
      module_definition                                             { $$ = $1; pContext->AddModuleDef($$); }
    | function_definition                                           { $$ = $1; pContext->AddFunction($$); }
    | import_statement                                              { $$ = $1; pContext->AddImport($$); }
    | enum_definition                                               { $$ = $1; pContext->AddTypeDef($$); }
	| struct_specifier                                              { $$ = $1; pContext->AddTypeDef($$); }
	| declaration                                                   { $$ = $1; pContext->AddGlobal($$); }
    ;

import_statement:
      IMPORT_TOKEN STRINGLITERAL SEMICOLON                          { $$ = new ImportStatementNode(pContext, @$); }

enum_definition:
      ENUM_TOKEN IDENTIFIER LEFT_BRACE enum_list RIGHT_BRACE        { $$ = $4; dynamic_cast<EnumDefinitionNode*>($$)->SetIdentifier($2); }
    | ENUM_TOKEN IDENTIFIER LEFT_BRACE enum_list COMMA RIGHT_BRACE  { $$ = $4; dynamic_cast<EnumDefinitionNode*>($$)->SetIdentifier($2); }
    ;

enum_list:
      enum_item                                                     { $$ = new EnumDefinitionNode(pContext, @$, $1); }
    | enum_list COMMA enum_item                                     { $$ = $1; dynamic_cast<EnumDefinitionNode*>($$)->AddEnum($3); }
    ;

enum_item:
      IDENTIFIER                                                    { $$ = EnumItem($1); }
    | IDENTIFIER EQUAL INTCONSTANT                                  { $$ = EnumItem($1, $3); }
    ;    

statement_list:
      statement                                                     { $$ = new ListNode(pContext, @$, $1); }
    | statement_list statement                                      { $$ = $1; $$->AddNode($2); }
    ;

statement:
      expression_statement                                          { $$ = $1; }
    | assignment_statement                                          { $$ = $1; }
    | selection_statement                                           { $$ = $1; }
    | declaration_statement                                         { $$ = $1; }
    | transition_statement                                          { $$ = $1; }
    | return_statement                                              { $$ = $1; }
    | switch_statement                                              { $$ = $1; }
    ;

switch_statement:
      SWITCH_TOKEN LEFT_PAREN expression RIGHT_PAREN LEFT_BRACE case_list RIGHT_BRACE
                                                                    { $$ = $6; dynamic_cast<SwitchStatementNode*>($$)->SetTest($3); }
    ;

case_list:
      case_statement                                                { $$ = new SwitchStatementNode(pContext, @$, $1); }
    | case_list case_statement                                      { $$ = $1; dynamic_cast<SwitchStatementNode*>($$)->AddNode($2); }
    ;

case_statement:
      CASE_TOKEN expression COLON LEFT_BRACE statement_list RIGHT_BRACE   
                                                                    { $$ = new CaseStatementNode(pContext, @$, $2, $5); }
    | DEFAULT_TOKEN COLON LEFT_BRACE statement_list RIGHT_BRACE     { $$ = new CaseStatementNode(pContext, @$, nullptr, $4); }
    ;

expression_statement:
      expression SEMICOLON                                          { $$ = new ExpressionStatementNode(pContext, @$, $1); }
    ;

assignment_statement:
      postfix_expression assignment_operator expression SEMICOLON   { $$ = new AssignmentNode(pContext, @$, $1, $3); }
    ;

assignment_operator:
      EQUAL
    ;

selection_statement:
      IF_TOKEN LEFT_PAREN expression RIGHT_PAREN selection_rest_statement 
                                                                    { $$ = $5; dynamic_cast<IfStatementNode*>($$)->SetExpression($3); }
    ;

selection_rest_statement:
      compound_statement ELSE_TOKEN compound_statement              { $$ = new IfStatementNode(pContext, @$, $1, $3); }
    | compound_statement                                            { $$ = new IfStatementNode(pContext, @$, $1, nullptr); }
    ;

unary_expression:
      postfix_expression                                            { $$ = $1; }
    | MINUS postfix_expression                                      { $$ = new UnaryOperatorNode(pContext, @$, $2, Operator::Negate); }
    | BANG postfix_expression                                       { $$ = new UnaryOperatorNode(pContext, @$, $2, Operator::LogicalNot); }
    ;

multiplicative_expression:
      unary_expression                                              { $$ = $1; }
    | multiplicative_expression STAR unary_expression               { $$ = new OperatorNode(pContext, @$, $1, $3, Operator::Multiply); }
    | multiplicative_expression SLASH unary_expression              { $$ = new OperatorNode(pContext, @$, $1, $3, Operator::Divide); }
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
    | relational_expression LT_EQUAL_OP shift_expression            { $$ = new OperatorNode(pContext, @$, $1, $3, Operator::LessThanEqual); }
    | relational_expression GT_EQUAL_OP shift_expression            { $$ = new OperatorNode(pContext, @$, $1, $3, Operator::GreaterThanEqual); }
    ;

equality_expression:
      relational_expression                                         { $$ = $1; }
    | equality_expression EQUAL_OP relational_expression            { $$ = new OperatorNode(pContext, @$, $1, $3, Operator::Equal); }
    | equality_expression NOTEQUAL_OP relational_expression         { $$ = new OperatorNode(pContext, @$, $1, $3, Operator::NotEqual); }
    ;

exclusive_or_expression:
      equality_expression                                           { $$ = $1; }
    | exclusive_or_expression HAT equality_expression               { $$ = new OperatorNode(pContext, @$, $1, $3, Operator::BitwiseXor); }
    ;

inclusive_or_expression:
      exclusive_or_expression                                       { $$ = $1; }
    | inclusive_or_expression BAR exclusive_or_expression           { $$ = new OperatorNode(pContext, @$, $1, $3, Operator::BitwiseOr); }
    ;

logical_and_expression:
      inclusive_or_expression                                       { $$ = $1; }
    | logical_and_expression AND_OP inclusive_or_expression         { $$ = new OperatorNode(pContext, @$, $1, $3, Operator::LogicalAnd); } 
    ;

logical_or_expression:
      logical_and_expression                                        { $$ = $1; }
    | logical_or_expression OR_OP logical_and_expression            { $$ = new OperatorNode(pContext, @$, $1, $3, Operator::LogicalOr); } 
    ;

conditional_expression:
      logical_or_expression                                         { $$ = $1; }
    | logical_or_expression QUESTION expression COLON expression    { $$ = new TernaryExpressionNode(pContext, @$, $1, $3, $5); }
    ;

expression:
      conditional_expression                                        { $$ = $1; }
    ;

postfix_expression:
      primary_expression                                            { $$ = $1; }
    | postfix_expression LEFT_BRACKET expression RIGHT_BRACKET      { $$ = new IndexSelectionNode(pContext, @$, $1, $3); }
    | postfix_expression LEFT_BRACKET expression COLON expression RIGHT_BRACKET      
                                                                    { $$ = new BitSelectionNode(pContext, @$, $1, $3, $5); }
    | function_call                                                 { $$ = $1; }
	| postfix_expression DOT IDENTIFIER								{ $$ = new FieldSelectionNode(pContext, @$, $1, $3); }
    ;

primary_expression:
      variable_identifier                                           { $$ = $1; }
    | glom_expression                                               { $$ = $1; }
    | INTCONSTANT                                                   { $$ = new ConstantNode(pContext, @$, $1); }
    | BOOLCONSTANT                                                  { $$ = new ConstantNode(pContext, @$, $1); }
    | LEFT_PAREN expression RIGHT_PAREN                             { $$ = new ParenNode(pContext, @$, $2); }
    ;

glom_expression:
      LEFT_BRACE glom_list RIGHT_BRACE                              { $$ = new GlomExpressionNode(pContext, @$, $2); }
    ;

glom_list:
      postfix_expression                                            { $$ = new ListNode(pContext, @$, $1); }
    | glom_list COMMA postfix_expression                            { $$ = $1; dynamic_cast<ListNode*>($$)->AddNode($3); }
    ;

declaration:
      init_declarator_list SEMICOLON                                { $$ = $1; }
    ;

variable_identifier:
      IDENTIFIER                                                    { $$ = new IdentifierNode(pContext, @$, $1); }
    ;

module_prototype:
      module_header_with_parameters RIGHT_PAREN                     { $$ = $1; }
    | module_header RIGHT_PAREN                                     { $$ = $1; }
    ;

module_header_with_parameters:
	  module_header module_param_decl						        { $$ = $1; dynamic_cast<ModuleDefinitionNode*>($$)->AddParameter($2); }
	| module_header_with_parameters COMMA module_param_decl         { $$ = $1; dynamic_cast<ModuleDefinitionNode*>($$)->AddParameter($3); }
	;

module_header:
      MODULE_TOKEN IDENTIFIER LEFT_PAREN                            { $$ = new ModuleDefinitionNode(pContext, @$, $2, -1, FunctionExpandType::None); }
    | MODULE_TOKEN IDENTIFIER LT IDENTIFIER GT LEFT_PAREN           { $$ = new ModuleDefinitionNode(pContext, @$, $2, $4, FunctionExpandType::None); }
    | MODULE_TOKEN LEFT_PAREN duplicate_type RIGHT_PAREN IDENTIFIER LEFT_PAREN { $$ = new ModuleDefinitionNode(pContext, @$, $5, -1, $3); }
    ;

duplicate_type:
      BLOCKING_TOKEN                                                { $$ = FunctionExpandType::StageBlocking; }
    | NONBLOCKING_TOKEN                                             { $$ = FunctionExpandType::StageNonblocking; }
    ;

module_param_decl:
      fully_specified_type IDENTIFIER                               { $$ = new ModuleParameterNode(pContext, @$, $1, $2, false); }
    | OUT_TOKEN fully_specified_type IDENTIFIER                     { $$ = new ModuleParameterNode(pContext, @$, $2, $3, true); }
	;

function_definition:
      function_prototype compound_statement                         { $$ = $1; dynamic_cast<FunctionDeclaratorNode*>($$)->SetStatementList($2); }
    ;

function_prototype:
      function_header_with_parameters RIGHT_PAREN                   { $$ = $1; }

function_header_with_parameters:
	  function_header function_param_decl							{ $$ = $1; dynamic_cast<FunctionDeclaratorNode*>($$)->AddParameter($2); }
	| function_header_with_parameters COMMA function_param_decl     { $$ = $1; dynamic_cast<FunctionDeclaratorNode*>($$)->AddParameter($3); }
	;

function_header:
      fully_specified_type IDENTIFIER LEFT_PAREN                    { $$ = new FunctionDeclaratorNode(pContext, @$, $1, $2, nullptr); }
    | fully_specified_type IDENTIFIER LT expression GT LEFT_PAREN   { $$ = new FunctionDeclaratorNode(pContext, @$, $1, $2, $4); }
    | STAGE_TOKEN IDENTIFIER LEFT_PAREN                             { $$ = new FunctionDeclaratorNode(pContext, @$, nullptr, $2, nullptr); }
    ;

function_param_decl:
      fully_specified_type IDENTIFIER                               { $$ = new FunctionParameterNode(pContext, @$, $1, $2, false); }
    | OUT_TOKEN fully_specified_type IDENTIFIER                     { $$ = new FunctionParameterNode(pContext, @$, $2, $3, true); }
	;

type_name_specifier:
      UINT64_TOKEN                                                  { $$ = new TypeNode(pContext, @$, TypeClass::Register, 64); }
    | UINT32_TOKEN                                                  { $$ = new TypeNode(pContext, @$, TypeClass::Register, 32); }
    | UINT16_TOKEN                                                  { $$ = new TypeNode(pContext, @$, TypeClass::Register, 16); }
    | UINT8_TOKEN                                                   { $$ = new TypeNode(pContext, @$, TypeClass::Register, 8); }
	| VOID_TOKEN                                                    { $$ = new TypeNode(pContext, @$, TypeClass::Void); }
    | CLOCK_TOKEN                                                   { $$ = new TypeNode(pContext, @$, TypeClass::Clock); }
    | BOOL_TOKEN                                                    { $$ = new TypeNode(pContext, @$, TypeClass::Register, 1); }
	| IDENTIFIER                                                    { $$ = new TypeNode(pContext, @$, TypeClass::Unknown, $1); }
    | UINT_TOKEN LT expression GT                                   { $$ = new TypeNode(pContext, @$, $3); }
    ;

fully_specified_type:
      WIRE_TOKEN type_name_specifier                                { $$ = $2; dynamic_cast<TypeNode*>($$)->SetModifier(TypeModifier::Wire); }
    | CONST_TOKEN type_name_specifier                               { $$ = $2; dynamic_cast<TypeNode*>($$)->SetModifier(TypeModifier::Const); }
    | type_name_specifier                                           { $$ = $1; }
    ;

struct_specifier:
      STRUCT_TOKEN IDENTIFIER LEFT_BRACE struct_declaration_list RIGHT_BRACE {
	                                    							  $$ = $4; dynamic_cast<StructSpecifierNode*>($$)->SetName($2); }
    ;

struct_declaration_list:
      struct_declaration											{ $$ = new StructSpecifierNode(pContext, @$, $1); }
    | struct_declaration_list struct_declaration					{ $$ = $1; $$->AddNode($2); }
    ;

struct_declaration:
      fully_specified_type IDENTIFIER SEMICOLON						{ $$ = new StructDeclarationNode(pContext, @$, $1, $2); }
    | fully_specified_type IDENTIFIER LEFT_BRACKET INTCONSTANT RIGHT_BRACKET SEMICOLON
                                                                    { $$ = new StructDeclarationNode(pContext, @$, $1, $2, $4); }
    ;

module_definition:
      module_prototype SEMICOLON                                    { $$ = $1; }
    | module_prototype module_states                                { $$ = $1; dynamic_cast<ModuleDefinitionNode*>($$)->SetStatementList($2); }
    ;

module_states:
      LEFT_BRACE RIGHT_BRACE                                        { $$ = new ListNode(pContext, @$, nullptr); }
    | LEFT_BRACE state_list RIGHT_BRACE                             { $$ = $2; }
    ;

state_list:
      module_member                                                 { $$ = new ListNode(pContext, @$, $1); }
    | state_list module_member                                      { $$ = $1; $$->AddNode($2); }
    ;

module_member:
      module_state                                                  { $$ = $1; }
    | declaration_statement                                         { $$ = $1; }
    | function_definition                                           { $$ = $1; }
    | drive_list_definition                                         { $$ = $1; }
    ;

drive_list_definition:
      DRIVE_TOKEN LEFT_BRACE drive_statement_list RIGHT_BRACE       { $$ = new DriveListDefinitionNode(pContext, @$, $3); }
    ;

drive_statement_list:
      drive_definition                                              { $$ = new ListNode(pContext, @$, $1); }
    | drive_statement_list drive_definition                         { $$ = $1; $$->AddNode($2); }
    ;

drive_definition:
      INTCONSTANT COLON assignment_statement                        { $$ = new DriveDefinitionNode(pContext, @$, $1, $3); }
    | INTCONSTANT COLON FINISH_TOKEN SEMICOLON                      { $$ = new DriveDefinitionNode(pContext, @$, $1, nullptr); }
    ;

module_state:
      STATE_TOKEN IDENTIFIER compound_statement                     { $$ = new StateDeclaratorNode(pContext, @$, $2, $3); }
    | STATE_TOKEN INITIAL_TOKEN compound_statement                  { $$ = new StateDeclaratorNode(pContext, @$, KnownStates::Initial, $3); }
    | STATE_TOKEN ALWAYS_TOKEN compound_statement                   { $$ = new StateDeclaratorNode(pContext, @$, KnownStates::Always, $3); }
    ;

init_declarator_list:
      single_declaration                                            { $$ = $1; }
    ;

single_declaration:
      fully_specified_type IDENTIFIER                               { $$ = new VariableDeclarationNode(pContext, @$, $1, $2, nullptr, nullptr); }
    | fully_specified_type IDENTIFIER LEFT_BRACKET expression RIGHT_BRACKET
                                                                    { $$ = new VariableDeclarationNode(pContext, @$, $1, $2, $4, nullptr); }
    | fully_specified_type IDENTIFIER EQUAL expression              { $$ = new VariableDeclarationNode(pContext, @$, $1, $2, nullptr, $4); }
    ;

declaration_statement:
      declaration                                                   { $$ = $1; }
    ;

compound_statement:
      LEFT_BRACE RIGHT_BRACE                                        { $$ = new ListNode(pContext, @$, nullptr); }
    | LEFT_BRACE statement_list RIGHT_BRACE                         { $$ = $2; }
    ;

function_call:
      function_call_header RIGHT_PAREN                              { $$ = $1; }
    | function_call_header_no_param RIGHT_PAREN                     { $$ = $1; }
    ;

function_call_header_no_param:
      IDENTIFIER LEFT_PAREN                                         { $$ = new FunctionCallNode(pContext, @$, $1, nullptr, nullptr); }
    | IDENTIFIER LT expression GT LEFT_PAREN                        { $$ = new FunctionCallNode(pContext, @$, $1, $3, nullptr); }
    ;

function_call_header:
      IDENTIFIER LEFT_PAREN fn_call_arg                             { $$ = new FunctionCallNode(pContext, @$, $1, nullptr, $3); }
    | IDENTIFIER LT expression GT LEFT_PAREN fn_call_arg            { $$ = new FunctionCallNode(pContext, @$, $1, $3, $6); }
    | function_call_header COMMA fn_call_arg                        { $$ = $1; $$->AddNode($3); }
    ;

fn_call_arg:
      expression                                                    { $$ = new FunctionCallParamNode(pContext, @$, false, $1); }
    | OUT_TOKEN postfix_expression                                  { $$ = new FunctionCallParamNode(pContext, @$, true, $2); }
    | STRINGLITERAL                                                 { $$ = new FunctionCallParamNode(pContext, @$); }
    ;

return_statement:
      RETURN_TOKEN expression SEMICOLON                             { $$ = new ReturnNode(pContext, @$, $2); }

transition_statement:
      TRANSITION_TOKEN IDENTIFIER SEMICOLON                         { $$ = new TransitionNode(pContext, @$, $2); }
    ;

%%
