%{

#include "ASTTree.h"
#include "VSharpCompilerContext.h"
#include "VSharp.tab.h"

#define YY_EXTRA_TYPE PSLCompilerContext*
#define YY_USER_ACTION yyextra->UserAction(yylloc, yytext);

%}

%option bison-locations
%option reentrant
%option bison-bridge
%option noyywrap
%option yylineno

%%
"//".*"\n"           ;
"\n"                 ;
"@"                  { return AT; }
"*"                  { return STAR; }
"+"                  { return PLUS; }
"-"                  { return MINUS; }
"="                  { return EQUAL; }
":"                  { return COLON; }
";"                  { return SEMICOLON; }
"{"                  { return LEFT_BRACE; }
"}"                  { return RIGHT_BRACE; }
"("                  { return LEFT_PAREN; }
")"                  { return RIGHT_PAREN; }
"["                  { return LEFT_BRACKET; }
"]"                  { return RIGHT_BRACKET; }
"->"                 { return ARROW; }
"<<"                 { return SHIFTLEFT; }
">>"                 { return SHIFTRIGHT; }
".<"                 { return LT_OP; }
">."                 { return GT_OP; }
"<"                  { return LT; }
">"                  { return GT; }
"\."                 { return DOT; }
","                  { return COMMA; }
"&"                  { return AMPERSAND; }
"&&"                 { return AND_OP; }
"=="                 { return EQUAL_OP; }
"!="                 { return NOTEQUAL_OP; }
"out"                { return OUT_TOKEN; }
"state"              { return STATE_TOKEN; }
"uint"               { return UINT_TOKEN; }
"uint32"             { return UINT32_TOKEN; }
"uint16"             { return UINT16_TOKEN; }
"uint8"              { return UINT8_TOKEN; }
"void"               { return VOID_TOKEN; }
"initial"            { return INITIAL_TOKEN; }
"bool"               { return BOOL_TOKEN; }
"void"               { return VOID_TOKEN; }
"struct"             { return STRUCT_TOKEN; }
"packbyte"           { return PACKBYTE_TOKEN; }
"module"             { return MODULE_TOKEN; }
"transition"         { return TRANSITION_TOKEN; }
"return"             { return RETURN_TOKEN; }
"if"                 { return IF_TOKEN; }
"while"              { return WHILE_TOKEN; }
"else"               { return ELSE_TOKEN; }
"true"               { yylval->intVal = 1; return BOOLCONSTANT; }
"false"              { yylval->intVal = 0; return BOOLCONSTANT; }
[0-9]+               { yylval->intVal = atoi(yytext); return INTCONSTANT; }
"0x"[0-9A-Fa-f]+     { yylval->intVal = strtol(yytext, nullptr, 16); return INTCONSTANT; }
[A-Za-z_][A-Za-z0-9_]* { yylval->symIndex = yyextra->AddSymbol(yytext); return IDENTIFIER; }
.                    ;
%%
