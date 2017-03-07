%{

#include "ASTTree.h"
#include "PSLCompilerContext.h"
#include "PSL.tab.h"

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
"=="                 { return EQUAL_OP; }
"!="                 { return NOTEQUAL_OP; }
"ptr"                { return PTR_TOKEN; }
"byte"               { return BYTE_TOKEN; }
"word"               { return WORD_TOKEN; }
"bool"               { return BOOL_TOKEN; }
"float"              { return FLOAT_TOKEN; }
"void"               { return VOID_TOKEN; }
"struct"             { return STRUCT_TOKEN; }
"nullptr"            { return NULLPTR_TOKEN; }
"sizeof"             { return SIZEOF_TOKEN; }
"offsetptr"          { return OFFSETPTR_TOKEN; }
"castptr"            { return CASTPTR_TOKEN; }
"readport"           { return READPORT_TOKEN; }
"writeport"          { return WRITEPORT_TOKEN; }
"packbyte"           { return PACKBYTE_TOKEN; }
"__datasegmentend"   { return DATASEGEND_TOKEN; }
"return"             { return RETURN_TOKEN; }
"if"                 { return IF_TOKEN; }
"while"              { return WHILE_TOKEN; }
"else"               { return ELSE_TOKEN; }
"__saveregisters"    { return SAVEREG_TOKEN; }
"true"               { yylval->intVal = 1; return BOOLCONSTANT; }
"false"              { yylval->intVal = 0; return BOOLCONSTANT; }
"__emit"             { return EMIT_TOKEN; }
"__rsp"              { yylval->regIndex = 64; return REG_INDEX; }
"__rpt"              { yylval->regIndex = 68; return REG_INDEX; }
"__r"[0-9]           { yylval->regIndex = atoi(yytext + 3); return REG_INDEX; }
"doutr"              { return DOUTR_TOKEN; }
"dinr"               { return DINR_TOKEN; }
"dlenr"              { return DLENR_TOKEN; }
"execr"              { return EXECR_TOKEN; }
"exit"               { return EXIT_TOKEN; }
"vpenable"           { return VPENABLE_TOKEN; }
"movrc"              { return MOVRC_TOKEN; }
"movrr"              { return MOVRR_TOKEN; }
[0-9]+               { yylval->intVal = atoi(yytext); return INTCONSTANT; }
"0x"[0-9A-Fa-f]+     { yylval->intVal = strtol(yytext, nullptr, 16); return INTCONSTANT; }
"f"[0-9]+"\."[0-9]*  { yylval->floatVal = (float)atof(yytext + 1); return FLOATCONSTANT; }
[A-Za-z_][A-Za-z0-9_]* { yylval->symIndex = yyextra->AddSymbol(yytext); return IDENTIFIER; }
.                    ;
%%
